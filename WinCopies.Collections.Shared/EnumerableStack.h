#pragma once
#ifndef ENUMERABLESTACK_H
#define ENUMERABLESTACK_H

#include "defines.h"
#include "IStack.h"
#include "Stack.h"
#include "EnumerableStack.h"
#include "SimpleLinkedListNode.h"
#include "IEnumerator.h"
#include "IEnumerable.h"
#include "StackEnumerator.h"
#include "../WinCopies.Util.Base.Shared/SafePointer.h"
#include "../WinCopies.Util.Base.Shared/OutPointer.h"

namespace WinCopies
{
    namespace Collections
    {
        TEMPLATE
        class IStack;

        TEMPLATE
        class Stack;

        TEMPLATE
        class EnumerableStack;

        TEMPLATE
        class SimpleLinkedListNode;

        TEMPLATE
        class DLLEXPORT IEnumerableStack ABSTRACT:
                public virtual IStack<T>,
                public virtual ISimpleEnumerableLinkedList<T>
        {
        public:
            virtual ~IEnumerableStack() override = default;
        };

        TEMPLATE
        class DLLEXPORT EnumerableStack:
                public virtual IEnumerableStack<T>
        {
        private:
            SafePointer<Stack<T>> _stack;
            unsigned int _version = 0;
            unsigned int _enumeratorsCount = 0;

            void incrementEnumeratorsCount()
            {
                _enumeratorsCount++;
            }
            
            friend class StackEnumerator<T>;

        public:
            explicit EnumerableStack()
            {
                _stack = new SafePointer<Stack<T>>(new Stack<T>());
            }

            virtual ~EnumerableStack()
            {
                // Left empty.
            }

            virtual IEnumerator<T>* GetEnumerator() final
            {
                incrementEnumeratorsCount();

                return new StackEnumerator<T>(this);
            }

            virtual unsigned int GetCount() const final
            {
                return _stack.GetPointer()->GetCount();
            }

            virtual bool GetIsReadOnly() const final
            {
                return _stack.GetPointer()->GetIsReadOnly();
            }

            virtual void Clear() final
            {
                _version++;

                return _stack.GetPointer()->Clear();
            }

            virtual T Peek() const final
            {
                return _stack.GetPointer()->Peek();
            }

            virtual bool TryPeek(OUTPOINTER result) const final
            {
                return _stack.GetPointer()->TryPeek(result);
            }

            virtual void Push(const T value) final
            {
                _version++;

                _stack.GetPointer()->Push(value);
            }

            virtual bool TryPush(const T value) final
            {
                _version++;

                return _stack.GetPointer()->TryPush(value);
            }

            virtual T Pop() final
            {
                _version++;

                return _stack.GetPointer()->Pop();
            }

            virtual bool TryPop(OUTPOINTER result) final
            {
                _version++;

                return _stack.GetPointer()->TryPop(result);
            }
        };
    }
}

#endif // ENUMERABLESTACK_H

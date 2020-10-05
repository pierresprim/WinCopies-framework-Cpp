#pragma once
#ifndef ENUMERABLESTACK_H
#define ENUMERABLESTACK_H
#include "Stack.h"
#include "SimpleLinkedListNode.h"
#include "IEnumerable.h"
#include "EnumeratorBase.h"
#include "StackEnumerator.h"

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
                public virtual IEnumerable<T>
        {
        public:
            virtual ~IEnumerableStack() override = default;
        };

        TEMPLATE
        class DLLEXPORT EnumerableStack:
                public virtual IEnumerableStack<T>
        {
        private:
            Stack<T>* _stack;
            uint _version = 0;
            uint _enumeratorsCount = 0;
            void incrementEnumeratorsCount()
            {
                _enumeratorsCount++;
            }
            friend class StackEnumerator<T>;
        public:
            explicit EnumerableStack()
            {
                _stack = new Stack<T>();
            }

            ~EnumerableStack()
            {
                _stack->~Stack<T>();

                delete _stack;

                _stack = nullptr;
            }

            virtual IEnumerator<T>* GetEnumerator() final
            {
                incrementEnumeratorsCount();

                return new StackEnumerator<T>(this);
            }

            virtual uint GetCount() const final
            {
                return _stack->GetCount();
            }

            virtual bool GetIsReadOnly() const final
            {
                return _stack->GetIsReadOnly();
            }

            virtual void Clear() final
            {
                _version++;

                return _stack->Clear();
            }

            virtual T Peek() const final
            {
                return _stack->Peek();
            }

            virtual bool TryPeek(T* result) const final
            {
                return _stack->TryPeek(result);
            }

            virtual void Push(const T value) final
            {
                _version++;

                _stack->Push(value);
            }

            virtual bool TryPush(const T value) final
            {
                _version++;

                return _stack->TryPush(value);
            }

            virtual T Pop() final
            {
                _version++;

                return _stack->Pop();
            }

            virtual bool TryPop(T* result) final
            {
                _version++;

                return _stack->TryPop(result);
            }
        };
    }
}

#endif // ENUMERABLESTACK_H

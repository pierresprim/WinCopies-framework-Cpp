#pragma once
#ifndef ENUMERABLESTACK_H
#define ENUMERABLESTACK_H
#include "Stack.h"
#include "SimpleLinkedListNode.h"
#include "IEnumerable.h"
#include "EnumeratorBase.h"

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
            class DLLEXPORT SimpleLinkedListNode;

        TEMPLATE
        class StackEnumerator :
                public virtual EnumeratorBase<T>
        {
        private:
            EnumerableStack<T>* _stack;
            uint _version;
            const SimpleLinkedListNode<T>* _currentNode;
        public:
            explicit StackEnumerator(EnumerableStack<T>* stack)
            {
                _stack = stack;

                _version = stack->_version;
            }

            virtual ~StackEnumerator() override
            {
                _stack->_enumeratorsCount--;

                if (_stack->_enumeratorsCount == 0)

                    _stack->_version = 0;

                _stack = nullptr;

                _currentNode = nullptr;
            }
        protected:
            virtual bool GetIsResetSupported() const final
            {
                return true;
            }

            virtual T GetCurrentOverride() const final
            {
                return _currentNode->GetValue();
            }

            virtual int MoveNextOverride(bool* result) final
            {
                if (_stack->_version!=_version)
                {
                    *result = false;

                    return OBJECT_HAS_CHANGED_DURING_ENUMERATION;
                }

                if (_currentNode == nullptr)

                    _currentNode = _stack->_stack->GetFirst();

                else

                    _currentNode = _currentNode->GetNextNode();

                *result = _currentNode != nullptr;

                return EXIT_SUCCESS;
            }

            virtual int ResetOverride() final
            {
                _currentNode = _stack->_stack->GetFirst();

                return EXIT_SUCCESS;
            }
        };

        TEMPLATE
        class EnumerableStack:
            public virtual IStack<T>,
            public virtual IEnumerable<T>
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

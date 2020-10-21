#pragma once
#ifndef ENUMERABLESTACK_H
#define ENUMERABLESTACK_H
#include "IStack.h"
#include "Stack.h"
#include "EnumerableStack.h"
#include "SimpleLinkedListNode.h"
#include "IEnumerator.h"
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
            Stack<T>* _stack;
            unsigned int _version = 0;
            unsigned int _enumeratorsCount = 0;
            void incrementEnumeratorsCount()
            {
                _enumeratorsCount++;
            }
            void incrementVersionCount()
            {
                if (_enumeratorsCount > 0)

                    _version++;
            }
        public:
            class DLLEXPORT StackEnumerator :
                public virtual EnumeratorBase<T>
            {
            private:
                EnumerableStack<T>* _stack;
                unsigned int _version;
                const SimpleLinkedListNode<T>* _currentNode;
            public:
                explicit StackEnumerator(EnumerableStack<T>* stack)
                {
                    _stack = stack;

                    _version = stack->_version;
                }

                virtual EnumerationDirection GetEnumerationDirection() const final
                {
                    return EnumerationDirection::LIFO;
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
                    if (_stack->_version != _version)
                    {
                        *result = false;

                        return OBJECT_HAS_CHANGED_DURING_ENUMERATION_EXCEPTION;
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
                    if (_stack->_version != _version)

                        return OBJECT_HAS_CHANGED_DURING_ENUMERATION_EXCEPTION;

                    _currentNode = _stack->_stack->GetFirst();

                    return EXIT_SUCCESS;
                }
            };
            explicit EnumerableStack()
            {
                _stack = new Stack<T>();
            }

            ~EnumerableStack()
            {
                delete _stack;

                _stack = nullptr;
            }

            virtual IEnumerator<T>* GetEnumerator() final
            {
                incrementEnumeratorsCount();

                return new StackEnumerator(this);
            }

            virtual unsigned int GetCount() const final
            {
                return _stack->GetCount();
            }

            virtual bool GetIsReadOnly() const final
            {
                return _stack->GetIsReadOnly();
            }

            virtual void Clear() final
            {
                incrementVersionCount();

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
                incrementVersionCount();

                _stack->Push(value);
            }

            virtual bool TryPush(const T value) final
            {
                if (_stack->TryPush(value))
                {
                    incrementVersionCount();

                    return true;
                }

                return false;
            }

            virtual T Pop() final
            {
                incrementVersionCount();

                return _stack->Pop();
            }

            virtual bool TryPop(T* result) final
            {
                if (_stack->TryPop(result))
                {
                    incrementVersionCount();

                    return true;
                }

                return false;
            }
        };
    }
}

#endif // ENUMERABLESTACK_H

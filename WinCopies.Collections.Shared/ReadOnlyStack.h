#pragma once
#ifndef READONLYSTACK_H
#define READONLYSTACK_H

#include "EnumerableStack.h"
#include "../WinCopies.Util.Base.Shared/Exception.h"

namespace WinCopies
{
    namespace Collections
    {
        TEMPLATE
        class DLLEXPORT ReadOnlyStack : public virtual IEnumerableStack<T>
        {
        private:
            IEnumerableStack<T>* _stack;
            bool _autoDispose;
        public:
            // Initializes a new instance of the ReadOnlyStack class.
            explicit ReadOnlyStack(IEnumerableStack<T>* stack, bool autoDispose)
            {
                _stack = stack;

                _autoDispose = autoDispose;
            }

            ~ReadOnlyStack()
            {
                if (_autoDispose)
                {
                    delete _stack;

                    _stack = nullptr;
                }
            }

            virtual IEnumerator<T>* GetEnumerator() final
            {
                return _stack->GetEnumerator();
            }

            virtual void Push(const T value) final
            {
                throw new ReadOnlyException();
            }

            virtual bool TryPush(const T value) final
            {
                return false;
            }

            virtual T Pop() final
            {
                throw new ReadOnlyException();
            }

            virtual bool TryPop( T*  result) final
            {
                return false;
            }

            virtual bool GetIsReadOnly() const final
            {
                return true;
            }

            virtual void Clear() final
            {
                throw new ReadOnlyException();
            }

            virtual T Peek() const final
            {
                return _stack->Peek();
            }

            virtual bool TryPeek( T*  result) const final
            {
                return _stack->TryPeek(result);
            }

            virtual unsigned int GetCount() const final
            {
                return _stack->GetCount();
            }
        };
    }
}

#endif // READONLYSTACK_H

#pragma once
#ifndef READONLYQUEUE_H
#define READONLYQUEUE_H

#include "defines.h"
#include "EnumerableQueue.h"
#include "../WinCopies.Util.Base.Shared/Exception.h"
#include "../WinCopies.Util.Base.Shared/ThrowHelper.h"
#include "../WinCopies.Util.Base.Shared/OutPointer.h"

namespace WinCopies
{
    namespace Collections
    {
        TEMPLATE
        class DLLEXPORT ReadOnlyQueue : public virtual IEnumerableQueue<T>
        {
        private:
            IEnumerableQueue<T>* _queue;
            bool _autoDispose;
        public:
            // Initializes a new instance of the ReadOnlyQueue class.
            explicit ReadOnlyQueue( IEnumerableQueue<T>* const queue, const bool autoDispose)
            {
                ThrowHelper::ThrowIfNullPtrValue(queue, L"queue");

                _queue = queue;

                _autoDispose = autoDispose;
            }

            ~ReadOnlyQueue()
            {
                if (_autoDispose)
                {
                    delete _queue;

                    _queue = nullptr;
                }
            }

            virtual IEnumerator<T>* GetEnumerator() final
            {
                return _queue->GetEnumerator();
            }

            virtual void Enqueue(const T value) final
            {
                throw new ReadOnlyException();
            }

            virtual bool TryEnqueue(const T value) final
            {
                return false;
            }

            virtual T Dequeue() final
            {
                throw new ReadOnlyException();
            }

            virtual bool TryDequeue(OUTPOINTER result) final
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
                return _queue->Peek();
            }

            virtual bool TryPeek(OUTPOINTER result) const final
            {
                return _queue->TryPeek(result);
            }

            virtual unsigned int GetCount() const final
            {
                return _queue->GetCount();
            }
        };
    }
}

#endif // READONLYQUEUE_H

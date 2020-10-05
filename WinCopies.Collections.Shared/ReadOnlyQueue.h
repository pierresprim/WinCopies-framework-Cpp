#pragma once
#ifndef READONLYQUEUE_H
#define READONLYQUEUE_H

#include "EnumerableQueue.h"
#include "../WinCopies.Util.Base.Shared/Exception.h"

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
            explicit ReadOnlyQueue(IEnumerableQueue<T>* queue, bool autoDispose)
            {
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

            virtual bool TryDequeue( T*  result) final
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

            virtual bool TryPeek( T*  result) const final
            {
                return _queue->TryPeek(result);
            }

            virtual uint GetCount() const final
            {
                return _queue->GetCount();
            }
        };
    }
}

#endif // READONLYQUEUE_H

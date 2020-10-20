#pragma once
#ifndef ENUMERABLEQUEUE_H
#define ENUMERABLEQUEUE_H

#include "defines.h"
#include "IQueue.h"
#include "Queue.h"
#include "EnumerableQueue.h"
#include "SimpleLinkedListNode.h"
#include "IEnumerator.h"
#include "IEnumerable.h"
#include "QueueEnumerator.h"
#include "../WinCopies.Util.Base.Shared/OutPointer.h"

namespace WinCopies
{
    namespace Collections
    {
        TEMPLATE
        class IQueue;

        TEMPLATE
        class Queue;

        TEMPLATE
        class EnumerableQueue;

        TEMPLATE
        class SimpleLinkedListNode;

        TEMPLATE
        class QueueEnumerator;

        TEMPLATE
        class DLLEXPORT IEnumerableQueue ABSTRACT:
                public virtual IQueue<T>,
                public virtual ISimpleEnumerableLinkedList<T>
        {
        public:
            virtual ~IEnumerableQueue() override = default;
        };

        TEMPLATE
        class DLLEXPORT EnumerableQueue:
                public virtual IEnumerableQueue<T>
        {
        private:
            typedef struct SafePointer<Queue<T>> SafePointer;
            SafePointer _queue;
            unsigned int _version = 0;
            unsigned int _enumeratorsCount = 0;

            void incrementEnumeratorsCount()
            {
                _enumeratorsCount++;
            }

            friend class QueueEnumerator<T>;

        public:
             EnumerableQueue()
            {
                 _queue = SafePointer::GetSafePointer( new Queue<T>());
            }

            virtual ~EnumerableQueue()
            {
                // Left empty.
            }

            virtual IEnumerator<T>* GetEnumerator() final
            {
                incrementEnumeratorsCount();

                return new QueueEnumerator<T>(this);
            }

            virtual unsigned int GetCount() const final
            {
                return _queue.GetPointer()->GetCount();
            }

            virtual bool GetIsReadOnly() const final
            {
                return _queue.GetPointer()->GetIsReadOnly();
            }

            virtual void Clear() final
            {
                _version++;

                return _queue.GetPointer()->Clear();
            }

            virtual T Peek() const final
            {
                return _queue.GetPointer()->Peek();
            }

            virtual bool TryPeek( OUTPOINTER result) const final
            {
                return _queue.GetPointer()->TryPeek(result);
            }

            virtual void Enqueue(const T value) final
            {
                _version++;

                _queue.GetPointer()->Enqueue(value);
            }

            virtual bool TryEnqueue(const T value) final
            {
                _version++;

                return _queue.GetPointer()->TryEnqueue(value);
            }

            virtual T Dequeue() final
            {
                _version++;

                return _queue.GetPointer()->Dequeue();
            }

            virtual bool TryDequeue(OUTPOINTER result) final
            {
                _version++;

                return _queue.GetPointer()->TryDequeue(result);
            }
        };
    }
}

#endif // ENUMERABLEQUEUE_H

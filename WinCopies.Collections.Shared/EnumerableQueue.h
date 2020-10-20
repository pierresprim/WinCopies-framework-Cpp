#pragma once
#ifndef ENUMERABLEQUEUE_H
#define ENUMERABLEQUEUE_H
#include "IQueue.h"
#include "Queue.h"
#include "EnumerableQueue.h"
#include "SimpleLinkedListNode.h"
#include "IEnumerator.h"
#include "IEnumerable.h"
#include "QueueEnumerator.h"

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
            Queue<T>* _queue;
            unsigned int _version = 0;
            unsigned int _enumeratorsCount = 0;
            void incrementEnumeratorsCount()
            {
                _enumeratorsCount++;
            }
            friend class QueueEnumerator<T>;
        public:
            explicit EnumerableQueue()
            {
                _queue = new Queue<T>();
            }

            ~EnumerableQueue()
            {
                _queue->~Queue<T>();

                delete _queue;

                _queue = nullptr;
            }

            virtual IEnumerator<T>* GetEnumerator() final
            {
                incrementEnumeratorsCount();

                return new QueueEnumerator<T>(this);
            }

            virtual unsigned int GetCount() const final
            {
                return _queue->GetCount();
            }

            virtual bool GetIsReadOnly() const final
            {
                return _queue->GetIsReadOnly();
            }

            virtual void Clear() final
            {
                _version++;

                return _queue->Clear();
            }

            virtual T Peek() const final
            {
                return _queue->Peek();
            }

            virtual bool TryPeek(T* result) const final
            {
                return _queue->TryPeek(result);
            }

            virtual void Enqueue(const T value) final
            {
                _version++;

                _queue->Enqueue(value);
            }

            virtual bool TryEnqueue(const T value) final
            {
                _version++;

                return _queue->TryEnqueue(value);
            }

            virtual T Dequeue() final
            {
                _version++;

                return _queue->Dequeue();
            }

            virtual bool TryDequeue(T* result) final
            {
                _version++;

                return _queue->TryDequeue(result);
            }
        };
    }
}

#endif // ENUMERABLEQUEUE_H

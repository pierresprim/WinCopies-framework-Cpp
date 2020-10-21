#pragma once
#ifndef ENUMERABLEQUEUE_H
#define ENUMERABLEQUEUE_H
#include "IQueue.h"
#include "Queue.h"
#include "EnumerableQueue.h"
#include "SimpleLinkedListNode.h"
#include "IEnumerator.h"
#include "IEnumerable.h"
#include "EnumeratorBase.h"

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
			class DLLEXPORT IEnumerableQueue ABSTRACT :
		public virtual IQueue<T>,
			public virtual ISimpleEnumerableLinkedList<T>
		{
		public:
			virtual ~IEnumerableQueue() override = default;
		};

		TEMPLATE
			class DLLEXPORT EnumerableQueue :
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
			void incrementVersionCount()
			{
				if (_enumeratorsCount > 0)

					_version++;
			}
			friend class QueueEnumerator<T>;
		public:
			class DLLEXPORT QueueEnumerator :
				public virtual EnumeratorBase<T>
			{
			private:
				EnumerableQueue<T>* _queue;
				unsigned int _version;
				const SimpleLinkedListNode<T>* _currentNode;
			public:
				explicit QueueEnumerator(EnumerableQueue<T>* queue)
				{
					_queue = queue;

					_version = queue->_version;
				}

				virtual EnumerationDirection GetEnumerationDirection() const final
				{
					return EnumerationDirection::FIFO;
				}

				virtual ~QueueEnumerator() override
				{
					_queue->_enumeratorsCount--;

					if (_queue->_enumeratorsCount == 0)

						_queue->_version = 0;

					_queue = nullptr;

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
					if (_queue->_version != _version)
					{
						*result = false;

						return OBJECT_HAS_CHANGED_DURING_ENUMERATION_EXCEPTION;
					}

					if (_currentNode == nullptr)

						_currentNode = _queue->_queue->GetFirst();

					else

						_currentNode = _currentNode->GetNextNode();

					*result = _currentNode != nullptr;

					return EXIT_SUCCESS;
				}

				virtual int ResetOverride() final
				{
					if (_queue->_version != _version)

						return OBJECT_HAS_CHANGED_DURING_ENUMERATION_EXCEPTION;

					_currentNode = _queue->_queue->GetFirst();

					return EXIT_SUCCESS;
				}
			};

			explicit EnumerableQueue()
			{
				_queue = new Queue<T>();
			}

			~EnumerableQueue()
			{
				delete _queue;

				_queue = nullptr;
			}

			virtual IEnumerator<T>* GetEnumerator() final
			{
				incrementEnumeratorsCount();

				return new QueueEnumerator(this);
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
				incrementVersionCount();

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
				incrementVersionCount();

				_queue->Enqueue(value);
			}

			virtual bool TryEnqueue(const T value) final
			{
				if (_queue->TryEnqueue(value))
				{
					incrementVersionCount();

					return true;
				}

				return false;
			}

			virtual T Dequeue() final
			{
				incrementVersionCount();

				return _queue->Dequeue();
			}

			virtual bool TryDequeue(T* result) final
			{
				if (_queue->TryDequeue(result))
				{
					incrementVersionCount();

					return true;
				}

				return false;
			}
		};
	}
}

#endif // ENUMERABLEQUEUE_H

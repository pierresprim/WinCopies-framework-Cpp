#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include "defines.h"
#include "IQueue.h"
#include "SimpleLinkedList.h"
#include "SimpleLinkedListNode.h"
#include "../WinCopies.Util.Base.Shared/Exception.h"
#include "../WinCopies.Util.Base.Shared/OutPointer.h"

namespace WinCopies
{
	namespace Collections
	{
		TEMPLATE
			class SimpleLinkedList;

		TEMPLATE
			class SimpleLinkedListNode;

		TEMPLATE
			class IQueue;

		TEMPLATE
			class DLLEXPORT Queue :
			virtual public SimpleLinkedList<T>,
			virtual public IQueue<T>
		{
		private:
			SimpleLinkedListNode<T>* _lastNode = nullptr;
		protected:
			void OnEnqueue(SimpleLinkedListNode<T>* const node)
			{
				if (this->GetCount() == 0)

					this->AddFirstItem(node);

				else

					_lastNode->SetNext(node);

				_lastNode = node;

				this->IncrementCount();
			}

			T OnDequeue()
			{
				T result;

				if (this->GetCount() == 1)
				{
					result = this->GetFirst()->GetValue();

					this->RemoveFirstItem();
				}

				else
				{
					const	SimpleLinkedListNode<T>* node = this->GetFirst();

					result = node->GetValue();

					this->AddFirstItem(node->GetNextNode());

					delete node;

					node = nullptr;

					this->DecrementCount();
				}

				return result;
			}

		public:
			virtual ~Queue() override
			{
				if (_lastNode != nullptr)

					_lastNode = nullptr; // This is a pointer to the last item of the Queue. Because all of the items are deleted in the SimpleLinkedList deconstructor, we do not have to delete _lastNode here.
			}

			virtual void Enqueue(const T value) final
			{
				OnEnqueue(new SimpleLinkedListNode<T>(value));
			}

			virtual bool TryEnqueue(const T value) final
			{
				Enqueue(value);

				return true;
			}

			virtual T Dequeue() final
			{
				if (this->GetCount() == 0)

					throw new EmptyObjectException();

				return OnDequeue();
			}

			virtual bool TryDequeue(OUTPOINTER result) final
			{
				if (this->GetCount() == 0)
				{
					*result = new OutPointer<T>();

					return false;
				}

				*result = new OutPointer<T>(OnDequeue());

				return true;
			}
		};
	}
}

#endif

#pragma once

#ifndef WINCOPIES_COLLECTIONS_QUEUE_H
#define WINCOPIES_COLLECTIONS_QUEUE_H

#include "IQueue.h"
#include "SimpleLinkedList.h"
#include "SimpleLinkedListNode.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				CLASS Queue :
			BASE_TEMPLATES(SimpleLinkedList, IQueue)
			{
			private:
				SimpleLinkedListNode<T>*_lastItem;

			protected:
				virtual SimpleLinkedListNode<T>* AddItem(const T item, bool* const actionAfter) final
				{
					if (this->GetFirstItem() == nullptr)
					{
						*actionAfter = true;

						return new SimpleLinkedListNode<T>(item);
					}

					*actionAfter = false;

					SimpleLinkedListNode<T>* newNode = new SimpleLinkedListNode<T>(item);

					this->ItemSetNext(_lastItem, newNode);

					_lastItem = newNode;

					return this->GetFirstItem();
				}

				FINAL_METHOD(void OnItemAdded)
				{
					_lastItem = this->GetFirstItem();
				}

				FINAL_METHOD(SimpleLinkedListNode<T>* RemoveItem)
				{
					SimpleLinkedListNode<T>* node;

					int result = this->GetFirstItem()->GenericGetNext2(&node);

					return node;
				}

			public:
				FINAL_ARG_METHOD(void Enqueue, const T item)
				{
					this->Add(item);
				}

				FINAL_ARG_METHOD(bool TryDequeue, T* const result)
				{
					return this->TryRemove(result);
				}

				FINAL_ARG_METHOD(int Dequeue, T* const result)
				{
					return this->Remove(result);
				}
			};
		}
	}
}
#endif // WINCOPIES_COLLECTIONS_QUEUE_H
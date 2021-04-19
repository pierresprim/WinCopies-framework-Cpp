#pragma once
#ifndef STACK_H
#define STACK_H
#include "defines.h"
#include "IStack.h"
#include "SimpleLinkedList.h"
#include "SimpleLinkedListNode.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				CLASS Stack :
			BASE_INTERFACE SimpleLinkedList<T>,
				BASE_INTERFACE IStack<T>
			{
			protected:
				virtual SimpleLinkedListNode<T>*AddItem(const T item, bool* const actionAfter) final
					{
						*actionAfter = false;

						SimpleLinkedListNode<T>* newNode = new SimpleLinkedListNode<T>(item);

						this->ItemSetNext(newNode, this->GetFirstItem());

						return newNode;
					}

					FINAL_METHOD(void OnItemAdded)
					{
						// Left empty.
					}

					FINAL_METHOD(SimpleLinkedListNode<T>* RemoveItem)
					{
						SimpleLinkedListNode<T>* node;

						int result = this->GetFirstItem()->GenericGetNext2(&node);

						return node;
					}

			public:
				FINAL_ARG_METHOD(void Push, const T item)
				{
					this->Add(item);
					}

					FINAL_ARG_METHOD(bool TryPop, T* const result)
					{
						return this->TryRemove(result);
						}

					FINAL_ARG_METHOD(int Pop, T* const result)
					{
						return this->Remove(result);
}
			};
		}
	}
}

#endif

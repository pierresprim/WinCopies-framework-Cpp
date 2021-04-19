#pragma once
#ifndef SIMPLELINKEDLIST_H
#define SIMPLELINKEDLIST_H

#include "defines.h"
#include "ISimpleLinkedList.h"
#include "SimpleLinkedListNode.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				CLASS SimpleLinkedListNode;

			INTERFACE(SimpleLinkedListBase) :
				BASE_INTERFACE ISimpleLinkedListBase2
			{
			protected:
				ABSTRACT_METHOD(void ClearItems);

			public:
				OVERRIDE_METHOD_CONST(bool GetHasItems)
				{
					return HAS_ITEMS;
				}

				int Clear()
				{
					if (GetIsReadOnly())

						return READ_ONLY_EXCEPTION;

					ClearItems();
				}
			};

			TEMPLATE
				INTERFACE(SimpleLinkedList) :
				BASE_INTERFACE SimpleLinkedListBase,
				BASE_INTERFACE ISimpleLinkedList<T>
			{
			private:
				// Fields
				UINT _count = 0;
				SimpleLinkedListNode<T>* _firstItem = nullptr;

				// Methods
				T OnRemove()
				{
					SimpleLinkedListNode<T>* firstItem = _firstItem;

					T result;

					firstItem->GenericGetValue(&result);

					_firstItem = RemoveItem();

					firstItem->Clear();

					_count--;

					return result;
				}

			protected:
				ABSTRACT_METHOD(SimpleLinkedListNode<T>* RemoveItem);

				void ItemSetNext(SimpleLinkedListNode<T>* const item, SimpleLinkedListNode<T>* const newNode)
				{
					item->SetNext(newNode);
				}

				virtual SimpleLinkedListNode<T>* AddItem(const T item, bool* const actionAfter) = 0;

				ABSTRACT_METHOD(void OnItemAdded);

				T _Peek() const
				{
					T result;

					_firstItem->GenericGetValue(&result);

					return result;
				}

				SimpleLinkedListNode<T>* GetFirstItem()
				{
					return _firstItem;
				}

				int Remove(T* const result)
				{
					if (GetIsReadOnly())

						return READ_ONLY_EXCEPTION;

					if (GetHasItems())
					{
						*result = OnRemove();

						return EXIT_SUCCESS;
					}

					return EMPTY_OBJECT_EXCEPTION;
				}

				int Add(const T item)
				{
					if (GetIsReadOnly())

						return READ_ONLY_EXCEPTION;

					bool actionAfter;

					_firstItem = AddItem(item, &actionAfter);

					_count++;

					if (actionAfter)

						OnItemAdded();

					return EXIT_SUCCESS;
				}

				FINAL_METHOD(void ClearItems)
				{
					SimpleLinkedListNode<T>* node;
					SimpleLinkedListNode<T>* temp;

					node = _firstItem;

					while (node != nullptr)
					{
						node->GenericGetNext2(&temp);

						node->Clear();

						node = temp;
					}

					_firstItem = nullptr;

					_count = 0;
				}

				bool TryRemove(T* const result)
				{
					if (GetIsReadOnly() || GetCount() == 0)

						return false;

					*result = OnRemove();

					return true;
				}

			public:
				FINAL_ARG_METHOD_CONST(bool GenericTryPeek, T* const result)
				{
					if (_count > 0)
					{
						*result = _Peek();

						return true;
					}

					return false;
				}

				FINAL_ARG_METHOD_CONST(int GenericPeek, T* const result)
				{
					if (_count > 0)
					{
						*result = _Peek();

						return EXIT_SUCCESS;
					}

					return EMPTY_OBJECT_EXCEPTION;
				}

				FINAL_METHOD_CONST(bool GetIsReadOnly)
				{
					return false;
				}

				FINAL_METHOD_CONST(UINT GetCount)
				{
					return _count;
				}

				~SimpleLinkedList()
				{
					Clear();

					delete _firstItem;

					_firstItem = nullptr;
				}
			};
		}
	}
}

#endif

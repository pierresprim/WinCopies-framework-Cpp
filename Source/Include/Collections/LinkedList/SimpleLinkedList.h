#pragma once
#ifndef SIMPLELINKEDLIST_H
#define SIMPLELINKEDLIST_H

#include "../ICollection.h"
#include "ISimpleLinkedList.h"
#include "SimpleLinkedListNode.h"

namespace WinCopies
{
	namespace Collections
	{
		INTERFACE_CLASS(SimpleLinkedListBase) :
			BASE_INTERFACE ISimpleLinkedListBase2,
			BASE_INTERFACE WinCopies::Collections::ICollection
		{
		protected:
			ABSTRACT_METHOD(void ClearItems);

		public:
			OVERRIDE_METHOD_CONST(bool GetHasItems);

			virtual ErrorCode Clear() final;
		};

		namespace Generic
		{
			TEMPLATE
				CLASS SimpleLinkedListNode;

			TEMPLATE
				INTERFACE_CLASS(SimpleLinkedList) :
				BASE_INTERFACE WinCopies::Collections::SimpleLinkedListBase,
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

				ErrorCode Remove(T* const result)
				{
					if (GetIsReadOnly())

						return ErrorCode::ReadOnlyException;

					if (GetHasItems())
					{
						*result = OnRemove();

						return ErrorCode::Success;
					}

					return ErrorCode::EmptyObjectException;
				}

				ErrorCode Add(const T item)
				{
					if (GetIsReadOnly())

						return ErrorCode::ReadOnlyException;

					bool actionAfter;

					_firstItem = AddItem(item, &actionAfter);

					_count++;

					if (actionAfter)

						OnItemAdded();

					return ErrorCode::Success;
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
					if (IsReadOnly() || GetCount() == 0)

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

				FINAL_ARG_METHOD_CONST(ErrorCode GenericPeek, T* const result)
				{
					if (_count > 0)
					{
						*result = _Peek();

						return ErrorCode::Success;
					}

					return ErrorCode::EmptyObjectException;
				}

				FINAL_METHOD_CONST(bool IsReadOnly)
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

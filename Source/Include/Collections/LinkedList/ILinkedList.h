#pragma once
#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H

#include "defines.h"
#include "IEnumerable.h"
#include "IEnumerator.h"
#include "IReadOnlyLinkedList.h"

using namespace WinCopies::Collections::Generic;

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				CLASS LinkedListNodeEnumerable :
			BASE_INTERFACE IUIntCountableEnumerable<ILinkedListNode<T>*>
			{
			private:
				ILinkedList<T>*_list;
			public:
				LinkedListNodeEnumerable(ILinkedList<T>* const list)
				{
					_list = list;
				}

				virtual UINT GetCount() final
				{
					return _list->GetCount();
				}

				virtual IEnumerator<T>* GetEnumerator()
				{
					return _list->GetNodeEnumerator();
				}

				virtual bool GetSupportsReversedEnumeration()
				{
					return true;
				}

				virtual IEnumerator<T>* GetReversedEnumerator()
				{
					return _list->GetReversedNodeEnumerator();
				}

				~LinkedListNodeEnumerable()
				{
					_linkedList = nullptr;
				}
			};

			TEMPLATE
				INTERFACE(ILinkedList) :
				BASE_INTERFACE IReadOnlyLinkedList<T>,
				BASE_INTERFACE WinCopies::Collections::ICollection
			{
			public:
				virtual ~ILinkedList() override = default;

				virtual IEnumerator<T>* GetEnumerator() = 0;

				virtual IEnumerator<T>* GetReversedEnumerator() = 0;

				virtual IEnumerator<ILinkedListNode<T>*> GetNodeEnumerator() = 0;

				virtual IEnumerator<ILinkedListNode<T>*> GetReversedNodeEnumerator() = 0;



				virtual ILinkedListNode<T>* AddAfter(ILinkedListNode<T>* const node, const T value) = 0;

				virtual ILinkedListNode<T>* AddBefore(ILinkedListNode<T>* const node, const T value) = 0;

				virtual ILinkedListNode<T>* AddFirst(const T value) = 0;

				virtual ILinkedListNode<T>* AddLast(const T value) = 0;



				virtual void Remove(ILinkedListNode<T>* node) = 0;

				virtual ILinkedListNode<T>* Remove(T item) = 0;

				virtual void RemoveFirst() = 0;

				virtual void RemoveLast() = 0;



				virtual bool Contains(const T item) = 0;

				virtual void CopyTo(const T* _array, const int arrayIndex, const int arrayLength) = 0;
			};

			TEMPLATE
				INTERFACE(ILinkedList2) :
				BASE_INTERFACE ILinkedList<T>
			{
				virtual ~ILinkedList2() override = default;

				virtual bool MoveAfter(ILinkedListNode<T>* node, ILinkedListNode<T>* after) = 0;

				virtual bool MoveBefore(ILinkedListNode<T> node, ILinkedListNode<T>* before) = 0;

				virtual void Swap(ILinkedListNode<T> x, ILinkedListNode<T> y) = 0;
			};
		}
	}
}

#endif // ILINKEDLIST_H

#pragma once

#ifndef WINCOPIES_COLLECTIONS_ILINKEDLIST_H
#define WINCOPIES_COLLECTIONS_ILINKEDLIST_H

#include "../Enumeration/IEnumerable.h"
#include "../Enumeration/IEnumerator.h"
#include "IReadOnlyLinkedList.h"

using namespace WinCopies::Collections::Generic;

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				INTERFACE_CLASS(ILinkedList);

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
					_list = nullptr;
				}
			};

			TEMPLATE
				INTERFACE_CLASS(ILinkedList) :
				BASE_TEMPLATE(IReadOnlyLinkedList),
				BASE_INTERFACE WinCopies::Collections::ICollection
			{
			public:
				virtual ~ILinkedList() override = default;

				ABSTRACT_CONST(IEnumerator<T>* GetEnumerator);
				ABSTRACT_CONST(IEnumerator<T>* GetReversedEnumerator);

				ABSTRACT_CONST(IEnumerator<ILinkedListNode<T>*> GetNodeEnumerator);
				ABSTRACT_CONST(IEnumerator<ILinkedListNode<T>*> GetReversedNodeEnumerator);



				ABSTRACT_ARG_CONST(ILinkedListNode<T>* AddBefore, ILinkedListNode<T>* const node, const T value);
				ABSTRACT_ARG_CONST(ILinkedListNode<T>* AddAfter, ILinkedListNode<T>* const node, const T value);

				ABSTRACT_ARG_CONST(ILinkedListNode<T>* AddFirst,const T value);
				ABSTRACT_ARG_CONST(ILinkedListNode<T>* AddLast,const T value);



				ABSTRACT_ARG_CONST(void Remove,ILinkedListNode<T>* node);
				ABSTRACT_ARG_CONST(ILinkedListNode<T>* Remove,T item);

				ABSTRACT_CONST(void RemoveFirst);
				ABSTRACT_CONST(void RemoveLast);



				ABSTRACT_ARG_CONST(bool Contains,const T item);

				ABSTRACT_ARG_CONST(void CopyTo,const T* _array, const int arrayIndex, const int arrayLength);
			};

			TEMPLATE
				INTERFACE_CLASS(ILinkedList2) :
				BASE_TEMPLATE(ILinkedList)
			{
				virtual ~ILinkedList2() override = default;

				ABSTRACT_ARG_CONST(bool MoveBefore, ILinkedListNode<T> node, ILinkedListNode<T>*before);
				ABSTRACT_ARG_CONST(bool MoveAfter, ILinkedListNode<T>*node, ILinkedListNode<T>*after);

				ABSTRACT_ARG_CONST(void Swap, ILinkedListNode<T> x, ILinkedListNode<T> y);
			};
		}
	}
}
#endif // WINCOPIES_COLLECTIONS_ILINKEDLIST_H
#pragma once

#ifndef WINCOPIES_COLLECTIONS_IREADONLY_LINKEDLIST_H
#define WINCOPIES_COLLECTIONS_IREADONLY_LINKEDLIST_H

#include "../Enumeration/IEnumerable.h"
#include "ILinkedListNode.h"
#include "../ICollection.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				class IReadOnlyLinkedListNode;

			TEMPLATE
				INTERFACE_CLASS(IReadOnlyLinkedList) :
				BASE_TEMPLATE(IUIntCountableEnumerable),
				BASE_INTERFACE IReadOnlyCollection
			{
			public:
				virtual ~IReadOnlyLinkedList() override = default;

				ABSTRACT_CONST(IReadOnlyLinkedListNode<T>* GetFirst);
				ABSTRACT_CONST(IReadOnlyLinkedListNode<T>* GetLast);

				ABSTRACT_CONST(bool GetIsReadOnly);

				ABSTRACT_CONST(bool GetSupportsReversedEnumeration);

				ABSTRACT_CONST(UINT GetCount);

				ABSTRACT_ARG_CONST(IReadOnlyLinkedListNode<T>* Find,const T value) = 0;
				ABSTRACT_ARG_CONST(IReadOnlyLinkedListNode<T>* FindLast,const T value) = 0;

				ABSTRACT_CONST(T GetFirstValue);
				ABSTRACT_CONST(T GetLastValue);
			};
		}
	}
}
#endif // WINCOPIES_COLLECTIONS_IREADONLY_LINKEDLIST_H
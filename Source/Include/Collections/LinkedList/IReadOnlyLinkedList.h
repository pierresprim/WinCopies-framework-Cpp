#pragma once
#ifndef IREADONLYLINKEDLIST_H
#define IREADONLYLINKEDLIST_H

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
					BASE_INTERFACE IUIntCountableEnumerable<T>,
					BASE_INTERFACE IReadOnlyCollection
			{
			public:
				virtual ~IReadOnlyLinkedList() override = default;

				virtual IReadOnlyLinkedListNode<T>* GetFirst() = 0;

				virtual IReadOnlyLinkedListNode<T>* GetLast() = 0;

				virtual bool GetIsReadOnly() = 0;

				virtual bool GetSupportsReversedEnumeration() = 0;

				virtual UINT GetCount() = 0;

				virtual IReadOnlyLinkedListNode<T>* Find(const T value) = 0;

				virtual IReadOnlyLinkedListNode<T>* FindLast(const T value) = 0;

				virtual T GetFirstValue() = 0;

				virtual T GetLastValue() = 0;
			};
		}
	}
}

#endif

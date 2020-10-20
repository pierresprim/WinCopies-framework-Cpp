#pragma once
#ifndef ISIMPLELINKEDLIST_H
#define ISIMPLELINKEDLIST_H

#include "defines.h"
#include "IUIntCountable.h"
#include "IEnumerable.h"
#include "ISimpleLinkedListNode.h"
#include "../WinCopies.Util.Base.Shared/OutPointer.h"

namespace WinCopies
{
	namespace Collections
	{
		enum class DLLEXPORT LinkedListDirection
		{
			FIFO = 1,

			LIFO = 2
		};

		TEMPLATE
			class DLLEXPORT ISimpleLinkedList ABSTRACT : public virtual IUIntCountable
		{
		public:
			virtual ~ISimpleLinkedList() override = default;

			// Gets the enumeration direction of the current linked list.
			virtual LinkedListDirection GetDirection() const = 0;
			virtual bool GetIsReadOnly() const = 0;
			virtual void Clear() = 0;
			virtual T Peek() const = 0;
			virtual bool TryPeek(OUTPOINTER result) const = 0;
		};

		TEMPLATE
			class DLLEXPORT ISimpleEnumerableLinkedList ABSTRACT : public virtual IUIntCountableEnumerable<T>
		{
		public:
			virtual bool GetSupportsReversedEnumeration() const final
			{
				return false;
			}

			virtual IEnumerator<T>* GetReversedEnumerator() final
			{
				throw new InvalidOperationException(L"This collection does not support reversed enumeration.");
			}

			virtual ~ISimpleEnumerableLinkedList()
			{
				// Left empty.
			}
		};
	}
}

#endif

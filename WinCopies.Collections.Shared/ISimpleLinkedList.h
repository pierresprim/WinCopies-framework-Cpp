#pragma once
#ifndef ISIMPLELINKEDLIST_H
#define ISIMPLELINKEDLIST_H
#include "defines.h"
#include "IUIntCountable.h"
#include "IEnumerable.h"
#include "ISimpleLinkedListNode.h"

namespace WinCopies
{
	namespace Collections
	{
		enum class DLLEXPORT LinkedListDirection
		{
			FIFO = 1,

			LIFO = 2
		};

		_T
		class DLLEXPORT ISimpleLinkedList abstract : public virtual IUIntCountable
		{
		public:
			~ISimpleLinkedList() {}
			// Gets the enumeration direction of the current linked list.
			virtual LinkedListDirection GetDirection() const = 0;
			virtual bool GetIsReadOnly() const = 0;
			virtual void Clear() = 0;
			virtual T Peek() const = 0;
			virtual bool TryPeek( T*  result) const = 0;
		};
	}
}

#endif

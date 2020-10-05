#pragma once
#ifndef ISTACK_H
#define ISTACK_H
#include "defines.h"
#include "ISimpleLinkedListNode.h"
#include "SimpleLinkedList.h"

namespace WinCopies
{
	namespace Collections
	{
		_T
			class DLLEXPORT IStack abstract : public virtual ISimpleLinkedList<T>
		{
		public:
			~IStack() {}

			virtual LinkedListDirection GetDirection() const final
			{
				return LinkedListDirection::LIFO;
			}

			virtual void Push(const T value) = 0;
			virtual bool TryPush(const T value) = 0;
			virtual T Pop() = 0;
			virtual bool TryPop(T* result) = 0;
		};
	}
}

#endif

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
        TEMPLATE
            class DLLEXPORT IStack ABSTRACT : public virtual ISimpleLinkedList<T>
		{
		public:
            virtual ~IStack() override = default;

			virtual LinkedListDirection GetDirection() const final
			{
				return LinkedListDirection::LIFO;
			}

			virtual void Push(const T value) = 0;
			virtual bool TryPush(const T value) = 0;
			virtual T Pop() = 0;
			virtual bool TryPop( T*  result) = 0;
		};
	}
}

#endif

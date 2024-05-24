#pragma once

#ifndef WINCOPIES_COLLECTIONS_ISTACK_H
#define WINCOPIES_COLLECTIONS_ISTACK_H

#include "../Util.h"
#include "ISimpleLinkedList.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				INTERFACE_CLASS(IStack) :
				BASE_INTERFACE WinCopies::Collections::ISimpleLinkedListBase
			{
			public:
				ABSTRACT_ARG_METHOD(void Push, const T item);
				ABSTRACT_ARG_METHOD(bool TryPop, T* const result);
				ABSTRACT_ARG_METHOD(int Pop, T* const result);
			};
		}
	}
}
#endif // WINCOPIES_COLLECTIONS_ISTACK_H
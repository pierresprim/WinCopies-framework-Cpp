#pragma once

#ifndef WINCOPIES_IQUEUE_H
#define WINCOPIES_IQUEUE_H

#include "../Util.h"
#include "ISimpleLinkedList.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				INTERFACE_CLASS(IQueue) :
				BASE_INTERFACE WinCopies::Collections::ISimpleLinkedListBase
			{
			public:
				ABSTRACT_ARG_METHOD(void Enqueue, const T item);
				ABSTRACT_ARG_METHOD(bool TryDequeue, T* const result);
				ABSTRACT_ARG_METHOD(int Dequeue, T* const result);
			};
		}
	}
}
#endif
#pragma once
#ifndef IQUEUE_H
#define IQUEUE_H
#include "defines.h"
#include "ISimpleLinkedList.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				INTERFACE(IQueueBase) :
				BASE_INTERFACE WinCopies::Collections::ISimpleLinkedListBase
			{
			public:
				ABSTRACT_ARG_METHOD(void Enqueue, const T item);

				ABSTRACT_ARG_METHOD(bool TryDequeue, T* const result);

				ABSTRACT_ARG_METHOD(int Dequeue, T* const result);
			};

			TEMPLATE
				INTERFACE(IQueue) :
				BASE_INTERFACE IQueueBase<T>
			{

			};
		}
	}
}

#endif

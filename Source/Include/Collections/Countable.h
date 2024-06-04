#pragma once

#ifndef WINCOPIES_COLLECTIONS_COUNTABLE_H
#define WINCOPIES_COLLECTIONS_COUNTABLE_H

#include "ISortable.h"

#include "../Util/Includes/Framework.h"

namespace WinCopies
{
	namespace Collections
	{
		UNSIGNED_INTEGRAL_INTERFACE(ICountable)
		{
		public:
			virtual ~ICountable() = default;

			ABSTRACT_CONST(T GetCount);
		};

		COLLECTION_TEMPLATE_SPECIALIZATION(Countable);

		namespace Generic
		{
			TEMPLATE_NC(2, ENABLE_IF_UNSIGNED_INTEGRAL(T2) = true) INTERFACE_CLASS(IIndexableR)
			{
			public:
				virtual ~IIndexableR() = default;

				ABSTRACT_ARG_CONST(ErrorCode GetAt, const T2 index, T1* const result);
			};

			TEMPLATE_NC(2, ENABLE_IF_UNSIGNED_INTEGRAL(T2) = true) INTERFACE_CLASS(IIndexableW)
			{
			public:
				virtual ~IIndexableW() = default;

				ABSTRACT_ARG_CONST(ErrorCode SetAt, const T2 index, T1& const result);
			};

			TEMPLATE_NC(2) INTERFACE_CLASS(IIndexable) :
				BASE_INTERFACE IIndexableR<T1, T2>,
				BASE_INTERFACE IIndexableW<T1, T2>,
				BASE_INTERFACE ISortable<T1>
			{
			public:
				virtual ~IIndexable() = default;

				ABSTRACT_ARG_CONST(ErrorCode Swap,const T2 x, const T2 y);
			};

			LIST_TEMPLATE_SPECIALIZATION(Indexable);
		}
	}
}
#endif
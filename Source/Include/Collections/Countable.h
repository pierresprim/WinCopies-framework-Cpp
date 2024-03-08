#pragma once

#ifndef WINCOPIES_COLLECTIONS_COUNTABLE_H
#define WINCOPIES_COLLECTIONS_COUNTABLE_H

#include "ISortable.h"

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

		typedef ICountable<UINT> IUIntCountable;
		typedef ICountable<ULONGLONG> IULongCountable;

		namespace Generic
		{
			TEMPLATE2 INTERFACE_CLASS(IIndexableR)
			{
			public:
				virtual ~IIndexableR() = default;

				virtual ErrorCode GetAt(const T2 index, T1 * result) const = 0;
			};

			TEMPLATE using IUIntIndexableR = IIndexableR<T, UINT>;
			TEMPLATE using IULongIndexableR = IIndexableR<T, ULONGLONG>;

			TEMPLATE2 INTERFACE_CLASS(IIndexableW)
			{
			public:
				virtual ~IIndexableW() = default;

				virtual ErrorCode SetAt(const T2 index, T1 & result) = 0;
			};

			TEMPLATE using IUIntIndexableW = IIndexableW<T, UINT>;
			TEMPLATE using IULongIndexableW = IIndexableW<T, ULONGLONG>;

			TEMPLATE2 INTERFACE_CLASS(IIndexable) :
				BASE_INTERFACE IIndexableR<T1, T2>,
				BASE_INTERFACE IIndexableW<T1, T2>,
				BASE_INTERFACE ISortable<T1>
			{
			public:
				virtual ~IIndexable() = default;

				virtual ErrorCode Swap(const T2 x, const T2 y) = 0;
			};

			TEMPLATE using IUIntIndexable = IIndexable<T, UINT>;
			TEMPLATE using IULongIndexable = IIndexable<T, ULONGLONG>;
		}
	}
}

#endif

#pragma once
#ifndef ISORTABLE_H
#define ISORTABLE_H

#include "defines.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				INTERFACE(ISortable)
			{
			public:
				static int DefaultComparison(const T x, const T y)
				{
					return x == y ? 0 : x < y ? -1 : 1;
				}

				virtual void Sort(const COMPARISON(T)) = 0;

				virtual void Sort()
				{
					return Sort(DefaultComparison);
				}
			};
		}
	}
}
#endif

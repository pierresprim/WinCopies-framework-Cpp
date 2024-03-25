#pragma once
#ifndef WINCOPIES_COLLECTIONS_ISORTABLE_H
#define WINCOPIES_COLLECTIONS_ISORTABLE_H

#include "Util.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				INTERFACE_CLASS(ISortable)
			{
			public:
				virtual ErrorCode Sort(PredicateFunction2<T, T>&const selector) = 0;
			};
		}
	}
}
#endif

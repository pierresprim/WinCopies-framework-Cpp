#pragma once

#ifndef WINCOPIES_DELEGATES_H
#define WINCOPIES_DELEGATES_H

#include "UtilBase.h"

namespace WinCopies
{
	namespace Delegates
	{
		TEMPLATE DLLEXPORT T Self(T value)
		{
			return value;
		}
		TEMPLATE2 DLLEXPORT T2 Self(T1 value)
		{
			return value;
		}

		TEMPLATE DLLEXPORT inline void Increment(T& value)
		{
			++value;
		}
		TEMPLATE DLLEXPORT inline T& IncrementByRef(T& value)
		{
			return ++value;
		}
		TEMPLATE DLLEXPORT inline void Decrement(T& value)
		{
			--value;
		}
		TEMPLATE DLLEXPORT inline T& DecrementByRef(T& value)
		{
			return --value;
		}
	}
}

#endif
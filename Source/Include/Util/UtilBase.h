#pragma once

#ifndef WINCOPIES_UTIL_BASE_H
#define WINCOPIES_UTIL_BASE_H

#include "PP/Enum/Bitwise.hpp"
#include "Enums/ErrorCode.h"
#include "Enums/SystemErrorCode.h"
#include "PP/Enum/MakeEnum.hpp"

namespace WinCopies
{
	ENUM Bool : SBYTE
	{
		None = -1,
		False = 0,
		True = 1
	};

	_MAKE_ENUM(1, 1, 0, ByteSelector, BYTE, First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth)

	TEMPLATE INLINE_METHOD Swap(T* const x, T* const y)
	{
		T tmp = *x;
		*x = *y;
		*y = tmp;
	}

	MULTI_TEMPLATE DLLEXPORT STDSTRING Format(const std::wstring_view message, T&... formatItems)
	{
		return std::vformat(message, std::make_wformat_args(std::forward<T&>(formatItems)...));
	}

	TEMPLATE METHOD OneLeftShift(T* const val, const BYTE& n)
	{
		std::make_unsigned_t<T> tmp = ~static_cast<T>(0);
		tmp = ~(tmp << n);
		std::make_unsigned_t<T> tmp2 = *val;

		*val = tmp | (tmp2 << n);
	}
	TEMPLATE DLLEXPORT T OneLeftShift(const T& val, const BYTE& n)
	{
		T result = val;

		OneLeftShift(&result, n);

		return result;
	}
}

#endif

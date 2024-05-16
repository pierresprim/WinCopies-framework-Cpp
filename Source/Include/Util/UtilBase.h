#pragma once

#ifndef WINCOPIES_UTIL_BASE_H
#define WINCOPIES_UTIL_BASE_H

#include "PP/Enum/Bitwise.hpp"
#include "Enums/ErrorCode.h"
#include "Enums/SystemErrorCode.h"

namespace WinCopies
{
	ENUM Bool : SBYTE
	{
		None = -1,
		False = 0,
		True = 1
	};

	ENUM ByteSelector : BYTE
	{
		None = 0,
		First = 1,
		Second = First << 1,
		Third = Second << 1,
		Fourth = Third << 1,
		Fifth = Fourth << 1,
		Sixth = Fifth << 1,
		Seventh = Sixth << 1,
		Eighth = Seventh << 1
	};

	ENABLE_ENUM_BITWISE_OPERATORS(ByteSelector);

	TEMPLATE METHOD Swap(T* const x, T* const y)
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

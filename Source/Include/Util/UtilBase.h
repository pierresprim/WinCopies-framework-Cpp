#pragma once

#ifndef WINCOPIES_UTIL_BASE_H
#define WINCOPIES_UTIL_BASE_H

#include "../Kernel/Enum/Bitwise.hxx"
#include "../Kernel/Enum/MakeEnum.hxx"
#include "../Kernel/Macros/Method/Base.hxx"

#include "../Core/Typing/Consts.h"
#include "../Core/Enums/ErrorCode.h"
#include "../Core/Enums/SystemErrorCode.h"

namespace WinCopies
{
	ENUM Bool : SBYTE
	{
		None = -1,
		False = 0,
		True = 1
	};

	MAKE_NULLABLE_BITWISE_ENUM(ByteSelector, BYTE, First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth)

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

	INLINE_FUNCTION bool CheckSuccess(ErrorCode value);
	INLINE_FUNCTION bool CheckFail(ErrorCode value);
}
#endif

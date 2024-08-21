#pragma once

#ifndef WINCOPIES_UTIL_BASE_H
#define WINCOPIES_UTIL_BASE_H

#include "../Kernel/Macros/Method/Base.hxx"

#include "../Framework.h"

#include "Enums.h"

namespace WinCopies
{
	UNSIGNED_FUNC() INLINE_FUNCTION_RETURN(bool, ValidateIndex, index < count , T const index, T const count)
	UNSIGNED_FUNC() INLINE_FUNCTION_RETURN(ErrorCode, ValidateIndexE, ValidateIndex(index, count) ? ErrorCode::Success : ErrorCode::ArgumentOutOfRange, T const index, T const count)

	TEMPLATE INLINE_FUNCTION_RETURN(T, GetValue, *(ptr + index), T* const ptr, size_t const index)

	TEMPLATE INLINE_METHOD_ACTION(0, SetValue, *(ptr + index) = value, T* const ptr, size_t const index, T const value)

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

	INLINE_FUNCTION bool CheckSuccess(SystemErrorCode value);
	INLINE_FUNCTION bool CheckFail(SystemErrorCode value);
}
#endif

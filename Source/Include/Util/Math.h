#pragma once

#ifndef WINCOPIES_MATH_H
#define WINCOPIES_MATH_H

#include <math.h>
#include <bit>

#include "UtilBase.h"

using namespace std;

namespace WinCopies
{
	namespace
	{
		TEMPLATE_IF_UNSIGNED_INTEGRAL(class TValue)
			static double _Log(const TValue& value, const T& base)
		{
			switch (base)
			{
			case 2:
				return log2(value);
			case 10:
				return log10(value);
			}

			return log(value) / log(base);
		}
	}

	namespace Math
	{
		DLLEXPORT inline bool IsAdditionResultInRange(const auto x, const auto y, const auto maxValue);
		DLLEXPORT inline bool IsAdditionResultInRange(const auto value, const auto maxValue);
		TEMPLATE_IF_UNSIGNED_INTEGRAL()
			DLLEXPORT inline bool ValidateLogBase(const T base)
		{
			return base >= 2;
		}
		TEMPLATE_IF_UNSIGNED_INTEGRAL()
			DLLEXPORT ErrorCode Log(double* const value, const T base)
		{
			if (ValidateLogBase(base))
			{
				*value = _Log(*value, base);

				return ErrorCode::Success;
			}

			return ErrorCode::ArgumentOutOfRange;
		}
		TEMPLATE_IF_UNSIGNED_INTEGRAL(class TValue)
			DLLEXPORT ErrorCode Log(const TValue value, const T base, double* const result)
		{
			if (ValidateLogBase(base))
			{
				*result = _Log(value, base);

				return ErrorCode::Success;
			}

			*result = 0;

			return ErrorCode::ArgumentOutOfRange;
		}

		TEMPLATE_IF_UNSIGNED_INTEGRAL()
			DLLEXPORT void Log2(T* value) { *value = (sizeof(value) << 3) - countl_zero(value) - 1; }
		TEMPLATE_IF_UNSIGNED_INTEGRAL()
			DLLEXPORT T& Log2(T value)
		{
			Log2(&value);

			return value;
		}

		DLLEXPORT bool Between(const auto x, const auto value, const auto y, const ByteSelector b);
		DLLEXPORT bool Outside(const auto x, const auto value, const auto y, const ByteSelector b);

		DLLEXPORT inline bool IsEven(auto value);
		DLLEXPORT inline bool IsOdd(auto value);
	}
}
#endif
#pragma once

#ifndef WINCOPIES_TYPING_CONSTS_H
#define WINCOPIES_TYPING_CONSTS_H

#include "../../Kernel/Typing/Consts.hxx"

using namespace std;

namespace WinCopies
{
	namespace Typing
	{
		ENABLE_IF_BOOL_CONDITION IsSigned = is_signed_v<T>;
		ENABLE_IF_BOOL_CONDITION IsUnsigned = is_unsigned_v<T>;

		ENABLE_IF_BOOL_CONDITION IsIntegral = is_integral_v<T>;
		ENABLE_IF_BOOL_CONDITION IsSignedIntegral = IsIntegral<T> && IsSigned<T>;
		ENABLE_IF_BOOL_CONDITION IsUnsignedIntegral = IsIntegral<T> && IsUnsigned<T>;

		ENABLE_IF_BOOL_CONDITION IsFloat = is_floating_point_v<T>;
		ENABLE_IF_BOOL_CONDITION IsEnum = is_enum_v<T>;

		TEMPLATE struct IsBitwiseEnumType;

		/**
		 * Helper to simplify syntax for querying whether or not bitwise operations are
		 * enabled for a given enum.
		 *
		 * @tparam T The enum type on which the type trait is being queried.
		 */
		ENABLE_IF_BOOL_CONDITION IsBitwiseEnum = IsBitwiseEnumType<T>::value;
		ENABLE_IF_BOOL_CONDITION IsUnsignedEnum = IsEnum<T> && IsUnsigned<UNDERLYING_TYPE(T)>;

		_ENABLE_IF_BOOL_CONDITION(TBase, TDerived) IsBaseOf = is_base_of_v<TBase, TDerived>;
	}
}

#endif WINCOPIES_TYPING_CONSTS_H
#pragma once

#ifndef WINCOPIES_TYPING_CONSTS_H
#define WINCOPIES_TYPING_CONSTS_H

#include <type_traits>
#include "../Macros/Template.h"
#include "../Macros/Type/TypeBase.h"
#include "Defines/Consts.h"
#include "Enum.h"

using namespace std;

#define __ENABLE_IF_BOOL_CONDITION inline CONST_EXPR bool
#define _ENABLE_IF_BOOL_CONDITION(...) TEMPLATE_EC(__VA_ARGS__) __ENABLE_IF_BOOL_CONDITION
#define ENABLE_IF_BOOL_CONDITION TEMPLATE __ENABLE_IF_BOOL_CONDITION

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
#pragma once

#ifndef WINCOPIES_UTIL_TYPING_CONSTS_H
#define WINCOPIES_UTIL_TYPING_CONSTS_H

#include <type_traits>
#include "../Macros/Template.h"
#include "../Macros/Type/Type.h"
#include "Defines/Consts.h"

using namespace std;

namespace WinCopies
{
	namespace Typing
	{
		TEMPLATE inline CONST_EXPR bool IsSigned = is_signed_v<T>;
		TEMPLATE inline CONST_EXPR bool IsUnsigned = is_unsigned_v<T>;
		
		TEMPLATE inline CONST_EXPR bool IsIntegral = is_integral_v<T>;
		TEMPLATE inline CONST_EXPR bool IsSignedIntegral = IsIntegral<T>&& IsSigned<T>;
		TEMPLATE inline CONST_EXPR bool IsUnsignedIntegral = IsIntegral<T> && IsUnsigned<T>;

		TEMPLATE inline CONST_EXPR bool IsFloat = is_floating_point_v<T>;
		TEMPLATE inline CONST_EXPR bool IsEnum = is_enum_v<T>;
	}
}

#endif // WINCOPIES_UTIL_TYPING_CONSTS_H
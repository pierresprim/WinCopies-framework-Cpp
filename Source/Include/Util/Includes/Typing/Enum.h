#pragma once

#ifndef WINCOPIES_UTIL_TYPING_ENUM_H
#define WINCOPIES_UTIL_TYPING_ENUM_H

#include <utility>

#include "../Main.h"
#include "../Macros/Type/Type.h"
#include "Usings.h"

using namespace std;

namespace WinCopies
{
	namespace Typing
	{
#define ENUM_CAST(enumType, enumValue) static_cast<::WinCopies::Typing::UnderlyingType<enumType>>(enumValue)

#if HAS_CPP23
		USING_TEMPLATE_FUNCTION(ToUnderlyingType, std::to_underlying)
#else
		TEMPLATE inline CONST_EXPR ::WinCopies::Typing::UnderlyingType<T> ToUnderlyingType(T value) noexcept
		{
			return ENUM_CAST(T, value);
		}
#endif

#define TO_UNDERLYING_TYPE(value) ::WinCopies::Typing::ToUnderlyingType(value)
	}
}

#endif // WINCOPIES_UTIL_TYPING_ENUM_H
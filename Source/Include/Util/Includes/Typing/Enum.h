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

#ifdef WINDOWS_NOT_CXX23
		TEMPLATE inline CONST_EXPR ::WinCopies::Typing::UnderlyingType<T> ToUnderlyingType(T value) noexcept {
			return ENUM_CAST(value);
		}
#else
		USING_TEMPLATE_FUNCTION(ToUnderlyingType, std:: to_underlying)
#endif

#define TO_UNDERLYING_TYPE(value) ::WinCopies::Typing::ToUnderlyingType(value)
	}
}

#endif // WINCOPIES_UTIL_TYPING_ENUM_H
#pragma once

#ifndef WINCOPIES_TYPING_ENUM_HXX
#define WINCOPIES_TYPING_ENUM_HXX

#include <utility>

#include "../Main.h"
#include "../Macros/Type/Type.hxx"

#include "../../Core/Typing/Typing.h"

#define UNDERLYING_TYPE(enumType) ::WinCopies::Typing::UnderlyingType<enumType>
#define ENUM_CAST(enumType, enumValue) static_cast<UNDERLYING_TYPE(enumType)>(enumValue)

namespace WinCopies
{
	namespace Typing
	{
#if HAS_CPP23
		USING_TEMPLATE_FUNCTION(ToUnderlyingType, ::std::to_underlying)
#else
		TEMPLATE inline CONST_EXPR UNDERLYING_TYPE(T) ToUnderlyingType(T value) noexcept
		{
			return ENUM_CAST(T, value);
		}
#endif

#define TO_UNDERLYING_TYPE(value) ::WinCopies::Typing::ToUnderlyingType(value)
	}
}

#endif WINCOPIES_TYPING_ENUM_HXX
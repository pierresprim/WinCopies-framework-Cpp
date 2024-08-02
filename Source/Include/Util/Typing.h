#pragma once

#ifndef WINCOPIES_UTIL_TYPING_H
#define WINCOPIES_UTIL_TYPING_H

#include <memory>
#include <type_traits>

#include "Includes/Macros/Template.h"
#include "Includes/Typing/EnableIf.h"
#include "Includes/Macros/Method/Inline.h"

namespace WinCopies
{
	namespace Typing
	{
		TEMPLATE using FreeableUniquePtr = unique_ptr<T, void (*)(void*)>;
		TEMPLATE using UnderlyingType = underlying_type_t<T>;
		
#define WINCOPIES_TYPING_AS_FROM_TYPE(modifier) TEMPLATE_NC(2, ENABLE_IF_BASE_OF(T1, T2) = true) INLINE_METHOD_RETURN(0, T1##modifier, AsFromType, value, T2##modifier value)

		WINCOPIES_TYPING_AS_FROM_TYPE()
		WINCOPIES_TYPING_AS_FROM_TYPE(*)
		WINCOPIES_TYPING_AS_FROM_TYPE(&)
#undef WINCOPIES_TYPING_AS_FROM_TYPE
	}
}
#endif WINCOPIES_UTIL_TYPING_H
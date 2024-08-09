#pragma once

#ifndef WINCOPIES_UTIL_TYPING_H
#define WINCOPIES_UTIL_TYPING_H

#include <memory>
#include <type_traits>

#include "../Kernel/Macros/Template.hxx"
#include "../Kernel/Macros/Method/Inline.hxx"

#include "../Core/Typing/EnableIf.h"

#include "../Core/Typing/Typing.h"

#include "Delegate.h"

using namespace WinCopies::Delegate;

namespace WinCopies
{
	namespace Typing
	{
#define WINCOPIES_TYPING_AS_FROM_TYPE_HEADER(tOut) TEMPLATE_NC(2, IF_NOT(tOut, , class TOut COMMA) ENABLE_IF_BASE_OF(T1, T2) = true)
#define WINCOPIES_TYPING_AS_FROM_TYPE(modifier) WINCOPIES_TYPING_AS_FROM_TYPE_HEADER(0) INLINE_METHOD_RETURN(0, VIRTUALITY_NONE, T1##modifier, AsFromType, value, T2##modifier value)

		WINCOPIES_TYPING_AS_FROM_TYPE()
		WINCOPIES_TYPING_AS_FROM_TYPE(*)
		WINCOPIES_TYPING_AS_FROM_TYPE(&)
#undef WINCOPIES_TYPING_AS_FROM_TYPE
#undef WINCOPIES_TYPING_AS_FROM_TYPE_HEADER
	}
}
#endif WINCOPIES_UTIL_TYPING_H
#pragma once

#ifndef WINCOPIES_UTIL_TYPING_ENABLE_IF_H
#define WINCOPIES_UTIL_TYPING_ENABLE_IF_H

#include "Consts.h"
#include "Defines/EnableIf.h"

namespace WinCopies
{
	namespace Typing
	{
		template<bool T1, class T2 = void> using EnableIf = enable_if_t<T1, T2>;
		_TEMPLATE(bool) using EnableBoolIf = EnableIf<T, bool>;

		MAKE_ENABLE_IF(Signed)
			MAKE_ENABLE_IF(Unsigned)

			MAKE_ENABLE_IF(Integral)
			MAKE_ENABLE_IF(SignedIntegral)
			MAKE_ENABLE_IF(UnsignedIntegral)

			MAKE_ENABLE_IF(Float)
			MAKE_ENABLE_IF(Enum)
	}
}

#endif // WINCOPIES_UTIL_TYPING_ENABLE_IF_H
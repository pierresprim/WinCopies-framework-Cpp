#pragma once

#ifndef WINCOPIES_DELEGATES_H
#define WINCOPIES_DELEGATES_H

#include "UtilBase.h"
#include "Misc.h"

namespace WinCopies
{
	namespace Delegates
	{
		TEMPLATE_NC(2) DLLEXPORT INLINE_METHOD_RETURN(0, T2, Self, value, T1 value)
		TEMPLATE using Self = Self<T, T>;

#define __WINCOPIES_DELEGATES_INC_DEC(prefix, methodName, _operator) CONCATENATE(prefix, ACTION)(0, methodName, _operator, T& value) \
CONCATENATE(prefix, RETURN)(0, T&, methodName, _operator, T& value)
#define _WINCOPIES_DELEGATES_INC_DEC(prefix, _operator) __WINCOPIES_DELEGATES_INC_DEC(TEMPLATE DLLEXPORT inline INLINE_METHOD_, CONCATENATE(prefix, crement), SURROUND(_operator, _operator, value))

			_WINCOPIES_DELEGATES_INC_DEC(In, +)
			_WINCOPIES_DELEGATES_INC_DEC(De, -)
	}
}

#endif
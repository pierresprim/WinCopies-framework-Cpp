#pragma once

#ifndef WINCOPIES_DELEGATES_H
#define WINCOPIES_DELEGATES_H

#include "UtilBase.h"
#include "Typing.h"

namespace WinCopies
{
	namespace Delegates
	{
		TEMPLATE INLINE_FUNCTION_RETURN(T, Self, value, T value)

#define __WINCOPIES_DELEGATES_INC_DEC(prefix, methodName, _operator, modifier) CONCATENATE(prefix, ACTION)(methodName, _operator, T##modifier value)
#define _WINCOPIES_DELEGATES_INC_DEC(prefix, methodName, _operator) __WINCOPIES_DELEGATES_INC_DEC(prefix, methodName, _operator, *) \
	__WINCOPIES_DELEGATES_INC_DEC(prefix, methodName, _operator, &) \
	CONCATENATE(prefix, RETURN)(T, methodName, _operator, T value)
#define WINCOPIES_DELEGATES_INC_DEC(prefix, _operator) _WINCOPIES_DELEGATES_INC_DEC(TEMPLATE DLLEXPORT INLINE_FUNCTION_, CONCATENATE(prefix, crement), SURROUND(_operator, _operator, value))

			WINCOPIES_DELEGATES_INC_DEC(In, +)
			WINCOPIES_DELEGATES_INC_DEC(De, -)
#undef WINCOPIES_DELEGATES_INC_DEC
#undef _WINCOPIES_DELEGATES_INC_DEC
#undef __WINCOPIES_DELEGATES_INC_DEC
	}
}

#endif
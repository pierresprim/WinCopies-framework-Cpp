#pragma once

#ifndef WINCOPIES_DELEGATES_H
#define WINCOPIES_DELEGATES_H

#include "UtilBase.h"
#include "Typing.h"

namespace WinCopies
{
	namespace Delegates
	{
		TEMPLATE INLINE_METHOD_RETURN(0, T, Self, value, T value)

#define ___WINCOPIES_DELEGATES_INC_DEC(prefix, methodName, _operator, modifier) CONCATENATE(prefix, ACTION)(0, methodName, _operator, T##modifier value)
#define __WINCOPIES_DELEGATES_INC_DEC(prefix, methodName, _operator) ___WINCOPIES_DELEGATES_INC_DEC(prefix, methodName, _operator, *) \
___WINCOPIES_DELEGATES_INC_DEC(prefix, methodName, _operator, &) \
CONCATENATE(prefix, RETURN)(0, T, methodName, _operator, T value)
#define _WINCOPIES_DELEGATES_INC_DEC(prefix, _operator) __WINCOPIES_DELEGATES_INC_DEC(TEMPLATE DLLEXPORT INLINE_METHOD_, CONCATENATE(prefix, crement), SURROUND(_operator, _operator, value))

			_WINCOPIES_DELEGATES_INC_DEC(In, +)
			_WINCOPIES_DELEGATES_INC_DEC(De, -)
	}
}

#endif
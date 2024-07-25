#pragma once

#ifndef WINCOPIES_UTIL_TYPING_H
#define WINCOPIES_UTIL_TYPING_H

#include "Includes/Macros/Template.h"
#include "Includes/Typing/EnableIf.h"

namespace WinCopies
{
	namespace Typing
	{
		TEMPLATE_NC(2, ENABLE_IF_BASE_OF(T1, T2) = true) inline T1 AsFromType(T2 value)
		{
			return value;
		}
		TEMPLATE_NC(2, ENABLE_IF_BASE_OF(T1, T2) = true) inline T1* AsFromType(T2* value)
		{
			return value;
		}
	}
}
#endif WINCOPIES_UTIL_TYPING_H
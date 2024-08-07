#pragma once

#ifndef WINCOPIES_KERNEL_FRAMEWORK_H
#define WINCOPIES_KERNEL_FRAMEWORK_H

#include "../Libraries.h"

#include "../PP/MiscBase.hpp"

#include "Macros/Type/Type.hxx"
#include "Types/Defs.hxx"

namespace WinCopies
{
	ENUM Bool : SBYTE;
	ENUM ErrorCode : LONG;
	ENUM SystemErrorCode : ULONG;
}

#include "Types/Delegates/Delegates.hxx"
#include "Types/Delegates/Defines.hxx"
#include "Macros/Method/Method.h"
#include "Macros/Misc.hxx"

#endif WINCOPIES_KERNEL_FRAMEWORK_H
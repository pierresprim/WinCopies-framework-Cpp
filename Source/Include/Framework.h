#pragma once

#ifndef WINCOPIES_FRAMEWORK_H
#define WINCOPIES_FRAMEWORK_H

#include "Libraries.h"

#include "PP/MiscBase.hpp"

#include "Kernel/Macros/Type/Type.hxx"
#include "Kernel/Types/Defs.hxx"

namespace WinCopies
{
	ENUM Bool : SBYTE;
	ENUM ErrorCode : LONG;
	ENUM SystemErrorCode : ULONG;
}

#include "Kernel/Types/Delegates/Delegates.hxx"
#include "Kernel/Types/Delegates/Defines.hxx"
#include "Kernel/Macros/Method/Method.h"
#include "Kernel/Macros/Misc.hxx"

#endif WINCOPIES_FRAMEWORK_H
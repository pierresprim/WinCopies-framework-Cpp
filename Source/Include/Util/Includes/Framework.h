#pragma once

#ifndef WINCOPIES_UTIL_FRAMEWORK_H
#define WINCOPIES_UTIL_FRAMEWORK_H

#include "../PP/MiscBase.hpp"

#include "Libraries.h"
#include "Types/Usings.h"
#include "Macros/Type/Type.h"
#include "Types/Defs.h"

namespace WinCopies
{
	ENUM Bool : SBYTE;
	ENUM ErrorCode : LONG;
	ENUM SystemErrorCode : ULONG;
}

#include "Types/Delegates/Delegates.h"
#include "Types/Delegates/Defines.h"
#include "Macros/Method/Method.h"
#include "Macros/Misc.h"

#endif
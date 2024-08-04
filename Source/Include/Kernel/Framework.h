#pragma once

#ifndef WINCOPIES_FRAMEWORK_H
#define WINCOPIES_FRAMEWORK_H

#include "../PP/MiscBase.hpp"

#include "Libraries.h"
#include "Types/Usings.h"
#include "Macros/Type/Type.hxx"
#include "Types/Defs.h"

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

#endif WINCOPIES_FRAMEWORK_H
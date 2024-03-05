#pragma once

#ifndef WINCOPIES_UTIL_FRAMEWORK_H
#define WINCOPIES_UTIL_FRAMEWORK_H

#define SINGLE_ARG(...) __VA_ARGS__

#include "Libraries.h"
#include "Macros/Template.h"
#include "Types/Usings.h"
#include "Macros/TemplateIf.h"
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
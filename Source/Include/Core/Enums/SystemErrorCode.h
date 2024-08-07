#pragma once

#ifndef WINCOPIES_UTIL_SYSTEM_ERROR_CODE_H
#define WINCOPIES_UTIL_SYSTEM_ERROR_CODE_H

#include "../../Libraries.h"

#ifdef WINDOWS
#define ERROR_OUT_OF_MEMORY ERROR_OUTOFMEMORY
#endif

namespace WinCopies
{
	ENUM SystemErrorCode : ULONG
	{
		Success = 0,
		OutOfMemory = ERROR_OUT_OF_MEMORY,
		NoMoreFiles = ERROR_NO_MORE_FILES,
		BadArguments = ERROR_BAD_ARGUMENTS,
		BadPathName = ERROR_BAD_PATHNAME,
		NoMoreItems = ERROR_NO_MORE_ITEMS,
		Error = ERROR_UNIDENTIFIED_ERROR
	};
}

#endif
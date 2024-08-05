#pragma once

#ifndef WINCOPIES_UTIL_ENUM_FLAGS_H
#define WINCOPIES_UTIL_ENUM_FLAGS_H

#include "../../PP/Loop/Loop.hpp"

#include "../../Kernel/Enum/Flags.hxx"

#include "../Types/Defs.h"

namespace WinCopies
{
	namespace Enum
	{
		__MAKE_ENUM_FLAG(BYTE, None, 0)

		LOOP(0, 7, MAKE_ENUM_BYTE_FLAG)
		LOOP_TO(8, 15, MAKE_ENUM_USHORT_FLAG)
		LOOP_TO(16, 31, MAKE_ENUM_UINT_FLAG)
	}
}

#endif WINCOPIES_UTIL_ENUM_FLAGS_H
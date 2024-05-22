#pragma once

#ifndef WINCOPIES_UTIL_ENUM_FLAGS_HPP
#define WINCOPIES_UTIL_ENUM_FLAGS_HPP

#include "../MISC.hpp"
#include "../Loop/Loop.hpp"
#include "../../Includes/Types/DefsBase.h"

#define ENUM_FLAG_NONE 0
#define ENUM_FLAG(i) SURROUND(, ::WinCopies::Enum::Flag, i)

#define __MAKE_ENUM_FLAG(type, label, value) constexpr type Flag##label = value;
#define _MAKE_ENUM_FLAG(type, i) __MAKE_ENUM_FLAG(type, i, 1 << i)
#define MAKE_ENUM_BYTE_FLAG(i) _MAKE_ENUM_FLAG(BYTE, i)
#define MAKE_ENUM_USHORT_FLAG(i) _MAKE_ENUM_FLAG(USHORT, i)
#define MAKE_ENUM_UINT_FLAG(i) _MAKE_ENUM_FLAG(UINT, i)

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

#endif // WINCOPIES_UTIL_ENUM_FLAGS_HPP
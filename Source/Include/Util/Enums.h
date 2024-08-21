#pragma once

#ifndef WINCOPIES_ENUMS_H
#define WINCOPIES_ENUMS_H

#include "../Kernel/Enum/MakeEnum.hxx"

namespace WinCopies
{
	ENUM Bool : SBYTE
	{
		None = -1,
		False = 0,
		True = 1
	};

	MAKE_NULLABLE_BITWISE_ENUM(ByteSelector, BYTE, First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth)
}

#endif WINCOPIES_ENUMS_H
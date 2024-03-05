#include "pch.h"
#include "../../Include/Util/Util.h"

/*

bool CheckOverflow(in int totalLength, ref int length, int offset)
{
	if (offset < 0)
	{
		offset = -offset;

		bool result = CheckOverflow(totalLength, ref offset, length);

		length = offset;

		return result;
	}

	if (length.Between(2, totalLength - 1) && (length % totalLength) > (length = totalLength - offset))

		return true;

	length = 0;

	return false;
}*/

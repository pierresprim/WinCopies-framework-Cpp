#include "pch.h"
#include "../../Include/Util/Util.h"

using namespace WinCopies;

SystemErrorCode WinCopies::MemoryAlloc(size_t const length, void** const result)
{
	*result = malloc(sizeof(length));

	return result ? SystemErrorCode::Success : SystemErrorCode::OutOfMemory;
}

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

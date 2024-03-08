#include "pch.h"

#include "../../../../Include/Collections/Array/Array.Partial/Sort.h"

using namespace WinCopies::Collections;

bool& _ArraySort::ValidateSort(bool condition, size_t& const e)
{
	if (condition)

		e += 8;

	return condition;
}
bool _ArraySort::ValidateSort(const size_t i, const size_t blocks, size_t& const e)
{
	return ValidateSort(i < blocks, e);
}
bool _ArraySort::ValidateSort(size_t& const blocks, size_t& const e)
{
	return ValidateSort((blocks >>= 1) > 0, e);
}
bool _ArraySort::ValidateMerge(size_t& const i, const size_t blocks, size_t& const e, const size_t size)
{
	if (i < blocks)
	{
		++i;

		e += size << 1;

		return true;
	}

	return false;
}
bool _ArraySort::ValidateMerge(const size_t blocks, size_t& const size)
{
	if (blocks > 0)
	{
		size <<= 1;

		return true;
	}

	return false;
}
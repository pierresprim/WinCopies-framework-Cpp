#include "pch.h"
#include "../Include/Util/ThrowHelper.h"

namespace WinCopies
{
	const NullPtrValueException* ThrowHelper::GetNullPtrValueException(const wchar_t* const argumentName)
	{
		return new NullPtrValueException(argumentName);
	}

	void ThrowHelper::ThrowIfNullPtrValue(const void* value, const wchar_t* const argumentName)
	{
		if (value == nullptr)

			throw GetNullPtrValueException(argumentName);
	}
}

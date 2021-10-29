#pragma once
#ifndef WINCOPIES_UTIL_THROWHELPER_H
#define WINCOPIES_UTIL_THROWHELPER_H

#include "wincopies_defines.h"

namespace WinCopies
{
	class ThrowHelper
	{
	private:
		ThrowHelper();

	public:
		static const NullPtrValueException* GetNullPtrValueException(const wchar_t* const argumentName);

		static void ThrowIfNullPtrValue(const void* value, const wchar_t* const argumentName);
	};
}
#endif

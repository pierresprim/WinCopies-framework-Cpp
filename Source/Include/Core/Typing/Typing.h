#pragma once

#ifndef WINCOPIES_TYPING_TYPING_H
#define WINCOPIES_TYPING_TYPING_H

#include "../../Kernel/Typing/Typing.h"

using namespace ::std;

namespace WinCopies
{
	namespace Typing
	{
		TEMPLATE using FreeableUniquePtr = unique_ptr<T, void (*)(void*)>;
		TEMPLATE using UnderlyingType = underlying_type_t<T>;
	}
}

#endif WINCOPIES_TYPING_TYPING_H
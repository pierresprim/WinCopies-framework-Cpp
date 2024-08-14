#pragma once

#ifndef WINCOPIES_TYPING_TYPING_H
#define WINCOPIES_TYPING_TYPING_H

#include "../../Libraries.h"

#include "../../Kernel/Macros/Template.hxx"

using namespace std;

namespace WinCopies
{
	namespace Typing
	{
		TEMPLATE using FreeableUnique = unique_ptr<T, void (*)(void*)>;
		TEMPLATE using Shared = shared_ptr<T>;

		TEMPLATE using UnderlyingType = underlying_type_t<T>;
	}
}

#endif WINCOPIES_TYPING_TYPING_H
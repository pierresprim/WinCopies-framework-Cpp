#pragma once

#ifndef WINCOPIES_UTIL_TYPING_USINGS_H
#define WINCOPIES_UTIL_TYPING_USINGS_H

#include <type_traits>
#include "../Macros/Template.h"

using namespace std;

namespace WinCopies
{
	namespace Typing
	{
		TEMPLATE using UnderlyingType = underlying_type_t<T>;
	}
}

#endif // WINCOPIES_UTIL_TYPING_USINGS_H
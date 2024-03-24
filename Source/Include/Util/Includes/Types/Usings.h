#pragma once

#ifndef WINCOPIES_UTIL_USINGS_H
#define WINCOPIES_UTIL_USINGS_H

#include <memory>
#include "../Typing/Typing.h"

using namespace std;

namespace WinCopies
{
	TEMPLATE using FreeableUniquePtr = unique_ptr<T, void (*)(void*)>;
}

#endif
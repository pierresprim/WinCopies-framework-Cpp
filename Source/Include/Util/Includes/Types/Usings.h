#pragma once

#ifndef WINCOPIES_USINGS_H
#define WINCOPIES_USINGS_H

#include <memory>
#include "../Typing/Typing.h"

using namespace std;

namespace WinCopies
{
	TEMPLATE using FreeableUniquePtr = unique_ptr<T, void (*)(void*)>;
}

#endif WINCOPIES_USINGS_H
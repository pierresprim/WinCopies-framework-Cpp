#pragma once

#ifndef WINCOPIES_TYPING_TYPING_H
#define WINCOPIES_TYPING_TYPING_H

#include "../../Kernel/Typing/Typing.h"

#include "../Types/Delegate.h"

using namespace ::std;

TEMPLATE using FreeableUniquePtr = unique_ptr<T, void (*)(void*)>;
TEMPLATE using UnderlyingType = underlying_type_t<T>;
TEMPLATE using DualPredicate = PredicateFunction2<T, ErrorCode>;
TEMPLATE using SystemDualPredicate = PredicateFunction2<T, SystemErrorCode>;

#endif WINCOPIES_TYPING_TYPING_H
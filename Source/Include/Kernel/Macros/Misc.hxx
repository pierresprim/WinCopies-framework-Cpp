#pragma once

#ifndef WINCOPIES_MACROS_MISC_HXX
#define WINCOPIES_MACROS_MISC_HXX

#include "../../Environment.h"

#define OUTPOINTER OutPointer<T>*

#define __MALLOC(type, prefix, _operator, suffix) (type*)malloc(prefix sizeof(type) _operator suffix)
#define _MALLOC(type, factor, _operator) __MALLOC(type, factor =, _operator, factor)

#define MALLOC(type) __MALLOC(type, , , )
#define MALLOC_SHIFT(type, count) _MALLOC(type, count, <<)
#define MALLOC_MULT(type, count) _MALLOC(type, count, *)

#define FREEABLE_UNIQUE_PTR_BASE(var, type, ptr) var = ::std::make_unique<type>(ptr, free)
#define FREEABLE_UNIQUE_PTR(var, type) FREEABLE_UNIQUE_PTR_BASE(var, type, MALLOC(type))
#define FREEABLE_UNIQUE_VOID_PTR(var, size) FREEABLE_UNIQUE_PTR_BASE(var, void*, malloc(size))

#define HAS_ITEMS GetCount() != 0;

#define GET_OR_THROW_IF_NULL_PTR(value, valueName) value == nullptr ? throw new NullPtrValueException(valueName) : value

#endif WINCOPIES_MACROS_MISC_HXX
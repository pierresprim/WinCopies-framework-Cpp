#pragma once

#ifndef WINCOPIES_MACROS_MISC_HXX
#define WINCOPIES_MACROS_MISC_HXX

#include "../../Environment.h"

#include "../../Core/Typing/Typing.h"

#define OUTPOINTER OutPointer<T>*

#define __MALLOC(type, prefix, _operator, suffix) (type*)malloc(prefix sizeof(type) _operator suffix)
#define _MALLOC(type, factor, _operator) __MALLOC(type, factor =, _operator, factor)

#define MALLOC(type) __MALLOC(type, , , )
#define MALLOC_SHIFT(type, count) _MALLOC(type, count, <<)
#define MALLOC_MULT(type, count) _MALLOC(type, count, *)

#define FREEABLE_UNIQUE_PTR_BASE(var, type, ptr) var = ::std::make_unique<type>(ptr, free)
#define FREEABLE_UNIQUE_PTR(var, type) FREEABLE_UNIQUE_PTR_BASE(var, type, MALLOC(type))
#define FREEABLE_UNIQUE_VOID_PTR(var, size) FREEABLE_UNIQUE_PTR_BASE(var, void*, malloc(size))

#define MAKE_SHARED(type, ...) ::std::make_shared<EXPAND(type)>(__VA_ARGS__)

#define SHARED_PTR_TYPE(type) ::WinCopies::Typing::Shared<EXPAND(type)>

#define SHARED_PTR(type, name, ptr) SHARED_PTR_TYPE(type) name(ptr)
#define MAKE_SHARED_PTR(type, name, ...) SHARED_PTR(type, name, MAKE_SHARED(type, __VA_ARGS__))

#define HAS_ITEMS GetCount() != 0;

#define GET_OR_THROW_IF_NULL_PTR(value, valueName) value == nullptr ? throw new NullPtrValueException(valueName) : value

#endif WINCOPIES_MACROS_MISC_HXX
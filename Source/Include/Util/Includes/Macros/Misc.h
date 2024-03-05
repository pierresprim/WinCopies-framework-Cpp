#pragma once

#ifndef WINCOPIES_UTIL_MISC_H
#define WINCOPIES_UTIL_MISC_H

// Misc

#define OUTPOINTER OutPointer<T>*

#define _MALLOC(type, factor, _operator) (type*)malloc(factor = sizeof(type) _operator factor)
#define MALLOC(type) _MALLOC(type, )
#define MALLOC_SHIFT(type, count) _MALLOC(type, count, <<)
#define MALLOC_MULT(type, count) _MALLOC(type, count, *)

#define FREEABLE_UNIQUE_PTR_BASE(var, type, ptr) var = ::std::make_unique<type>(ptr, free)
#define FREEABLE_UNIQUE_PTR(var, type) FREEABLE_UNIQUE_PTR_BASE(var, type, MALLOC(type))
#define FREEABLE_UNIQUE_VOID_PTR(var, size) FREEABLE_UNIQUE_PTR_BASE(var, void*, malloc(size))

#define HAS_ITEMS GetCount() != 0;

#define GET_OR_THROW_IF_NULL_PTR(value, valueName) value == nullptr ? throw new NullPtrValueException(valueName) : value
#ifdef _WIN32
#define ERROR_OUT_OF_MEMORY ERROR_OUTOFMEMORY
#endif

#endif
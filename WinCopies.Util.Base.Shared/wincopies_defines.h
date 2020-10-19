#pragma once

#ifndef WINCOPIES_UTIL_BASE_DEFINES_H
#define WINCOPIES_UTIL_BASE_DEFINES_H

#ifdef QT
#define DLLEXPORT Q_DECL_EXPORT
#define ABSTRACT
#include "../WinCopies_Qt/WinCopies.Util.Base/WinCopies_Util_Base/main.h"
#else
#define DLLEXPORT __declspec(dllexport)
#define ABSTRACT abstract
#endif

#define TEMPLATE template<class T>
#define METHOD_TEMPLATE template <class F>

/// WinCopies Framework Error codes

constexpr auto UNKNOWN_EXCEPTION = -1;
constexpr auto ARGUMENT_EXCEPTION = -2;
constexpr auto ARGUMENT_OUT_OF_RANGE_EXCEPTION = -3;
constexpr auto INVALID_OPERATION_EXCEPTION = -4;
constexpr auto READ_ONLY_EXCEPTION = -5;
constexpr auto EMPTY_OBJECT_EXCEPTION = -6;
constexpr auto OBJECT_HAS_CHANGED_DURING_ENUMERATION_EXCEPTION = -7;
constexpr auto OBJECT_HAS_NO_VALUE_EXCEPTION = -8;
constexpr auto INVALID_CAST_EXCEPTION = -9;
constexpr auto NULLPTR_VALUE_EXCEPTION = -10;
#endif

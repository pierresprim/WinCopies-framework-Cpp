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

/// WinCopies Framework Error codes

constexpr auto ARGUMENT_EXCEPTION = -1;
constexpr auto ARGUMENT_OUT_OF_RANGE_EXCEPTION = -2;
constexpr auto INVALID_OPERATION_EXCEPTION = -3;
constexpr auto READ_ONLY_EXCEPTION = -4;
constexpr auto EMPTY_OBJECT_EXCEPTION = -5;
constexpr auto OBJECT_HAS_CHANGED_DURING_ENUMERATION = -6;
#endif

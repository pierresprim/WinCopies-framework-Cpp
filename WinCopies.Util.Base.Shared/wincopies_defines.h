#pragma once

#ifndef WINCOPIES_UTIL_BASE_DEFINES_H
#define WINCOPIES_UTIL_BASE_DEFINES_H

///
/// Defines
/// 

#ifdef QT
#define DLLEXPORT Q_DECL_EXPORT
#define ABSTRACT
#include "../WinCopies_Qt/WinCopies.Util.Base/WinCopies_Util_Base/main.h"
#else
#define DLLEXPORT __declspec(dllexport)
#define ABSTRACT abstract
#endif

// Templates

#define TEMPLATE template<class T>
#define TEMPLATE2 template<class T1, class T2>
#define TEMPLATE3 template<class T1, class T2, class T3>
#define METHOD_TEMPLATE template <class F>

// Named templates

#define NAMED_TEMPLATE2(t1, t2) template<class t1, class t2>
#define NAMED_TEMPLATE3(t1, t2, t3) template<class t1, class t2, class t3>

// Misc

#define PREDICATE bool(*Predicate)(T)
#define PREDICATE_PARAMETER bool(*predicate)(T)
#define PREDICATE_FIELD bool(*_predicate)(T);

#define SELECTOR U(*Selector)(T)
#define SELECTOR_PARAMETER U(*selector)(T)
#define SELECTOR_FIELD U(*_selector)(T);

#define OUTPOINTER OutPointer<T>*

///
/// Type defs
/// 

typedef unsigned short USHORT;
typedef unsigned int UINT;
typedef unsigned long ULONG;
typedef unsigned long long ULONGLONG;

typedef char* STRING;
typedef wchar_t* WSTRING;

///
/// WinCopies Framework Error codes
/// 

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

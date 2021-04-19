#pragma once

#ifndef WINCOPIES_UTIL_BASE_DEFINES_H
#define WINCOPIES_UTIL_BASE_DEFINES_H

///
/// Defines
/// 

#ifdef QT
#define DLLEXPORT Q_DECL_EXPORT
#define ABSTRACT
#include "../WinCopies_Qt/WinCopies.Util/WinCopies_Util/main.h"
#else
#define DLLEXPORT __declspec(dllexport)
#define ABSTRACT abstract
#endif

#define CLASS class DLLEXPORT
#define INTERFACE(interfaceName) class DLLEXPORT interfaceName ABSTRACT
#define BASE_INTERFACE public virtual

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

#define SELECTOR(t1, t2) t2(*Selector)(t1)
#define SELECTOR_PARAMETER(t1, t2) t2(*selector)(t1)
#define SELECTOR_FIELD(t1, t2) t2(*_selector)(t1);

#define OUTPOINTER OutPointer<T>*

#define _ABSTRACT_ARG_METHOD(typeAndName, arguments, constKeyword, virtualityType) virtual typeAndName(arguments) constKeyword virtualityType
#define ABSTRACT_ARG_METHOD(typeAndName, arguments) _ABSTRACT_ARG_METHOD(typeAndName, arguments, , = 0)
#define ABSTRACT_ARG_METHOD_CONST(typeAndName, arguments) _ABSTRACT_ARG_METHOD(typeAndName, arguments, const, = 0)
#define ABSTRACT_METHOD(typeAndName) ABSTRACT_ARG_METHOD(typeAndName, )
#define ABSTRACT_METHOD_CONST(typeAndName) ABSTRACT_ARG_METHOD_CONST(typeAndName, )

#define OVERRIDE_ARG_METHOD(typeAndName, arguments) _ABSTRACT_ARG_METHOD(typeAndName, arguments, , override)
#define OVERRIDE_ARG_METHOD_CONST(typeAndName, arguments) _ABSTRACT_ARG_METHOD(typeAndName, arguments, const, override)
#define OVERRIDE_METHOD(typeAndName) OVERRIDE_ARG_METHOD(typeAndName, )
#define OVERRIDE_METHOD_CONST(typeAndName) OVERRIDE_ARG_METHOD_CONST(typeAndName, )

#define FINAL_ARG_METHOD(typeAndName, arguments) _ABSTRACT_ARG_METHOD(typeAndName, arguments, , final)
#define FINAL_ARG_METHOD_CONST(typeAndName, arguments) _ABSTRACT_ARG_METHOD(typeAndName, arguments, const, final)
#define FINAL_METHOD(typeAndName) FINAL_ARG_METHOD(typeAndName, )
#define FINAL_METHOD_CONST(typeAndName) FINAL_ARG_METHOD_CONST(typeAndName, )

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
/// Macros
///

#define HAS_ITEMS GetCount() != 0;

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
constexpr auto OBJECT_IS_DISPOSED_EXCEPTION = -11;
#endif

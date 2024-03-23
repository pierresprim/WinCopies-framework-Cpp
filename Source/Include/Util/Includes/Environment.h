#pragma once

#ifndef WINCOPIES_UTIL_ENVIRONMENT_H
#define WINCOPIES_UTIL_ENVIRONMENT_H

#ifdef QT
#define HAS_QT 1
#else
#define HAS_QT 0
#endif

#ifdef _MSC_VER
#ifndef _WIN32
#define _WIN32
#endif
#endif

#ifdef _WIN32
#define HAS_WINDOWS 1
#define WINDOWS

#ifdef _WIN64
#define HAS_X64 1
#define X64
#else
#define HAS_X64 0
#endif
#else
#define HAS_WINDOWS 0
#endif

#ifdef __GNUG__
#define HAS_GPP 1

#ifndef __GNUC__
#define __GNUC__
#endif
#else
#define HAS_GPP 0
#endif

#ifdef __GNUC__
#define HAS_GCC 1
#else
#define HAS_GCC 0
#endif

#if HAS_QT
#define DLLEXPORT Q_DECL_EXPORT
#define ABSTRACT
#include "../WinCopies_Qt/WinCopies.Util/WinCopies_Util/main.h"
#elif HAS_WINDOWS
#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

#define ABSTRACT abstract

#define HAS_CPP23 _HAS_CXX23

#if HAS_CPP23
#define WINDOWS_CXX23
#define WINDOWS_CPP23

#define HAS_WINDOWS_CPP23 1
#define HAS_WINDOWS_CXX23 1
#else
#define WINDOWS_NOT_CPP23
#define WINDOWS_NOT_CXX23
#endif
#elif HAS_GCC
#define DLLEXPORT __attribute__((visibility("default")))
#define DLLIMPORT
#endif

#if !HAS_WINDOWS
#define HAS_WINDOWS_CPP23 0
#define HAS_WINDOWS_CXX23 0
#endif

#if __cplusplus >= 201402L
#ifndef HAS_CPP14
#define HAS_CPP14
#endif

#ifndef HAS_CXX14
#define HAS_CXX14
#endif

#if __cplusplus >= 201703L
#ifndef HAS_CPP17
#define HAS_CPP17
#endif

#ifndef HAS_CXX17
#define HAS_CXX17
#endif

#if __cplusplus >= 202002L
#ifndef HAS_CPP20
#define HAS_CPP20
#endif

#ifndef HAS_CXX20
#define HAS_CXX20
#endif
#endif // HAS_CPP20
#endif // HAS_CPP17
#endif // HAS_CPP14

#endif // WINCOPIES_UTIL_ENVIRONMENT_H
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
#elif HAS_GCC
#define DLLEXPORT __attribute__((visibility("default")))
#define DLLIMPORT
#endif

#endif // WINCOPIES_UTIL_ENVIRONMENT_H
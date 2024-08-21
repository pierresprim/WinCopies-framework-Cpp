#pragma once

#ifndef WINCOPIES_TYPE_DEFS_H
#define WINCOPIES_TYPE_DEFS_H

#include "../../Libraries.h"

#include "../../Kernel/Types/Defs.hxx"

typedef char SBYTE;

#ifdef WINDOWS
#include <Windows.h>
#else
TYPEDEF_U char BYTE;
TYPEDEF_L LONG;
TYPEDEF_U int UINT;
TYPEDEF_U short USHORT;
TYPEDEF_UL ULONG;
TYPEDEF_UL long ULONGLONG;
#endif

typedef char* STRING;
typedef wchar_t* WSTRING;
typedef std::wstring STDSTRING;
typedef std::string STDSTRINGA;

#endif WINCOPIES_TYPE_DEFS_H
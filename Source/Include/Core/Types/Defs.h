#pragma once

#ifndef WINCOPIES_TYPE_DEFS_H
#define WINCOPIES_TYPE_DEFS_H

#include "../../Kernel/Types/Defs.hxx"

typedef char SBYTE;
TYPEDEF_U short USHORT;
TYPEDEF_U int UINT;
TYPEDEF_UL ULONG;
TYPEDEF_UL long ULONGLONG;

#ifdef WINDOWS
#include <Windows.h>
#else
TYPEDEF_L LONG;
TYPEDEF_U char BYTE;
#endif

typedef char* STRING;
typedef wchar_t* WSTRING;
typedef std::wstring STDSTRING;
typedef std::string STDSTRINGA;

#endif WINCOPIES_TYPE_DEFS_H
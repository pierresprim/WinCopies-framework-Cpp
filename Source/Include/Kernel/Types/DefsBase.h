#pragma once

#ifndef WINCOPIES_TYPE_DEFS_BASE_H
#define WINCOPIES_TYPE_DEFS_BASE_H

#define _TYPEDEF(value) typedef value
#define TYPEDEF_U _TYPEDEF(unsigned)
#define _TYPEDEF_L(macro) macro long
#define TYPEDEF_UL _TYPEDEF_L(TYPEDEF_U)
#define TYPEDEF_L _TYPEDEF_L(typedef)

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

#endif WINCOPIES_TYPE_DEFS_BASE_H
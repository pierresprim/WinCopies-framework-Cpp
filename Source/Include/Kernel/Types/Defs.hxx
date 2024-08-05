#pragma once

#ifndef WINCOPIES_TYPE_DEFS_HXX
#define WINCOPIES_TYPE_DEFS_HXX

#define _TYPEDEF(value) typedef value
#define TYPEDEF_U _TYPEDEF(unsigned)
#define _TYPEDEF_L(macro) macro long
#define TYPEDEF_UL _TYPEDEF_L(TYPEDEF_U)
#define TYPEDEF_L _TYPEDEF_L(typedef)

#endif WINCOPIES_TYPE_DEFS_HXX
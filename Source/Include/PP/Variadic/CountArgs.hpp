#pragma once

#ifndef WINCOPIES_COUNT_ARGS_HPP
#define WINCOPIES_COUNT_ARGS_HPP

#include "../Conditional/If.hpp"
#include "../Math/INCREMENT.h"

#define __COUNT_ARGS(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, _99, _100, n, ...) n
#define _COUNT_ARGS(...) SINGLE_ARG(__COUNT_ARGS(__VA_ARGS__ 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))

#if HAS_VA_OPT < 1
#define _VA_OPT_CHECK(...) ,

#define _VA_OPT_BOOL(x, y, z) COMPL(_COUNT_ARGS(CALL_VA_MACRO(CONCATENATE, SURROUND(_VA_OPT_BOOL_001, x, y), z)))
#define _VA_OPT_BOOL_001 ,

#define VA_OPT_BOOL(...) _VA_OPT_BOOL(_COUNT_ARGS(_VA_OPT_CHECK __VA_ARGS__), \
          _COUNT_ARGS(__VA_ARGS__()), \
          _COUNT_ARGS(_VA_OPT_CHECK __VA_ARGS__()))
#define ____COUNT_ARGS(macro, n, a, ...) IF(n, macro(n), VA_OPT_BOOL(a))
#define ___COUNT_ARGS(macro, ...) ____COUNT_ARGS(macro, _COUNT_ARGS(__VA_ARGS__), __VA_ARGS__)
#define COUNT_ARGS(...) ___COUNT_ARGS(INCREMENT, __VA_ARGS__)
#else
#define VA_ARGS_FILLED(...) IS_ONE(__VA_OPT__(1))
#define VA_ARGS_EMPTY(...) COMPL(VA_ARGS_FILLED(__VA_ARGS__))

#define IF_VA_ARGS(ifTrue, ifFalse, ...) IF(VA_ARGS_FILLED(__VA_ARGS__), ifTrue, ifFalse)
#define IF_NO_VA_ARG(ifTrue, ifFalse, ...) IF(VA_ARGS_EMPTY(__VA_ARGS__), ifTrue, ifFalse)

#define ___COUNT_ARGS(...) IF_VA_ARGS(INCREMENT(__VA_ARGS__), 0, __VA_ARGS__)
#define COUNT_ARGS(...) ___COUNT_ARGS(__VA_OPT__(_COUNT_ARGS(__VA_ARGS__)))
#endif

#endif WINCOPIES_COUNT_ARGS_HPP
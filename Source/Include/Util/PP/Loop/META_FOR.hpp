#pragma once

#ifndef WINCOPIES_META_FOR_HPP
#define WINCOPIES_META_FOR_HPP

#include "../MISC.hpp"

#define ___FOR(concatenator, prefix, result, ...) concatenator(prefix, result, __VA_ARGS__)
#define __FOR(n, concatenator, prefix, macro, ...) ___FOR(concatenator, prefix, macro(n), __VA_ARGS__)
#define _FOR(n, concatenator, prefix, macro, ...) ___FOR(concatenator, prefix, macro(n), __VA_ARGS__),

#define FOR_1(n, concatenator, prefix, macro, ...) FOR##n(concatenator, prefix, macro, __VA_ARGS__)_FOR(INCREMENT(n), concatenator, prefix, macro, __VA_ARGS__)
#define _FOR_1(n1, n2, n3, concatenator, prefix, macro, ...) _FOR##n1(n2, concatenator, prefix, macro, __VA_ARGS__)_FOR(n3, concatenator, prefix, macro, __VA_ARGS__)

#define _FOR10_1(concatenator, prefix, macro, ...) _FOR10(1, concatenator, prefix, macro, __VA_ARGS__)
#define _FOR10_2(concatenator, prefix, macro, ...) _FOR10(1, concatenator, prefix, macro, __VA_ARGS__)_FOR10(11, concatenator, prefix, macro, __VA_ARGS__)

#define FOR10N(n1, n2, n3, concatenator, prefix, macro, ...) CONCATENATE(_FOR10_, n1)(concatenator, prefix, macro, __VA_ARGS__)_FOR##n2(n3, concatenator, prefix, macro, __VA_ARGS__)

#define FOR_10(n, concatenator, prefix, macro, ...) FOR10N(1, n, 11, concatenator, prefix, macro, __VA_ARGS__)
#define FOR_20(n, concatenator, prefix, macro, ...) FOR10N(2, n, 21, concatenator, prefix, macro, __VA_ARGS__)

#define _FFOR2_O INCREMENT PAR_O INCREMENT PAR_O
#define _FFOR2_C PAR_C PAR_C

#define _FFOR2(n) _FFOR2_O n _FFOR2_C
#define _FFOR4(n) _FFOR2(_FFOR2(n))
#define _FFOR6(n) _FFOR2(_FFOR4(n))
#define _FFOR8(n) _FFOR4(_FFOR4(n))

#define _FOR2(n, concatenator, prefix, macro, ...) _FOR(n, concatenator, prefix, macro, __VA_ARGS__)_FOR(INCREMENT(n), concatenator, prefix, macro, __VA_ARGS__)
#define _FOR3(n, concatenator, prefix, macro, ...) _FOR_1(2, n, _FFOR2(n), concatenator, prefix, macro, __VA_ARGS__)
#define _FOR4(n, concatenator, prefix, macro, ...) _FOR2(n, concatenator, prefix, macro, __VA_ARGS__)_FOR2(_FFOR2(n), concatenator, prefix, macro, __VA_ARGS__)
#define _FOR5(n, concatenator, prefix, macro, ...) _FOR_1(4, n, _FFOR4(n), concatenator, prefix, macro, __VA_ARGS__)
#define _FOR6(n, concatenator, prefix, macro, ...) _FOR4(n, concatenator, prefix, macro, __VA_ARGS__)_FOR2(_FFOR4(n), concatenator, prefix, macro, __VA_ARGS__)
#define _FOR7(n, concatenator, prefix, macro, ...) _FOR_1(6, n, _FFOR6(n), concatenator, prefix, macro, __VA_ARGS__)
#define _FOR8(n, concatenator, prefix, macro, ...) _FOR4(n, concatenator, prefix, macro, __VA_ARGS__)_FOR4(_FFOR4(n), concatenator, prefix, macro, __VA_ARGS__)
#define _FOR9(n, concatenator, prefix, macro, ...) _FOR_1(8, n, _FFOR8(n), concatenator, prefix, macro, __VA_ARGS__)
#define _FOR10(n, concatenator, prefix, macro, ...) _FOR8(n, concatenator, prefix, macro, __VA_ARGS__)_FOR2(_FFOR8(n), concatenator, prefix, macro, __VA_ARGS__)

#endif // WINCOPIES_META_FOR_HPP
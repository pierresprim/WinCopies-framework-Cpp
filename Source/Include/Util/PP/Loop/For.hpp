#pragma once

#ifndef WINCOPIES_FOR_HPP
#define WINCOPIES_FOR_HPP

#include "Include/FOR.hpp"
#include "../Conditional/If.hpp"

#define FOR0(concatenator, prefix, macro, ...)
#define FOR1(concatenator, prefix, macro, ...) _FOR(1, concatenator, prefix, macro, __VA_ARGS__)
#define FOR2(concatenator, prefix, macro, ...) _FOR2(1, concatenator, prefix, macro, __VA_ARGS__)
#define FOR3(concatenator, prefix, macro, ...) _FOR3(1, concatenator, prefix, macro, __VA_ARGS__)
#define FOR4(concatenator, prefix, macro, ...) _FOR4(1, concatenator, prefix, macro, __VA_ARGS__)
#define FOR5(concatenator, prefix, macro, ...) _FOR5(1, concatenator, prefix, macro, __VA_ARGS__)
#define FOR6(concatenator, prefix, macro, ...) _FOR6(1, concatenator, prefix, macro, __VA_ARGS__)
#define FOR7(concatenator, prefix, macro, ...) _FOR7(1, concatenator, prefix, macro, __VA_ARGS__)
#define FOR8(concatenator, prefix, macro, ...) _FOR8(1, concatenator, prefix, macro, __VA_ARGS__)
#define FOR9(concatenator, prefix, macro, ...) _FOR9(1, concatenator, prefix, macro, __VA_ARGS__)
#define FOR10(concatenator, prefix, macro, ...) _FOR10(1, concatenator, prefix, macro, __VA_ARGS__)

#define FOR11(concatenator, prefix, macro, ...) FOR_1(10, concatenator, prefix, macro, __VA_ARGS__)
#define FOR12(concatenator, prefix, macro, ...) FOR_10(2, concatenator, prefix, macro, __VA_ARGS__)
#define FOR13(concatenator, prefix, macro, ...) FOR_10(3, concatenator, prefix, macro, __VA_ARGS__)
#define FOR14(concatenator, prefix, macro, ...) FOR_10(4, concatenator, prefix, macro, __VA_ARGS__)
#define FOR15(concatenator, prefix, macro, ...) FOR_10(5, concatenator, prefix, macro, __VA_ARGS__)
#define FOR16(concatenator, prefix, macro, ...) FOR_10(6, concatenator, prefix, macro, __VA_ARGS__)
#define FOR17(concatenator, prefix, macro, ...) FOR_10(7, concatenator, prefix, macro, __VA_ARGS__)
#define FOR18(concatenator, prefix, macro, ...) FOR_10(8, concatenator, prefix, macro, __VA_ARGS__)
#define FOR19(concatenator, prefix, macro, ...) FOR_10(9, concatenator, prefix, macro, __VA_ARGS__)
#define FOR20(concatenator, prefix, macro, ...) FOR_1(19, concatenator, prefix, macro, __VA_ARGS__)

#define FOR21(concatenator, prefix, macro, ...) FOR20(concatenator, prefix, macro, __VA_ARGS__)_FOR(21, concatenator, prefix, macro, __VA_ARGS__)
#define FOR22(concatenator, prefix, macro, ...) FOR_20(2, concatenator, prefix, macro, __VA_ARGS__)
#define FOR23(concatenator, prefix, macro, ...) FOR_20(3, concatenator, prefix, macro, __VA_ARGS__)
#define FOR24(concatenator, prefix, macro, ...) FOR_20(4, concatenator, prefix, macro, __VA_ARGS__)
#define FOR25(concatenator, prefix, macro, ...) FOR_20(5, concatenator, prefix, macro, __VA_ARGS__)
#define FOR26(concatenator, prefix, macro, ...) FOR_20(6, concatenator, prefix, macro, __VA_ARGS__)
#define FOR27(concatenator, prefix, macro, ...) FOR_20(7, concatenator, prefix, macro, __VA_ARGS__)
#define FOR28(concatenator, prefix, macro, ...) FOR_20(8, concatenator, prefix, macro, __VA_ARGS__)
#define FOR29(concatenator, prefix, macro, ...) FOR_20(9, concatenator, prefix, macro, __VA_ARGS__)
#define FOR30(concatenator, prefix, macro, ...) FOR_1(29, concatenator, prefix, macro, __VA_ARGS__)

#define FOR31(concatenator, prefix, macro, ...) _FOR_1(value, 30)
#define FOR32(concatenator, prefix, macro, ...) FOR_30(value, 2)

#define FOR41(value) _FOR_1(value, 40)

#define FOR51(value) _FOR_1(value, 50)

#define FOR61(value) _FOR_1(value, 60)

#define FOR71(value) _FOR_1(value, 70)

#define FOR81(value) _FOR_1(value, 80)

#define FOR91(value) _FOR_1(value, 90)

#define FOR99(value) FOR_90(value, 9)
#define FOR100(value) FOR_90(value, 10)

#define FOR101(value) FOR100(value) value
#define FOR102(value) FOR_100(value, 2)

#define __FFOR(n, concatenator, prefix, macro, suffix) FOR##n(concatenator, prefix, macro, suffix)
#define _FFOR(n, concatenator, prefix, macro, suffix) __FFOR(n, concatenator, prefix, macro, suffix)

#define FOR(n, concatenator, prefix, macro, suffix) _FFOR(CONCATENATE(DECREMENT, n), concatenator, prefix, macro, suffix)IF_NOT(n, __FOR(n, concatenator, prefix, macro, )suffix)
#define FFOR(n, concatenator, prefix, macro) FOR(n, concatenator, prefix, macro, )
#define FOR_C(n, constant) FFOR(n, SURROUND, constant, DISCARD)
#define FOR_M(n, macro) FFOR(n, SURROUND, , macro)
#define FOR_I(n, concatenator, prefix, suffix) FOR(n, concatenator, prefix, SINGLE_ARG, suffix)
#define FFOR_I(n, constant) FOR_I(n, SURROUND, constant, )

#endif // WINCOPIES_FOR_HPP
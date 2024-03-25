#pragma once

#ifndef WINCOPIES_REPEAT_HPP
#define WINCOPIES_REPEAT_HPP

#include "../MISC.hpp"

#define _REPEAT1(n, macro, ...) macro (REPEAT##n(macro, __VA_ARGS__))

#define _REPEAT10(n, macro, ...) REPEAT##n(macro, REPEAT10(macro, __VA_ARGS__))

#define REPEAT1(macro, ...) macro(__VA_ARGS__)
#define REPEAT2(macro, ...) macro(macro(__VA_ARGS__))
#define REPEAT3(macro, ...) _REPEAT1(2, macro, __VA_ARGS__)
#define REPEAT4(macro, ...) REPEAT2(macro, REPEAT2(macro, __VA_ARGS__))
#define REPEAT5(macro, ...) _REPEAT1(4, macro, __VA_ARGS__)
#define REPEAT6(macro, ...) REPEAT2(macro, REPEAT4(macro, __VA_ARGS__))
#define REPEAT7(macro, ...) _REPEAT1(6, macro, __VA_ARGS__)
#define REPEAT8(macro, ...) REPEAT2(macro, REPEAT6(macro, __VA_ARGS__))
#define REPEAT9(macro, ...) _REPEAT1(8, macro, __VA_ARGS__)
#define REPEAT10(macro, ...) REPEAT2(macro, REPEAT8(macro, __VA_ARGS__))

#define REPEAT11(macro, ...) _REPEAT1(10, macro, __VA_ARGS__)
#define REPEAT12(macro, ...) _REPEAT10(2, macro, __VA_ARGS__)
#define REPEAT13(macro, ...) _REPEAT1(12, macro, __VA_ARGS__)
#define REPEAT14(macro, ...) _REPEAT10(4, macro, __VA_ARGS__)
#define REPEAT15(macro, ...) _REPEAT1(14, macro, __VA_ARGS__)
#define REPEAT16(macro, ...) _REPEAT10(6, macro, __VA_ARGS__)
#define REPEAT17(macro, ...) _REPEAT1(16, macro, __VA_ARGS__)
#define REPEAT18(macro, ...) _REPEAT10(8, macro, __VA_ARGS__)
#define REPEAT19(macro, ...) _REPEAT1(18, macro, __VA_ARGS__)
#define REPEAT20(macro, ...) _REPEAT10(10, macro, __VA_ARGS__)

#define REPEAT21(macro, ...) REPEAT20(macro, __VA_ARGS__)_REPEAT(21, macro, __VA_ARGS__)
#define REPEAT22(macro, ...) REPEAT_20(2, macro, __VA_ARGS__)
#define REPEAT23(macro, ...) REPEAT_20(3, macro, __VA_ARGS__)
#define REPEAT24(macro, ...) REPEAT_20(4, macro, __VA_ARGS__)
#define REPEAT25(macro, ...) REPEAT_20(5, macro, __VA_ARGS__)
#define REPEAT26(macro, ...) REPEAT_20(6, macro, __VA_ARGS__)
#define REPEAT27(macro, ...) REPEAT_20(7, macro, __VA_ARGS__)
#define REPEAT28(macro, ...) REPEAT_20(8, macro, __VA_ARGS__)
#define REPEAT29(macro, ...) REPEAT_20(9, macro, __VA_ARGS__)
#define REPEAT30(macro, ...) REPEAT_1(29, macro, __VA_ARGS__)

#define REPEAT31(macro, ...) _REPEAT_1(value, 30)
#define REPEAT32(macro, ...) REPEAT_30(value, 2)

#define REPEAT41(value) _REPEAT_1(value, 40)

#define REPEAT51(value) _REPEAT_1(value, 50)

#define REPEAT61(value) _REPEAT_1(value, 60)

#define REPEAT71(value) _REPEAT_1(value, 70)

#define REPEAT81(value) _REPEAT_1(value, 80)

#define REPEAT91(value) _REPEAT_1(value, 90)

#define REPEAT99(value) REPEAT_90(value, 9)
#define REPEAT100(value) REPEAT_90(value, 10)

#define REPEAT101(value) REPEAT100(value) value
#define REPEAT102(value) REPEAT_100(value, 2)

#define REPEAT(n, macro, ...) REPEAT##n(macro, __VA_ARGS__)

#endif // WINCOPIES_REPEAT_HPP
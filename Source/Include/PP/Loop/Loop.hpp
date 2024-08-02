#pragma once

#ifndef WINCOPIES_LOOP_HPP
#define WINCOPIES_LOOP_HPP

#include "../Conditional/Conditional.hpp"

#define _LOOP_IF(c, macro) IF(c, macro, DISCARD)
#define LOOP_IF(c, i) _LOOP_IF(c, LOOP##i)

#define LOOP1(c, macro) macro(1)
#define LOOP2(c, macro) _LOOP_IF(c, macro)(1) macro(2)
#define LOOP3(c, macro) LOOP_IF(c, 2)(DECREMENT(c), macro) macro(3)
#define LOOP4(c, macro) LOOP_IF(c, 3)(DECREMENT(c), macro) macro(4)
#define LOOP5(c, macro) LOOP_IF(c, 4)(DECREMENT(c), macro) macro(5)
#define LOOP6(c, macro) LOOP_IF(c, 5)(DECREMENT(c), macro) macro(6)
#define LOOP7(c, macro) LOOP_IF(c, 6)(DECREMENT(c), macro) macro(7)
#define LOOP8(c, macro) LOOP_IF(c, 7)(DECREMENT(c), macro) macro(8)
#define LOOP9(c, macro) LOOP_IF(c, 8)(DECREMENT(c), macro) macro(9)
#define LOOP10(c, macro) LOOP_IF(c, 9)(DECREMENT(c), macro) macro(10)
#define LOOP11(c, macro) LOOP_IF(c, 10)(DECREMENT(c), macro) macro(11)
#define LOOP12(c, macro) LOOP_IF(c, 11)(DECREMENT(c), macro) macro(12)
#define LOOP13(c, macro) LOOP_IF(c, 12)(DECREMENT(c), macro) macro(13)
#define LOOP14(c, macro) LOOP_IF(c, 13)(DECREMENT(c), macro) macro(14)
#define LOOP15(c, macro) LOOP_IF(c, 14)(DECREMENT(c), macro) macro(15)
#define LOOP16(c, macro) LOOP_IF(c, 15)(DECREMENT(c), macro) macro(16)
#define LOOP17(c, macro) LOOP_IF(c, 16)(DECREMENT(c), macro) macro(17)
#define LOOP18(c, macro) LOOP_IF(c, 17)(DECREMENT(c), macro) macro(18)
#define LOOP19(c, macro) LOOP_IF(c, 18)(DECREMENT(c), macro) macro(19)
#define LOOP20(c, macro) LOOP_IF(c, 19)(DECREMENT(c), macro) macro(20)
#define LOOP21(c, macro) LOOP_IF(c, 20)(DECREMENT(c), macro) macro(21)
#define LOOP22(c, macro) LOOP_IF(c, 21)(DECREMENT(c), macro) macro(22)
#define LOOP23(c, macro) LOOP_IF(c, 22)(DECREMENT(c), macro) macro(23)
#define LOOP24(c, macro) LOOP_IF(c, 23)(DECREMENT(c), macro) macro(24)
#define LOOP25(c, macro) LOOP_IF(c, 24)(DECREMENT(c), macro) macro(25)
#define LOOP26(c, macro) LOOP_IF(c, 25)(DECREMENT(c), macro) macro(26)
#define LOOP27(c, macro) LOOP_IF(c, 26)(DECREMENT(c), macro) macro(27)
#define LOOP28(c, macro) LOOP_IF(c, 27)(DECREMENT(c), macro) macro(28)
#define LOOP29(c, macro) LOOP_IF(c, 28)(DECREMENT(c), macro) macro(29)
#define LOOP30(c, macro) LOOP_IF(c, 29)(DECREMENT(c), macro) macro(30)
#define LOOP31(c, macro) LOOP_IF(c, 30)(DECREMENT(c), macro) macro(31)
#define LOOP32(c, macro) LOOP_IF(c, 31)(DECREMENT(c), macro) macro(32)
#define LOOP33(c, macro) LOOP_IF(c, 32)(DECREMENT(c), macro) macro(33)
#define LOOP34(c, macro) LOOP_IF(c, 33)(DECREMENT(c), macro) macro(34)
#define LOOP35(c, macro) LOOP_IF(c, 34)(DECREMENT(c), macro) macro(35)

#define __LOOP(length, n, macro) CONCATENATE(LOOP, n)(length, macro)
#define _LOOP(start, length, macro) __LOOP(DECREMENT(length), ADD(start, DECREMENT(length)), macro)
#define LOOP0(start, length, macro) macro(0) _LOOP(1, length, macro)
#define LOOP(start, length, macro) IF_ZERO(start, LOOP0, _LOOP)(start, length, macro)
#define LOOP_TO(start, end, macro) LOOP(start, SUB(end, DECREMENT(start)), macro)

#endif WINCOPIES_LOOP_HPP
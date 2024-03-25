#pragma once

#ifndef WINCOPIES_LOOP_HPP
#define WINCOPIES_LOOP_HPP

#include "../Conditional/Conditional.hpp"

#define LOOP1(c, macro) macro(1)
#define LOOP2(c, macro) IF(c, macro, DISCARD)(1) macro(2)
#define LOOP3(c, macro) IF(c, LOOP2, DISCARD)(DECREMENT(c), macro) macro(3)
#define LOOP4(c, macro) IF(c, LOOP3, DISCARD)(DECREMENT(c), macro) macro(4)
#define LOOP5(c, macro) IF(c, LOOP4, DISCARD)(DECREMENT(c), macro) macro(5)
#define LOOP6(c, macro) IF(c, LOOP5, DISCARD)(DECREMENT(c), macro) macro(6)
#define LOOP7(c, macro) IF(c, LOOP6, DISCARD)(DECREMENT(c), macro) macro(7)
#define LOOP8(c, macro) IF(c, LOOP7, DISCARD)(DECREMENT(c), macro) macro(8)
#define LOOP9(c, macro) IF(c, LOOP8, DISCARD)(DECREMENT(c), macro) macro(9)
#define LOOP10(c, macro) IF(c, LOOP9, DISCARD)(DECREMENT(c), macro) macro(10)
#define LOOP11(c, macro) IF(c, LOOP10, DISCARD)(DECREMENT(c), macro) macro(11)
#define LOOP12(c, macro) IF(c, LOOP11, DISCARD)(DECREMENT(c), macro) macro(12)
#define LOOP13(c, macro) IF(c, LOOP12, DISCARD)(DECREMENT(c), macro) macro(13)
#define LOOP14(c, macro) IF(c, LOOP13, DISCARD)(DECREMENT(c), macro) macro(14)
#define LOOP15(c, macro) IF(c, LOOP14, DISCARD)(DECREMENT(c), macro) macro(15)
#define LOOP16(c, macro) IF(c, LOOP15, DISCARD)(DECREMENT(c), macro) macro(16)
#define LOOP17(c, macro) IF(c, LOOP16, DISCARD)(DECREMENT(c), macro) macro(17)

#define _LOOP(length, n, macro) CONCATENATE(LOOP, n)(length, macro)
#define LOOP(start, length, macro) _LOOP(DECREMENT(length), ADD(start, DECREMENT(length)), macro)
#define LOOP_TO(start, end, macro) LOOP(start, SUB(end, DECREMENT(start)), macro)

#endif // WINCOPIES_LOOP_HPP
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

#define _LOOP(length, n, macro) CONCATENATE(LOOP, n)(length, macro)
#define LOOP(start, length, macro) _LOOP(DECREMENT(length), ADD(start, DECREMENT(length)), macro)

#endif // WINCOPIES_LOOP_HPP
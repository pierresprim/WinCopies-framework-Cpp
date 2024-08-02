#pragma once

#ifndef WINCOPIES_MATH_MUL_HPP
#define WINCOPIES_MATH_MUL_HPP

#include "MUL.inc.hpp"

#define MUL_PREDICATE(i, l, x, y) LESS(i, l)
#define MUL_ACTION(i, l, x, y) INCREMENT(i), l, MUL_ADD(x, y)

#define _MUL(x, y) FIRST_ARG(REPEAT(2, REMOVE_FIRST_ARG, WHILE(MUL_PREDICATE, MUL_ACTION, 1, y, x, x)))
#define MUL_SORTED(x, y) _MUL(y, x)
#define MUL_SORT(x, y) IF_LESS(y, x, _MUL, MUL_SORTED)(x, y)
#define MUL1_Y(x, y) EQUALS(y, 1, FIRST_ARG, MUL_SORT)(x,y)
#define MUL1_X(x, y) EQUALS(x, 1, SECOND_ARG, MUL1_Y)(x, y)

#define MUL(x, y) IF_B(AND(x,y), MUL1_X, MUL0)(x, y)

#endif WINCOPIES_MATH_MUL_HPP
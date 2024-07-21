#pragma once

#ifndef WINCOPIES_MATH_DIV_HPP
#define WINCOPIES_MATH_DIV_HPP

#include "MUL.inc.hpp"

#define DIV_PREDICATE(i, n, t, x, y) LESS(x, n)
#define DIV_ACTION(i, n, t, x, y) INCREMENT(i), n, t, MUL_ADD(x, y)

#define DIV_R0(x, y) 0, y
#define DIV_R(result, remainder) result, remainder
#define DIV_R_1_0(x, y) 1, 0
#define __DIV_R(i, n, t, x, y) DIV_R(i, SUB(t, x))
#define DIV_ADD(i, n, t, x, y) DIV_R(INCREMENT(i), 0)
#define _DIV_R(i, n, t, x, y) EQUALS(SUB(t, x), y, DIV_ADD, __DIV_R)(i, n, t, x, y)
#define __DIV(n, x, y) CALL_VA_MACRO(_DIV_R, WHILE(DIV_PREDICATE, DIV_ACTION, 1, n, x, y, y))
#define _DIV(n, x, y) IF(n, __DIV, DIV_R_1_0)(n, x, y)
#define DIV_SORTED(x, y) _DIV(SUB(x, y), x, y)
#define DIV_SORT(x, y) IF_LESS(x, y, DIV_R0, DIV_SORTED)(x, y)
#define DIV1_X(x, y) EQUALS(x, 1, DIV_R0, DIV_SORT)(x, y)
#define DIV1_Y(x, y) EQUALS(y, 1, FIRST_ARG, DIV1_X)(x, y)
#define DIV0_X(x, y) IF(x, DIV1_Y, MUL0)(x, y)

#define DIV(x, y) IF(y, DIV0_X, DISCARD)(x, y)

#define IDIV(x, y) FIRST_ARG(DIV(x,y))
#define MODULO(x, y) GET_SECOND_ARG(DIV(x,y))

#endif WINCOPIES_MATH_DIV_HPP
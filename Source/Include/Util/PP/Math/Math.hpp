#pragma once

#ifndef WINCOPIES_MATH_HPP
#define WINCOPIES_MATH_HPP

#include "../Conditional/Conditional.hpp"
#include "../Loop/While.hpp"
#include "../Util.hpp"

#define MUL_PREDICATE(i, l, x, y) LESS(i, l)
#define MUL_ACTION(i, l, x, y) INCREMENT(i), l, ADD(x, y), y

#define __MUL(x, y) FIRST_ARG(REPEAT(2, REMOVE_FIRST_ARG, WHILE(MUL_PREDICATE, MUL_ACTION, 1, y, x, x)))
#define _MUL(x, y) IF(EQUAL(y, 1), FIRST_ARG, __MUL)(x,y)

#define MUL(x, y) IF(EQUAL(x, 1), SECOND_ARG, _MUL)(x, y) //WHILE(0, ADD, x, x)

#endif // WINCOPIES_MATH_HPP
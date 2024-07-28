#pragma once

#ifndef WINCOPIES_IF_HPP
#define WINCOPIES_IF_HPP

#include "../MISC.hpp"
#include "Tables.h"

#define IF(value, ifTrue, ...) IF_B(BOOL(value), ifTrue, __VA_ARGS__)
#define IF_FALSE(value, ifFalse, ...) IF_B(NOT(value), ifFalse, __VA_ARGS__)
#define IF_TRUE(value, ...) IF_FALSE(value, , __VA_ARGS__)

#define IF_ZERO IF_FALSE
#define IF_ONE(value, ifTrue, ...) IF_B(IS_ONE(value), ifTrue, __VA_ARGS__)

#define IF_NOT(value, ...) IF(value, , __VA_ARGS__)

#define IF_VALUES(_operator, x, y) SURROUND(_operator, x, y)

#define AND_B(x, y) IF_VALUES(AND, x, y)
#define OR_B(x, y) IF_VALUES(OR, x, y)

#define AND(x, y) AND_B(BOOL(x), BOOL(y))
#define OR(x, y) OR_B(BOOL(x), BOOL(y))

#endif // WINCOPIES_IF_HPP
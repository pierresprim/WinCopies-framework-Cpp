#pragma once

#ifndef WINCOPIES_IF_HPP
#define WINCOPIES_IF_HPP

#include "../MISC.hpp"
#include "Tables.h"

#define IF(value, ifTrue, ...) IF_B(BOOL(value), ifTrue, __VA_ARGS__)
#define IF_FALSE(value, ...) IF(NOT(value), , __VA_ARGS__)

#define IF_ZERO(value, ifTrue, ...) IF(NOT(value), ifTrue, __VA_ARGS__)
#define IF_ONE(value, ifTrue, ...) IF(IS_ONE(value), ifTrue, __VA_ARGS__)

#define IF_NOT(value, ...) IF_B(NOT(value), , __VA_ARGS__)

#define IF_VALUES(_operator, x, y) SURROUND(_operator, x, y)

#define AND_B(x, y) IF_VALUES(AND, x, y)
#define OR_B(x, y) IF_VALUES(OR, x, y)

#define AND(x, y) AND_B(BOOL(x), BOOL(y))
#define OR(x, y) OR_B(BOOL(x), BOOL(y))

#endif // WINCOPIES_IF_HPP
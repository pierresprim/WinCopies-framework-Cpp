#pragma once

#ifndef WINCOPIES_IF_HPP
#define WINCOPIES_IF_HPP

#include "../MISC.hpp"
#include "Tables.h"

#define IF(value, ifTrue, ...) IF_B(PP_BOOL(value), ifTrue, __VA_ARGS__)
#define IF_NOT(value, ifFalse, ...) IF_B(NOT(value), ifFalse, __VA_ARGS__)

#define IF_TRUE(value, ...) IF_NOT(value, , __VA_ARGS__)
#define IF_FALSE(value, ...) IF(value, , __VA_ARGS__)

#define IF_ZERO IF_NOT
#define IF_ONE(value, ifTrue, ...) IF_B(IS_ONE(value), ifTrue, __VA_ARGS__)

#define CALL_IF_B(condition, macro) IF_B(condition, macro, DISCARD)
#define CALL_IF(condition, macro) CALL_IF_B(PP_BOOL(condition), macro)

#define CALL_WHEN_B(condition, macro, ...) CALL_IF_B(condition, macro)(__VA_ARGS__)
#define CALL_WHEN(condition, macro, ...) CALL_WHEN_B(PP_BOOL(condition), macro, __VA_ARGS__)

#define IF_VALUES(_operator, x, y) SURROUND(_operator, x, y)

#define AND_B(x, y) IF_VALUES(AND, x, y)
#define OR_B(x, y) IF_VALUES(OR, x, y)

#define AND(x, y) AND_B(PP_BOOL(x), PP_BOOL(y))
#define OR(x, y) OR_B(PP_BOOL(x), PP_BOOL(y))

#endif WINCOPIES_IF_HPP
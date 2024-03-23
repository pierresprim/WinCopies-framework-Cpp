#pragma once

#ifndef WINCOPIES_CONDITIONAL_HPP
#define WINCOPIES_CONDITIONAL_HPP

#include "../Math/Math.hpp"

#define IF_B(value, ifTrue, ...) CONCATENATE(IF, value)(ifTrue, __VA_ARGS__)
#define IF0(value, ...) __VA_ARGS__
#define IF1(value, ...) value
#define IF2(value, ...) value, __VA_ARGS__

#define GET_FIRST_ARG(...) IF1(__VA_ARGS__)
#define GET_SECOND_ARG(...) IF0(__VA_ARGS__)
#define GET_FIRST_AND_SECOND_ARG(...) IF2(__VA_ARGS__)

#define IF(value, ifTrue, ...) IF_B(BOOL(value), ifTrue, __VA_ARGS__)

#define LESS(x, y) IF(x, BOOL(SUB(y, x)), BOOL(y))

#define _EQUAL_OR_GREATER(x, y, macro) IF_B(LESS(x, y), 0, macro(LESS(y, x)))

#define EQUAL(x, y) _EQUAL_OR_GREATER(x, y, NOT)
#define GREATER(x, y) _EQUAL_OR_GREATER(x, y, SINGLE_ARG)

#define PRINT_OR_CALL(b, value) IF_B(b, value, DISCARD)()

#define SURROUND_IF_ELSE(condition, prefix, ifTrue, suffix, ...) IF(condition, SURROUND(prefix, ifTrue, suffix), __VA_ARGS__)
#define SURROUND_IF(condition, prefix, value, ...) SURROUND_IF_ELSE(condition, prefix, value, __VA_ARGS__, value)
#define SURROUND_ONLY_IF(condition, prefix, value, ...) SURROUND_IF_ELSE(condition, prefix, value, __VA_ARGS__, )

#endif // WINCOPIES_BOOL_HPP
#pragma once

#ifndef WINCOPIES_CONDITIONAL_HPP
#define WINCOPIES_CONDITIONAL_HPP

#include "../Math/MathBase.hpp"

#define LESS(x, y) IF(x, BOOL(SUB(y, x)), BOOL(y))

#define _EQUAL_OR_GREATER(x, y, macro) IF_B(LESS(x, y), 0, macro(LESS(y, x)))

#define EQUAL(x, y) _EQUAL_OR_GREATER(x, y, NOT)
#define GREATER(x, y) _EQUAL_OR_GREATER(x, y, SINGLE_ARG)

#define SURROUND_IF_ELSE(condition, prefix, ifTrue, suffix, ...) IF(condition, SURROUND(prefix, ifTrue, suffix), __VA_ARGS__)
#define SURROUND_IF(condition, prefix, value, ...) SURROUND_IF_ELSE(condition, prefix, value, __VA_ARGS__, value)
#define SURROUND_ONLY_IF(condition, prefix, value, ...) SURROUND_IF_ELSE(condition, prefix, value, __VA_ARGS__, )

#endif // WINCOPIES_CONDITIONAL_HPP
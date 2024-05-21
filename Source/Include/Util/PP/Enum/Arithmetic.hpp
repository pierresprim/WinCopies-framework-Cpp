#pragma once

#ifndef WINCOPIES_UTIL_ENUM_ARITHMETIC_HPP
#define WINCOPIES_UTIL_ENUM_ARITHMETIC_HPP

#include "Operators.hpp"

#define _ARITHMETIC_ENUM_UNARY_OPERATOR(operatorSymbol, dummyParameter, referenceOperator) CEA_OPERATOR_TEMPLATE operatorSymbol(T& val dummyParameter) \
	-> typename enable_if_t<IS_ENUM(T), T referenceOperator>

#define ARITHMETIC_ENUM_PREFIX_INCREMENTATION_OPERATOR(operatorSymbol) _ARITHMETIC_ENUM_UNARY_OPERATOR(operatorSymbol, , &) \
	{ auto tmp = ENUM_CAST(T, val); \
		return val = static_cast<T>(operatorSymbol tmp); }
#define ARITHMETIC_ENUM_SUFFIX_INCREMENTATION_OPERATOR(operatorSymbol) _ARITHMETIC_ENUM_UNARY_OPERATOR(operatorSymbol, SINGLE_ARG(, const int), ) \
	{ auto tmp = val; \
	operatorSymbol val; \
	return tmp; }
#define ARITHMETIC_ENUM_INCREMENTATION_OPERATORS(operatorSymbol) ARITHMETIC_ENUM_PREFIX_INCREMENTATION_OPERATOR(operatorSymbol) \
	ARITHMETIC_ENUM_SUFFIX_INCREMENTATION_OPERATOR(operatorSymbol)

BITWISE_ENUM_SHIFT_OPERATOR(+)
BITWISE_ENUM_SHIFT_OPERATOR2(+)

BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR(+, +=)
BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR2(+, +=)

ARITHMETIC_ENUM_INCREMENTATION_OPERATORS(++)

BITWISE_ENUM_SHIFT_OPERATOR(-)
BITWISE_ENUM_SHIFT_OPERATOR2(-)

BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR(-, -=)
BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR2(-, -=)

ARITHMETIC_ENUM_INCREMENTATION_OPERATORS(--)

BITWISE_ENUM_SHIFT_OPERATOR(*)
BITWISE_ENUM_SHIFT_OPERATOR2(*)

BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR(*, *=)
BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR2(*, *=)

BITWISE_ENUM_SHIFT_OPERATOR(/ )
BITWISE_ENUM_SHIFT_OPERATOR2(/ )

BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR(/ , /=)
BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR2(/ , /=)

BITWISE_ENUM_SHIFT_OPERATOR(%)
BITWISE_ENUM_SHIFT_OPERATOR2(%)

BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR(%, %=)
BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR2(%, %=)

#endif // WINCOPIES_UTIL_ENUM_ARITHMETIC_HPP
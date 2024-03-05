#pragma once

#ifndef WINCOPIES_UTIL_ENUM_OPERATORS_H
#define WINCOPIES_UTIL_ENUM_OPERATORS_H

#include "../Includes/Framework.h"

#define ENUM_OPERATOR(operatorSymbol, condition) OPERATOR_TEMPLATE operatorSymbol(const T& lhs, const T& rhs) \
	-> typename enable_if_t<condition, T> \
	{ return static_cast<T>( \
		ENUM_CAST(T, lhs) operatorSymbol \
		ENUM_CAST(T, rhs)); }

#define ENUM_COMPARISON_OPERATOR(operatorSymbol) OPERATOR_TEMPLATE operatorSymbol(const T& lhs, const T& rhs) \
	-> typename ENABLE_IF(is_enum_v) \
	{ return ENUM_CAST(T, lhs) operatorSymbol \
		ENUM_CAST(T, rhs); }

#define ENUM_COMPARISON_OPERATOR2(operatorSymbol) OPERATOR_TEMPLATE2 operatorSymbol(const T1& lhs, const T2& rhs) \
	-> typename EnableIf<IS_ENUM(T1)> \
	{ return ENUM_CAST(T1, lhs) operatorSymbol rhs; }

#define BITWISE_ENUM_SHIFT_OPERATOR(operatorSymbol) OPERATOR_TEMPLATE operatorSymbol(const T& lhs, const T& rhs) \
	-> typename enable_if_t<is_enum_v<T>, T> \
	{ return static_cast<T>( \
		ENUM_CAST(T, lhs) operatorSymbol \
		ENUM_CAST(T, rhs)); }

#define BITWISE_ENUM_SHIFT_OPERATOR2(operatorSymbol) OPERATOR_TEMPLATE2 operatorSymbol(const T1& lhs, const T2& rhs) \
	-> typename enable_if_t<is_enum_v<T1>, T1> \
	{ return static_cast<T1>( \
		ENUM_CAST(T1, lhs) operatorSymbol rhs); }

#define BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR(operatorSymbol, operatorAssignmentSymbol) OPERATOR_TEMPLATE operatorAssignmentSymbol(T& lhs, const T& rhs) \
	-> typename enable_if_t<is_enum_v<T>, T> \
	{ return lhs = lhs operatorSymbol rhs; }

#define BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR2(operatorSymbol, operatorAssignmentSymbol) OPERATOR_TEMPLATE2 operatorAssignmentSymbol(T1& lhs, const T2& rhs) \
	-> typename enable_if_t<is_enum_v<T1>, T1> \
	{ return lhs = lhs operatorSymbol rhs; }

ENUM_COMPARISON_OPERATOR(== )
ENUM_COMPARISON_OPERATOR2(== )

ENUM_COMPARISON_OPERATOR(!= )
ENUM_COMPARISON_OPERATOR2(!= )

#endif
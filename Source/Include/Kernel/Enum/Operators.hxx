#pragma once

#ifndef WINCOPIES_ENUM_OPERATORS_HXX
#define WINCOPIES_ENUM_OPERATORS_HXX

#include "../Framework.h"

#include "../Typing/EnableIf.hxx"

#define ENUM_OPERATOR(operatorSymbol, condition) CEA_OPERATOR_TEMPLATE operatorSymbol(const T& lhs, const T& rhs) \
	-> typename ENABLE_IF_VALUE(condition<T>, T) \
	{ return static_cast<T>( \
		ENUM_CAST(T, lhs) operatorSymbol \
		ENUM_CAST(T, rhs)); }

#define ENUM_COMPARISON_OPERATOR(operatorSymbol) CEA_OPERATOR_TEMPLATE operatorSymbol(const T& lhs, const T& rhs) \
	-> typename ENABLE_IF_ENUM(T) \
	{ return ENUM_CAST(T, lhs) operatorSymbol \
		ENUM_CAST(T, rhs); }

#define ENUM_COMPARISON_OPERATOR2(operatorSymbol) CEA_OPERATOR_TEMPLATE_NC(2) operatorSymbol(const T1& lhs, const T2& rhs) \
	-> typename ENABLE_IF_ENUM(T1) \
	{ return ENUM_CAST(T1, lhs) operatorSymbol rhs; }

#define BITWISE_ENUM_SHIFT_OPERATOR(operatorSymbol) CEA_OPERATOR_TEMPLATE operatorSymbol(const T& lhs, const T& rhs) \
	-> typename ENABLE_WHEN_ENUM(T) \
	{ return static_cast<T>( \
		ENUM_CAST(T, lhs) operatorSymbol \
		ENUM_CAST(T, rhs)); }

#define BITWISE_ENUM_SHIFT_OPERATOR2(operatorSymbol) CEA_OPERATOR_TEMPLATE_NC(2) operatorSymbol(const T1& lhs, const T2& rhs) \
	-> typename ENABLE_WHEN_ENUM(T1) \
	{ return static_cast<T1>( \
		ENUM_CAST(T1, lhs) operatorSymbol rhs); }

#define BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR(operatorSymbol, operatorAssignmentSymbol) CEA_OPERATOR_TEMPLATE operatorAssignmentSymbol(T& lhs, const T& rhs) \
	-> typename ENABLE_WHEN_ENUM(T) \
	{ return lhs = lhs operatorSymbol rhs; }

#define BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR2(operatorSymbol, operatorAssignmentSymbol) CEA_OPERATOR_TEMPLATE_NC(2) operatorAssignmentSymbol(T1& lhs, const T2& rhs) \
	-> typename ENABLE_WHEN_ENUM(T1) \
	{ return lhs = lhs operatorSymbol rhs; }

#endif WINCOPIES_ENUM_OPERATORS_HXX
#pragma once

#ifndef WINCOPIES_ENUM_BITWISE_H
#define WINCOPIES_ENUM_BITWISE_H

#include "../../Kernel/Enum/Bitwise.hxx"

#include "Operators.h"

 /**
  * Bitwise-or operator for enums that have bitwise operations enabled.
  *
  * @tparam T The enum type on which the bitwise-or operation is being
  *                performed.
  *
  * @param lhs The left-hand side of the operation.
  * @param rhs The right-hand side of the operation.
  *
  * @returns The result of the bitwise-or operation on the underlying enum type.
  */
BITWISE_ENUM_OPERATOR(| )

/**
 * Bitwise-or-equals operator for enums that have bitwise operations enabled.
 *
 * @tparam T The enum type on which the bitwise-or-equals operation is
 *                being performed.
 *
 * @param lhs The left-hand side of the operation.
 * @param rhs The right-hand side of the operation.
 */
BITWISE_ENUM_ASSIGNMENT_OPERATOR(| , |=)

/**
	* Bitwise-and operator for enums that have bitwise operations enabled.
	*
	* @tparam T The enum type on which the bitwise-and operation is being
	*                performed.
	*
	* @param lhs The left-hand side of the operation.
	* @param rhs The right-hand side of the operation.
	*
	* @returns The result of the bitwise-and operation on the underlying enum type.
	*/
BITWISE_ENUM_OPERATOR(&)

/**
	* Bitwise-and-equals operator for enums that have bitwise operations enabled.
	*
	* @tparam T The enum type on which the bitwise-and-equals operation is
	*                being performed.
	*
	* @param lhs The left-hand side of the operation.
	* @param rhs The right-hand side of the operation.
	*/
BITWISE_ENUM_ASSIGNMENT_OPERATOR(&, &=)

/**
	* Bitwise-xor operator for enums that have bitwise operations enabled.
	*
	* @tparam T The enum type on which the bitwise-xor operation is being
	*                performed.
	*
	* @param lhs The left-hand side of the operation.
	* @param rhs The right-hand side of the operation.
	*
	* @returns The result of the bitwise-xor operation on the underlying enum type.
	*/
BITWISE_ENUM_OPERATOR(^)

/**
	* Bitwise-xor-equals operator for enums that have bitwise operations enabled.
	*
	* @tparam T The enum type on which the bitwise-xor-equals operation is
	*                being performed.
	*
	* @param lhs The left-hand side of the operation.
	* @param rhs The right-hand side of the operation.
	*/
BITWISE_ENUM_ASSIGNMENT_OPERATOR(^, ^=)

/**
	* Bitwise-not operator for enums that have bitwise operations enabled.
	*
	* @tparam T The enum type on which the bitwise-not operation is being
	*                performed.
	*
	* @param val The value to negate.
	*
	* @returns The result of the bitwise-not operation on the underlying enum type.
	*/
BITWISE_ENUM_UNARY_OPERATOR(~)

/**
	* Logical-not operator for enums that have bitwise operations enabled. Returns
	* the result of comparing the underlying enum value with the underlying type's
	* representation of zero.
	*
	* @tparam T The enum type on which the logical-not operation is being
	*                performed.
	*
	* @param val The value on which to perform logical-not.
	*
	* @returns True if the enum value is zero, false otherwise.
	*/
BITWISE_ENUM_UNARY_OPERATOR(!)

BITWISE_ENUM_SHIFT_OPERATOR(<< )
BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR(<< , <<=)

BITWISE_ENUM_SHIFT_OPERATOR2(<< )
BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR2(<< , <<=)

BITWISE_ENUM_SHIFT_OPERATOR(>> )
BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR(>> , >>=)

BITWISE_ENUM_SHIFT_OPERATOR2(>> )
BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR2(>> , >>=)

#endif WINCOPIES_ENUM_BITWISE_H
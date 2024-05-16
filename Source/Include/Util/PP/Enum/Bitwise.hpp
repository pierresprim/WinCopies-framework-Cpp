/**
 * @brief Defines bitwise operators for specific enum classes.
 * @authors Aaron Jones, Pierre Sprimont
 * @copyright MIT License
 *
 * This can be used to allow an enum class to gain the following bitwise and
 * logical operations: |, |=, &, &=, ^, ^=, ~, !. This additional functionality
 * comes at a cost in that values that are not defined in the enum can more
 * easily be created.  Switch statements that cover every explicitly defined
 * value in the enum may miss values because of this.
 *
 * One oddity is that implicit conversion to bool is not enabled, so a statement
 * like "if (val)" does not work. In order to check if any bits are set in a
 * value the logical-not operator (!) must be applied twice, for example
 * "if (!!val)". To check if no bits are set the normal way works, e.g.
 * "if (!val)".
 *
 * Despite those shortcomings, many useful properties of enum classes are
 * retained. Enum values of one type cannot be mixed up with enum values of
 * another, or even with the underlying type of the enum. So "Foo::VALUE |
 * Bar::VALUE" and "Foo::VALUE | 3" will not compile without explicit casting.
 * The < operator and std::hash implementations are provided by enum classes,
 * so they can still be used in ordered and unordered collections. All
 * arithmetic and bit shifting operations are still denied since they typically
 * do not make sense in the context of bitwise flags.
 *
 * The operators are all constexpr, so the bitwise operations may be used at
 * compile-time.
 *
 * Example:
 * \code
 * #include <cassert>
 * #include <cstdint>
 * #include <set>
 * #include <unordered_set>
 * #include "Bitwise.h"
 *
 * enum class foo : uint8_t {
 *     FOO0 = 0b00,
 *     FOO1 = 0b01,
 *     FOO2 = 0b10
 * };
 * ENABLE_ENUM_BITWISE_OPERATORS(foo);
 *
 * enum class bar : uint8_t {
 *     BAR1 = 0b01,
 *     BAR2 = 0b10
 * };
 * ENABLE_ENUM_BITWISE_OPERATORS(bar);
 *
 * // FAILS TO COMPILE - ENABLE_ENUM_BITWISE_OPERATORS(int);
 *
 * int main(int, char**) {
 *     constexpr foo foo1 = foo::FOO1;
 *     constexpr foo foo2 = foo::FOO2;
 *     constexpr foo foo3 = foo::FOO1 | foo::FOO2;
 *     static_assert(foo3 & foo1, "Error.");
 *     static_assert((foo3 & ~foo2) == foo1, "Error.");
 *     static_assert(!!foo1, "Error.");
 *     static_assert(!foo::FOO0, "Error.");
 *     // FAILS TO COMPILE - constexpr foo foo4 = foo1 | 0b01;
 *     // FAILS TO COMPILE - constexpr foo foo5 = foo1 | bar::BAR1;
 *     // FAILS TO COMPILE - constexpr foo foo6 = foo::FOO1 + foo::FOO2;
 *
 *     std::set<foo> foo_set{foo::FOO1, foo::FOO2};
 *     assert(foo_set.count(foo::FOO1));
 *     std::unordered_set<foo> foo_unordered_set{foo::FOO1, foo::FOO2};
 *     assert(foo_unordered_set.count(foo::FOO1));
 * }
 * \endcode
 */

#pragma once

#ifndef WINCOPIES_UTIL_ENUM_BITWISE_HPP
#define WINCOPIES_UTIL_ENUM_BITWISE_HPP

#include "Operators.hpp"

#define BITWISE_ENUM_OPERATOR(operatorSymbol) ENUM_OPERATOR(operatorSymbol, ::WinCopies::Typing::IsBitwiseEnum)

#define BITWISE_ENUM_ASSIGNMENT_OPERATOR(operatorSymbol, operatorAssignmentSymbol) TEMPLATE constexpr auto operator operatorAssignmentSymbol(T& lhs, const T& rhs) \
    -> typename ENABLE_TYPE_IF_BITWISE_ENUM(T, void) \
    { lhs = lhs operatorSymbol rhs; }

#define BITWISE_ENUM_UNARY_OPERATOR(operatorSymbol) template<typename enum_t> constexpr auto operator operatorSymbol(const enum_t& val) \
	-> typename ENABLE_WHEN_BITWISE_ENUM(enum_t) \
	{ return static_cast<enum_t>( \
		operatorSymbol ENUM_CAST(enum_t, val)); }

#define BITWISE_ENUM_UNARY_ASSIGNMENT_OPERATOR(operatorSymbol, operatorAssignmentSymbol) template<typename enum_t> constexpr auto operator operatorAssignmentSymbol(const enum_t& val) \
    -> typename ENABLE_TYPE_IF_BITWISE_ENUM(enum_t, void) \
    { val = operatorSymbol val; }

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

#define _ENABLE_ENUM_BITWISE_OPERATORS(_namespace, T)                      \
    template <> struct WinCopies::Typing::IsBitwiseEnumType<_namespace::T> \
    {                                                                      \
        static_assert(IS_ENUM(_namespace::T), "T must be an enum.");       \
        static constexpr bool value = true;                                \
    };

/**
 * Helper macro to enable bitwise operations on a given enum type.
 *
 * @param T The enum type for which bitwise operations should be enabled.
 */
#define ENABLE_ENUM_BITWISE_OPERATORS(T, ...) _ENABLE_ENUM_BITWISE_OPERATORS(JOIN_ARGS(::, __VA_ARGS__), T)

#define __BITWISE_ENUM(open, namespaces, T, ...) IF(NOT(open), , namespaces) ENUM T; TRANSCRIBE_REPEATED_FOR_EACH(}, __VA_ARGS__) \
    ENABLE_ENUM_BITWISE_OPERATORS(T, __VA_ARGS__) \
    namespaces enum class T
#define _BITWISE_ENUM(open, T, ...) __BITWISE_ENUM(open, TRANSCRIBE_ARGS_WITH(namespace, {, __VA_ARGS__), T, __VA_ARGS__)
#define BITWISE_ENUM(T, ...) _BITWISE_ENUM(0, T, __VA_ARGS__)

BITWISE_ENUM_SHIFT_OPERATOR(<<)
BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR(<< , <<=)

BITWISE_ENUM_SHIFT_OPERATOR2(<<)
BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR2(<<, <<=)

BITWISE_ENUM_SHIFT_OPERATOR(>>)
BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR(>>, >>=)

BITWISE_ENUM_SHIFT_OPERATOR2(>>)
BITWISE_ENUM_SHIFT_ASSIGNMENT_OPERATOR2(>>, >>=)

#define FLAG_CHECK(enumValue, flag, bitwiseOperator) (enumValue & flag) bitwiseOperator 0

#define HAS_FLAG(enumValue, flag) FLAG_CHECK(enumValue, flag, !=)
#define HAS_NOT_FLAG(enumValue, flag) FLAG_CHECK(enumValue, flag, ==)

#define ADD_FLAG(enumValue, flag) enumValue | flag
#define SET_FLAG(enumValue, flag) enumValue |= flag

#define REMOVE_FLAG(enumValue, flag) enumValue & ~flag
#define UNSET_FLAG(enumValue, flag) enumValue &= ~flag

#define TOGGLE_FLAG(enumValue, flag) enumValue ^ flag
#define UPDATE_FLAG(enumValue, flag) enumValue ^= flag

#endif // WINCOPIES_UTIL_ENUM_BITWISE_HPP

#pragma once

#ifndef WINCOPIES_VARIADIC_HPP
#define WINCOPIES_VARIADIC_HPP

#include "../Conditional/Conditional.hpp"

#if HAS_VA_OPT < 1
#define VA_ARGS_FILLED(...) ___COUNT_ARGS(BOOL, __VA_ARGS__)
#define VA_ARGS_EMPTY(...) COMPL(VA_ARGS_FILLED(__VA_ARGS__))

#define IF_VA_ARGS(ifTrue, ifFalse, ...) IF(VA_ARGS_FILLED(__VA_ARGS__), ifTrue, ifFalse)
#define IF_NO_VA_ARG(ifTrue, ifFalse, ...) IF(VA_ARGS_EMPTY(__VA_ARGS__), ifTrue, ifFalse)
#endif

#define VA_PREPEND_OR_DEFAULT(ifFilled, ifEmpty, ...) IF(VA_ARGS_EMPTY(__VA_ARGS__), ifEmpty, ifFilled, __VA_ARGS__)
#define VA_APPEND_OR_DEFAULT(ifFilled, ifEmpty, ...) IF(VA_ARGS_EMPTY(__VA_ARGS__), ifEmpty, __VA_ARGS__, ifFilled)

#if HAS_VA_OPT < 1
#define VA_OPT(value, ...) IF(VA_ARGS_FILLED(__VA_ARGS__), value)

#define VA_ADD(value, macro, ...) IF(VA_ARGS_FILLED(__VA_ARGS__), macro(value, __VA_ARGS__))

#define VA_PREPEND(value, ...) VA_PREPEND_OR_DEFAULT(value, , __VA_ARGS__)
#define VA_APPEND(value, ...) VA_APPEND_OR_DEFAULT(value, , __VA_ARGS__)

#define VA_SURROUND(prefix, suffix, macro, ...) IF(VA_ARGS_FILLED(__VA_ARGS__), macro(prefix, suffix, __VA_ARGS__))
#else
#define VA_OPT(value, ...) __VA_OPT__(value)

#define VA_ADD(value, macro, ...) __VA_OPT__(macro(value, __VA_ARGS__))

#define VA_PREPEND(value, ...) __VA_OPT__(value, __VA_ARGS__)
#define VA_APPEND(value, ...) __VA_OPT__(__VA_ARGS__, value)

#define VA_SURROUND(prefix, suffix, macro, ...) __VA_OPT__(macro(prefix, suffix, __VA_ARGS__))
#endif

#define PREPEND_ARG(value, ...) VA_PREPEND_OR_DEFAULT(value, value, __VA_ARGS__)
#define APPEND_ARG(value, ...) VA_APPEND_OR_DEFAULT(value, value, __VA_ARGS__)

#define VA_ARGS_OR_IF_EMPTY(ifEmpty, ...) IF(VA_ARGS_EMPTY(__VA_ARGS__), ifEmpty, __VA_ARGS__)

#endif // WINCOPIES_VARIADIC_HPP
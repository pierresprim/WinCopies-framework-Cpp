#pragma once

#ifndef WINCOPIES_VARIADIC_HPP
#define WINCOPIES_VARIADIC_HPP

#include "../Conditional/Conditional.hpp"

#if HAS_VA_OPT < 1
#define VA_ARGS_FILLED(...) ___COUNT_ARGS(BOOL, __VA_ARGS__)
#define VA_ARGS_EMPTY(...) NOT(VA_ARGS_FILLED(__VA_ARGS__))

#define VA_OPT(value, ...) IF(VA_ARGS_FILLED(__VA_ARGS__), value)
#define VA_ADD(value, macro, ...) IF(VA_ARGS_FILLED(__VA_ARGS__), macro(value, __VA_ARGS__))
#define VA_PREPEND(value, ...) IF(VA_ARGS_EMPTY(__VA_ARGS__),, value, __VA_ARGS__)
#define VA_APPEND(value, ...) IF(VA_ARGS_EMPTY(__VA_ARGS__),, __VA_ARGS__, value)
#define VA_SURROUND(prefix, suffix, macro, ...) IF(VA_ARGS_FILLED(__VA_ARGS__), macro(prefix, suffix, __VA_ARGS__))
#else
#define VA_OPT(value, ...) __VA_OPT__(value)
#define VA_ADD(value, macro, ...) __VA_OPT__(macro(value, __VA_ARGS__))
#define VA_PREPEND(value, ...) __VA_OPT__(value, __VA_ARGS__)
#define VA_APPEND(value, ...) __VA_OPT__(__VA_ARGS__, value)
#define VA_SURROUND(prefix, suffix, macro, ...) __VA_OPT__(macro(prefix, suffix, __VA_ARGS__))
#endif

#endif // WINCOPIES_VARIADIC_HPP
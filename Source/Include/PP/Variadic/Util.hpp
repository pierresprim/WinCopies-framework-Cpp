#pragma once

#ifndef WINCOPIES_VA_UTIL_HPP
#define WINCOPIES_VA_UTIL_HPP

#include "../Conditional/Conditional.hpp"
#include "UtilBase.hpp"

#define GET_LAST_ARG_INDEX(...) SUB_OR_DISCARD_IF_ZERO(COUNT_ARGS(__VA_ARGS__))

#define GET_LAST_ARG(...) GET_ARG(GET_LAST_ARG_INDEX(__VA_ARGS__), __VA_ARGS__)

#define ____GET_ARG_INDEX_FROM_LAST(i, n) IF_LESS(i, n, 0)
#define ___GET_ARG_INDEX_FROM_LAST(i, j, k) IF(j, j, ____GET_ARG_INDEX_FROM_LAST(i, k))
#define __GET_ARG_INDEX_FROM_LAST(i, n) ___GET_ARG_INDEX_FROM_LAST(i, SUB(n, INCREMENT(i)), n)
#define _GET_ARG_INDEX_FROM_LAST(i, n) IF(n, __GET_ARG_INDEX_FROM_LAST, DISCARD)(i, n)
#define GET_ARG_INDEX_FROM_LAST(i, ...) _GET_ARG_INDEX_FROM_LAST(i, COUNT_ARGS(__VA_ARGS__))

#define GET_ARG_FROM_LAST(i, ...) GET_ARG(GET_ARG_INDEX_FROM_LAST(i, __VA_ARGS__), __VA_ARGS__)

#define GET_ARGS_FROM_LAST(start, length, ...) GET_ARGS(GET_ARG_INDEX_FROM_LAST(start, __VA_ARGS__), length, __VA_ARGS__)

#define GET_ARGS_RTL(start, length, ...) GET_ARGS(SUB(GET_ARG_INDEX_FROM_LAST(start, __VA_ARGS__), DECREMENT(length)), length, __VA_ARGS__)

#endif WINCOPIES_VA_UTIL_HPP
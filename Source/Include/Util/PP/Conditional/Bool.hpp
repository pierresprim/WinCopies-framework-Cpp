#pragma once

#ifndef WINCOPIES_BOOL_HPP
#define WINCOPIES_BOOL_HPP

#include "../MiscBase.hpp"

#define _CHECK(value, n, ...) n
#define CHECK(n, ...) SINGLE_ARG(_CHECK(__VA_ARGS__, n,))

#define CHECK_N(macro, value) CHECK(0, CONCATENATE(macro, value))

#define NOT(value) CHECK_N(NOT, value)
#define NOT0 , 1

#define COMPL(b) CONCATENATE(COMPL, b)
#define COMPL0 1
#define COMPL1 0

#define _BOOL(value) CHECK(1, CONCATENATE(_BOOL, value))
#define _BOOL0 , 0

#define _IS_ONE1 NOT0

#define IS_ZERO(value) NOT(value)
#define IS_ONE(value) CHECK_N(_IS_ONE, value)

#define BOOL(value) _BOOL(value)

#endif // WINCOPIES_BOOL_HPP
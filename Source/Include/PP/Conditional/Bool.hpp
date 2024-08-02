#pragma once

#ifndef WINCOPIES_BOOL_HPP
#define WINCOPIES_BOOL_HPP

#include "../MiscBase.hpp"

#define __CHECK(value, n, ...) n
#define _CHECK(n, ...) SINGLE_ARG(__CHECK(__VA_ARGS__, n,))

#define CHECK(macro, value) _CHECK(0, CONCATENATE(macro, value))

#define NOT(value) CHECK(NOT, value)
#define NOT0 , 1

#define COMPL(b) CONCATENATE(COMPL, b)
#define COMPL0 1
#define COMPL1 0

#define CHECK_BOOL(value) _CHECK(1, CONCATENATE(_BOOL, value))
#define _BOOL0 , 0
#define _BOOL _BOOL0

#define IS_ONE1 NOT0

#define IS_ZERO(value) NOT(value)
#define IS_ONE(value) CHECK(IS_ONE, value)

#define PP_BOOL(value) CHECK_BOOL(value)

#endif // WINCOPIES_BOOL_HPP
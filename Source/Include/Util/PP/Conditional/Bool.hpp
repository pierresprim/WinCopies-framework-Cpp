#pragma once

#ifndef WINCOPIES_BOOL_HPP
#define WINCOPIES_BOOL_HPP

#include "../MiscBase.hpp"

#define _CHECK(value, n, ...) n
#define CHECK(...) SINGLE_ARG(_CHECK(__VA_ARGS__, 0,))

#define NOT(value) CHECK(CONCATENATE(NOT, value))
#define NOT0 , 1

#define COMPL(b) CONCATENATE(COMPL, b)
#define COMPL0 1
#define COMPL1 0

#define BOOL(value) COMPL(NOT(value))

#endif // WINCOPIES_BOOL_HPP
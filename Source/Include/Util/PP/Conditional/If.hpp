#pragma once

#ifndef WINCOPIES_IF_HPP
#define WINCOPIES_IF_HPP

#include "Bool.hpp"

#define IF(value, ifTrue, ...) IF_B(BOOL(value), ifTrue, __VA_ARGS__)

#endif // WINCOPIES_IF_HPP
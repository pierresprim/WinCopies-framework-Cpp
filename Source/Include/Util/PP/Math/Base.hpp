#pragma once

#ifndef WINCOPIES_MATH_BASE_HPP
#define WINCOPIES_MATH_BASE_HPP

#include "../Loop/Repeat.hpp"

#define ADD(x, y) REPEAT(y, INCREMENT, x)
#define SUB(x, y) REPEAT(y, DECREMENT, x)

#endif // WINCOPIES_MATH_BASE_HPP
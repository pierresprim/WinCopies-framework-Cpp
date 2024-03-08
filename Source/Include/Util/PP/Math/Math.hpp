#ifndef WINCOPIES_MATH_HPP
#define WINCOPIES_MATH_HPP

#include "../Loop/Repeat.hpp"

#define ADD(x, y) REPEAT(y, INCREMENT, x)
#define SUB(x, y) REPEAT(y, DECREMENT, x)

#define MUL(x, y) REPEAT(y, ADD, x)

#endif // WINCOPIES_MATH_HPP
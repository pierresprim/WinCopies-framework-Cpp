#ifndef WINCOPIES_BOOL_HPP
#define WINCOPIES_BOOL_HPP

#include "../Math/Math.hpp"

#define _CHECK(value, n, ...) n
#define CHECK(...) _CHECK(__VA_ARGS__, 0,)

#define NOT(value) CHECK(CONCATENATE(NOT, value))
#define NOT0 , 1,

#define COMPL(b) CONCATENATE(COMPL, b)
#define COMPL0 1
#define COMPL1 0

#define BOOL(value) COMPL(NOT(value))

#endif // WINCOPIES_BOOL_HPP
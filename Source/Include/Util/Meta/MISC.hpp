#ifndef WINCOPIES_MISC_HPP
#define WINCOPIES_MISC_HPP

#include "Math/INCREMENT.h"
#include "Math/DECREMENT.h"

#define CONCATENATE(value, ...) value##__VA_ARGS__
#define SURROUND(prefix, value, ...) CONCATENATE(prefix##value, __VA_ARGS__)
#define ARGS_TRANSCRIPTION(value, ...) value __VA_ARGS__
#define TRANSCRIBE_ARGS(prefix, value, ...) prefix value __VA_ARGS__

#define INCREMENT(n) CONCATENATE(INCREMENT, n)
#define DECREMENT(n) CONCATENATE(DECREMENT, n)

#define SINGLE_ARG(...) __VA_ARGS__
#define DISCARD(...)

#define COMMA ,
#define GET_COMMA() ,

#define PAR_O (
#define PAR_C )

#define _COUNT_ARGS(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, n, ...) n
#define COUNT_ARGS(...) _COUNT_ARGS(__VA_ARGS__ __VA_OPT__(,) 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#endif // WINCOPIES_MISC_HPP
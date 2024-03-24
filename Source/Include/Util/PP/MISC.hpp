#pragma once

#ifndef WINCOPIES_MISC_HPP
#define WINCOPIES_MISC_HPP

#include "Conditional/Bool.hpp"

#include "Math/INCREMENT.h"
#include "Math/DECREMENT.h"

#define _SURROUND(x, y) CONCATENATE(x, y)
#define SURROUND(prefix, value, ...) _SURROUND(CONCATENATE(prefix, value), __VA_ARGS__)
#define ARGS_TRANSCRIPTION(value, ...) value __VA_ARGS__
#define TRANSCRIBE_ARGS(prefix, value, ...) prefix value __VA_ARGS__

#define INCREMENT(n) CONCATENATE(INCREMENT, n)
#define DECREMENT(n) CONCATENATE(DECREMENT, n)

#define DISCARD(...)

#define COMMA ,
#define GET_COMMA() ,

#define PAR_O (
#define PAR_C )
#endif // WINCOPIES_MISC_HPP
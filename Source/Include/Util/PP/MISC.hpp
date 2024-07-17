#pragma once

#ifndef WINCOPIES_MISC_HPP
#define WINCOPIES_MISC_HPP

#include "Conditional/Bool.hpp"

#include "Math/INCREMENT.h"
#include "Math/DECREMENT.h"

#define _SURROUND(x, y) CONCATENATE(x, y)

#define PREFIX(prefix, value, ...) prefix##value
#define SURROUND(prefix, value, ...) _SURROUND(CONCATENATE(prefix, value), __VA_ARGS__)
#define SUFFIX(prefix, value, ...) value##__VA_ARGS__

#define ARGS_TRANSCRIPTION(value, ...) value __VA_ARGS__

#define TRANSCRIBE_ARGS(prefix, value, ...) prefix value __VA_ARGS__
#define TRANSCRIBE_ARGS_CS(prefix, value, ...) TRANSCRIBE_ARGS(COMMA prefix, value, __VA_ARGS__)
#define TRANSCRIBE_ARGS_CE(prefix, value, ...) TRANSCRIBE_ARGS(prefix, value, __VA_ARGS__ COMMA)

#define TRANSCRIBE_VA_ARGS(prefix, suffix, ...) prefix, __VA_ARGS__, suffix

#define CALL_VA_MACRO(macro, ...) macro(__VA_ARGS__)

#define INCREMENT(n) CONCATENATE(INCREMENT, n)
#define DECREMENT(n) CONCATENATE(DECREMENT, n)

#define DISCARD(...)

#define COMMA ,
#define GET_COMMA() ,

#define PAR_O (
#define PAR_C )
#endif // WINCOPIES_MISC_HPP
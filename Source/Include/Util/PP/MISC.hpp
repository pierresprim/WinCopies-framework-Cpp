#pragma once

#ifndef WINCOPIES_MISC_HPP
#define WINCOPIES_MISC_HPP

#include "Conditional/Bool.hpp"

#include "Math/INCREMENT.h"
#include "Math/DECREMENT.h"

#define INCREMENT(n) CONCATENATE(INCREMENT, n)
#define DECREMENT(n) CONCATENATE(DECREMENT, n)

#define DISCARD(...)

#define COMMA ,
#define GET_COMMA() ,

#define PAR_O (
#define PAR_C )

#define _SURROUND(x, y) CONCATENATE(x, y)

#define PREFIX(prefix, value, ...) prefix##value
#define PREFIX_CS(prefix, value, ...) COMMA PREFIX(prefix, value)
#define PREFIX_CE(prefix, value, ...) PREFIX(prefix, value) COMMA

#define SURROUND(prefix, value, ...) _SURROUND(CONCATENATE(prefix, value), __VA_ARGS__)
#define SURROUND_CS(prefix, value, ...) COMMA SURROUND(prefix, value, __VA_ARGS__)
#define SURROUND_CE(prefix, value, ...) SURROUND(prefix, value, __VA_ARGS__) COMMA

#define SUFFIX(prefix, value, ...) value##__VA_ARGS__
#define SUFFIX_CS(prefix, value, ...) COMMA SUFFIX(, value, __VA_ARGS__)
#define SUFFIX_CE(prefix, value, ...) SUFFIX(, value, __VA_ARGS__) COMMA

#define ARGS_TRANSCRIPTION(value, ...) value __VA_ARGS__

#define TRANSCRIBE_ARGS(prefix, value, ...) prefix value __VA_ARGS__
#define TRANSCRIBE_ARGS_CS(prefix, value, ...) COMMA TRANSCRIBE_ARGS(prefix, value, __VA_ARGS__)
#define TRANSCRIBE_ARGS_CE(prefix, value, ...) TRANSCRIBE_ARGS(prefix, value, __VA_ARGS__) COMMA

#define TRANSCRIBE_VA_ARGS(prefix, suffix, ...) prefix, __VA_ARGS__, suffix
#endif WINCOPIES_MISC_HPP
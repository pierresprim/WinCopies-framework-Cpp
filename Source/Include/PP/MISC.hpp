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
#define GET_COMMA() COMMA

#define PAR_O (
#define PAR_C )

#define _SURROUND(x, ...) CONCATENATE(x, __VA_ARGS__)

#define PREFIX(prefix, value, ...) prefix##value
#define PREFIX_CS(prefix, value, ...) COMMA PREFIX(prefix, value)
#define PREFIX_CE(prefix, value, ...) PREFIX(prefix, value) COMMA

#define PREFIX_SPACED(prefix, value, ...) prefix value
#define PREFIX_CS_SPACED(prefix, value, ...) COMMA PREFIX_SPACED(prefix, value, __VA_ARGS__)
#define PREFIX_CE_SPACED(prefix, value, ...) PREFIX_SPACED(prefix, value, __VA_ARGS__) COMMA

#define PREFIX_WS(prefix, value, ...) EMPTY PREFIX(prefix, value, ...)

#define SURROUND(prefix, value, ...) _SURROUND(CONCATENATE(prefix, value), __VA_ARGS__)
#define SURROUND_CS(prefix, value, ...) COMMA SURROUND(prefix, value, __VA_ARGS__)
#define SURROUND_CE(prefix, value, ...) SURROUND(prefix, value, __VA_ARGS__) COMMA

#define SURROUND_SPACED(prefix, value, ...) prefix value __VA_ARGS__
#define SURROUND_CS_SPACED(prefix, value, ...) COMMA SURROUND_SPACED(prefix, value, __VA_ARGS__)
#define SURROUND_CE_SPACED(prefix, value, ...) SURROUND_SPACED(prefix, value, __VA_ARGS__) COMMA

#define SURROUND_WS(prefix, value, ...) EMPTY SURROUND(prefix, value, __VA_ARGS__)

#define SUFFIX(prefix, value, ...) value##__VA_ARGS__
#define SUFFIX_CS(prefix, value, ...) COMMA SUFFIX(prefix, value, __VA_ARGS__)
#define SUFFIX_CE(prefix, value, ...) SUFFIX(prefix, value, __VA_ARGS__) COMMA

#define SUFFIX_SPACED(prefix, value, ...) value __VA_ARGS__
#define SUFFIX_CS_SPACED(prefix, value, ...) COMMA SUFFIX_SPACED(prefix, value, __VA_ARGS__)
#define SUFFIX_CE_SPACED(prefix, value, ...) SUFFIX_SPACED(prefix, value, __VA_ARGS__) COMMA

#define SUFFIX_WS(prefix, value, ...) EMPTY SUFFIX(prefix, value, ...)

#define ARGS_TRANSCRIPTION(value, ...) value __VA_ARGS__

#define TRANSCRIBE_ARGS_CS(prefix, value, ...) COMMA prefix value __VA_ARGS__
#define TRANSCRIBE_ARGS_CE(prefix, value, ...) prefix value __VA_ARGS__ COMMA

#define TRANSCRIBE_VA_ARGS(prefix, suffix, ...) prefix, __VA_ARGS__, suffix

#define TRANSCRIBE_VALUE_AS_ARRAY(...) (__VA_ARGS__)

#define RENDER_COMMA(renderer, ...) , renderer(__VA_ARGS__),
#define RENDER_CS(renderer, ...) , renderer(__VA_ARGS__)
#define RENDER_CE(renderer, ...) renderer(__VA_ARGS__),

#define __RENDERED_ARRAY_TRANSCRIBER(macro, ...) (macro(__VA_ARGS__))
#define _RENDERED_ARRAY_TRANSCRIBER(expander, prefix, value) __RENDERED_ARRAY_TRANSCRIBER(FIRST_ARG prefix, expander(value))

#define _RENDERED_ARRAY_TRANSCRIBER_P(expander, prefix, value, ...) SECOND_ARG prefix, _RENDERED_ARRAY_TRANSCRIBER(expander, prefix, value)
#define _RENDERED_ARRAY_TRANSCRIBER_S(expander, prefix, value, ...) _RENDERED_ARRAY_TRANSCRIBER(expander, prefix, value), __VA_ARGS__
#define _RENDERED_ARRAY_TRANSCRIBER_P_S(expander, prefix, value, ...) _RENDERED_ARRAY_TRANSCRIBER_P(expander, prefix, value), __VA_ARGS__



#define RENDERED_AS_ARRAY_TRANSCRIBER(prefix, value, ...) _RENDERED_ARRAY_TRANSCRIBER(SINGLE_ARG, prefix, value)
#define RENDERED_AS_ARRAY_TRANSCRIBER_CS(prefix, value, ...) COMMA RENDERED_AS_ARRAY_TRANSCRIBER(prefix, value)

#define RENDERED_AS_ARRAY_TRANSCRIBER_P(prefix, value, ...) _RENDERED_ARRAY_TRANSCRIBER_P(SINGLE_ARG, prefix, value)
#define RENDERED_AS_ARRAY_TRANSCRIBER_P_CS(prefix, value, ...) COMMA RENDERED_AS_ARRAY_TRANSCRIBER_P(prefix, value)

#define RENDERED_AS_ARRAY_TRANSCRIBER_S(prefix, value, ...) _RENDERED_ARRAY_TRANSCRIBER_S(SINGLE_ARG, prefix, value, __VA_ARGS__)
#define RENDERED_AS_ARRAY_TRANSCRIBER_S_CS(prefix, value, ...) COMMA RENDERED_AS_ARRAY_TRANSCRIBER_S(prefix, value, __VA_ARGS__)

#define RENDERED_AS_ARRAY_TRANSCRIBER_P_S(prefix, value, ...) _RENDERED_ARRAY_TRANSCRIBER_P_S(SINGLE_ARG, prefix, value, __VA_ARGS__)
#define RENDERED_AS_ARRAY_TRANSCRIBER_P_S_CS(prefix, value, ...) COMMA RENDERED_AS_ARRAY_TRANSCRIBER_P_S(prefix, value, __VA_ARGS__)



#define RENDERED_ARRAY_TRANSCRIBER(prefix, value, ...) _RENDERED_ARRAY_TRANSCRIBER(EXPAND, prefix, value)
#define RENDERED_ARRAY_TRANSCRIBER_CS(prefix, value, ...) COMMA RENDERED_ARRAY_TRANSCRIBER(prefix, value)

#define RENDERED_ARRAY_TRANSCRIBER_P(prefix, value, ...) _RENDERED_ARRAY_TRANSCRIBER_P(EXPAND, prefix, value)
#define RENDERED_ARRAY_TRANSCRIBER_P_CS(prefix, value, ...) COMMA RENDERED_ARRAY_TRANSCRIBER_P(prefix, value)

#define RENDERED_ARRAY_TRANSCRIBER_S(prefix, value, ...) _RENDERED_ARRAY_TRANSCRIBER_S(EXPAND, prefix, value, __VA_ARGS__)
#define RENDERED_ARRAY_TRANSCRIBER_S_CS(prefix, value, ...) COMMA RENDERED_ARRAY_TRANSCRIBER_S(prefix, value, __VA_ARGS__)

#define RENDERED_ARRAY_TRANSCRIBER_P_S(prefix, value, ...) _RENDERED_ARRAY_TRANSCRIBER_P_S(EXPAND, prefix, value, __VA_ARGS__)
#define RENDERED_ARRAY_TRANSCRIBER_P_S_CS(prefix, value, ...) COMMA RENDERED_ARRAY_TRANSCRIBER_P_S(prefix, value, __VA_ARGS__)

#endif WINCOPIES_MISC_HPP
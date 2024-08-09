#pragma once

#ifndef WINCOPIES_VA_UTIL_BASE_HPP
#define WINCOPIES_VA_UTIL_BASE_HPP

#include "../Loop/For.hpp"
#include "../Loop/ForEach.hpp"

#define GET_ARGS_FROM(i, ...) SELECT(i, 1, SURROUND, , DISCARD, , __VA_ARGS__)
#define _GET_ARGS_FROM(i, ...) GET_ARGS_FROM(i, __VA_ARGS__)

#define ___GET_ARGS(length, ...) FIRST_ARG(__VA_ARGS__) SELECT(DECREMENT(length), 0, TRANSCRIBE_ARGS_CS, , SINGLE_ARG, , ALL_BUT_FIRST_ARG(__VA_ARGS__))
#define __GET_ARGS(start, length, ...) ___GET_ARGS(length, _GET_ARGS_FROM(start, __VA_ARGS__))
#define _GET_ARGS(start, length, count, ...) IF(count, __GET_ARGS, DISCARD)(start, length, __VA_ARGS__)
#define GET_ARGS(start, length, ...) _GET_ARGS(start, length, COUNT_ARGS(__VA_ARGS__), __VA_ARGS__)

#define GET_ARG(i, ...) GET_ARGS(i, 1, __VA_ARGS__)

#define GET_N_ARGS(length, ...) GET_ARGS(0, length, __VA_ARGS__)

#define _JOIN_RENDERED_ARGS(renderer, separator, first, ...) renderer(first)FOR_EACH(SURROUND_SPACED, separator, renderer, , __VA_ARGS__)
#define JOIN_RENDERED_ARGS(renderer, separator, ...) _JOIN_RENDERED_ARGS(renderer, separator, __VA_ARGS__)
#define JOIN_ARGS(separator, ...) JOIN_RENDERED_ARGS(SINGLE_ARG, separator, __VA_ARGS__)

#define CONCATENATE_WITH(concatenator, prefix, suffix, ...) FOR_EACH_C(concatenator, prefix, suffix, __VA_ARGS__)
#define CONCATENATE_ARGS(...) CONCATENATE_WITH(SURROUND, , , __VA_ARGS__)

#define __RENDER_ARGS(concatenator, prefix, renderer, suffix, first, ...) SURROUND_SPACED(prefix, first, suffix)FOR_EACH(concatenator, prefix, renderer, suffix, __VA_ARGS__)
#define _RENDER_ARGS(concatenator, prefix, renderer, suffix, first, ...) __RENDER_ARGS(concatenator, prefix, renderer, suffix, renderer(first), __VA_ARGS__)

#define RENDER_ARGS(concatenator, renderer, ...) _RENDER_ARGS(concatenator, , renderer, , __VA_ARGS__)

#define RENDER_PREFIXED(concatenator, prefix, renderer, ...) _RENDER_ARGS(concatenator, prefix, renderer, , __VA_ARGS__)
#define RENDER_SURROUNDED(concatenator, prefix, renderer, suffix, ...) _RENDER_ARGS(concatenator, prefix, renderer, suffix, __VA_ARGS__)
#define RENDER_SUFFIXED(concatenator, suffix, renderer, ...) _RENDER_ARGS(concatenator, , renderer, suffix, __VA_ARGS__)

#define CONCATENATE_PREFIXED(prefix, ...) CONCATENATE_WITH(PREFIX, prefix, , __VA_ARGS__)
#define CONCATENATE_SURROUNDED(prefix, suffix, ...) CONCATENATE_WITH(SURROUND, prefix, suffix, __VA_ARGS__)
#define CONCATENATE_SUFFIXED(suffix, ...) CONCATENATE_WITH(SUFFIX, , suffix, __VA_ARGS__)

#define _PRINT_ARGS_SURROUNDED(macro, prefix, suffix, ...) macro(prefix, FIRST_ARG(__VA_ARGS__), suffix)CONCATENATE_WITH(macro##_WS, prefix, suffix, ALL_BUT_FIRST_ARG(__VA_ARGS__))

#define PRINT_ARGS_PREFIXED(prefix, ...) _PRINT_ARGS_SURROUNDED(PREFIX, prefix, , __VA_ARGS__)
#define PRINT_ARGS_SURROUNDED(prefix, suffix, ...)  _PRINT_ARGS_SURROUNDED(SURROUND, prefix, suffix, __VA_ARGS__)
#define PRINT_ARGS_SUFFIXED(suffix, ...)  _PRINT_ARGS_SURROUNDED(SUFFIX, , suffix, __VA_ARGS__)

#define PRINT_ARGS(...) PRINT_ARGS_PREFIXED(, __VA_ARGS__)

#define TRANSCRIBE_ARGS_WITH(prefix, suffix, ...) CONCATENATE_WITH(SURROUND_SPACED, prefix, suffix, __VA_ARGS__)

#define ___TRANSCRIBE_SURROUNDED(firstPrefix, prefix, suffix, macro, firstTranscriber, transcriber, first, ...) firstTranscriber(firstPrefix, macro(first), suffix) FOR_EACH_C(transcriber, prefix, suffix, __VA_ARGS__)
#define __TRANSCRIBE_SURROUNDED(firstPrefix, prefix, suffix, macro, firstTranscriber, transcriber, ...) ___TRANSCRIBE_SURROUNDED(firstPrefix, prefix, suffix, macro, firstTranscriber, transcriber, __VA_ARGS__)



#define _SURROUND_ARGS(prefix, suffix, macro, ...) __TRANSCRIBE_SURROUNDED(prefix, prefix, suffix, SINGLE_ARG, SURROUND, macro, __VA_ARGS__)

#define PREFIX_ARGS(prefix, ...) _SURROUND_ARGS(prefix, , PREFIX_CS, __VA_ARGS__)
#define SURROUND_ARGS(prefix, suffix, ...) _SURROUND_ARGS(prefix, suffix, SURROUND_CS, __VA_ARGS__)
#define SUFFIX_ARGS(suffix, ...) _SURROUND_ARGS(, suffix, SUFFIX_CS, __VA_ARGS__)

#define _TRANSCRIBE_SURROUNDED(firstPrefix, prefix, suffix, macro, ...) __TRANSCRIBE_SURROUNDED(firstPrefix, prefix, suffix, macro, SURROUND_SPACED, TRANSCRIBE_ARGS_CS, __VA_ARGS__)

#define TRANSCRIBE_SURROUNDED(prefix, suffix, ...) _TRANSCRIBE_SURROUNDED(prefix, prefix, suffix, SINGLE_ARG, __VA_ARGS__)
#define TRANSCRIBE_PREFIXED(prefix, ...) TRANSCRIBE_SURROUNDED(prefix, , __VA_ARGS__)
#define TRANSCRIBE_SUFFIXED(suffix, ...) TRANSCRIBE_SURROUNDED(, suffix, __VA_ARGS__)

#define TRANSCRIBE_ARRAY_SURROUNDED(prefix, suffix, ...) _TRANSCRIBE_SURROUNDED(prefix, prefix SINGLE_ARG, suffix, EXPAND, __VA_ARGS__)
#define TRANSCRIBE_ARRAY_PREFIXED(prefix, ...) TRANSCRIBE_ARRAY_SURROUNDED(prefix, , __VA_ARGS__)
#define TRANSCRIBE_ARRAY_SUFFIXED(suffix, ...) TRANSCRIBE_ARRAY_SURROUNDED(, suffix, __VA_ARGS__)

#define _SURROUND_ARRAY(...) TRANSCRIBE_ARRAY_SURROUNDED(, , __VA_ARGS__)

#define PREFIX_ARRAY(prefix, ...) PREFIX_ARGS(prefix, _SURROUND_ARRAY(__VA_ARGS__))
#define SURROUND_ARRAY(prefix, suffix, ...) SURROUND_ARGS(prefix, suffix, _SURROUND_ARRAY(__VA_ARGS__))
#define SUFFIX_ARRAY(suffix, ...) SUFFIX_ARGS(suffix, _SURROUND_ARRAY(__VA_ARGS__))



#define REPEAT_ARG(count, value) FOR_I(count, FIRST_ARG, value, )
#define REPEAT_FOR_EACH(value, ...) REPEAT_ARG(COUNT_ARGS(__VA_ARGS__), value)

#define TRANSCRIBE_REPEATED_ARG(count, value) FFOR_EACH_C(count, SURROUND_SPACED, , , REPEAT_ARG(count, value))
#define TRANSCRIBE_REPEATED_FOR_EACH(value, ...) TRANSCRIBE_REPEATED_ARG(COUNT_ARGS(__VA_ARGS__), value)

#endif WINCOPIES_VA_UTIL_BASE_HPP
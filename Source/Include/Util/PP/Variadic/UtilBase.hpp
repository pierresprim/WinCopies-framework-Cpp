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

//#define CONCATENATE_ARGS(...) 
#define _JOIN_ARGS(separator, first, ...) first FOR_EACH_C(TRANSCRIBE_ARGS, separator, , __VA_ARGS__)
#define JOIN_ARGS(separator, ...) _JOIN_ARGS(separator, __VA_ARGS__)
#define CONCATENATE_WITH(concatenator, prefix, suffix, ...) FOR_EACH_C(concatenator, prefix, suffix, __VA_ARGS__)
#define PREFIX_ARGS(prefix, ...) CONCATENATE_WITH(PREFIX, prefix, , __VA_ARGS__)
#define SURROUND_ARGS(prefix, suffix, ...) CONCATENATE_WITH(SURROUND, prefix, suffix, __VA_ARGS__)
#define SUFFIX_ARGS(suffix, ...) CONCATENATE_WITH(SUFFIX, , suffix, __VA_ARGS__)

#define TRANSCRIBE_ARGS_WITH(prefix, suffix, ...) CONCATENATE_WITH(TRANSCRIBE_ARGS, prefix, suffix, __VA_ARGS__)

#define TRANSCRIBE_SURROUNDED(prefix, suffix, ...) prefix FIRST_ARG(__VA_ARGS__) suffix FOR_EACH_C(TRANSCRIBE_ARGS_CS, prefix, suffix, ALL_BUT_FIRST_ARG(__VA_ARGS__))
#define TRANSCRIBE_PREFIXED(prefix, ...) TRANSCRIBE_SURROUNDED(prefix, , __VA_ARGS__)
#define TRANSCRIBE_SUFFIXED(suffix, ...) TRANSCRIBE_SURROUNDED(, suffix, __VA_ARGS__)

#define TRANSCRIBE_TOKENS_SURROUNDED(prefix, suffix, ...) TRANSCRIBE_SURROUNDED(prefix SINGLE_ARG, suffix, __VA_ARGS__)
#define TRANSCRIBE_TOKENS_PREFIXED(prefix, ...) TRANSCRIBE_PREFIXED(prefix SINGLE_ARG, __VA_ARGS__)
#define TRANSCRIBE_TOKENS_SUFFIXED(suffix, ...) TRANSCRIBE_TOKENS_SURROUNDED(, suffix, __VA_ARGS__)

#define REPEAT_ARG(count, value) FOR_I(count, FIRST_ARG, value, )
#define REPEAT_FOR_EACH(value, ...) REPEAT_ARG(COUNT_ARGS(__VA_ARGS__), value)

#define TRANSCRIBE_REPEATED_ARG(count, value) FFOR_EACH_C(count, TRANSCRIBE_ARGS, , , REPEAT_ARG(count, value))
#define TRANSCRIBE_REPEATED_FOR_EACH(value, ...) TRANSCRIBE_REPEATED_ARG(COUNT_ARGS(__VA_ARGS__), value)

#endif WINCOPIES_VA_UTIL_BASE_HPP
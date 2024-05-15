#pragma once

#ifndef WINCOPIES_UTIL_HPP
#define WINCOPIES_UTIL_HPP

#include "Loop/For.hpp"
#include "Loop/ForEach.hpp"

#define SELECT_ARGS_FROM(i, ...) SELECT(i, 1, SURROUND, , DISCARD, , __VA_ARGS__)
#define GET_ARGS_FROM(i, ...) SELECT_ARGS_FROM(i, __VA_ARGS__)

#define SELECT_ARGS(start, length, ...) SELECT(length, 0, SURROUND, , SINGLE_ARG, , GET_ARGS_FROM(start, __VA_ARGS__))
#define GET_ARGS(start, length, ...) SELECT_ARGS(start, length, __VA_ARGS__)
#define GET_ARG(i, ...) GET_ARGS(i, 1, __VA_ARGS__)

//#define CONCATENATE_ARGS(...) 
#define _JOIN_ARGS(separator, first, ...) first FOR_EACH_C(TRANSCRIBE_ARGS, separator, , __VA_ARGS__)
#define JOIN_ARGS(separator, ...) _JOIN_ARGS(separator, __VA_ARGS__)
#define CONCATENATE_WITH(concatenator, prefix, suffix, ...) FOR_EACH_C(concatenator, prefix, suffix, __VA_ARGS__)
#define SURROUND_ARGS(prefix, suffix, ...) CONCATENATE_WITH(SURROUND, prefix, suffix, __VA_ARGS__)
#define TRANSCRIBE_ARGS_WITH(prefix, suffix, ...) CONCATENATE_WITH(TRANSCRIBE_ARGS, prefix, suffix, __VA_ARGS__)

#define REPEAT_ARG(count, value) FOR_I(count, FIRST_ARG, value, )
#define REPEAT_FOR_EACH(value, ...) REPEAT_ARG(COUNT_ARGS(__VA_ARGS__), value)

#define TRANSCRIBE_REPEATED_ARG(count, value) FFOR_EACH_C(count, TRANSCRIBE_ARGS, , , REPEAT_ARG(count, value))
#define TRANSCRIBE_REPEATED_FOR_EACH(value, ...) TRANSCRIBE_REPEATED_ARG(COUNT_ARGS(__VA_ARGS__), value)

#define TYPE_TEMPLATE_N(n, kind, ...) template<FFOR(n, SURROUND, kind T, SINGLE_ARG) VA_OPT(COMMA)  TRANSCRIBE_ARGS_WITH(kind, , __VA_ARGS__)>
#define TEMPLATE_NE(n, ...) TYPE_TEMPLATE_N(n, class, __VA_ARGS__)
#define TEMPLATE_TYPES(n) FFOR(n, SURROUND, T, SINGLE_ARG)

#endif // WINCOPIES_UTIL_HPP
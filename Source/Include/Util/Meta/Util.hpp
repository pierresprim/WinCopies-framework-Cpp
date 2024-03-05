#ifndef WINCOPIES_UTIL_HPP
#define WINCOPIES_UTIL_HPP

#include "Loop/For.hpp"
#include "Loop/ForEach.hpp"

#define SELECT_ARGS_FROM(i, ...) SELECT(i, 1, SURROUND, , DISCARD, , __VA_ARGS__)
#define GET_ARGS_FROM(i, ...) SELECT_ARGS_FROM(i, __VA_ARGS__)

#define SELECT_ARGS(start, length, ...) SELECT(length, 0, SURROUND, , SINGLE_ARG, , GET_ARGS_FROM(start, __VA_ARGS__))
#define GET_ARGS(start, length, ...) SELECT_ARGS(start, length, __VA_ARGS__)
#define GET_ARG(i, ...) GET_ARGS(i, 1, __VA_ARGS__)

#define CONCATENATE_ARGS(...) 
#define JOIN_ARGS(separator, ...) FOR_EACH(TRANSCRIBE_ARGS, separator, SINGLE_ARG, , __VA_ARGS__)
#define CONCATENATE_WITH(concatenator, prefix, suffix, ...) FOR_EACH(concatenator, prefix, SINGLE_ARG, suffix, __VA_ARGS__)
#define SURROUND_ARGS(concatenator, prefix, suffix, ...) CONCATENATE_WITH(concatenator, prefix, suffix, __VA_ARGS__)

#define TEMPLATE template<class T>
#define TYPE_TEMPLATE_N(n, kind, ...) template<FFOR(n, SURROUND, kind T, SINGLE_ARG) __VA_OPT__(,) SURROUND_ARGS(TRANSCRIBE_ARGS, kind, , __VA_ARGS__)>
#define TEMPLATE_N(n, ...) TYPE_TEMPLATE_N(n, class, __VA_ARGS__)
#define TEMPLATE_TYPES(n) FFOR(n, SURROUND, T, SINGLE_ARG)
#define CLASS class
#define CLASS_N(n) TEMPLATE_N(n, ) CLASS

#endif // WINCOPIES_UTIL_HPP
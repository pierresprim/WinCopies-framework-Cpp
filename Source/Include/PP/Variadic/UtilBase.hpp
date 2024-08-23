#pragma once

#ifndef WINCOPIES_VA_UTIL_BASE_HPP
#define WINCOPIES_VA_UTIL_BASE_HPP

#include "../Loop/For.hpp"
#include "../Loop/ForAll.hpp"
#include "../Loop/ForEach.hpp"

#if !HAS_VA_OPT
#include "Variadic.hpp"
#endif

#define _PP_PARSE_ARRAY_CONCATENATOR(macro, _array, ...) (macro _array)
#define PP_PARSE_ARRAY(macro, ...) FOR_EACH_C(_PP_PARSE_ARRAY_CONCATENATOR, macro, , __VA_ARGS__)

#define _PP_PPARSE_ARRAY_CONCATENATOR(macro, _array, params) (macro(EXPAND(params), EXPAND(_array)))
#define PP_PPARSE_ARRAY(macro, params, ...) FOR_EACH_C(_PP_PPARSE_ARRAY_CONCATENATOR, macro, params, __VA_ARGS__)

#define CALL_IF_VA_ARGS(macro, ...) CALL_IF(VA_ARGS_FILLED(__VA_ARGS__), macro)
#define CALL_WHEN_VA_ARGS(macro, ...) CALL_WHEN(VA_ARGS_FILLED(__VA_ARGS__), macro, __VA_ARGS__)

#define RENDER_WHEN_VA_ARGS(renderer, macro, ...) CALL_IF_VA_ARGS(renderer, __VA_ARGS__)(macro, __VA_ARGS__)

#define GET_ARGS_FROM(i, ...) SELECT(i, 1, SURROUND, , DISCARD, , __VA_ARGS__)
#define _GET_ARGS_FROM(i, ...) GET_ARGS_FROM(i, __VA_ARGS__)

#define ___GET_ARGS(length, ...) FIRST_ARG(__VA_ARGS__) SELECT(DECREMENT(length), 0, TRANSCRIBE_ARGS_CS, , SINGLE_ARG, , ALL_BUT_FIRST_ARG(__VA_ARGS__))
#define __GET_ARGS(start, length, ...) ___GET_ARGS(length, _GET_ARGS_FROM(start, __VA_ARGS__))
#define _GET_ARGS(start, length, count, ...) CALL_IF(count, __GET_ARGS)(start, length, __VA_ARGS__)
#define GET_ARGS(start, length, ...) _GET_ARGS(start, length, COUNT_ARGS(__VA_ARGS__), __VA_ARGS__)

#define GET_ARG(i, ...) GET_ARGS(i, 1, __VA_ARGS__)

#define GET_N_ARGS(length, ...) GET_ARGS(0, length, __VA_ARGS__)

#define _JOIN_RENDERED_ARGS(renderer, separator, first, ...) renderer(first)FOR_EACH(SURROUND_SPACED, separator, renderer, , __VA_ARGS__)
#define JOIN_RENDERED_ARGS(renderer, separator, ...) CALL_IF_VA_ARGS(_JOIN_RENDERED_ARGS, __VA_ARGS__)(renderer, separator, __VA_ARGS__)
#define JOIN_ARGS(separator, ...) JOIN_RENDERED_ARGS(SINGLE_ARG, separator, __VA_ARGS__)

#define _ZIP_ARGS(_array, ...) ((FIRST_ARG _array, FIRST_ARG(__VA_ARGS__))), (ALL_BUT_FIRST_ARG _array)
#define ZIP_ARGS(_array, ...) FOR_ALL(_ZIP_ARGS, _array, __VA_ARGS__)

#define CONCATENATE_WITH(concatenator, prefix, suffix, ...) FOR_EACH_C(concatenator, prefix, suffix, __VA_ARGS__)
#define CONCATENATE_ARGS(...) CONCATENATE_WITH(SURROUND, , , __VA_ARGS__)

#define _RENDER_ARGS(concatenator, prefix, renderer, suffix, first, ...) SURROUND_SPACED(prefix, renderer(first), suffix)FOR_EACH(concatenator, prefix, renderer, suffix, __VA_ARGS__)

#define RRENDER_SURROUNDED(concatenator, prefix, renderer, suffix, ...) CALL_IF_VA_ARGS(_RENDER_ARGS, __VA_ARGS__)(concatenator, prefix, renderer, suffix, __VA_ARGS__)

#define RRENDER_PREFIXED(concatenator, prefix, renderer, ...) RRENDER_SURROUNDED(concatenator, prefix, renderer, , __VA_ARGS__)
#define RRENDER_SUFFIXED(concatenator, suffix, renderer, ...) RRENDER_SURROUNDED(concatenator, , renderer, suffix, __VA_ARGS__)

#define RRENDER_ARGS(concatenator, renderer, ...) RRENDER_SURROUNDED(concatenator, , renderer, , __VA_ARGS__)

#define RENDER_PREFIXED(prefix, renderer, ...) RRENDER_PREFIXED(TRANSCRIBE_ARGS_CS, prefix, renderer, __VA_ARGS__)
#define RENDER_SURROUNDED(prefix, renderer, suffix, ...) RRENDER_SURROUNDED(TRANSCRIBE_ARGS_CS, prefix, renderer, suffix, __VA_ARGS__)
#define RENDER_SUFFIXED(suffix, renderer, ...) RRENDER_SUFFIXED(TRANSCRIBE_ARGS_CS, suffix, renderer, __VA_ARGS__)

#define RENDER_ARGS(renderer, ...) RRENDER_ARGS(TRANSCRIBE_ARGS_CS, renderer, __VA_ARGS__)

#define PRINT_RENDERED_PREFIXED(prefix, renderer, ...) RRENDER_PREFIXED(SURROUND_SPACED, prefix, renderer, __VA_ARGS__)
#define PRINT_RENDERED_SURROUNDED(prefix, renderer, suffix, ...) RRENDER_SURROUNDED(SURROUND_SPACED, prefix, renderer, suffix, __VA_ARGS__)
#define PRINT_RENDERED_SUFFIXED(suffix, renderer, ...) RRENDER_SUFFIXED(SURROUND_SPACED, suffix, renderer, __VA_ARGS__)

#define PRINT_ARGS_RENDERED(renderer, ...) RRENDER_ARGS(SURROUND_SPACED, renderer, __VA_ARGS__)

#define CONCATENATE_PREFIXED(prefix, ...) CONCATENATE_WITH(PREFIX, prefix, , __VA_ARGS__)
#define CONCATENATE_SURROUNDED(prefix, suffix, ...) CONCATENATE_WITH(SURROUND, prefix, suffix, __VA_ARGS__)
#define CONCATENATE_SUFFIXED(suffix, ...) CONCATENATE_WITH(SUFFIX, , suffix, __VA_ARGS__)

#define _PRINT_ARGS_SURROUNDED(macro, prefix, suffix, ...) macro(prefix, FIRST_ARG(__VA_ARGS__), suffix)CONCATENATE_WITH(macro##_WS, prefix, suffix, ALL_BUT_FIRST_ARG(__VA_ARGS__))

#define PRINT_ARGS_PREFIXED(prefix, ...) _PRINT_ARGS_SURROUNDED(PREFIX, prefix, , __VA_ARGS__)
#define PRINT_ARGS_SURROUNDED(prefix, suffix, ...)  _PRINT_ARGS_SURROUNDED(SURROUND, prefix, suffix, __VA_ARGS__)
#define PRINT_ARGS_SUFFIXED(suffix, ...)  _PRINT_ARGS_SURROUNDED(SUFFIX, , suffix, __VA_ARGS__)

#define PRINT_ARGS(...) PRINT_ARGS_PREFIXED(, __VA_ARGS__)

#define TRANSCRIBE_ARGS_SURROUNDED(prefix, suffix, ...) CONCATENATE_WITH(SURROUND_SPACED, prefix, suffix, __VA_ARGS__)
#define TRANSCRIBE_ARGS_PREFIXED(prefix, ...) TRANSCRIBE_ARGS_SURROUNDED(prefix, , __VA_ARGS__)
#define TRANSCRIBE_ARGS_SUFFIXED(suffix, ...) TRANSCRIBE_ARGS_SURROUNDED(, suffix, __VA_ARGS__)

#define TRANSCRIBE_ARGS(...) TRANSCRIBE_ARGS_SURROUNDED(, , __VA_ARGS__)

#define ___TRANSCRIBE_SURROUNDED(firstPrefix, prefix, suffix, macro, firstTranscriber, transcriber, first, ...) firstTranscriber(firstPrefix, macro(first), suffix) FOR_EACH_C(transcriber, prefix, suffix, __VA_ARGS__)
#define __TRANSCRIBE_SURROUNDED(firstPrefix, prefix, suffix, macro, firstTranscriber, transcriber, ...) CALL_IF_VA_ARGS(___TRANSCRIBE_SURROUNDED, __VA_ARGS__)(firstPrefix, prefix, suffix, macro, firstTranscriber, transcriber, __VA_ARGS__)



#define __SURROUND_ARGS(prefix, suffix, firstTranscriber, transcriber, ...) __TRANSCRIBE_SURROUNDED(prefix, prefix, suffix, SINGLE_ARG, firstTranscriber, transcriber, __VA_ARGS__)
#define _SURROUND_ARGS(prefix, suffix, macro, ...) __SURROUND_ARGS(prefix, suffix, SURROUND, macro, __VA_ARGS__)

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

#define TRANSCRIBE_REPEATED_FOR_EACH(value, ...) FOR_EACH_C(SURROUND_SPACED, , , REPEAT_ARG(COUNT_ARGS(__VA_ARGS__), value))

#define PREFIX_VA_ARGS(prefix, ...) IF_TRUE(VA_ARGS_FILLED(__VA_ARGS__), prefix __VA_ARGS__)
#define SURROUND_VA_ARGS(prefix, suffix, ...) IF_TRUE(VA_ARGS_FILLED(__VA_ARGS__), prefix __VA_ARGS__ suffix)
#define SUFFIX_VA_ARGS(suffix, ...) IF_TRUE(VA_ARGS_FILLED(__VA_ARGS__), __VA_ARGS__ suffix)

#define EXPAND_PREFIXED(prefix, _array) PREFIX_VA_ARGS(prefix, EXPAND(_array))
#define EXPAND_SURROUNDED(prefix, suffix, _array) SURROUND_VA_ARGS(prefix, suffix, EXPAND(_array))
#define EXPAND_SUFFIXED(suffix, _array) SUFFIX_VA_ARGS(suffix, EXPAND(_array))

#define ___PROCESS_ARG_ARRAY_RENDERING(processor, prefix, suffix, first, ...) processor(prefix, first, suffix) FOR_EACH_C(CONCATENATE(processor, _CS), prefix, suffix, __VA_ARGS__)
#define __PROCESS_ARG_ARRAY_RENDERING(processor, prefix, macro, suffix, ...) ___PROCESS_ARG_ARRAY_RENDERING(SURROUND(processor, IF_VA_ARGS(_P, , EXPAND(prefix)), IF_VA_ARGS(_S, , EXPAND(suffix))), (macro, prefix), suffix, __VA_ARGS__)
#define _PROCESS_ARG_ARRAY_RENDERING(processor, prefix, macro, suffix, ...) CALL_IF_VA_ARGS(__PROCESS_ARG_ARRAY_RENDERING, __VA_ARGS__)(SURROUND(RENDERED_, processor, ARRAY_TRANSCRIBER), prefix, macro, suffix, __VA_ARGS__)

#define RENDER_ARGS_AS_ARRAY(prefix, macro, suffix, ...) _PROCESS_ARG_ARRAY_RENDERING(AS_, prefix, macro, suffix, __VA_ARGS__)
#define RENDER_ARG_ARRAY(prefix, macro, suffix, ...) _PROCESS_ARG_ARRAY_RENDERING(, prefix, macro, suffix, __VA_ARGS__)

#define _PRINT_RENDERED_ARG_ARRAY(processor, prefix, macro, suffix, ...) TRANSCRIBE_ARGS_PREFIXED(SINGLE_ARG, SURROUND(RENDER_ARG, processor, _ARRAY)(prefix, macro, suffix, __VA_ARGS__))

#define PRINT_RENDERED_ARGS_AS_ARRAY(prefix, macro, suffix, ...) _PRINT_RENDERED_ARG_ARRAY(S_AS, prefix, macro, suffix, __VA_ARGS__)
#define PRINT_RENDERED_ARG_ARRAY(prefix, macro, suffix, ...) _PRINT_RENDERED_ARG_ARRAY(, prefix, macro, suffix, __VA_ARGS__)

#define _TRANSCRIBE_ARG_PAIRS(prefix, ...) PREFIX_ARGS(prefix ARGS_TRANSCRIPTION, __VA_ARGS__)

#define TRANSCRIBE_ARG_PAIRS(...) _TRANSCRIBE_ARG_PAIRS(, __VA_ARGS__)
#define EXPAND_ARG_PAIRS(...) _TRANSCRIBE_ARG_PAIRS(SINGLE_ARG, __VA_ARGS__)

#define GET_ARG_PAIRS_KEY(...) PREFIX_ARGS(FIRST_ARG, __VA_ARGS__)
#define GET_ARG_PAIRS_VALUE(...) PREFIX_ARGS(SECOND_ARG, __VA_ARGS__)

#endif WINCOPIES_VA_UTIL_BASE_HPP
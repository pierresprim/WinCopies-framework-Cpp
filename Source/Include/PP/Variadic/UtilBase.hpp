#pragma once

#ifndef WINCOPIES_VA_UTIL_BASE_HPP
#define WINCOPIES_VA_UTIL_BASE_HPP

#include "../Loop/For.hpp"
#include "../Loop/ForAll.hpp"
#include "../Loop/ForEach.hpp"

#include "Variadic.hpp"

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

#define ___ZIP_ARGS(renderer, argsExpander, arrayPreexpander, arrayPostexpander, _array, ...) ((renderer(arrayPreexpander _array, argsExpander(FIRST_ARG(__VA_ARGS__))))), (arrayPostexpander _array)
#define __ZIP_ARGS(expander, _array, ...) ___ZIP_ARGS(SINGLE_ARG, expander, FIRST_ARG, ALL_BUT_FIRST_ARG, _array, __VA_ARGS__)

#define _ZIP_ARGS(_array, ...) __ZIP_ARGS(SINGLE_ARG, _array, __VA_ARGS__)
#define ZIP_ARGS(_array, ...) FOR_ALL(_ZIP_ARGS, _array, __VA_ARGS__)

#define _ZIP_ARG_ARRAY(_array, ...) __ZIP_ARGS(EXPAND, _array, __VA_ARGS__)
#define ZIP_ARG_ARRAY(_array, ...) FOR_ALL(_ZIP_ARG_ARRAY, _array, __VA_ARGS__)

#define _ADD_TO_VA_ARGS(renderer, expander, _array, ...) ___ZIP_ARGS(renderer, expander, SINGLE_ARG, SINGLE_ARG, _array, __VA_ARGS__)

#define __PREPEND_TO_VA_ARGS(expander, _array, ...) _ADD_TO_VA_ARGS(SINGLE_ARG, expander, _array, __VA_ARGS__)

#define _PREPEND_TO_VA_ARGS(_array, ...) __PREPEND_TO_VA_ARGS(SINGLE_ARG, _array, __VA_ARGS__)
#define PREPEND_TO_VA_ARGS(_array, ...) FOR_ALL(_PREPEND_TO_VA_ARGS, _array, __VA_ARGS__)

#define _PREPEND_TO_ARG_ARRAY(_array, ...) __PREPEND_TO_VA_ARGS(EXPAND, _array, __VA_ARGS__)
#define PREPEND_TO_ARG_ARRAY(_array, ...) FOR_ALL(_PREPEND_TO_ARG_ARRAY, _array, __VA_ARGS__)

#define PREPEND_TO_REVERSED_VA_ARGS(_array, ...) FOR_ALL_REVERSED(_PREPEND_TO_VA_ARGS, _array, __VA_ARGS__)
#define PREPEND_TO_REVERSED_ARG_ARRAY(_array, ...) FOR_ALL_REVERSED(_PREPEND_TO_ARG_ARRAY, _array, __VA_ARGS__)

#define __APPEND_TO_VA_ARGS(expander, _array, ...) _ADD_TO_VA_ARGS(REVERSE_FIRST_TWO_ARGS, expander, _array, __VA_ARGS__)

#define _APPEND_TO_VA_ARGS(_array, ...) __APPEND_TO_VA_ARGS(SINGLE_ARG, _array, __VA_ARGS__)
#define APPEND_TO_VA_ARGS(_array, ...) FOR_ALL(_APPEND_TO_VA_ARGS, _array, __VA_ARGS__)

#define _APPEND_TO_ARG_ARRAY(_array, ...) __APPEND_TO_VA_ARGS(EXPAND, _array, __VA_ARGS__)
#define APPEND_TO_ARG_ARRAY(_array, ...) FOR_ALL(_APPEND_TO_ARG_ARRAY, _array, __VA_ARGS__)

#define APPEND_TO_REVERSED_VA_ARGS(_array, ...) FOR_ALL_REVERSED(_APPEND_TO_VA_ARGS, _array, __VA_ARGS__)
#define APPEND_TO_REVERSED_ARG_ARRAY(_array, ...) FOR_ALL_REVERSED(_APPEND_TO_ARG_ARRAY, _array, __VA_ARGS__)

#define ___SURROUND_VA_ARGS_WITH(x, y, ...) SINGLE_ARG FIRST_ARG(x), y, SINGLE_ARG SECOND_ARG(x)
#define __SURROUND_VA_ARGS_WITH(expander, _array, ...) _ADD_TO_VA_ARGS(___SURROUND_VA_ARGS_WITH, expander, _array, __VA_ARGS__)

#define _SURROUND_VA_ARGS_WITH(_array, ...) __SURROUND_VA_ARGS_WITH(SINGLE_ARG, _array, __VA_ARGS__)
#define SURROUND_VA_ARGS_WITH(prefixes, suffixes, ...) FOR_ALL(_SURROUND_VA_ARGS_WITH, (prefixes, suffixes), __VA_ARGS__)

#define _SURROUND_ARG_ARRAY_WITH(_array, ...) __SURROUND_VA_ARGS_WITH(EXPAND, _array, __VA_ARGS__)
#define SURROUND_ARG_ARRAY_WITH(prefixes, suffixes, ...) FOR_ALL(_SURROUND_ARG_ARRAY_WITH, (prefixes, suffixes), __VA_ARGS__)

#define SURROUND_REVERSED_VA_ARGS(prefixes, suffixes, ...) FOR_ALL_REVERSED(_SURROUND_VA_ARGS_WITH, (prefixes, suffixes), __VA_ARGS__)
#define SURROUND_REVERSED_ARG_ARRAY(prefixes, suffixes, ...) FOR_ALL_REVERSED(_SURROUND_ARG_ARRAY_WITH, (prefixes, suffixes), __VA_ARGS__)

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



#define ___SURROUND_ARGS(prefix, suffix, firstTranscriber, transcriber, ...) __TRANSCRIBE_SURROUNDED(prefix, prefix, suffix, SINGLE_ARG, firstTranscriber, transcriber, __VA_ARGS__)
#define __SURROUND_ARGS(renderer, prefix, suffix, macro, ...) ___SURROUND_ARGS(prefix, suffix, CONCATENATE(SURROUND, renderer), CONCATENATE(macro, renderer), __VA_ARGS__)

#define SURROUND_ARGS_RENDERED(prefix, suffix, macro, ...) __SURROUND_ARGS(, prefix, suffix, macro, __VA_ARGS__)
#define SURROUND_ARGS_RENDERED_SPACED(prefix, suffix, macro, ...) __SURROUND_ARGS(_SPACED, prefix, suffix, macro, __VA_ARGS__)

#define _PREFIX_ARGS(renderer, prefix, ...) __SURROUND_ARGS(renderer, prefix, , PREFIX_CS, __VA_ARGS__)
#define _SURROUND_ARGS(renderer, prefix, suffix, ...) __SURROUND_ARGS(renderer, prefix, suffix, SURROUND_CS, __VA_ARGS__)
#define _SUFFIX_ARGS(renderer, suffix, ...) __SURROUND_ARGS(renderer, , suffix, SUFFIX_CS, __VA_ARGS__)

#define PREFIX_ARGS(prefix, ...) _PREFIX_ARGS(, prefix, __VA_ARGS__)
#define SURROUND_ARGS(prefix, suffix, ...) _SURROUND_ARGS(, prefix, suffix, __VA_ARGS__)
#define SUFFIX_ARGS(suffix, ...) _SUFFIX_ARGS(, suffix, __VA_ARGS__)

#define PREFIX_ARGS_SPACED(prefix, ...) _PREFIX_ARGS(_SPACED, prefix, __VA_ARGS__)
#define SURROUND_ARGS_SPACED(prefix, suffix, ...) _SURROUND_ARGS(_SPACED, prefix, suffix, __VA_ARGS__)
#define SUFFIX_ARGS_SPACED(suffix, ...) _SUFFIX_ARGS(_SPACED, suffix, __VA_ARGS__)

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

#define TRANSCRIBE_ARGS_AS_ARRAYS(...) RENDER_ARGS(TRANSCRIBE_VALUE_AS_ARRAY, __VA_ARGS__)

#define RENDER_SELECTED(prefix, suffix, transcriber, selector, renderer, ...) FOR_EACH(transcriber, prefix, renderer, suffix, selector(__VA_ARGS__))

#define ___PROCESS_ARG_ARRAY_RENDERING(processor, prefix, suffix, first, ...) processor(prefix, first, suffix) FOR_EACH_C(CONCATENATE(processor, _CS), prefix, suffix, __VA_ARGS__)
#define __PROCESS_ARG_ARRAY_RENDERING(processor, prefix, macro, suffix, ...) ___PROCESS_ARG_ARRAY_RENDERING(SURROUND(processor, IF_VA_ARGS(_P, , EXPAND(prefix)), IF_VA_ARGS(_S, , EXPAND(suffix))), (macro, prefix), suffix, __VA_ARGS__)
#define _PROCESS_ARG_ARRAY_RENDERING(processor, prefix, macro, suffix, ...) CALL_IF_VA_ARGS(__PROCESS_ARG_ARRAY_RENDERING, __VA_ARGS__)(SURROUND(RENDERED_, processor, ARRAY_TRANSCRIBER), prefix, macro, suffix, __VA_ARGS__)

#define RENDER_ARGS_AS_ARRAY(prefixes, macro, suffixes, ...) _PROCESS_ARG_ARRAY_RENDERING(AS_, prefixes, macro, suffixes, __VA_ARGS__)
#define RENDER_ARG_ARRAY(prefixes, macro, suffixes, ...) _PROCESS_ARG_ARRAY_RENDERING(, prefixes, macro, suffixes, __VA_ARGS__)

#define _PRINT_RENDERED_ARG_ARRAY(processor, prefix, macro, suffix, ...) TRANSCRIBE_ARGS_PREFIXED(SINGLE_ARG, SURROUND(RENDER_ARG, processor, _ARRAY)(prefix, macro, suffix, __VA_ARGS__))

#define PRINT_RENDERED_ARGS_AS_ARRAY(prefix, macro, suffix, ...) _PRINT_RENDERED_ARG_ARRAY(S_AS, prefix, macro, suffix, __VA_ARGS__)
#define PRINT_RENDERED_ARG_ARRAY(prefix, macro, suffix, ...) _PRINT_RENDERED_ARG_ARRAY(, prefix, macro, suffix, __VA_ARGS__)

#define _RENDER_VA_ARGS_R0 RENDER_ARGS
#define _RENDER_VA_ARGS_P0 PRINT_ARGS_RENDERED

#define _RENDER_VA_ARGS_R1 RENDER_ARG_ARRAY
#define _RENDER_VA_ARGS_P1 PRINT_RENDERED_ARG_ARRAY

#define _RENDER_VA_ARGS11(prefixes, suffixes, ...) SURROUND_VA_ARGS_WITH(prefixes, suffixes, __VA_ARGS__)
#define _RENDER_VA_ARGS10(prefixes, suffixes, ...) PREPEND_TO_VA_ARGS(prefixes, __VA_ARGS__)
#define _RENDER_VA_ARGS01(prefixes, suffixes, ...) APPEND_TO_VA_ARGS(suffixes, __VA_ARGS__)
#define _RENDER_VA_ARGS00(prefixes, suffixes, ...) TRANSCRIBE_ARGS_AS_ARRAYS(__VA_ARGS__)

#define ____RENDER_VA_ARGS(bits) CONCATENATE(_RENDER_VA_ARGS, bits)
#define _GET_ARGS_RENDERER(renderer, _bool) _RENDER_VA_ARGS_##renderer##_bool

#define _RENDER_VA_ARGS1(bits, renderer, overallPrefixes, overallSuffixes, macro, argPrefixes, argSuffixes, ...) _GET_ARGS_RENDERER(renderer, 1)(overallPrefixes, macro, overallSuffixes, ____RENDER_VA_ARGS(CONCATENATE bits)(argPrefixes, argSuffixes, __VA_ARGS__))
#define _RENDER_VA_ARGS0(bits, renderer, overallPrefixes, overallSuffixes, macro, argPrefixes, argSuffixes, ...) _GET_ARGS_RENDERER(renderer, 0)(macro, __VA_ARGS__)

#define ___RENDER_VA_ARGS(_bool, bits, renderer, overallPrefixes, overallSuffixes, macro, argPrefixes, argSuffixes, ...) CONCATENATE(_RENDER_VA_ARGS, _bool)(bits, renderer, overallPrefixes, overallSuffixes, macro, argPrefixes, argSuffixes, __VA_ARGS__)
#define __RENDER_VA_ARGS(bits, renderer, overallPrefixes, overallSuffixes, macro, argPrefixes, argSuffixes, ...) ___RENDER_VA_ARGS(OR_B(ARRAY_FILLED(overallPrefixes), OR_B(ARRAY_FILLED(overallSuffixes), OR_B bits)), bits, renderer, overallPrefixes, overallSuffixes, macro, argPrefixes, argSuffixes, __VA_ARGS__)
#define _RENDER_VA_ARGS(renderer, overallPrefixes, overallSuffixes, macro, argPrefixes, argSuffixes, ...) __RENDER_VA_ARGS((ARRAY_FILLED(argPrefixes), ARRAY_FILLED(argSuffixes)), renderer, overallPrefixes, overallSuffixes, macro, argPrefixes, argSuffixes, __VA_ARGS__)

#define RRENDER_VA_ARGS(overallPrefixes, overallSuffixes, macro, argPrefixes, argSuffixes, ...) _RENDER_VA_ARGS(R, overallPrefixes, overallSuffixes, macro, argPrefixes, argSuffixes, __VA_ARGS__)
#define RENDER_VA_ARGS(macro, prefixes, suffixes, ...) RRENDER_VA_ARGS((), (), macro, prefixes, suffixes, __VA_ARGS__)

#define PPRINT_RENDERED_VA_ARGS(overallPrefixes, overallSuffixes, macro, argPrefixes, argSuffixes, ...) _RENDER_VA_ARGS(P, overallPrefixes, overallSuffixes, macro, argPrefixes, argSuffixes, __VA_ARGS__)
#define PRINT_RENDERED_VA_ARGS(macro, prefixes, suffixes, ...) PPRINT_RENDERED_VA_ARGS((), (), macro, prefixes, suffixes, __VA_ARGS__)

#define EXPAND_ARGS(...) RENDER_ARGS(EXPAND, __VA_ARGS__)
#define PRINT_EXPANDED_ARGS(...) PRINT_ARGS_RENDERED(EXPAND, __VA_ARGS__)

#define TRANSCRIBE_ARG_PAIRS(...) PREFIX_ARGS(ARGS_TRANSCRIPTION, __VA_ARGS__)
#define EXPAND_ARG_PAIRS(...) EXPAND_ARGS(TRANSCRIBE_ARG_PAIRS(__VA_ARGS__))

#define GET_ARG_PAIRS_KEY(...) PREFIX_ARGS(FIRST_ARG, __VA_ARGS__)
#define GET_ARG_PAIRS_VALUE(...) PREFIX_ARGS(SECOND_ARG, __VA_ARGS__)

#define REMOVE_FIRST_VALUE(...) RENDER_ARG_ARRAY((), ALL_BUT_FIRST_ARG, (), __VA_ARGS__)

#define ___PARSE_ITEMS(macro, ...) macro(__VA_ARGS__) // Needed for indirection.
#define __PARSE_ITEMS(macro, ...) ___PARSE_ITEMS(macro, __VA_ARGS__)
#define _PARSE_ITEMS(_array, ...) (__PARSE_ITEMS(FIRST_ARG _array, SINGLE_ARG SECOND_ARG _array, FIRST_ARG FIRST_ARG(__VA_ARGS__), SINGLE_ARG THIRD_ARG _array, ALL_BUT_FIRST_ARG FIRST_ARG(__VA_ARGS__))), _array

#define PPARSE_ITEMS(renderer, prefixes, macro, suffixes, ...) FFOR_ALL(renderer, _PARSE_ITEMS, (macro, prefixes, suffixes), __VA_ARGS__)
#define PARSE_ITEMS(prefixes, macro, suffixes, ...) PPARSE_ITEMS(SINGLE_ARG, prefixes, macro, suffixes, __VA_ARGS__)

#endif WINCOPIES_VA_UTIL_BASE_HPP
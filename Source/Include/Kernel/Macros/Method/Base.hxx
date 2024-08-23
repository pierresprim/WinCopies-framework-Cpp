#pragma once

#ifndef WINCOPIES_MACROS_METHOD_BASE_HXX
#define WINCOPIES_MACROS_METHOD_BASE_HXX

#include "../../../PP/Variadic/UtilBase.hpp"

#include "../../../Environment.h"

#define _METHOD(modifiers) DLLEXPORT modifiers void

#define METHOD _METHOD()

#define INLINE_METHOD _METHOD(inline)
#define INLINE_FUNCTION DLLEXPORT inline

#define ____RENDER_ARG_METHODS(renderer, ...) PRINT_RENDERED_ARG_ARRAY((), renderer, (;), __VA_ARGS__)
#define ___RENDER_ARG_METHODS(prefix, preRenderer, postRenderer, _array, ...) ____RENDER_ARG_METHODS(postRenderer, ZIP_ARG_ARRAY((preRenderer(prefix, SINGLE_ARG _array)), REMOVE_FIRST_VALUE(__VA_ARGS__)))
#define __RENDER_ARG_METHODS(prefix, midRendererArg, preRenderer, midRenderer, postRenderer, ...) ___RENDER_ARG_METHODS(prefix, preRenderer, postRenderer, (midRenderer(midRendererArg, GET_ARG_PAIRS_KEY(__VA_ARGS__))), __VA_ARGS__)
#define _RENDER_ARG_METHODS(prefix, preRenderer, postRenderer, ...) __RENDER_ARG_METHODS(prefix, , preRenderer, ALL_BUT_FIRST_ARG, postRenderer, __VA_ARGS__)

#define RENDER_METHODS_SELECTED(selector, renderer, ...) RENDER_SELECTED(, ;, SURROUND_SPACED, selector, renderer, __VA_ARGS__)
#define RENDER_ARG_METHODS_SELECTED(selector, renderer, ...) __RENDER_ARG_METHODS(, selector, PREFIX_ARGS, RENDER_ARGS, renderer, __VA_ARGS__)

#define RENDER_METHODS(renderer, ...) RENDER_METHODS_SELECTED(SINGLE_ARG, renderer, __VA_ARGS__)
#define RENDER_ARG_METHODS(renderer, ...) ____RENDER_ARG_METHODS(renderer, __VA_ARGS__)

#define RENDER_METHODS_PREFIXED(prefix, renderer, ...) RENDER_METHODS_SELECTED(PREFIX_ARGS, renderer, prefix, __VA_ARGS__)
#define RENDER_ARG_METHODS_PREFIXED(prefix, renderer, ...) _RENDER_ARG_METHODS(prefix, PREFIX_ARGS, renderer, __VA_ARGS__)

#define RENDER_METHODS_TYPE_PREFIXED(type, renderer, ...) RENDER_METHODS_SELECTED(TRANSCRIBE_PREFIXED, renderer, type, __VA_ARGS__)
#define RENDER_ARG_METHODS_TYPE_PREFIXED(type, renderer, ...) _RENDER_ARG_METHODS(type, TRANSCRIBE_PREFIXED, renderer, __VA_ARGS__)

#endif WINCOPIES_MACROS_METHOD_BASE_HXX
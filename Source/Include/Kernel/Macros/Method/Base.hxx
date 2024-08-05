#pragma once

#ifndef WINCOPIES_MACROS_METHOD_BASE_HXX
#define WINCOPIES_MACROS_METHOD_BASE_HXX

#include "../../../PP/Variadic/UtilBase.hpp"
#include "../../Environment.h"

#define _METHOD(modifiers) DLLEXPORT modifiers void

#define METHOD _METHOD()

#define INLINE_METHOD _METHOD(inline)
#define INLINE_FUNCTION DLLEXPORT inline

#define _RENDER_METHODS(selector, renderer, ...) FOR_EACH(SURROUND_SPACED, , renderer, ;, selector(__VA_ARGS__))
#define RENDER_METHODS(renderer, ...) _RENDER_METHODS(SINGLE_ARG, renderer, __VA_ARGS__)

#define RENDER_METHODS_TYPE_PREFIXED(type, renderer, ...) _RENDER_METHODS(TRANSCRIBE_PREFIXED, renderer, type, __VA_ARGS__)
#define RENDER_METHODS_PREFIXED(prefix, renderer, ...) _RENDER_METHODS(PREFIX_ARGS, renderer, prefix, __VA_ARGS__)

#endif WINCOPIES_MACROS_METHOD_BASE_HXX
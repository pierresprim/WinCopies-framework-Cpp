#pragma once

#ifndef WINCOPIES_MACROS_METHOD_BASE_H
#define WINCOPIES_MACROS_METHOD_BASE_H

#include "../../../PP/Variadic/UtilBase.hpp"
#include "../../Environment.h"

#define _METHOD(modifiers) DLLEXPORT modifiers void

#define METHOD _METHOD()

#define INLINE_METHOD _METHOD(inline)
#define INLINE_FUNCTION DLLEXPORT inline

#define RENDER_METHODS(type, renderer, ...) FOR_EACH(SURROUND_SPACED, , renderer, ;, TRANSCRIBE_PREFIXED(type, __VA_ARGS__))

#endif WINCOPIES_MACROS_METHOD_BASE_H
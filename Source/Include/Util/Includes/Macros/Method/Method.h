#pragma once

#ifndef WINCOPIES_MACROS_METHOD_H
#define WINCOPIES_MACROS_METHOD_H

#define _METHOD(modifiers) DLLEXPORT modifiers void

#define METHOD _METHOD()

#define INLINE_METHOD _METHOD(inline)
#define INLINE_FUNCTION DLLEXPORT inline

#include "Templates/Method.h"
#include "Templates/Inline.h"
#include "Templates/Func.h"
#include "Templates/Function.h"

#include "Abstract.h"

#endif WINCOPIES_MACROS_METHOD_H
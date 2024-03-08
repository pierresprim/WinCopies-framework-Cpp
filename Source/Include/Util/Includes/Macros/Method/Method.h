#pragma once

#ifndef WINCOPIES_UTIL_MACROS_METHOD_H
#define WINCOPIES_UTIL_MACROS_METHOD_H

#define __METHOD(modifiers) DLLEXPORT modifiers
#define _METHOD(modifiers) __METHOD() void

#define METHOD _METHOD()

#define INLINE_METHOD _METHOD(inline)
#define FUNCTION __METHOD(inline)

#include "Templates/Method.h"
#include "Templates/Inline.h"
#include "Templates/Func.h"
#include "Templates/Function.h"

#define _ABSTRACT_ARG_METHOD(typeAndName, constKeyword, virtualityType, ...) virtual typeAndName(__VA_ARGS__) constKeyword virtualityType

#define ABSTRACT_ARG_METHOD(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, , = 0, __VA_ARGS__)
#define ABSTRACT_ARG_CONST(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, const, = 0, __VA_ARGS__)
#define ABSTRACT_METHOD(typeAndName) ABSTRACT_ARG_METHOD(typeAndName, )
#define ABSTRACT_CONST(typeAndName) ABSTRACT_ARG_CONST(typeAndName, )

#define OVERRIDE_ARG_METHOD(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, , override, __VA_ARGS__)
#define OVERRIDE_ARG_CONST(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, const, override, __VA_ARGS__)
#define OVERRIDE_METHOD(typeAndName) OVERRIDE_ARG_METHOD(typeAndName, )
#define OVERRIDE_CONST(typeAndName) OVERRIDE_ARG_CONST(typeAndName, )

#define FINAL_ARG_METHOD(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, , final, __VA_ARGS__)
#define FINAL_ARG_CONST(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, const, final, __VA_ARGS__)
#define FINAL_METHOD(typeAndName) FINAL_ARG_METHOD(typeAndName, )
#define FINAL_CONST(typeAndName) FINAL_ARG_CONST(typeAndName, )

#endif
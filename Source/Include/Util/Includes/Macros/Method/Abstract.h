#pragma once

#ifndef WINCOPIES_MACROS_METHOD_ABSTRACT_H
#define WINCOPIES_MACROS_METHOD_ABSTRACT_H

#include "AbstractBase.h"
#include "Base.h"

#define _ABSTRACT_ARG_METHOD(typeAndName, constKeyword, virtualityType, ...) virtual typeAndName(__VA_ARGS__) constKeyword virtualityType

#define ABSTRACT_ARG_METHOD(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, , = 0, __VA_ARGS__)
#define ABSTRACT_ARG_CONST(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, CONST, = 0, __VA_ARGS__)
#define ABSTRACT_METHOD(typeAndName) ABSTRACT_ARG_METHOD(typeAndName, )
#define ABSTRACT_CONST(typeAndName) ABSTRACT_ARG_CONST(typeAndName, )

#define OVERRIDE_ARG_METHOD(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, , override, __VA_ARGS__)
#define OVERRIDE_ARG_CONST(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, CONST, override, __VA_ARGS__)
#define OVERRIDE_METHOD(typeAndName) OVERRIDE_ARG_METHOD(typeAndName, )
#define OVERRIDE_CONST(typeAndName) OVERRIDE_ARG_CONST(typeAndName, )

#define FINAL_ARG_METHOD(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, , final, __VA_ARGS__)
#define FINAL_ARG_CONST(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, CONST, final, __VA_ARGS__)
#define FINAL_METHOD(typeAndName) FINAL_ARG_METHOD(typeAndName, )
#define FINAL_CONST(typeAndName) FINAL_ARG_CONST(typeAndName, )

#define __ABSTRACT_METHOD_IMPLEMENTATIONS(expand, type, method, ...) _ABSTRACT_METHOD_IMPLEMENTATION(IF(expand, FIRST_ARG method) type, IF(expand, SECOND_ARG) method, __VA_ARGS__)
#define _ABSTRACT_METHOD_IMPLEMENTATIONS(type, method, ...) __ABSTRACT_METHOD_IMPLEMENTATIONS(FIRST_ARG type, SECOND_ARG type, method, __VA_ARGS__)
#define ABSTRACT_METHOD_IMPLEMENTATIONS(isConst, expand, type, methods, ...) FOR_EACH_C(_ABSTRACT_METHOD_IMPLEMENTATIONS, (expand, SURROUND(IF_FALSE(expand, _), GET_TYPE_FULL_NAME)(type, __VA_ARGS__)), IF(isConst, const), EXPAND(methods))

#define ABSTRACT_ARG_METHODS(type, ...) RENDER_METHODS(type, ABSTRACT_ARG_METHOD, __VA_ARGS__)
#define ABSTRACT_ARG_CONST_METHODS(type, ...) RENDER_METHODS(type, ABSTRACT_ARG_CONST, __VA_ARGS__)
#define ABSTRACT_METHODS(type, ...) RENDER_METHODS(type, ABSTRACT_METHOD, __VA_ARGS__)
#define ABSTRACT_CONST_METHODS(type, ...) RENDER_METHODS(type, ABSTRACT_CONST, __VA_ARGS__)

#define OVERRIDE_ARG_METHODS(type, ...) RENDER_METHODS(type, OVERRIDE_ARG_METHOD, __VA_ARGS__)
#define OVERRIDE_ARG_CONST_METHODS(type, ...) RENDER_METHODS(type, OVERRIDE_ARG_CONST, __VA_ARGS__)
#define OVERRIDE_METHODS(type, ...) RENDER_METHODS(type, OVERRIDE_METHOD, __VA_ARGS__)
#define OVERRIDE_CONST_METHODS(type, ...) RENDER_METHODS(type, OVERRIDE_CONST, __VA_ARGS__)

#define FINAL_ARG_METHODS(type, ...) RENDER_METHODS(type, FINAL_ARG_METHOD, __VA_ARGS__)
#define FINAL_ARG_CONST_METHODS(type, ...) RENDER_METHODS(type, FINAL_ARG_CONST, __VA_ARGS__)
#define FINAL_METHODS(type, ...) RENDER_METHODS(type, FINAL_METHOD, __VA_ARGS__)
#define FINAL_CONST_METHODS(type, ...) RENDER_METHODS(type, FINAL_CONST, __VA_ARGS__)

#endif WINCOPIES_MACROS_METHOD_ABSTRACT_H
#pragma once

#ifndef WINCOPIES_MACROS_TYPE_BASE_H
#define WINCOPIES_MACROS_TYPE_BASE_H

#include "../../Environment.h"
#include "../../../PP/Variadic/UtilBase.hpp"

#define CONST_EXPR DLLEXPORT constexpr

#define GET_TYPE_FULL_NAME(type, ...) IF_NO_VA_ARG(type, JOIN_ARGS(::, __VA_ARGS__, type), __VA_ARGS__)
#define __GET_TYPE_FULL_NAME(type, ...) __VA_ARGS__ type
#define _GET_TYPE_FULL_NAME(type, ...) IF_GREATER(COUNT_ARGS(__VA_ARGS__), 1, GET_TYPE_FULL_NAME, __GET_TYPE_FULL_NAME)(type, __VA_ARGS__)

#define _ABSTRACT_METHOD_IMPLEMENTATION(type, method, ...) type::method() __VA_ARGS__ { /* Left empty. */ }
#define ABSTRACT_METHOD_IMPLEMENTATION(isConst, type, method, ...) _ABSTRACT_METHOD_IMPLEMENTATION(GET_TYPE_FULL_NAME(type, __VA_ARGS__), method, IF(isConst, const))

#define ___ABSTRACT_METHOD_IMPLEMENTATIONS(expand, type, method, ...) _ABSTRACT_METHOD_IMPLEMENTATION(IF(expand, FIRST_ARG method) type, IF(expand, SECOND_ARG) method, __VA_ARGS__)
#define __ABSTRACT_METHOD_IMPLEMENTATIONS(type, method, ...) ___ABSTRACT_METHOD_IMPLEMENTATIONS(FIRST_ARG type, SECOND_ARG type, method, __VA_ARGS__)
#define ABSTRACT_METHOD_IMPLEMENTATIONS(isConst, expand, type, methods, ...) FOR_EACH_C(__ABSTRACT_METHOD_IMPLEMENTATIONS, (expand, SURROUND(IF_NOT(expand, _), GET_TYPE_FULL_NAME)(type, __VA_ARGS__)), IF(isConst, const), EXPAND(methods))

#define DEFAULT_C_D_TOR(name, modifier, implementation, ...) modifier name() __VA_ARGS__ implementation;

#define DEFAULT_CONSTRUCTOR(name, implementation, ...) DEFAULT_C_D_TOR(name, , implementation, __VA_ARGS__)
#define DEFAULT_DESTRUCTOR(name, implementation, ...) DEFAULT_C_D_TOR(~name, virtual, implementation, __VA_ARGS__)

#define INTERFACE_CONSTRUCTOR(name) protected: explicit DEFAULT_CONSTRUCTOR(name, = default)
#define _INTERFACE_DESTRUCTOR(name, _override, ...) public: DEFAULT_DESTRUCTOR(name, IF(_override, override, = 0), __VA_ARGS__)
#define INTERFACE_DESTRUCTOR(name, ...) _INTERFACE_DESTRUCTOR(name, 1, __VA_ARGS__)

#define ABSTRACT_DESTRUCTOR(name, ...) ABSTRACT_METHOD_IMPLEMENTATION(0, name, ~name, __VA_ARGS__)

#define INTERFACE_C_D_TOR(name, ...) INTERFACE_CONSTRUCTOR(name) INTERFACE_DESTRUCTOR(name, __VA_ARGS__)

#define SCOPED_INTERFACE_C_D_TOR(name, ...) { INTERFACE_CONSTRUCTOR(name) _INTERFACE_DESTRUCTOR(name, 0, __VA_ARGS__) };

#define _STATIC_CLASS_C_D_TOR(name, prefix, ...) SURROUND(DEFAULT_, prefix, STRUCTOR)(name, delete, __VA_ARGS__)

#define STATIC_CLASS_CONSTRUCTOR(name) _STATIC_CLASS_C_D_TOR(name, CON)
#define STATIC_CLASS_DESTRUCTOR(name) _STATIC_CLASS_C_D_TOR(name, DE, final)

#define STATIC_CLASS_C_D_TOR(name) private: STATIC_CLASS_CONSTRUCTOR(name) STATIC_CLASS_DESTRUCTOR(name)

#define CLASS class DLLEXPORT
#define INTERFACE_TYPE(name) CLASS name ABSTRACT

#endif WINCOPIES_MACROS_TYPE_BASE_H
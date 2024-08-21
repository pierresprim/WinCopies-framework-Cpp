#pragma once

#ifndef WINCOPIES_MACROS_METHOD_ABSTRACT_HXX
#define WINCOPIES_MACROS_METHOD_ABSTRACT_HXX

#include "../../../Libraries.h"

#include "AbstractBase.hxx"
#include "Base.hxx"

#define _ARG_METHOD_DEFINITION(typeAndName, constKeyword, ...) typeAndName(__VA_ARGS__) constKeyword
#define _ABSTRACT_ARG_METHOD(typeAndName, constKeyword, virtualityType, ...) virtual _ARG_METHOD_DEFINITION(typeAndName, constKeyword, __VA_ARGS__) virtualityType

#define CONCRETE_ARG_METHOD(typeAndName, ...) _ARG_METHOD_DEFINITION(typeAndName, , __VA_ARGS__)
#define CONCRETE_ARG_CONST(typeAndName, ...) _ARG_METHOD_DEFINITION(typeAndName, CONST, __VA_ARGS__)
#define CONCRETE_METHOD(typeAndName) CONCRETE_ARG_METHOD(typeAndName, )
#define CONCRETE_CONST(typeAndName) CONCRETE_ARG_CONST(typeAndName, )

#define ABSTRACT_ARG_METHOD(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, , = 0, __VA_ARGS__)
#define ABSTRACT_ARG_CONST(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, CONST, = 0, __VA_ARGS__)
#define ABSTRACT_METHOD(typeAndName) ABSTRACT_ARG_METHOD(typeAndName, )
#define ABSTRACT_CONST(typeAndName) ABSTRACT_ARG_CONST(typeAndName, )

#define VIRTUAL_ARG_METHOD(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, , , __VA_ARGS__)
#define VIRTUAL_ARG_CONST(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, CONST, , __VA_ARGS__)
#define VIRTUAL_METHOD(typeAndName) VIRTUAL_ARG_METHOD(typeAndName, )
#define VIRTUAL_CONST(typeAndName) VIRTUAL_ARG_CONST(typeAndName, )

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



#define CONCRETE_ARG_METHODS(...) RENDER_METHODS(CONCRETE_ARG_METHOD, __VA_ARGS__)
#define CONCRETE_ARG_CONST_METHODS(...) RENDER_METHODS(CONCRETE_ARG_CONST, __VA_ARGS__)
#define CONCRETE_METHODS(...) RENDER_METHODS(CONCRETE_METHOD, __VA_ARGS__)
#define CONCRETE_CONST_METHODS(...) RENDER_METHODS(CONCRETE_CONST, __VA_ARGS__)

#define RENDER_CONCRETE_ARG_METHODS(selector, ...) _RENDER_METHODS(selector, CONCRETE_ARG_METHOD, __VA_ARGS__)
#define RENDER_CONCRETE_ARG_CONST_METHODS(selector, ...) _RENDER_METHODS(selector, CONCRETE_ARG_CONST, __VA_ARGS__)
#define RENDER_CONCRETE_METHODS(selector, ...) _RENDER_METHODS(selector, CONCRETE_METHOD, __VA_ARGS__)
#define RENDER_CONCRETE_CONST_METHODS(selector, ...) _RENDER_METHODS(selector, CONCRETE_CONST, __VA_ARGS__)

#define CONCRETE_ARG_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, CONCRETE_ARG_METHOD, __VA_ARGS__)
#define CONCRETE_ARG_CONST_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, CONCRETE_ARG_CONST, __VA_ARGS__)
#define CONCRETE_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, CONCRETE_METHOD, __VA_ARGS__)
#define CONCRETE_CONST_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, CONCRETE_CONST, __VA_ARGS__)

#define CONCRETE_ARG_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, CONCRETE_ARG_METHOD, __VA_ARGS__)
#define CONCRETE_ARG_CONST_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, CONCRETE_ARG_CONST, __VA_ARGS__)
#define CONCRETE_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, CONCRETE_METHOD, __VA_ARGS__)
#define CONCRETE_CONST_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, CONCRETE_CONST, __VA_ARGS__)



#define ABSTRACT_ARG_METHODS(...) RENDER_METHODS(ABSTRACT_ARG_METHOD, __VA_ARGS__)
#define ABSTRACT_ARG_CONST_METHODS(...) RENDER_METHODS(ABSTRACT_ARG_CONST, __VA_ARGS__)
#define ABSTRACT_METHODS(...) RENDER_METHODS(ABSTRACT_METHOD, __VA_ARGS__)
#define ABSTRACT_CONST_METHODS(...) RENDER_METHODS(ABSTRACT_CONST, __VA_ARGS__)

#define RENDER_ABSTRACT_ARG_METHODS(selector, ...) _RENDER_METHODS(selector, ABSTRACT_ARG_METHOD, __VA_ARGS__)
#define RENDER_ABSTRACT_ARG_CONST_METHODS(selector, ...) _RENDER_METHODS(selector, ABSTRACT_ARG_CONST, __VA_ARGS__)
#define RENDER_ABSTRACT_METHODS(selector, ...) _RENDER_METHODS(selector, ABSTRACT_METHOD, __VA_ARGS__)
#define RENDER_ABSTRACT_CONST_METHODS(selector, ...) _RENDER_METHODS(selector, ABSTRACT_CONST, __VA_ARGS__)

#define ABSTRACT_ARG_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, ABSTRACT_ARG_METHOD, __VA_ARGS__)
#define ABSTRACT_ARG_CONST_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, ABSTRACT_ARG_CONST, __VA_ARGS__)
#define ABSTRACT_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, ABSTRACT_METHOD, __VA_ARGS__)
#define ABSTRACT_CONST_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, ABSTRACT_CONST, __VA_ARGS__)

#define ABSTRACT_ARG_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, ABSTRACT_ARG_METHOD, __VA_ARGS__)
#define ABSTRACT_ARG_CONST_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, ABSTRACT_ARG_CONST, __VA_ARGS__)
#define ABSTRACT_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, ABSTRACT_METHOD, __VA_ARGS__)
#define ABSTRACT_CONST_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, ABSTRACT_CONST, __VA_ARGS__)



#define OVERRIDE_ARG_METHODS(...) RENDER_METHODS(OVERRIDE_ARG_METHOD, __VA_ARGS__)
#define OVERRIDE_ARG_CONST_METHODS(...) RENDER_METHODS(OVERRIDE_ARG_CONST, __VA_ARGS__)
#define OVERRIDE_METHODS(...) RENDER_METHODS(OVERRIDE_METHOD, __VA_ARGS__)
#define OVERRIDE_CONST_METHODS(...) RENDER_METHODS(OVERRIDE_CONST, __VA_ARGS__)

#define RENDER_OVERRIDE_ARG_METHODS(selector, ...) _RENDER_METHODS(selector, OVERRIDE_ARG_METHOD, __VA_ARGS__)
#define RENDER_OVERRIDE_ARG_CONST_METHODS(selector, ...) _RENDER_METHODS(selector, OVERRIDE_ARG_CONST, __VA_ARGS__)
#define RENDER_OVERRIDE_METHODS(selector, ...) _RENDER_METHODS(selector, OVERRIDE_METHOD, __VA_ARGS__)
#define RENDER_OVERRIDE_CONST_METHODS(selector, ...) _RENDER_METHODS(selector, OVERRIDE_CONST, __VA_ARGS__)

#define OVERRIDE_ARG_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, OVERRIDE_ARG_METHOD, __VA_ARGS__)
#define OVERRIDE_ARG_CONST_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, OVERRIDE_ARG_CONST, __VA_ARGS__)
#define OVERRIDE_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, OVERRIDE_METHOD, __VA_ARGS__)
#define OVERRIDE_CONST_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, OVERRIDE_CONST, __VA_ARGS__)

#define OVERRIDE_ARG_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, OVERRIDE_ARG_METHOD, __VA_ARGS__)
#define OVERRIDE_ARG_CONST_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, OVERRIDE_ARG_CONST, __VA_ARGS__)
#define OVERRIDE_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, OVERRIDE_METHOD, __VA_ARGS__)
#define OVERRIDE_CONST_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, OVERRIDE_CONST, __VA_ARGS__)



#define FINAL_ARG_METHODS(...) RENDER_METHODS(FINAL_ARG_METHOD, __VA_ARGS__)
#define FINAL_ARG_CONST_METHODS(...) RENDER_METHODS(FINAL_ARG_CONST, __VA_ARGS__)
#define FINAL_METHODS(...) RENDER_METHODS(FINAL_METHOD, __VA_ARGS__)
#define FINAL_CONST_METHODS(...) RENDER_METHODS(FINAL_CONST, __VA_ARGS__)

#define RENDER_FINAL_ARG_METHODS(selector, ...) _RENDER_METHODS(selector, FINAL_ARG_METHOD, __VA_ARGS__)
#define RENDER_FINAL_ARG_CONST_METHODS(selector, ...) _RENDER_METHODS(selector, FINAL_ARG_CONST, __VA_ARGS__)
#define RENDER_FINAL_METHODS(selector, ...) _RENDER_METHODS(selector, FINAL_METHOD, __VA_ARGS__)
#define RENDER_FINAL_CONST_METHODS(selector, ...) _RENDER_METHODS(selector, FINAL_CONST, __VA_ARGS__)

#define FINAL_ARG_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, FINAL_ARG_METHOD, __VA_ARGS__)
#define FINAL_ARG_CONST_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, FINAL_ARG_CONST, __VA_ARGS__)
#define FINAL_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, FINAL_METHOD, __VA_ARGS__)
#define FINAL_CONST_METHODS_PREFIXED(prefix, ...) RENDER_METHODS_PREFIXED(prefix, FINAL_CONST, __VA_ARGS__)

#define FINAL_ARG_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, FINAL_ARG_METHOD, __VA_ARGS__)
#define FINAL_ARG_CONST_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, FINAL_ARG_CONST, __VA_ARGS__)
#define FINAL_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, FINAL_METHOD, __VA_ARGS__)
#define FINAL_CONST_METHODS_TYPE_PREFIXED(type, ...) RENDER_METHODS_TYPE_PREFIXED(type, FINAL_CONST, __VA_ARGS__)

#endif WINCOPIES_MACROS_METHOD_ABSTRACT_HXX
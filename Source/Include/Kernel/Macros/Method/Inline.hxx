#pragma once

#ifndef WINCOPIES_MACROS_METHOD_INLINE_HXX
#define WINCOPIES_MACROS_METHOD_INLINE_HXX

#include "../../../PP/Variadic/Variadic.hpp"
#include "../../../PP/Variadic/UtilBase.hpp"

#include "../../Reflection/Reflection.h"
#include "Property.hxx"

#define _INLINE_METHOD_ACTION_ABSTRACT(action) IF_VA_ARGS(; static_assert(false, L"Abstract method can not be implemented."), , action);
#define _INLINE_METHOD_ACTION_IMPLEMENTATION(action) { action; }

#define __INLINE_METHOD_ACTION(macro, action) CONCATENATE(_INLINE_METHOD_ACTION, macro)(action)
#define _INLINE_METHOD_ACTION(isInline, isConst, virtuality, returnType, methodName, action, ...) IF_GREATER(virtuality, 0, virtual) IF(isInline, inline) returnType methodName(__VA_ARGS__) IF(isConst, const) METHOD_VIRTUALITY(virtuality) __INLINE_METHOD_ACTION(EQUALS(virtuality, METHOD_VIRTUALITY_ABSTRACT, _ABSTRACT, _IMPLEMENTATION), action)

#define INLINE_METHOD_ACTION(isConst, virtuality, methodName, action, ...) _INLINE_METHOD_ACTION(1, isConst, virtuality, void, methodName, action, __VA_ARGS__)
#define INLINE_FUNCTION_ACTION(methodName, action, ...) INLINE_METHOD_ACTION(0, VIRTUALITY_NONE, methodName, action, __VA_ARGS__)

#define _INLINE_C_DTOR(isConst, virtuality, _namespace, className, methodName, action, ...) _INLINE_METHOD_ACTION(0, isConst, virtuality, , VA_OPT(_namespace::, _namespace)IF_VA_ARGS(className::, , className)methodName, action, __VA_ARGS__)

#define INLINE_CONSTRUCTOR(_namespace, className, action, ...) _INLINE_C_DTOR(0, 0, _namespace, className, className, action, __VA_ARGS__)
#define INLINE_DESTRUCTOR(virtuality, _namespace, className, action) _INLINE_C_DTOR(0, virtuality, _namespace, className, ~className, action)

#define INLINE_CONSTRUCTOR_DEFINITION(className, action, ...) _INLINE_C_DTOR(0, 0, , , className, action, __VA_ARGS__)
#define INLINE_DESTRUCTOR_DEFINITION(virtuality, className, action) _INLINE_C_DTOR(0, virtuality, , , ~className, action)

#define INLINE_METHOD_RETURN(isConst, virtuality, returnType, methodName, value, ...) _INLINE_METHOD_ACTION(1, isConst, virtuality, returnType, methodName, return value, __VA_ARGS__)
#define INLINE_FUNCTION_RETURN(returnType, methodName, value, ...) INLINE_METHOD_RETURN(0, VIRTUALITY_NONE, returnType, methodName, value, __VA_ARGS__)

#define INLINE_PROPERTY_GET(isConst, virtuality, returnType, value) CALL_VA_MACRO(INLINE_METHOD_RETURN, isConst, virtuality, _PROPERTY_GET(returnType), value)
#define INLINE_PROPERTY_IS(isConst, virtuality, name, value) CALL_VA_MACRO(INLINE_METHOD_RETURN, isConst, virtuality, _PROPERTY_IS(name), value)

#define FIELD_SET(field, value) _##field = value;
#define FIELD_UPDATE(value) FIELD_SET(value, value)

#define _INLINE_FIELD_SET(className, paramType, field, value) className(paramType value) { FIELD_SET(field, value) }
#define _INLINE_FIELD_UPDATE(methodName, paramType, field, value) _INLINE_FIELD_SET(void methodName, paramType, field, value)

#define INLINE_FIELD_SET(className, paramType, value) _INLINE_FIELD_SET(className, paramType, value, value)
#define INLINE_FIELD_UPDATE(methodName, paramType, value) _INLINE_FIELD_UPDATE(methodName, paramType, value, value)

#define IINLINE_FIELD_RETURN(virtuality, returnType, methodName, field) INLINE_METHOD_RETURN(1, virtuality, returnType, methodName, _##field)
#define INLINE_FIELD_RETURN(virtuality, returnType, methodName, field) IINLINE_FIELD_RETURN(virtuality, returnType, Get##methodName, field)

#define INLINE_OBJECT_RETURN(returnType, methodName, params, ...) INLINE_METHOD_RETURN(returnType*, methodName, new returnType PAR_O __VA_ARGS__ PAR_C, params)

#define _GENERIC_BRANCH(metaCondition, condition, ifTrue, ...) if (condition) { ifTrue; } SURROUND_IF_ELSE(metaCondition, else {, __VA_ARGS__, ; },__VA_ARGS__;)
#define GENERIC_BRANCH(condition, ifTrue, ...) _GENERIC_BRANCH(1, condition, ifTrue, __VA_ARGS__)
#define RETURN_BRANCH(condition, ifTrue, valueIfTrue, ifFalse, valueIfFalse) _GENERIC_BRANCH(0, condition, ifTrue; return valueIfTrue, ifFalse; return valueIfFalse)

#define GET_FIELD_IF_ELSE(returnType, methodName, paramType, paramName, condition, valueIfTrue, ifFalse, valueIfFalse) returnType methodName(paramType* paramName) { RETURN_BRANCH(condition, *##paramName = _##paramName, valueIfTrue, *##paramName = ifFalse, valueIfFalse) }

#define __BASE_FIELDS_INITIALIZER(baseType, ...) : EXPAND(baseType)(GET_ARG_PAIRS_VALUE(__VA_ARGS__))
#define _BASE_FIELDS_INITIALIZER(hasBaseArgs, ...) CALL_IF_B(hasBaseArgs, __BASE_FIELDS_INITIALIZER)(__VA_ARGS__)

#define __FIELDS_INITIALIZER(renderer, addComma, ...) renderer(EXPAND_ARG_PAIRS(ALL_BUT_FIRST_ARG(__VA_ARGS__))) IF_TRUE(addComma, COMMA)
#define _FIELDS_INITIALIZER(renderer, hasBaseArgs, addComma, ...) CALL_IF_B(hasBaseArgs, __FIELDS_INITIALIZER)(renderer, addComma, __VA_ARGS__)

#define _FIELDS_INITIALIZATION(renderer, hasBaseArgs, name, preInit, postInit, base, ...) name(_FIELDS_INITIALIZER(renderer, hasBaseArgs, VA_ARGS_FILLED(__VA_ARGS__), EXPAND(base)) renderer(EXPAND_ARG_PAIRS(__VA_ARGS__))) _BASE_FIELDS_INITIALIZER(hasBaseArgs, EXPAND(base)) { EXPAND_SUFFIXED(;, preInit) RRENDER_ARGS(SURROUND_SPACED, FIELD_UPDATE, GET_ARG_PAIRS_VALUE(__VA_ARGS__)) EXPAND_SUFFIXED(;, postInit) }

#define _FFIELDS_INITIALIZER(expand, name, preInit, postInit, base, ...) _FIELDS_INITIALIZATION(IF(expand, EXPAND, SINGLE_ARG), VA_ARGS_FILLED base, name, preInit, postInit, base, __VA_ARGS__)

#define FFIELDS_INITIALIZER(name, preInit, postInit, base, ...) _FFIELDS_INITIALIZER(0, name, preInit, postInit, base, __VA_ARGS__)
#define FIELDS_INITIALIZER(name, ...) FFIELDS_INITIALIZER(name, (), (), (), __VA_ARGS__)

#endif WINCOPIES_MACROS_METHOD_INLINE_HXX
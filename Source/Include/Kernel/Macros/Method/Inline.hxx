#pragma once

#ifndef WINCOPIES_MACROS_METHOD_INLINE_HXX
#define WINCOPIES_MACROS_METHOD_INLINE_HXX

#include "../../../PP/Variadic/Variadic.hpp"

#define _INLINE_METHOD_ACTION_ABSTRACT(action) IF_VA_ARGS(; static_assert(true, L"Abstract method can not be implemented."), , action);
#define _INLINE_METHOD_ACTION_IMPLEMENTATION(action) { action; }

#define __INLINE_METHOD_ACTION(macro, action) CONCATENATE(_INLINE_METHOD_ACTION, macro)(action)
#define _INLINE_METHOD_ACTION(isInline, isConst, virtuality, returnType, methodName, action, ...) IF_GREATER(virtuality, 0, virtual) IF(isInline, inline) returnType methodName(__VA_ARGS__) IF(isConst, const) METHOD_VIRTUALITY(virtuality) __INLINE_METHOD_ACTION(EQUALS(virtuality, METHOD_VIRTUALITY_ABSTRACT, _ABSTRACT, _IMPLEMENTATION), action)

#define INLINE_METHOD_ACTION(isConst, methodName, action, ...) _INLINE_METHOD_ACTION(1, isConst, 0, void, methodName, action, __VA_ARGS__)
#define _INLINE_C_DTOR(isConst, virtuality, _namespace, className, methodName, action, ...) _INLINE_METHOD_ACTION(0, isConst, virtuality, , VA_OPT(_namespace::, _namespace)IF_VA_ARGS(className::, , className)methodName, action, __VA_ARGS__)

#define INLINE_CONSTRUCTOR(isConst, _namespace, className, action, ...) _INLINE_C_DTOR(isConst, 0, _namespace, className, className, action, __VA_ARGS__)
#define INLINE_DESTRUCTOR(virtuality, _namespace, className, action) _INLINE_C_DTOR(0, virtuality, _namespace, className, ~className, action)

#define INLINE_CONSTRUCTOR_DEFINITION(isConst, _namespace, className, action, ...) _INLINE_C_DTOR(isConst, 0, _namespace, , className, action, __VA_ARGS__)
#define INLINE_DESTRUCTOR_DEFINITION(virtuality, _namespace, className, action) _INLINE_C_DTOR(0, virtuality, _namespace, , ~className, action)

#define INLINE_METHOD_RETURN(isConst, virtuality, returnType, methodName, value, ...) _INLINE_METHOD_ACTION(1, isConst, virtuality, returnType, methodName, return value, __VA_ARGS__)

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

#endif WINCOPIES_MACROS_METHOD_INLINE_HXX
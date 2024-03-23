#include "PP/Conditional/Conditional.hpp"

#define _INLINE_METHOD_ACTION(isConst, returnType, methodName, action, ...) returnType methodName(__VA_ARGS__) IF(isConst, const) { action; }
#define INLINE_METHOD_ACTION(isConst, methodName, action, ...) _INLINE_METHOD_ACTION(isConst, void, methodName, action, __VA_ARGS__)
#define INLINE_METHOD_RETURN(isConst, returnType, methodName, value, ...) _INLINE_METHOD_ACTION(isConst, returnType, methodName, return value, __VA_ARGS__)

#define INLINE_FIELD_SET(className, param, field) className(param field) { _##field = field; }
#define IINLINE_FIELD_RETURN(returnType, methodName, field) INLINE_METHOD_RETURN(1, returnType, methodName, _##field)
#define INLINE_FIELD_RETURN(returnType, methodName, field) IINLINE_FIELD_RETURN(returnType, Get##methodName, field)

#define INLINE_OBJECT_RETURN(returnType, methodName, params, ...) INLINE_METHOD_RETURN(returnType*, methodName, new returnType PAR_O __VA_ARGS__ PAR_C, params)

#define _GENERIC_BRANCH(metaCondition, condition, ifTrue, ...) if (condition) { ifTrue; } SURROUND_IF_ELSE(metaCondition, else {, __VA_ARGS__, ; },__VA_ARGS__;)
#define GENERIC_BRANCH(condition, ifTrue, ...) _GENERIC_BRANCH(1, condition, ifTrue, __VA_ARGS__)
#define RETURN_BRANCH(condition, ifTrue, valueIfTrue, ifFalse, valueIfFalse) _GENERIC_BRANCH(0, condition, ifTrue; return valueIfTrue, ifFalse; return valueIfFalse)

#define GET_FIELD_IF_ELSE(returnType, methodName, paramType, paramName, condition, valueIfTrue, ifFalse, valueIfFalse) returnType methodName(paramType* paramName) { RETURN_BRANCH(condition, *##paramName = _##paramName, valueIfTrue, *##paramName = ifFalse, valueIfFalse) }

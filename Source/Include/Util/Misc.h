#include "Meta/Conditional/Conditional.hpp"

#define INLINE_SET_FIELD(className, param, field) className(param field) { _##field = field; }
#define INLINE_FIELD_RETURN(returnType, methodName, field) returnType methodName() { return _##field; }

#define _GENERIC_BRANCH(metaCondition, condition, ifTrue, ...) if (condition) { ifTrue; } SURROUND_IF_ELSE(metaCondition, else {, __VA_ARGS__, ; },__VA_ARGS__;)
#define GENERIC_BRANCH(condition, ifTrue, ...) _GENERIC_BRANCH(1, condition, ifTrue, __VA_ARGS__)
#define RETURN_BRANCH(condition, ifTrue, valueIfTrue, ifFalse, valueIfFalse) _GENERIC_BRANCH(0, condition, ifTrue; return valueIfTrue, ifFalse; return valueIfFalse)

#define GET_FIELD_IF_ELSE(returnType, methodName, paramType, paramName, condition, valueIfTrue, ifFalse, valueIfFalse) returnType methodName(paramType* paramName) { RETURN_BRANCH(condition, *##paramName = _##paramName, valueIfTrue, *##paramName = ifFalse, valueIfFalse) }

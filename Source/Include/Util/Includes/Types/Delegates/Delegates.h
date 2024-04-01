#pragma once

#ifndef WINCOPIES_UTIL_DELEGATE_USINGS_H
#define WINCOPIES_UTIL_DELEGATE_USINGS_H

#include "../../Framework.h"
#include "../../../PP/Util.hpp"
#include "../../../PP/Loop/Loop.hpp"

#define TEMPLATE_METHOD_ARG(n) T##n value##n
#define TEMPLATE_METHOD_MAX_ARGS 16
#define TEMPLATE_FUNCTION_MAX_ARGS INCREMENT(TEMPLATE_METHOD_MAX_ARGS)

#define ___DELEGATE_ACTION(delegateKind, typeName, namePrefix, name, returnType, functionPrefix, functionSuffix, ...) using namePrefix##delegateKind##name = functionPrefix returnType typeName(__VA_ARGS__) functionSuffix;
#define __DELEGATE_ACTION(delegateKind, typeName, prefix, name, returnType, ...) ___DELEGATE_ACTION(delegateKind, PAR_O typeName * PAR_C, prefix, name, returnType, , , __VA_ARGS__)
#define _DELEGATE_ACTION(name, delegateKind, returnType, ...) __DELEGATE_ACTION(delegateKind, , , name, returnType, __VA_ARGS__)
#define _INSTANCE_ACTION(name, delegateKind, returnType, ...) __DELEGATE_ACTION(delegateKind, TObj::, Instance, name, returnType, __VA_ARGS__)
#define _STD_ACTION(name, delegateKind, returnType, ...) ___DELEGATE_ACTION(delegateKind, , , Function##name, returnType, std::function<, >, __VA_ARGS__)

#define APPEND_TOUT(appendTOut) IF(NOT(appendTOut), , SINGLE_ARG(COMMA class TOut))
#define _APPEND_TOBJ(appendTObj, prependClass) IF(NOT(appendTObj), , SINGLE_ARG(IF(prependClass, class) TObj COMMA))
#define APPEND_TOBJ(appendTObj) _APPEND_TOBJ(appendTObj, 1)

#define __MAKE_TEMPLATE_PARAMS(count, prefix, suffix, appendTOut) FOR_I(count, SURROUND, prefix T##suffix, ) APPEND_TOUT(appendTOut)
#define _MAKE_TEMPLATE_PARAMS(count, suffix, appendTObj, appendTOut) template<APPEND_TOBJ(appendTObj) __MAKE_TEMPLATE_PARAMS(count, class, suffix, appendTOut)>

#define MAKE_DELEGATE_ACTION(count, appendTObj, delegateKind, suffix, appendTOut, macro) _MAKE_TEMPLATE_PARAMS(count, suffix, appendTObj, appendTOut) macro(count, delegateKind, GET_DELEGATE_ACTION_RETURN_TYPE(appendTOut), __MAKE_TEMPLATE_PARAMS(count, , suffix, 0))

#define GET_DELEGATE_ACTION_RETURN_TYPE(appendTOut) IF(appendTOut, TOut, void)

#define DELEGATE_ACTION(count, delegateKind, suffix, appendTOut) MAKE_DELEGATE_ACTION(count, 0, delegateKind, suffix, appendTOut, _DELEGATE_ACTION)
#define INSTANCE_ACTION(count, delegateKind, suffix, appendTOut) MAKE_DELEGATE_ACTION(count, 1, delegateKind, suffix, appendTOut, _INSTANCE_ACTION)
#define STD_ACTION(count, delegateKind, suffix, appendTOut) MAKE_DELEGATE_ACTION(count, 0, delegateKind, suffix, appendTOut, _STD_ACTION)

#define DELEGATE_VOID(count) DELEGATE_ACTION(count, Action, , 0)
#define INSTANCE_VOID(count) INSTANCE_ACTION(count, Action, , 0)
#define ACTION_VOID(count) STD_ACTION(count, Action, , 0)

#define DELEGATE_FUNCTION(count) DELEGATE_ACTION(count, Selector, In, 1)
#define INSTANCE_FUNCTION(count) INSTANCE_ACTION(count, Selector, In, 1)
#define ACTION_FUNCTION(count) STD_ACTION(count, Selector, In, 1)

#define ___CREATE_DELEGATE_ACTION(appendTObj, typeName, delegateKind, appendTOut, macro) template<APPEND_TOBJ(appendTObj) class typeName APPEND_TOUT(appendTOut)> macro(, delegateKind, GET_DELEGATE_ACTION_RETURN_TYPE(appendTOut), typeName)
#define __CREATE_DELEGATE_ACTION(appendTObj, typeNameSuffix, delegateKind, appendTOut, macro) ___CREATE_DELEGATE_ACTION(appendTObj, T##typeNameSuffix, delegateKind, appendTOut, macro)
#define _CREATE_DELEGATE_ACTION(appendTObj, macro) __CREATE_DELEGATE_ACTION(appendTObj, , Action, 0, macro)
#define _CREATE_DELEGATE_FUNCTION(appendTObj, macro) __CREATE_DELEGATE_ACTION(appendTObj, In, Selector, 1, macro)
#define CREATE_DELEGATE_ACTION(appendTObj, macro) _CREATE_DELEGATE_ACTION(appendTObj, macro) _CREATE_DELEGATE_FUNCTION(appendTObj, macro)

#define __CREATE_DELEGATE_ACTIONS(delegateKind, macro) LOOP_TO(2, TEMPLATE_METHOD_MAX_ARGS, macro##delegateKind)
#define _CREATE_DELEGATE_ACTIONS(macro) __CREATE_DELEGATE_ACTIONS(_VOID, macro)
#define _CREATE_DELEGATE_FUNCTIONS(macro) __CREATE_DELEGATE_ACTIONS(_FUNCTION, macro)
#define CREATE_DELEGATE_ACTIONS(macro) _CREATE_DELEGATE_ACTIONS(macro) _CREATE_DELEGATE_FUNCTIONS(macro)

typedef void(*ActionVoid)();
typedef std::function<void()> ActionFunctionVoid;

TEMPLATE using Function = T(*)();
TEMPLATE using FunctionFunction = std::function<T()>;

CREATE_DELEGATE_ACTION(0, _DELEGATE_ACTION)
CREATE_DELEGATE_ACTION(1, _INSTANCE_ACTION)
CREATE_DELEGATE_ACTION(0, _STD_ACTION)

CREATE_DELEGATE_ACTIONS(DELEGATE)
CREATE_DELEGATE_ACTIONS(INSTANCE)
CREATE_DELEGATE_ACTIONS(ACTION)

#define _CREATE_SELECTOR_DELEGATE(name, prefix, suffix, TOut, appendTObj, ...) template<APPEND_TOBJ(appendTObj) class T> using prefix##name##suffix = prefix##Selector##suffix<_APPEND_TOBJ(appendTObj, 0) __VA_ARGS__, TOut>;
#define CREATE_SELECTOR_DELEGATE(name, prefix, suffix, TOut, appendTObj) _CREATE_SELECTOR_DELEGATE(name, prefix, suffix, TOut, appendTObj, T)
#define CREATE_SELECTOR_DELEGATES(name, TOut) CREATE_SELECTOR_DELEGATE(name, , , TOut, 0) CREATE_SELECTOR_DELEGATE(name, Instance, , TOut, 1) CREATE_SELECTOR_DELEGATE(name, , Function, TOut, 0)

CREATE_SELECTOR_DELEGATES(Converter, T)
CREATE_SELECTOR_DELEGATES(Predicate, bool)

#define CREATE_SELECTOR(name, TOut) template<>

template<class T1, class T2>
using Predicate2 = Selector2<T1, T2, bool>;
template<class T1, class T2>
using PredicateFunction2 = SelectorFunction2<T1, T2, bool>;

template<class T1, class T2>
using Comparison2 = Selector2<T1, T2, BYTE>;
template<class T1, class T2>
using ComparisonFunction2 = SelectorFunction2<T1, T2, BYTE>;

template<class T1, class T2>
using EqualityComparison2 = Predicate2<T1, T2>;
template<class T1, class T2>
using EqualityComparisonFunction2 = PredicateFunction2<T1, T2>;

TEMPLATE
using Comparison = Comparison2<T, T>;
TEMPLATE
using ComparisonFunction = ComparisonFunction2<T, T>;

TEMPLATE
using EqualityComparison = EqualityComparison2<T, T>;
TEMPLATE
using EqualityComparisonFunction = EqualityComparisonFunction2<T, T>;

#endif
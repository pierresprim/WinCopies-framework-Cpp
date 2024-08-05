#pragma once

#ifndef WINCOPIES_TYPES_DELEGATES_HXX
#define WINCOPIES_TYPES_DELEGATES_HXX

#include "../../Framework.h"
#include "../../../PP/Variadic/Util.hpp"
#include "../../../PP/Loop/Loop.hpp"

#define INSTANCE_DELEGATE(typeName, returnType, ...) returnType(typeName::*)(__VA_ARGS__)

#define TEMPLATE_METHOD_MAX_ARGS 16

#define ___DELEGATE_ACTION(delegateKind, typeName, namePrefix, name, returnType, functionPrefix, functionSuffix, ...) using namePrefix##delegateKind##name = functionPrefix returnType typeName(__VA_ARGS__) functionSuffix;
#define __DELEGATE_ACTION(delegateKind, typeName, prefix, name, returnType, ...) ___DELEGATE_ACTION(delegateKind, PAR_O typeName * PAR_C, prefix, name, returnType, , , __VA_ARGS__)
#define _DELEGATE_ACTION(name, delegateKind, returnType, ...) __DELEGATE_ACTION(delegateKind, , , name, returnType, __VA_ARGS__)
#define _INSTANCE_ACTION(name, delegateKind, returnType, ...) __DELEGATE_ACTION(delegateKind, TObj::, Instance, name, returnType, __VA_ARGS__)
#define _STD_ACTION(name, delegateKind, returnType, ...) ___DELEGATE_ACTION(delegateKind, , , Function##name, returnType, std::function<, >, __VA_ARGS__)

#define APPEND_TOUT(appendTOut) IF(NOT(appendTOut), , SINGLE_ARG(COMMA class TOut))
#define _APPEND_TOBJ(appendTObj, prependClass) IF(NOT(appendTObj), , SINGLE_ARG(IF(prependClass, class) TObj COMMA))
#define APPEND_TOBJ(appendTObj) _APPEND_TOBJ(appendTObj, 1)

#define __MAKE_TEMPLATE_PARAMS(count, prefix, suffix, appendTOut)  MAKE_TEMPLATE_PARAMS(count, prefix, suffix) APPEND_TOUT(appendTOut)
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

#define _CREATE_SELECTOR_DELEGATE(name, prefix, suffix, TOut, appendTObj, ...) template<APPEND_TOBJ(appendTObj) class T> using prefix##name##suffix = prefix##Selector##suffix<_APPEND_TOBJ(appendTObj, 0) __VA_ARGS__, TOut>;
#define CREATE_SELECTOR_DELEGATE(name, prefix, suffix, TOut, appendTObj) _CREATE_SELECTOR_DELEGATE(name, prefix, suffix, TOut, appendTObj, T)
#define CREATE_SELECTOR_DELEGATES(name, TOut) CREATE_SELECTOR_DELEGATE(name, , , TOut, 0) CREATE_SELECTOR_DELEGATE(name, Instance, , TOut, 1) CREATE_SELECTOR_DELEGATE(name, , Function, TOut, 0)

#define CREATE_SELECTOR_TEMPLATE(count, prefix, appendTObj) template<APPEND_TOBJ(appendTObj) MAKE_TEMPLATE_PARAMS(count, prefix, )>
#define CREATE_SELECTOR_TEMPLATE_ARGS(count, appendTObj) _APPEND_TOBJ(appendTObj, 0) MAKE_TEMPLATE_PARAMS(count, , )
#define __CREATE_SELECTOR(count, kind, name, prefix, suffix, templatePrefix, appendTObj, ...) CREATE_SELECTOR_TEMPLATE(count, templatePrefix, appendTObj) using CONCATENATE(prefix##name##suffix, count) = CONCATENATE(prefix##kind##suffix, count)<CREATE_SELECTOR_TEMPLATE_ARGS(count, appendTObj) VA_PREPEND(, __VA_ARGS__)>;
#define _CREATE_SELECTOR(count, kind, name, prefix, suffix, appendTObj, ...) __CREATE_SELECTOR(count, kind, name, prefix, suffix, class, appendTObj, __VA_ARGS__)
#define CREATE_SELECTOR(count, kind, name, ...) _CREATE_SELECTOR(count, kind, name, , , 0, __VA_ARGS__) _CREATE_SELECTOR(count, kind, name, Instance, , 1, __VA_ARGS__) _CREATE_SELECTOR(count, kind, name, , Function, 0, __VA_ARGS__)

#define CREATE_PREDICATE(count) CREATE_SELECTOR(count, Selector, Predicate, bool)
#define CREATE_COMPARISON(count) CREATE_SELECTOR(count, Selector, Comparison, BYTE)
#define CREATE_EQUALITY_COMPARISON(count) CREATE_SELECTOR(count, Predicate, EqualityComparison)

#define CREATE_SELECTORS(macro) LOOP_TO(2, TEMPLATE_METHOD_MAX_ARGS, CREATE##macro)

#define _CREATE_COMPARISON_DELEGATES(prefix, suffix, appendTObj) template<APPEND_TOBJ(appendTObj) class T> using SURROUND(prefix, Comparison, suffix) = SURROUND(prefix, Comparison, suffix##2)<_APPEND_TOBJ(appendTObj, 0) T, T>;

#define CREATE_COMPARISON_DELEGATES(prefix) _CREATE_COMPARISON_DELEGATES(prefix, , 0) _CREATE_COMPARISON_DELEGATES(Instance##prefix, , 1) _CREATE_COMPARISON_DELEGATES(prefix, Function, 0)

#endif WINCOPIES_TYPES_DELEGATES_HXX
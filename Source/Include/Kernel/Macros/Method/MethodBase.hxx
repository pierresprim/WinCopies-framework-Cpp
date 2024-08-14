#pragma once

#ifndef WINCOPIES_MACROS_METHOD_METHOD_BASE_HXX
#define WINCOPIES_MACROS_METHOD_METHOD_BASE_HXX

#include "../../../PP/Variadic/UtilBase.hpp"

#define _MAKE_PARAMETERS_SPACED(prefix, value, ...) ((prefix FIRST_ARG value) EXPAND(__VA_ARGS__))
#define _MAKE_PARAMETERS_CS(prefix, value, ...) COMMA _MAKE_PARAMETERS_SPACED(prefix, value, __VA_ARGS__)

#define ____MAKE_PARAMETERS(ptrType, _namespace, genericTypeArguments, renderer, ...) ZIP_ARGS((__SURROUND_ARGS(FIRST_ARG ptrType _namespace renderer, (EXPAND(genericTypeArguments) SECOND_ARG ptrType), _MAKE_PARAMETERS_SPACED, _MAKE_PARAMETERS_CS, __VA_ARGS__)), PREFIX_ARGS(SECOND_ARG, __VA_ARGS__))
#define ___MAKE_PARAMETERS(ptrType, _namespace, genericTypeArguments, ...) ____MAKE_PARAMETERS(ptrType, _namespace, genericTypeArguments, IF(VA_ARGS_EMPTY(EXPAND(genericTypeArguments)), SINGLE_ARG), __VA_ARGS__)

#define __MAKE_PARAMETER_ARRAY(ptrType, _namespace, genericTypeArguments, ...) (___MAKE_PARAMETERS(ptrType, _namespace, genericTypeArguments, __VA_ARGS__)),
#define _MAKE_PARAMETER_ARRAY(ptrType, _namespace, genericTypeArguments, ...) CALL_IF_VA_ARGS(__MAKE_PARAMETER_ARRAY, __VA_ARGS__)(ptrType, _namespace, genericTypeArguments, __VA_ARGS__)

#define __MAKE_PARAMETERS(ptrType, _namespace, genericTypeArguments, _array, ...) _MAKE_PARAMETER_ARRAY(ptrType, _namespace, genericTypeArguments, EXPAND(_array)) ___MAKE_PARAMETERS(ptrType, _namespace, genericTypeArguments, __VA_ARGS__)
#define _MAKE_PARAMETERS(ptrType, _namespace, genericTypeArguments, _array, ...) __MAKE_PARAMETERS(ptrType, SUFFIX_VA_ARGS(::, _namespace), genericTypeArguments, _array, __VA_ARGS__)

#define MMAKE_PARAMETERS(ptrType, _namespace, genericTypeArguments, _array, ...) _MAKE_PARAMETERS(IF_VA_ARGS((ptrType <, >), , ptrType), _namespace, (GET_TEMPLATE_ARGS(EXPAND(genericTypeArguments))), _array, __VA_ARGS__)
#define MAKE_PARAMETERS(ptrType, _namespace, genericTypeArguments, ...) MMAKE_PARAMETERS(ptrType, _namespace, genericTypeArguments, (), __VA_ARGS__)

#endif WINCOPIES_MACROS_METHOD_METHOD_BASE_HXX
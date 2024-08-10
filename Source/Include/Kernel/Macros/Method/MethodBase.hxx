#pragma once

#ifndef WINCOPIES_MACROS_METHOD_METHOD_BASE_HXX
#define WINCOPIES_MACROS_METHOD_METHOD_BASE_HXX

#include "../../../PP/Variadic/UtilBase.hpp"

#define __MAKE_PARAMETERS(ptrType, _namespace, genericTypeArgument, ...) ZIP_ARGS((SURROUND_ARGS(FIRST_ARG ptrType _namespace FIRST_ARG, genericTypeArgument SECOND_ARG ptrType, __VA_ARGS__)), PREFIX_ARGS(SECOND_ARG, __VA_ARGS__))

#define __MAKE_PARAMETER_ARRAY(ptrType, _namespace, genericTypeArgument, ...) (__MAKE_PARAMETERS(ptrType, _namespace, genericTypeArgument, __VA_ARGS__)),
#define _MAKE_PARAMETER_ARRAY(ptrType, _namespace, genericTypeArgument, ...) IF_VA_ARGS(__MAKE_PARAMETER_ARRAY, DISCARD, __VA_ARGS__)(ptrType, _namespace, genericTypeArgument, __VA_ARGS__)

#define _MAKE_PARAMETERS(ptrType, _namespace, genericTypeArgument, _array, ...) _MAKE_PARAMETER_ARRAY(ptrType, _namespace, genericTypeArgument, EXPAND(_array)) __MAKE_PARAMETERS(ptrType, _namespace, genericTypeArgument, __VA_ARGS__)

#define MMAKE_PARAMETERS(ptrType, _namespace, genericTypeArgument, _array, ...) _MAKE_PARAMETERS(IF_VA_ARGS((ptrType <, >), , ptrType), _namespace, IF_VA_ARGS(<genericTypeArgument>, , genericTypeArgument), _array, __VA_ARGS__)
#define MAKE_PARAMETERS(ptrType, _namespace, genericTypeArgument, ...) MMAKE_PARAMETERS(ptrType, _namespace, genericTypeArgument, (), __VA_ARGS__)

#endif WINCOPIES_MACROS_METHOD_METHOD_BASE_HXX
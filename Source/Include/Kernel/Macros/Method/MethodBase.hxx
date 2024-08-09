#pragma once

#ifndef WINCOPIES_MACROS_METHOD_METHOD_BASE_HXX
#define WINCOPIES_MACROS_METHOD_METHOD_BASE_HXX

#include "../../../PP/Variadic/UtilBase.hpp"

#define _ZIP_PARAMETERS(ptrType, _namespace, genericTypeArgument, ...) ZIP_ARGS((SURROUND_ARGS(FIRST_ARG ptrType _namespace FIRST_ARG, genericTypeArgument SECOND_ARG ptrType, __VA_ARGS__)), PREFIX_ARGS(SECOND_ARG, __VA_ARGS__))
#define ZIP_PARAMETERS(ptrType, _namespace, genericTypeArgument, ...) _ZIP_PARAMETERS(IF_VA_ARGS((ptrType <, >), , ptrType), _namespace, IF_VA_ARGS(<genericTypeArgument>, , genericTypeArgument), __VA_ARGS__)

#endif WINCOPIES_MACROS_METHOD_METHOD_BASE_HXX
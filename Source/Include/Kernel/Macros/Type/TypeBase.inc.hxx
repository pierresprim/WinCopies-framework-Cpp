#pragma once

#ifndef WINCOPIES_MACROS_TYPE_BASE_INC_HXX
#define WINCOPIES_MACROS_TYPE_BASE_INC_HXX

#include "../../../PP/Variadic/UtilBase.hpp"

#define GET_TYPE_FULL_NAME(type, ...) IF_NO_VA_ARG(type, JOIN_ARGS(::, __VA_ARGS__, type), __VA_ARGS__)

#define PREFIX_TEMPLATE_TYPES(...) PREFIX_ARGS(T, __VA_ARGS__)

#define GET_TEMPLATE_ARGS(...) SURROUND_VA_ARGS(<, >, __VA_ARGS__)

#endif WINCOPIES_MACROS_TYPE_BASE_INC_HXX
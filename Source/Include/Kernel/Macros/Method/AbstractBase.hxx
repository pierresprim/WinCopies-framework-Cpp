#pragma once

#ifndef WINCOPIES_MACROS_METHOD_ABSTRACT_BASE_HXX
#define WINCOPIES_MACROS_METHOD_ABSTRACT_BASE_HXX

#include "../../../PP/Variadic/UtilBase.hpp"

#if !HAS_VA_OPT
#include "../../../PP/Variadic/Variadic.hpp"
#endif

#define GET_TYPE_FULL_NAME(type, ...) IF_NO_VA_ARG(type, JOIN_ARGS(::, __VA_ARGS__, type), __VA_ARGS__)

#define _ABSTRACT_METHOD_IMPLEMENTATION(type, method, ...) type::method() __VA_ARGS__ { /* Left empty. */ }
#define ABSTRACT_METHOD_IMPLEMENTATION(isConst, type, method, ...) _ABSTRACT_METHOD_IMPLEMENTATION(GET_TYPE_FULL_NAME(type, __VA_ARGS__), method, IF(isConst, const))

#endif WINCOPIES_MACROS_METHOD_ABSTRACT_BASE_HXX
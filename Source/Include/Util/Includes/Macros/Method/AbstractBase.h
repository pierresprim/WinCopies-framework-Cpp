#pragma once

#ifndef WINCOPIES_MACROS_METHOD_ABSTRACT_BASE_H
#define WINCOPIES_MACROS_METHOD_ABSTRACT_BASE_H

#include "../../../PP/Variadic/UtilBase.hpp"

#if !HAS_VA_OPT
#include "../../../PP/Variadic/Variadic.hpp"
#endif

#define GET_TYPE_FULL_NAME(type, ...) IF_NO_VA_ARG(type, JOIN_ARGS(::, __VA_ARGS__, type), __VA_ARGS__)
#define __GET_TYPE_FULL_NAME(type, ...) __VA_ARGS__ type
#define _GET_TYPE_FULL_NAME(type, ...) IF_GREATER(COUNT_ARGS(__VA_ARGS__), 1, GET_TYPE_FULL_NAME, __GET_TYPE_FULL_NAME)(type, __VA_ARGS__)

#define _ABSTRACT_METHOD_IMPLEMENTATION(type, method, ...) type::method() __VA_ARGS__ { /* Left empty. */ }
#define ABSTRACT_METHOD_IMPLEMENTATION(isConst, type, method, ...) _ABSTRACT_METHOD_IMPLEMENTATION(GET_TYPE_FULL_NAME(type, __VA_ARGS__), method, IF(isConst, const))

#endif WINCOPIES_MACROS_METHOD_ABSTRACT_BASE_H
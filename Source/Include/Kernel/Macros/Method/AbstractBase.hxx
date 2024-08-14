#pragma once

#ifndef WINCOPIES_MACROS_METHOD_ABSTRACT_BASE_HXX
#define WINCOPIES_MACROS_METHOD_ABSTRACT_BASE_HXX

#include "../../../PP/Variadic/UtilBase.hpp"

#include "../Type/TypeBase.inc.hxx"

#define __ABSTRACT_METHOD_IMPLEMENTATION(type, method, ...) type::method() __VA_ARGS__ { /* Left empty. */ }
#define _ABSTRACT_METHOD_IMPLEMENTATION(isConst, templateArgs, type, method, ...) __ABSTRACT_METHOD_IMPLEMENTATION(GET_TYPE_FULL_NAME(type, __VA_ARGS__) GET_TEMPLATE_ARGS(EXPAND(templateArgs)), method, IF(isConst, const))

#define ABSTRACT_METHOD_IMPLEMENTATION(isConst, type, method, ...) _ABSTRACT_METHOD_IMPLEMENTATION(0, (), type, method, __VA_ARGS__)
#define ABSTRACT_TEMPLATE_METHOD_IMPLEMENTATION(isConst, templateArgs, type, method, ...) _ABSTRACT_METHOD_IMPLEMENTATION(0, templateArgs, type, method, __VA_ARGS__)

#endif WINCOPIES_MACROS_METHOD_ABSTRACT_BASE_HXX
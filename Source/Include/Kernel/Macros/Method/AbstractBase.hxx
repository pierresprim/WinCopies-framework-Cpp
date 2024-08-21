#pragma once

#ifndef WINCOPIES_MACROS_METHOD_ABSTRACT_BASE_HXX
#define WINCOPIES_MACROS_METHOD_ABSTRACT_BASE_HXX

#include "../Type/TypeBase.inc.hxx"

#define ABSTRACT_TEMPLATE_METHOD_IMPLEMENTATION(isConst, templateArgs, type, method, ...) GET_TYPE_FULL_NAME(type, __VA_ARGS__)GET_TEMPLATE_ARGS(EXPAND(templateArgs))::method() IF(isConst, const) { /* Left empty. */ }
#define ABSTRACT_METHOD_IMPLEMENTATION(isConst, type, method, ...) ABSTRACT_TEMPLATE_METHOD_IMPLEMENTATION(0, (), type, method, __VA_ARGS__)

#endif WINCOPIES_MACROS_METHOD_ABSTRACT_BASE_HXX
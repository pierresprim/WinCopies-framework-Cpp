#pragma once

#ifndef WINCOPIES_UTIL_TEMPLATES_FUNC_H
#define WINCOPIES_UTIL_TEMPLATES_FUNC_H

#define SIGNED_FUNC TEMPLATE_IF_SIGNED DLLEXPORT
#define UNSIGNED_FUNC TEMPLATE_IF_UNSIGNED DLLEXPORT

#define INTEGRAL_FUNC TEMPLATE_IF_INTEGRAL DLLEXPORT
#define SIGNED_INTEGRAL_FUNC TEMPLATE_IF_SIGNED_INTEGRAL DLLEXPORT
#define UNSIGNED_INTEGRAL_FUNC TEMPLATE_IF_UNSIGNED_INTEGRAL DLLEXPORT

#define FLOAT_FUNC TEMPLATE_IF_FLOAT DLLEXPORT
#define ENUM_FUNC TEMPLATE_IF_ENUM DLLEXPORT



#define MULTI_SIGNED_FUNC(...) MULTI_TEMPLATE_IF_SIGNED(__VA_ARGS__) DLLEXPORT
#define MULTI_UNSIGNED_FUNC(...) MULTI_TEMPLATE_IF_UNSIGNED(__VA_ARGS__) DLLEXPORT

#define MULTI_INTEGRAL_FUNC(...) MULTI_TEMPLATE_IF_INTEGRAL(__VA_ARGS__) DLLEXPORT
#define MULTI_SIGNED_INTEGRAL_FUNC(...) MULTI_TEMPLATE_IF_SIGNED_INTEGRAL(__VA_ARGS__) DLLEXPORT
#define MULTI_UNSIGNED_INTEGRAL_FUNC(...) MULTI_TEMPLATE_IF_UNSIGNED_INTEGRAL(__VA_ARGS__) DLLEXPORT

#define MULTI_FLOAT_FUNC(...) MULTI_TEMPLATE_IF_FLOAT(__VA_ARGS__) DLLEXPORT
#define MULTI_ENUM_FUNC(...) MULTI_TEMPLATE_IF_ENUM(__VA_ARGS__) DLLEXPORT

#endif
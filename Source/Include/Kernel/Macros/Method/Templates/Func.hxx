#pragma once

#ifndef WINCOPIES_TEMPLATES_FUNC_HXX
#define WINCOPIES_TEMPLATES_FUNC_HXX

#define SIGNED_FUNC(...) TEMPLATE_IF_SIGNED(__VA_ARGS__) DLLEXPORT
#define UNSIGNED_FUNC(...) TEMPLATE_IF_UNSIGNED(__VA_ARGS__) DLLEXPORT

#define INTEGRAL_FUNC(...) TEMPLATE_IF_INTEGRAL(__VA_ARGS__) DLLEXPORT
#define SIGNED_INTEGRAL_FUNC(...) TEMPLATE_IF_SIGNED_INTEGRAL(__VA_ARGS__) DLLEXPORT
#define UNSIGNED_INTEGRAL_FUNC(...) TEMPLATE_IF_UNSIGNED_INTEGRAL(__VA_ARGS__) DLLEXPORT

#define FLOAT_FUNC(...) TEMPLATE_IF_FLOAT(__VA_ARGS__) DLLEXPORT
#define ENUM_FUNC(...) TEMPLATE_IF_ENUM(__VA_ARGS__) DLLEXPORT

#endif WINCOPIES_TEMPLATES_FUNC_HXX
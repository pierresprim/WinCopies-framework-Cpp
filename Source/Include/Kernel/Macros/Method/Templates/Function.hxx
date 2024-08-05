#pragma once

#ifndef WINCOPIES_TEMPLATES_FUNCTION_HXX
#define WINCOPIES_TEMPLATES_FUNCTION_HXX

#define SIGNED_FUNCTION(...) TEMPLATE_IF_SIGNED(__VA_ARGS__) FUNCTION
#define UNSIGNED_FUNCTION(...) TEMPLATE_IF_UNSIGNED(__VA_ARGS__) FUNCTION

#define INTEGRAL_FUNCTION(...) TEMPLATE_IF_INTEGRAL(__VA_ARGS__) FUNCTION
#define SIGNED_INTEGRAL_FUNCTION(...) TEMPLATE_IF_SIGNED_INTEGRAL(__VA_ARGS__) FUNCTION
#define UNSIGNED_INTEGRAL_FUNCTION(...) TEMPLATE_IF_UNSIGNED_INTEGRAL(__VA_ARGS__) FUNCTION

#define FLOAT_FUNCTION(...) TEMPLATE_IF_FLOAT(__VA_ARGS__) FUNCTION
#define ENUM_FUNCTION(...) TEMPLATE_IF_ENUM(__VA_ARGS__) FUNCTION

#endif WINCOPIES_TEMPLATES_FUNCTION_HXX
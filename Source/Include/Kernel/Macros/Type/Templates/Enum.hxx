#pragma once

#ifndef WINCOPIES_TEMPLATES_ENUM_HXX
#define WINCOPIES_TEMPLATES_ENUM_HXX

#define SIGNED_ENUM(...) TEMPLATE_IF_SIGNED(__VA_ARGS__) ENUM
#define UNSIGNED_ENUM(...) TEMPLATE_IF_UNSIGNED(__VA_ARGS__) ENUM

#define INTEGRAL_ENUM(...) TEMPLATE_IF_INTEGRAL(__VA_ARGS__) ENUM
#define SIGNED_INTEGRAL_ENUM(...) TEMPLATE_IF_SIGNED_INTEGRAL(__VA_ARGS__) ENUM
#define UNSIGNED_INTEGRAL_ENUM(...) TEMPLATE_IF_UNSIGNED_INTEGRAL(__VA_ARGS__) ENUM

#define FLOAT_ENUM(...) TEMPLATE_IF_FLOAT(__VA_ARGS__) ENUM
#define ENUM_ENUM(...) TEMPLATE_IF_ENUM(__VA_ARGS__) ENUM

#endif WINCOPIES_TEMPLATES_ENUM_HXX
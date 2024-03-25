#pragma once

#ifndef WINCOPIES_UTIL_TEMPLATES_INLINE_H
#define WINCOPIES_UTIL_TEMPLATES_INLINE_H

#define SIGNED_INLINE TEMPLATE_IF_SIGNED INLINE_METHOD
#define UNSIGNED_INLINE TEMPLATE_IF_UNSIGNED INLINE_METHOD

#define INTEGRAL_INLINE TEMPLATE_IF_INTEGRAL INLINE_METHOD
#define SIGNED_INTEGRAL_INLINE TEMPLATE_IF_SIGNED_INTEGRAL INLINE_METHOD
#define UNSIGNED_INTEGRAL_INLINE TEMPLATE_IF_UNSIGNED_INTEGRAL INLINE_METHOD

#define FLOAT_INLINE TEMPLATE_IF_FLOAT INLINE_METHOD
#define ENUM_INLINE TEMPLATE_IF_ENUM INLINE_METHOD



#define MULTI_SIGNED_INLINE(...) MULTI_TEMPLATE_IF_SIGNED(__VA_ARGS__) INLINE_METHOD
#define MULTI_UNSIGNED_INLINE(...) MULTI_TEMPLATE_IF_UNSIGNED(__VA_ARGS__) INLINE_METHOD

#define MULTI_INTEGRAL_INLINE(...) MULTI_TEMPLATE_IF_INTEGRAL(__VA_ARGS__) INLINE_METHOD
#define MULTI_SIGNED_INTEGRAL_INLINE(...) MULTI_TEMPLATE_IF_SIGNED_INTEGRAL(__VA_ARGS__) INLINE_METHOD
#define MULTI_UNSIGNED_INTEGRAL_INLINE(...) MULTI_TEMPLATE_IF_UNSIGNED_INTEGRAL(__VA_ARGS__) INLINE_METHOD

#define MULTI_FLOAT_INLINE(...) MULTI_TEMPLATE_IF_FLOAT(__VA_ARGS__) INLINE_METHOD
#define MULTI_ENUM_INLINE(...) MULTI_TEMPLATE_IF_ENUM(__VA_ARGS__) INLINE_METHOD

#endif
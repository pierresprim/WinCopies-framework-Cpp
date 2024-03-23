#pragma once

#ifndef WINCOPIES_UTIL_TEMPLATE_IF_H
#define WINCOPIES_UTIL_TEMPLATE_IF_H

using namespace WinCopies;

#define __TEMPLATE_IF(typeKind, ...) __TEMPLATE(typeKind, SINGLE_ARG(, __VA_ARGS__ = true))

#define _TEMPLATE_IF(typeKind, condition) __TEMPLATE_IF(typeKind, SINGLE_ARG(::std::enable_if_t<condition, bool>))
#define TEMPLATE_IF(condition) _TEMPLATE_IF(class, condition)

#define __TEMPLATE_IF_T(typeKind, ...) __TEMPLATE_IF(typeKind, __VA_ARGS__)
#define _TEMPLATE_IF_T(...) __TEMPLATE_IF_T(class, __VA_ARGS__<T>)

#define TEMPLATE_IF_SIGNED _TEMPLATE_IF_T(EnableIfSigned)
#define TEMPLATE_IF_UNSIGNED _TEMPLATE_IF_T(EnableIfUnsigned)

#define TEMPLATE_IF_INTEGRAL _TEMPLATE_IF_T(EnableIfIntegral)
#define TEMPLATE_IF_SIGNED_INTEGRAL _TEMPLATE_IF_T(EnableIfSignedIntegral)
#define TEMPLATE_IF_UNSIGNED_INTEGRAL _TEMPLATE_IF_T(EnableIfUnsignedIntegral)

#define TEMPLATE_IF_FLOAT _TEMPLATE_IF_T(EnableIfFloat)
#define TEMPLATE_IF_ENUM _TEMPLATE_IF_T(EnableIfEnum)



#define MULTI_TEMPLATE_IF_SIGNED(...) _TEMPLATE_IF_T(SINGLE_ARG(__VA_ARGS__, EnableIfSigned))
#define MULTI_TEMPLATE_IF_UNSIGNED(...) _TEMPLATE_IF_T(SINGLE_ARG(__VA_ARGS__, EnableIfUnsigned))

#define MULTI_TEMPLATE_IF_INTEGRAL(...) _TEMPLATE_IF_T(SINGLE_ARG(__VA_ARGS__, EnableIfIntegral))
#define MULTI_TEMPLATE_IF_SIGNED_INTEGRAL(...) _TEMPLATE_IF_T(SINGLE_ARG(__VA_ARGS__, EnableIfSignedIntegral))
#define MULTI_TEMPLATE_IF_UNSIGNED_INTEGRAL(...) _TEMPLATE_IF_T(SINGLE_ARG(__VA_ARGS__, EnableIfUnsignedIntegral))

#define MULTI_TEMPLATE_IF_FLOAT(...) _TEMPLATE_IF_T(SINGLE_ARG(__VA_ARGS__, EnableIfFloat))
#define MULTI_TEMPLATE_IF_ENUM(...) _TEMPLATE_IF_T(SINGLE_ARG(__VA_ARGS__, EnableIfEnum))

#endif
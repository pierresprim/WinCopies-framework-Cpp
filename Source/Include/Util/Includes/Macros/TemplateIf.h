#pragma once

#ifndef WINCOPIES_UTIL_TEMPLATE_IF_H
#define WINCOPIES_UTIL_TEMPLATE_IF_H

#include "../Typing/EnableIf.h"

using namespace WinCopies;

#define ___TEMPLATE_IF(typeKind, ...) __TEMPLATE(typeKind, SINGLE_ARG(, __VA_ARGS__ = true))
#define __TEMPLATE_IF(typeKind, condition, ...) ___TEMPLATE_IF(typeKind, VA_APPEND(, __VA_ARGS__) ::WinCopies::Typing::EnableIf##condition<T>)

#define _TEMPLATE_IF(typeKind, condition, ...) __TEMPLATE_IF(typeKind, SINGLE_ARG(EnableIf<condition, bool>), __VA_ARGS__)
#define TEMPLATE_IF(condition, ...) _TEMPLATE_IF(class, condition, __VA_ARGS__)

#define __TEMPLATE_IF_T(typeKind, condition, ...) __TEMPLATE_IF(typeKind, condition, __VA_ARGS__)
#define _TEMPLATE_IF_T(condition, ...) __TEMPLATE_IF_T(class, condition, __VA_ARGS__)

#define TEMPLATE_IF_SIGNED _TEMPLATE_IF_T(Signed)
#define TEMPLATE_IF_UNSIGNED _TEMPLATE_IF_T(Unsigned)

#define TEMPLATE_IF_INTEGRAL _TEMPLATE_IF_T(Integral)
#define TEMPLATE_IF_SIGNED_INTEGRAL _TEMPLATE_IF_T(SignedIntegral)
#define TEMPLATE_IF_UNSIGNED_INTEGRAL _TEMPLATE_IF_T(UnsignedIntegral)

#define TEMPLATE_IF_FLOAT _TEMPLATE_IF_T(Float)
#define TEMPLATE_IF_ENUM _TEMPLATE_IF_T(Enum)



#define MULTI_TEMPLATE_IF_SIGNED(...) _TEMPLATE_IF_T(Signed, __VA_ARGS__)
#define MULTI_TEMPLATE_IF_UNSIGNED(...) _TEMPLATE_IF_T(Unsigned, __VA_ARGS__)

#define MULTI_TEMPLATE_IF_INTEGRAL(...) _TEMPLATE_IF_T(Integral, __VA_ARGS__)
#define MULTI_TEMPLATE_IF_SIGNED_INTEGRAL(...) _TEMPLATE_IF_T(SignedIntegral, __VA_ARGS__)
#define MULTI_TEMPLATE_IF_UNSIGNED_INTEGRAL(...) _TEMPLATE_IF_T(UnsignedIntegral, __VA_ARGS__)

#define MULTI_TEMPLATE_IF_FLOAT(...) _TEMPLATE_IF_T(Float, __VA_ARGS__)
#define MULTI_TEMPLATE_IF_ENUM(...) _TEMPLATE_IF_T(Enum, __VA_ARGS__)

#endif
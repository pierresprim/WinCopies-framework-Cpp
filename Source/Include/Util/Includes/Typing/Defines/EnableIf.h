#pragma once

#ifndef WINCOPIES_UTIL_TYPING_DEFINES_ENABLE_IF_H
#define WINCOPIES_UTIL_TYPING_DEFINES_ENABLE_IF_H

#include "../../Macros/Template.h"
#include "../../../PP/CountArgs.hpp"
#include "../../../PP/Loop/ForEach.hpp"

#define __ENABLE_IF(valuePrefix, n, prefix, suffix, ...) FOR_EACH_C(SURROUND, && ::valuePrefix::prefix, suffix<T##n>, __VA_ARGS__)
#define _ENABLE_IF(prefix, value, n, type, extra, ...) SURROUND(::WinCopies::Typing::Enable, type, If)<::prefix::value<T##n> SINGLE_ARG(IF(VA_ARGS_FILLED(__VA_ARGS__), __ENABLE_IF, DISCARD)(prefix, n, __VA_ARGS__)) extra>
#define ENABLE_IF(prefix, value, ...) _ENABLE_IF(prefix, value, , Bool, , __VA_ARGS__)
#define ENABLE_TYPE_IF(prefix, value, ...) _ENABLE_IF(prefix, value, 1, , COMMA T2, __VA_ARGS__)
#define ENABLE_WHEN(prefix, value, ...) _ENABLE_IF(prefix, value, , , COMMA T, __VA_ARGS__)

#define __MAKE_ENABLE_IF(enableType, prefix, enableFor, ...) TEMPLATE using CONCATENATE(EnableIf, enableType) = ENABLE_IF(prefix, enableFor, __VA_ARGS__); \
	TEMPLATE_NC(2) using CONCATENATE(EnableTypeIf, enableType) = ENABLE_TYPE_IF(prefix, enableFor, __VA_ARGS__); \
	TEMPLATE using CONCATENATE(EnableWhen, enableType) = ENABLE_WHEN(prefix, enableFor, __VA_ARGS__);
#define _MAKE_ENABLE_IF(enableType, prefix, subprefix, suffix, enableFor, ...) __MAKE_ENABLE_IF(enableType, prefix, SURROUND(subprefix, enableFor, suffix), IF(COMPL(VA_ARGS_FILLED(__VA_ARGS__)), , subprefix, suffix, __VA_ARGS__))
#define MAKE_ENABLE_IF_STD(enableType, enableFor, ...) _MAKE_ENABLE_IF(enableType, std, is_, _v, enableFor, __VA_ARGS__)
#define MAKE_ENABLE_IF(enableFor, ...) _MAKE_ENABLE_IF(enableFor, WinCopies::Typing, , , Is##enableFor, __VA_ARGS__)



#define __ENABLE_IF_VALUE(kind, check, ...) ::WinCopies::Typing::Enable##check##kind<__VA_ARGS__>
#define _ENABLE_IF_VALUE(kind, ...) __ENABLE_IF_VALUE(kind, If, __VA_ARGS__)
#define ENABLE_IF_VALUE(...) _ENABLE_IF_VALUE(, __VA_ARGS__)



#define _ENABLE_TYPE_IF(kind, ...) __ENABLE_IF_VALUE(kind, TypeIf, __VA_ARGS__)
#define ENABLE_TYPE_IF_VALUE(...) _ENABLE_TYPE_IF(, __VA_ARGS__)



#define _ENABLE_WHEN(kind, ...) __ENABLE_IF_VALUE(kind, When, __VA_ARGS__)
#define ENABLE_WHEN_VALUE(...) _ENABLE_WHEN(, __VA_ARGS__)



#define ENABLE_IF_SIGNED(type) _ENABLE_IF_VALUE(Signed, type)
#define ENABLE_IF_UNSIGNED(type) _ENABLE_IF_VALUE(Unsigned, type)

#define ENABLE_IF_INTEGRAL(type) _ENABLE_IF_VALUE(Integral, type)
#define ENABLE_IF_SIGNED_INTEGRAL(type) _ENABLE_IF_VALUE(SignedIntegral, type)
#define ENABLE_IF_UNSIGNED_INTEGRAL(type) _ENABLE_IF_VALUE(UnsignedIntegral, type)

#define ENABLE_IF_FLOAT(type) _ENABLE_IF_VALUE(Float, type)
#define ENABLE_IF_ENUM(type) _ENABLE_IF_VALUE(Enum, type)
#define ENABLE_IF_BITWISE_ENUM(type) _ENABLE_IF_VALUE(BitwiseEnum, type)



#define ENABLE_TYPE_IF_SIGNED(typeIn, typeOut) _ENABLE_TYPE_IF(Signed, typeIn, typeOut)
#define ENABLE_TYPE_IF_UNSIGNED(type1, type2) _ENABLE_TYPE_IF(Unsigned, type1, type2)

#define ENABLE_TYPE_IF_INTEGRAL(type1, type2) _ENABLE_TYPE_IF(Integral, type1, type2)
#define ENABLE_TYPE_IF_SIGNED_INTEGRAL(type1, type2) _ENABLE_TYPE_IF(SignedIntegral, type1, type2)
#define ENABLE_TYPE_IF_UNSIGNED_INTEGRAL(type1, type2) _ENABLE_TYPE_IF(UnsignedIntegral, type1, type2)

#define ENABLE_TYPE_IF_FLOAT(type1, type2) _ENABLE_TYPE_IF(Float, type1, type2)
#define ENABLE_TYPE_IF_ENUM(type1, type2) _ENABLE_TYPE_IF(Enum, type1, type2)
#define ENABLE_TYPE_IF_BITWISE_ENUM(type1, type2) _ENABLE_TYPE_IF(BitwiseEnum, type1, type2)



#define ENABLE_WHEN_SIGNED(type) _ENABLE_WHEN(Signed, type)
#define ENABLE_WHEN_UNSIGNED(type) _ENABLE_WHEN(Unsigned, type)

#define ENABLE_WHEN_INTEGRAL(type) _ENABLE_WHEN(Integral, type)
#define ENABLE_WHEN_SIGNED_INTEGRAL(type) _ENABLE_WHEN(SignedIntegral, type)
#define ENABLE_WHEN_UNSIGNED_INTEGRAL(type) _ENABLE_WHEN(UnsignedIntegral, type)

#define ENABLE_WHEN_FLOAT(type) _ENABLE_WHEN(Float, type)
#define ENABLE_WHEN_ENUM(type) _ENABLE_WHEN(Enum, type)
#define ENABLE_WHEN_BITWISE_ENUM(type) _ENABLE_WHEN(BitwiseEnum, type)

#endif // WINCOPIES_UTIL_TYPING_DEFINES_ENABLE_IF_H
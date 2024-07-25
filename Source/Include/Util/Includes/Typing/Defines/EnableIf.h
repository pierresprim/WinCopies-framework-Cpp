#pragma once

#ifndef WINCOPIES_UTIL_TYPING_DEFINES_ENABLE_IF_H
#define WINCOPIES_UTIL_TYPING_DEFINES_ENABLE_IF_H

#include "../../Macros/Template.h"
#include "../../../PP/Loop/ForEach.hpp"
#include "../../../PP/Variadic/Variadic.hpp"

#define ____ENABLE_IF(...) , EXTRACT_AND_CALL(__VA_ARGS__)
#define ___ENABLE_IF(n, types) VA_ARGS_OR_IF_EMPTY(T##n, EXPAND(types))
#define __ENABLE_IF(valuePrefix, n, prefix, suffix, ...) FOR_EACH_C(SURROUND, && ::valuePrefix::prefix, suffix<T##n>, __VA_ARGS__)
#define _ENABLE_IF(prefix, value, n, type, extra, types, ...) SURROUND(::WinCopies::Typing::Enable, type, If)<::prefix::value<___ENABLE_IF(n, types)> SINGLE_ARG(IF_VA_ARGS(__ENABLE_IF, DISCARD, __VA_ARGS__)(prefix, n, __VA_ARGS__)) IF_VA_ARGS(____ENABLE_IF, DISCARD, EXPAND(extra))extra>



#define ENABLE_IF_TYPES(prefix, value, types, ...) _ENABLE_IF(prefix, value, , Bool, (), types, __VA_ARGS__)
#define ENABLE_TYPE_IF_TYPES(prefix, value, types, ...) _ENABLE_IF(prefix, value, 1, , (CONCATENATE, T, IF_NO_VA_ARG(2, , EXPAND(types))), types, __VA_ARGS__)
#define ENABLE_WHEN_TYPES(prefix, value, types, ...) _ENABLE_IF(prefix, value, , , (EXPAND, IF_VA_ARGS((GET_LAST_ARG(EXPAND(types))), (T), EXPAND(types))), types, __VA_ARGS__)

#define ENABLE_IF(prefix, value, ...) ENABLE_IF_TYPES(prefix, value, (), __VA_ARGS__)
#define ENABLE_TYPE_IF(prefix, value, ...) ENABLE_TYPE_IF_TYPES(prefix, value, (), __VA_ARGS__)
#define ENABLE_WHEN(prefix, value, ...) ENABLE_WHEN_TYPES(prefix, value, (), __VA_ARGS__)



#define _ENABLE_IF_TEMPLATE(...) template<TRANSCRIBE_SURROUNDED(class, , __VA_ARGS__), class T>
#define ENABLE_IF_TEMPLATE(multi, types) EXPAND(IF_VA_ARGS((IF(multi, _ENABLE_IF_TEMPLATE, TEMPLATE_EC) types), IF(multi, (TEMPLATE_NC(2)), (TEMPLATE)), EXPAND(types)))

#define ___MAKE_ENABLE_IF(enableType, prefix, enableFor, types, ...) ENABLE_IF_TEMPLATE(0, types) using CONCATENATE(EnableIf, enableType) = ENABLE_IF_TYPES(prefix, enableFor, types, __VA_ARGS__); \
	ENABLE_IF_TEMPLATE(1, types) using CONCATENATE(EnableTypeIf, enableType) = ENABLE_TYPE_IF_TYPES(prefix, enableFor, types, __VA_ARGS__); \
	ENABLE_IF_TEMPLATE(0, types) using CONCATENATE(EnableWhen, enableType) = ENABLE_WHEN_TYPES(prefix, enableFor, types, __VA_ARGS__);
#define __MAKE_ENABLE_IF(enableType, prefix, subprefix, suffix, enableFor, types, ...) ___MAKE_ENABLE_IF(enableType, prefix, SURROUND(subprefix, enableFor, suffix), types, IF(VA_ARGS_EMPTY(__VA_ARGS__), , subprefix, suffix, __VA_ARGS__))

#define _MAKE_ENABLE_IF_STD(enableType, enableFor, types, ...) __MAKE_ENABLE_IF(enableType, std, is_, _v, enableFor, types, __VA_ARGS__)
#define _MAKE_ENABLE_IF(enableFor, types, ...) __MAKE_ENABLE_IF(enableFor, WinCopies::Typing, , , Is##enableFor, types, __VA_ARGS__)



#define MAKE_ENABLE_IF_STD(enableType, enableFor, ...) _MAKE_ENABLE_IF_STD(enableType, enableFor, (), __VA_ARGS__)
#define MAKE_ENABLE_IF(enableFor, ...) _MAKE_ENABLE_IF(enableFor, (), __VA_ARGS__)

#define MAKE_ENABLE_IF_TYPES_STD(enableType, enableFor, types, ...) _MAKE_ENABLE_IF_STD(enableType, enableFor, types, __VA_ARGS__)
#define MAKE_ENABLE_IF_TYPES(enableFor, types, ...) _MAKE_ENABLE_IF(enableFor, types, __VA_ARGS__)



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

#define ENABLE_IF_BASE_OF(base, derived) _ENABLE_IF_VALUE(BaseOf, base, derived)



#define ENABLE_TYPE_IF_SIGNED(type1, type2) _ENABLE_TYPE_IF(Signed, type1, type2)
#define ENABLE_TYPE_IF_UNSIGNED(type1, type2) _ENABLE_TYPE_IF(Unsigned, type1, type2)

#define ENABLE_TYPE_IF_INTEGRAL(type1, type2) _ENABLE_TYPE_IF(Integral, type1, type2)
#define ENABLE_TYPE_IF_SIGNED_INTEGRAL(type1, type2) _ENABLE_TYPE_IF(SignedIntegral, type1, type2)
#define ENABLE_TYPE_IF_UNSIGNED_INTEGRAL(type1, type2) _ENABLE_TYPE_IF(UnsignedIntegral, type1, type2)

#define ENABLE_TYPE_IF_FLOAT(type1, type2) _ENABLE_TYPE_IF(Float, type1, type2)
#define ENABLE_TYPE_IF_ENUM(type1, type2) _ENABLE_TYPE_IF(Enum, type1, type2)
#define ENABLE_TYPE_IF_BITWISE_ENUM(type1, type2) _ENABLE_TYPE_IF(BitwiseEnum, type1, type2)

#define ENABLE_TYPE_IF_BASE_OF(base, derived, type) _ENABLE_TYPE_IF(BaseOf, base, derived, type)



#define ENABLE_WHEN_SIGNED(type) _ENABLE_WHEN(Signed, type)
#define ENABLE_WHEN_UNSIGNED(type) _ENABLE_WHEN(Unsigned, type)

#define ENABLE_WHEN_INTEGRAL(type) _ENABLE_WHEN(Integral, type)
#define ENABLE_WHEN_SIGNED_INTEGRAL(type) _ENABLE_WHEN(SignedIntegral, type)
#define ENABLE_WHEN_UNSIGNED_INTEGRAL(type) _ENABLE_WHEN(UnsignedIntegral, type)

#define ENABLE_WHEN_FLOAT(type) _ENABLE_WHEN(Float, type)
#define ENABLE_WHEN_ENUM(type) _ENABLE_WHEN(Enum, type)
#define ENABLE_WHEN_BITWISE_ENUM(type) _ENABLE_WHEN(BitwiseEnum, type)

#define ENABLE_WHEN_BASE_OF(base, derived) _ENABLE_WHEN(BaseOf, base, derived)

#endif // WINCOPIES_UTIL_TYPING_DEFINES_ENABLE_IF_H
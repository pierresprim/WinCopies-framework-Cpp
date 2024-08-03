#pragma once

#ifndef WINCOPIES_TYPING_DEFINES_CONSTS_H
#define WINCOPIES_TYPING_DEFINES_CONSTS_H

#define IS_TYPE(condition, ...) ::WinCopies::Typing::Is##condition<__VA_ARGS__>

#define IS_SIGNED(type) IS_TYPE(Signed, type)
#define IS_UNSIGNED(type) IS_TYPE(Unsigned, type)

#define IS_INTEGRAL(type) IS_TYPE(Integral, type)
#define IS_SIGNED_INTEGRAL(type) IS_TYPE(SignedIntegral, type)
#define IS_UNSIGNED_INTEGRAL(type) IS_TYPE(UnsignedIntegral, type)

#define IS_FLOAT(type) IS_TYPE(Float, type)

#define IS_ENUM(type) IS_TYPE(Enum, type)
#define IS_BITWISE_ENUM(type) IS_TYPE(BitwiseEnum, type)
#define IS_UNSIGNED_ENUM(type) IS_TYPE(UnsignedEnum, type)

#define IS_BASE_OF(base, derived) IS_TYPE(BaseOf, base, derived)

#endif WINCOPIES_TYPING_DEFINES_CONSTS_H
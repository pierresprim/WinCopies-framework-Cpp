#pragma once

#ifndef WINCOPIES_UTIL_TYPING_DEFINES_CONSTS_H
#define WINCOPIES_UTIL_TYPING_DEFINES_CONSTS_H

#define IS_TYPE(type, condition) ::WinCopies::Typing::Is##condition<type>

#define IS_SIGNED(type) IS_TYPE(type, Signed)
#define IS_UNSIGNED(type) IS_TYPE(type, Unsigned)

#define IS_INTEGRAL(type) IS_TYPE(type, Integral)
#define IS_SIGNED_INTEGRAL(type) IS_TYPE(type, SignedIntegral)
#define IS_UNSIGNED_INTEGRAL(type) IS_TYPE(type, UnsignedIntegral)

#define IS_FLOAT(type) IS_TYPE(type, Float)
#define IS_ENUM(type) IS_TYPE(type, Enum)

#endif // WINCOPIES_UTIL_TYPING_DEFINES_CONSTS_H
#pragma once

#ifndef WINCOPIES_UTIL_MACROS_TYPE_H
#define WINCOPIES_UTIL_MACROS_TYPE_H

#include "../Environment.h"

// Type kinds

#define BASE_INTERFACE public virtual

#define INTERFACE_CLASS(interfaceName) CLASS interfaceName ABSTRACT
#define CLASS class DLLEXPORT
#define STRUCT struct DLLEXPORT
#define ENUM enum CLASS

#define SHARED_TYPE(typeKind, typeName, type) typeKind typeName : public ::std::enable_shared_from_this<typeName type>
#define _SHARED_CLASS(className, type) SHARED_TYPE(CLASS, className, type)

#define SHARED_CLASS(className) _SHARED_CLASS(className, )
#define SHARED_TEMPLATE(className) TEMPLATE _SHARED_CLASS(className, <T>)
#define SHARED_TEMPLATE_CLASS(className) TEMPLATE SHARED_TYPE(class, className, <T>)

#include "Templates/Enum.h"
#include "Templates/Struct.h"
#include "Templates/Interface.h"
#include "Templates/Class.h"

#define _TO_UNDERLYING(value, methodNamespace) methodNamespace to_underlying(value)

#ifdef WINDOWS
#if !_HAS_CXX23
template <class enum_t>
constexpr ::std::underlying_type_t<enum_t> to_underlying(enum_t value) noexcept {
	return static_cast<::std::underlying_type_t<enum_t>>(value);
}

#define TO_UNDERLYING(value) _TO_UNDERLYING(value, )
#endif
#endif

#ifndef TO_UNDERLYING
#define TO_UNDERLYING(value) _TO_UNDERLYING(value, ::std::)
#endif

#define ENUM_CAST(enumType, enumValue) static_cast<std::underlying_type_t<enumType>>(enumValue)

#define IS_ENUM(type) ::std::is_enum_v<type>

#endif
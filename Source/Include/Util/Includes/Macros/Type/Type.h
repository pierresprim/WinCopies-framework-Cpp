#pragma once

#ifndef WINCOPIES_UTIL_MACROS_TYPE_H
#define WINCOPIES_UTIL_MACROS_TYPE_H

#include "../../Environment.h"

// Type kinds

#define BASE_INTERFACE public virtual

#define CLASS class DLLEXPORT
#define INTERFACE_CLASS(interfaceName) CLASS interfaceName ABSTRACT
#define STRUCT struct DLLEXPORT
#define ENUM enum CLASS
#define CONST_EXPR DLLEXPORT constexpr

#define SHARED_TYPE(typeKind, typeName, type) typeKind typeName : public ::std::enable_shared_from_this<typeName type>
#define _SHARED_CLASS(className, type) SHARED_TYPE(CLASS, className, type)

#define SHARED_CLASS(className) _SHARED_CLASS(className, )
#define SHARED_TEMPLATE(className) TEMPLATE _SHARED_CLASS(className, <T>)
#define SHARED_TEMPLATE_CLASS(className) TEMPLATE SHARED_TYPE(class, className, <T>)

#define ENUM_HEADER(name, type) ENUM name : type

#include "Templates/Enum.h"
#include "Templates/Struct.h"
#include "Templates/Interface.h"
#include "Templates/Class.h"

#endif
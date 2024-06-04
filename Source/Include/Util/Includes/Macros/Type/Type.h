#pragma once

#ifndef WINCOPIES_UTIL_MACROS_TYPE_H
#define WINCOPIES_UTIL_MACROS_TYPE_H

#include "../../../PP/Loop/ForEach.hpp"
#include "../Template.h"
#include "../../Environment.h"
#include "../TemplateIf.h"
#include "TypeBase.h"

// Type kinds

#define BASE_INTERFACE public virtual

#define _BASE_INTERFACES(suffix, ...) BASE_INTERFACE FIRST_ARG(__VA_ARGS__)suffix FOR_EACH_C(TRANSCRIBE_ARGS_CS, BASE_INTERFACE, suffix, ALL_BUT_FIRST_ARG(__VA_ARGS__))
#define BASE_INTERFACES(...) _BASE_INTERFACES(, __VA_ARGS__)
#define BASE_TEMPLATES(...) _BASE_INTERFACES(<T>, __VA_ARGS__)

#define _BASE_TEMPLATE(name, ...) BASE_INTERFACE name<__VA_ARGS__>

#define BASE_TEMPLATE(name) _BASE_TEMPLATE(name, T)
#define BASE_TEMPLATE_N(name, count) _BASE_TEMPLATE(name, MAKE_TEMPLATE_PARAMS(count, , ))

#define CLASS class DLLEXPORT
#define INTERFACE_CLASS(interfaceName) CLASS interfaceName ABSTRACT
#define STRUCT struct DLLEXPORT
#define ENUM enum CLASS

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
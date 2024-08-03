#pragma once

#ifndef WINCOPIES_MACROS_TYPE_H
#define WINCOPIES_MACROS_TYPE_H

#include "../../../PP/Loop/ForEach.hpp"
#include "../Template.h"
#include "../../Environment.h"
#include "../TemplateIf.h"
#include "../../../Interface.h"

#define BASE_INTERFACE public virtual

#define __BASE_INTERFACES(suffix, macro, ...) SURROUND(TRANSCRIBE, macro, _SURROUNDED)(BASE_INTERFACE, suffix, __VA_ARGS__)
#define _BASE_INTERFACES(areArgsTokens, suffix, ...) __BASE_INTERFACES(suffix, IF(areArgsTokens, _TOKENS), __VA_ARGS__)

#define BASE_INTERFACES(...) _BASE_INTERFACES(0, , __VA_ARGS__)
#define BASE_TEMPLATES(...) _BASE_INTERFACES(0, <T>, __VA_ARGS__)

#define BASE_INTERFACE_TEMPLATES(...) _BASE_INTERFACES(1, , __VA_ARGS__)

#define _BASE_TEMPLATE(name, ...) BASE_INTERFACE name<__VA_ARGS__>

#define BASE_TEMPLATE(name) _BASE_TEMPLATE(name, T)
#define BASE_TEMPLATE_N(count, name) _BASE_TEMPLATE(name, TEMPLATE_PARAMS(count))

#define _STATIC_CLASS(local, name) IF(local, class name ABSTRACT, INTERFACE_TYPE(name)) final { STATIC_CLASS_C_D_TOR(name)
#define STATIC_CLASS(name) _STATIC_CLASS(0, name)
#define LOCAL_STATIC_CLASS(name) _STATIC_CLASS(1, name)

#define _INTERFACE_CLASS(addCtorAndDtor, name, ...) INTERFACE_TYPE(name) : BASE_INTERFACE ::WinCopies::Interface VA_OPT(COMMA, __VA_ARGS__) __VA_ARGS__ IF(addCtorAndDtor, { INTERFACE_C_D_TOR(name))
#define INTERFACE_CLASS(name, ...) _INTERFACE_CLASS(1, name, __VA_ARGS__)
#define STRUCT struct DLLEXPORT
#define ENUM enum CLASS

#define TEMPLATE_INTERFACE(name, macro, ...) macro() INTERFACE_CLASS(name, __VA_ARGS__)
#define TEMPLATE_INTERFACE_NC(name, n, ...) TEMPLATE_NC(n) INTERFACE_CLASS(name, __VA_ARGS__)
#define TEMPLATE_INTERFACE_C(name, ...) TEMPLATE INTERFACE_CLASS(name, __VA_ARGS__)

#define CONSTRAINED_INTERFACE_NC(name, n, ...) TEMPLATE_NC(n, __VA_ARGS__) INTERFACE_CLASS(name)

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
#include "Templates/Template.h"

#endif WINCOPIES_MACROS_TYPE_H
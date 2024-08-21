#pragma once

#ifndef WINCOPIES_MACROS_TYPE_HXX
#define WINCOPIES_MACROS_TYPE_HXX

#include "../../../Environment.h"

#include "../../../PP/Loop/ForEach.hpp"

#include "../TemplateIf.hxx"
#include "TypeBase.hxx"

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

#define STRUCT struct DLLEXPORT
#define ENUM enum CLASS

#define SHARED_TYPE(typeKind, typeName, type) typeKind typeName : public ::std::enable_shared_from_this<typeName type>
#define _SHARED_CLASS(className, type) SHARED_TYPE(CLASS, className, type)

#define SHARED_CLASS(className) _SHARED_CLASS(className, )
#define SHARED_TEMPLATE(className) TEMPLATE _SHARED_CLASS(className, <T>)
#define SHARED_TEMPLATE_CLASS(className) TEMPLATE SHARED_TYPE(class, className, <T>)

#define ENUM_HEADER(name, type) ENUM name : type

#define _INTERFACE_DESTRUCTORS(prefix, macro, ...) FOR_EACH(SURROUND_SPACED, prefix, macro, , __VA_ARGS__)

#define INTERFACE_DESTRUCTORS(...) _INTERFACE_DESTRUCTORS(, ABSTRACT_DESTRUCTOR, __VA_ARGS__)
#define TEMPLATE_DESTRUCTORS(...) _INTERFACE_DESTRUCTORS(TEMPLATE, ABSTRACT_TEMPLATE_DESTRUCTOR, __VA_ARGS__)
#define SELECTOR_DESTRUCTORS(...) SELECTOR_TEMPLATE _INTERFACE_DESTRUCTORS(, ABSTRACT_SELECTOR_DESTRUCTOR, __VA_ARGS__)

#include "Templates/Enum.hxx"
#include "Templates/Struct.hxx"
#include "Templates/Interface.hxx"
#include "Templates/Class.hxx"
#include "Templates/Template.hxx"

#endif WINCOPIES_MACROS_TYPE_HXX
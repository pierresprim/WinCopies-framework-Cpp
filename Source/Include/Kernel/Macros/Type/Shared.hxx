#pragma once

#ifndef WINCOPIES_MACROS_SHARED_HXX
#define WINCOPIES_MACROS_SHARED_HXX

#include "../../../Core/Typing/Shared.h"

#define _SHARED_TYPE(baseType, ...) ::WinCopies::Typing::Shared##baseType SURROUND_VA_ARGS(<, >, __VA_ARGS__)

#define SHARED_TYPE(...) _SHARED_TYPE(Type, __VA_ARGS__)
#define SHARED_BASE(...) _SHARED_TYPE(Base, __VA_ARGS__)

#define _SHARED_INTERFACE_TYPE(...) _SHARED_TYPE(Interface)
#define SHARED_INTERFACE _SHARED_INTERFACE_TYPE()

#define __SHARED_FROM_THIS(isVirtual, prefix, baseType, ...) public IF(isVirtual, virtual) SURROUND(prefix, SHARED_, baseType)(__VA_ARGS__)
#define _SHARED_FROM_THIS(baseType, ...) __SHARED_FROM_THIS(0, , baseType, __VA_ARGS__)

#define SHARED_FROM_THIS(...) _SHARED_FROM_THIS(TYPE, __VA_ARGS__)
#define SHARED_FROM_BASE(...) _SHARED_FROM_THIS(BASE, __VA_ARGS__)
#define SHARED_FROM_INTERFACE __SHARED_FROM_THIS(1, _, INTERFACE_TYPE)

#define SHARED_TYPE_HEADER(typeKind, typeName, ...) typeKind typeName : SHARED_FROM_THIS(typeName SURROUND_VA_ARGS(<, >, __VA_ARGS__))

#define SHARED_CLASS(className, ...) SHARED_TYPE_HEADER(CLASS, className, __VA_ARGS__)
#define SHARED_TEMPLATE(className) TEMPLATE SHARED_CLASS(className, T)
#define SHARED_TEMPLATE_CLASS(className) TEMPLATE SHARED_TYPE_HEADER(class, className, T)
#endif
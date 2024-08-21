#pragma once

#ifndef WINCOPIES_MACROS_TYPE_INTERFACE_HXX
#define WINCOPIES_MACROS_TYPE_INTERFACE_HXX

#include "../../../Util/Interface.h"

#define _INTERFACE_STRUCT(name) CLASS name
#define __INTERFACE_CLASS(name) INTERFACE_TYPE(name)

#define IINTERFACE_CLASS(forPtrUse, addCtorAndDtor, name, ...) IF(forPtrUse, __INTERFACE_CLASS, _INTERFACE_STRUCT)(name) : BASE_INTERFACE ::WinCopies::Interface VA_OPT(COMMA, __VA_ARGS__) __VA_ARGS__ IF(addCtorAndDtor, { INTERFACE_C_D_TOR(name))

#define INTERFACE_STRUCT(name, ...) IINTERFACE_CLASS(0, 1, name, __VA_ARGS__)
#define INTERFACE_CLASS(name, ...) IINTERFACE_CLASS(1, 1, name, __VA_ARGS__)

#define _TEMPLATE_INTERFACE(forPtrUse, name, macro, ...) macro() IINTERFACE_CLASS(forPtrUse, 1, name, __VA_ARGS__)

#define TEMPLATE_INTERFACE(name, macro, ...) _TEMPLATE_INTERFACE(1, name, macro, __VA_ARGS__)
#define TEMPLATE_INTERFACE_NC(name, n, ...) TEMPLATE_NC(n) INTERFACE_CLASS(name, __VA_ARGS__)
#define TEMPLATE_INTERFACE_C(name, ...) TEMPLATE INTERFACE_CLASS(name, __VA_ARGS__)

#define CONSTRAINED_INTERFACE_NC(name, n, ...) TEMPLATE_NC(n, __VA_ARGS__) INTERFACE_CLASS(name)

#define TEMPLATE_INTERFACE_STRUCT(name, macro, ...) _TEMPLATE_INTERFACE(0, name, macro, __VA_ARGS__)
#define TEMPLATE_INTERFACE_NS(name, n, ...) TEMPLATE_NC(n) INTERFACE_STRUCT(name, __VA_ARGS__)
#define TEMPLATE_INTERFACE_S(name, ...) TEMPLATE INTERFACE_STRUCT(name, __VA_ARGS__)

#define CONSTRAINED_INTERFACE_NS(name, n, ...) TEMPLATE_NC(n, __VA_ARGS__) INTERFACE_STRUCT(name)

#endif WINCOPIES_MACROS_TYPE_INTERFACE_HXX
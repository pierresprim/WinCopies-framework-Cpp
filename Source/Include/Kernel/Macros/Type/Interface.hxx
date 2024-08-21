#pragma once

#ifndef WINCOPIES_MACROS_TYPE_INTERFACE_HXX
#define WINCOPIES_MACROS_TYPE_INTERFACE_HXX

#include "../../../Util/Interface.h"

#define _INTERFACE_CLASS(addCtorAndDtor, name, ...) INTERFACE_TYPE(name) : BASE_INTERFACE ::WinCopies::Interface VA_OPT(COMMA, __VA_ARGS__) __VA_ARGS__ IF(addCtorAndDtor, { INTERFACE_C_D_TOR(name))
#define INTERFACE_CLASS(name, ...) _INTERFACE_CLASS(1, name, __VA_ARGS__)

#define TEMPLATE_INTERFACE(name, macro, ...) macro() INTERFACE_CLASS(name, __VA_ARGS__)
#define TEMPLATE_INTERFACE_NC(name, n, ...) TEMPLATE_NC(n) INTERFACE_CLASS(name, __VA_ARGS__)
#define TEMPLATE_INTERFACE_C(name, ...) TEMPLATE INTERFACE_CLASS(name, __VA_ARGS__)

#define CONSTRAINED_INTERFACE_NC(name, n, ...) TEMPLATE_NC(n, __VA_ARGS__) INTERFACE_CLASS(name)

#endif WINCOPIES_MACROS_TYPE_INTERFACE_HXX
#pragma once

#ifndef WINCOPIES_TEMPLATES_INTERFACE_H
#define WINCOPIES_TEMPLATES_INTERFACE_H

#define SIGNED_INTERFACE(name, ...) TEMPLATE_IF_SIGNED(__VA_ARGS__) INTERFACE_CLASS(name)
#define UNSIGNED_INTERFACE(name, ...) TEMPLATE_IF_UNSIGNED(__VA_ARGS__) INTERFACE_CLASS(name)

#define INTEGRAL_INTERFACE(name, ...) TEMPLATE_IF_INTEGRAL(__VA_ARGS__) INTERFACE_CLASS
#define SIGNED_INTEGRAL_INTERFACE(name, ...) TEMPLATE_IF_SIGNED_INTEGRAL(__VA_ARGS__) INTERFACE_CLASS(name)
#define UNSIGNED_INTEGRAL_INTERFACE(name, ...) TEMPLATE_IF_UNSIGNED_INTEGRAL(__VA_ARGS__) INTERFACE_CLASS(name)

#define FLOAT_INTERFACE(name, ...) TEMPLATE_IF_FLOAT(__VA_ARGS__) INTERFACE_CLASS(name)
#define ENUM_INTERFACE(name, ...) TEMPLATE_IF_ENUM(__VA_ARGS__) INTERFACE_CLASS(name)

#endif WINCOPIES_TEMPLATES_INTERFACE_H
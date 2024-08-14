#pragma once

#ifndef WINCOPIES_MACROS_TYPE_BASE_HXX
#define WINCOPIES_MACROS_TYPE_BASE_HXX

#include "../../../Environment.h"

#include "../Method/AbstractBase.hxx"
#include "../Method/Inline.hxx"
#include "../Method/MethodBase.hxx"
#include "../Template.hxx"

#define CONST_EXPR DLLEXPORT constexpr

#define DEFAULT_C_D_TOR(name, modifier, implementation, ...) modifier name() __VA_ARGS__ implementation;

#define CONSTRUCTOR(name, ...) name::name(__VA_ARGS__)
#define DESTRUCTOR(name) name::~name()

#define DEFAULT_CONSTRUCTOR(name, implementation, ...) DEFAULT_C_D_TOR(name, , implementation, __VA_ARGS__)
#define DEFAULT_DESTRUCTOR(name, implementation, ...) DEFAULT_C_D_TOR(~name, virtual, implementation, __VA_ARGS__)

#define INTERFACE_CONSTRUCTOR(name) protected: explicit DEFAULT_CONSTRUCTOR(name, = default)
#define _INTERFACE_DESTRUCTOR(name, _override, ...) public: DEFAULT_DESTRUCTOR(name, IF(_override, override) = 0, __VA_ARGS__)
#define INTERFACE_DESTRUCTOR(name, ...) _INTERFACE_DESTRUCTOR(name, 1, __VA_ARGS__)

#define _ABSTRACT_DESTRUCTOR(isTemplate, name, ...) ABSTRACT_METHOD_IMPLEMENTATION(0, name IF(isTemplate, <T>), ~name, __VA_ARGS__)

#define ABSTRACT_DESTRUCTOR(name, ...) _ABSTRACT_DESTRUCTOR(0, name, __VA_ARGS__)
#define ABSTRACT_TEMPLATE_DESTRUCTOR(name, ...) _ABSTRACT_DESTRUCTOR(1, name, __VA_ARGS__)
#define ABSTRACT_SELECTOR_DESTRUCTOR(name, ...) ABSTRACT_TEMPLATE_METHOD_IMPLEMENTATION(0, (SELECTOR_TEMPLATE_ARGS), name, ~name, __VA_ARGS__)

#define INTERFACE_C_D_TOR(name, ...) INTERFACE_CONSTRUCTOR(name) INTERFACE_DESTRUCTOR(name, __VA_ARGS__)

#define SCOPED_INTERFACE_C_D_TOR(name, ...) { INTERFACE_CONSTRUCTOR(name) _INTERFACE_DESTRUCTOR(name, 0, __VA_ARGS__) };

#define _STATIC_CLASS_C_D_TOR(name, prefix, ...) SURROUND(DEFAULT_, prefix, STRUCTOR)(name, delete, __VA_ARGS__)

#define STATIC_CLASS_CONSTRUCTOR(name) _STATIC_CLASS_C_D_TOR(name, CON)
#define STATIC_CLASS_DESTRUCTOR(name) _STATIC_CLASS_C_D_TOR(name, DE, final)

#define STATIC_CLASS_C_D_TOR(name) private: STATIC_CLASS_CONSTRUCTOR(name) STATIC_CLASS_DESTRUCTOR(name)

#define CLASS class DLLEXPORT
#define INTERFACE_TYPE(name) CLASS name ABSTRACT

#define __TYPE_INITIALIZATION(name, baseTypeName, base, ...) FFIELDS_INITIALIZER(name, (), (), (baseTypeName, EXPAND(base)), __VA_ARGS__)
#define _TYPE_INITIALIZATION(name, baseTypeName, ...) __TYPE_INITIALIZATION(name, baseTypeName, FIRST_ARG(__VA_ARGS__), ALL_BUT_FIRST_ARG(__VA_ARGS__))
#define TYPE_INITIALIZATION(name, baseTypeName, ptrType, _namespace, genericTypeArgument, _array, ...) _TYPE_INITIALIZATION(name, baseTypeName, MMAKE_PARAMETERS(ptrType, _namespace, genericTypeArgument, _array, __VA_ARGS__))

#endif WINCOPIES_MACROS_TYPE_BASE_HXX
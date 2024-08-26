#pragma once

#ifndef WINCOPIES_MACROS_METHOD_PROPERTY_HXX
#define WINCOPIES_MACROS_METHOD_PROPERTY_HXX

#include "../../../PP/Variadic/UtilBase.hpp"

#define _PROPERTY_GET(type) type, Get##type
#define _PROPERTY_IS(name) bool, Is##name
#define _PROPERTY_HAS(name) bool, Has##name

#define MAKE_PROPERTY_DEFINITION(value, accessorType) PRINT_FIRST_TWO_ARGS(CONCATENATE(_PROPERTY_, accessorType)(value))

#define PROPERTY_GET(type) MAKE_PROPERTY_DEFINITION(type, GET)
#define PROPERTY_IS(name) MAKE_PROPERTY_DEFINITION(name, IS)
#define PROPERTY_HAS(name) MAKE_PROPERTY_DEFINITION(name, HAS)

#define _PROPERTIES(propertyKind, renderer, ...) PRINT_RENDERED_SUFFIXED(; , renderer, RENDER_ARGS(PROPERTY_##propertyKind, __VA_ARGS__))

#define PROPERTIES_GET(renderer, ...) _PROPERTIES(GET, renderer, __VA_ARGS__)
#define PROPERTIES_IS(renderer, ...) _PROPERTIES(IS, renderer, __VA_ARGS__)
#define PROPERTIES_HAS(renderer, ...) _PROPERTIES(HAS, renderer, __VA_ARGS__)

#endif WINCOPIES_MACROS_METHOD_PROPERTY_HXX
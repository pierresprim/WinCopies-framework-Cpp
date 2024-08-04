#pragma once

#ifndef WINCOPIES_MACROS_METHOD_PROPERTY_H
#define WINCOPIES_MACROS_METHOD_PROPERTY_H

#include "../../../PP/Variadic/UtilBase.hpp"

#define _PROPERTY_GET(type) type, Get##type
#define _PROPERTY_IS(name) bool, Is##name

#define MAKE_PROPERTY_DEFINITION(value, accessorType) PRINT_FIRST_TWO_ARGS(CONCATENATE(_PROPERTY_, accessorType)(value))

#define PROPERTY_GET(type) MAKE_PROPERTY_DEFINITION(type, GET)
#define PROPERTY_IS(name) MAKE_PROPERTY_DEFINITION(name, IS)

#endif WINCOPIES_MACROS_METHOD_PROPERTY_H
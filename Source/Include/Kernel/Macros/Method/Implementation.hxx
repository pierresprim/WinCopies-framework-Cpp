#pragma once

#ifndef WINCOPIES_MACROS_METHOD_DEFINITION_HXX
#define WINCOPIES_MACROS_METHOD_DEFINITION_HXX

#include "../../../PP/MiscBase.hpp"

#define _METHOD_DEFINITION(name, implementation, modifiers, ...) name(__VA_ARGS__) EXPAND(modifiers) = implementation



#define _ABSTRACT_METHOD_DEFINITION(name, modifiers, ...) _METHOD_DEFINITION(name, 0, modifiers, __VA_ARGS__)
#define ABSTRACT_METHOD_DEFINITION(name, modifiers, ...) virtual _ABSTRACT_METHOD_DEFINITION(name, modifiers, __VA_ARGS__)

#define DEFAULT_METHOD_DEFINITION(name, modifiers, ...) _METHOD_DEFINITION(name, default, modifiers, __VA_ARGS__)
#define REMOVED_METHOD_DEFINITION(name) _METHOD_DEFINITION(name, delete, ())



#define __DESTRUCTOR_DEFINITION(_override, name, macro) virtual macro(~name, (IF(_override, override)))
#define _DESTRUCTOR_DEFINITION(_override, name, macro) __DESTRUCTOR_DEFINITION(_override, name, CONCATENATE(macro, METHOD_DEFINITION))

#define ABSTRACT_DESTRUCTOR_DEFINITION(name) _DESTRUCTOR_DEFINITION(0, name, _ABSTRACT_)
#define VIRTUAL_DESTRUCTOR_DEFINITION(name) _DESTRUCTOR_DEFINITION(1, name, _ABSTRACT_)

#define DEFAULT_DESTRUCTOR_DEFINITION(name) _DESTRUCTOR_DEFINITION(1, name, DEFAULT_)
#define STRUCT_DESTRUCTOR_DEFINITION(name) _DESTRUCTOR_DEFINITION(0, name, DEFAULT_)

#endif WINCOPIES_MACROS_METHOD_DEFINITION_HXX
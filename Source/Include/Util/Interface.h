#pragma once

#ifndef WINCOPIES_INTERFACE
#define WINCOPIES_INTERFACE

#include "../../Include/Util/Includes/Macros/Type/TypeBase.h"

#define BASE_INTERFACE_CLASS(name) INTERFACE_TYPE(name) SCOPED_INTERFACE_C_D_TOR(name)

namespace WinCopies
{
	BASE_INTERFACE_CLASS(Interface)

	Interface::~Interface() { /* Left empty. */ }
}

#undef BASE_INTERFACE_CLASS

#endif // WINCOPIES_INTERFACE
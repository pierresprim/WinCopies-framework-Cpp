#pragma once

#ifndef WINCOPIES_REFLECTION_MACROS_H
#define WINCOPIES_REFLECTION_MACROS_H

#include "../../PP/MiscBase.hpp"

#define VIRTUALITY_0
#define VIRTUALITY_1 = 0
#define VIRTUALITY_2 override
#define VIRTUALITY_3 final

#define METHOD_VIRTUALITY(n) CONCATENATE(VIRTUALITY_, n)

#endif WINCOPIES_REFLECTION_MACROS_H
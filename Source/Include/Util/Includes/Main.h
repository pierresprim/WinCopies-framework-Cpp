#pragma once

#ifndef WINCOPIES_UTIL_MAIN_H
#define WINCOPIES_UTIL_MAIN_H

#include "Environment.h"

#define USING_TEMPLATE_FUNCTION(highLevelF, lowLevelF) \
template<typename... Args> \
inline auto highLevelF(Args&&... args) -> decltype(lowLevelF(std::forward<Args>(args)...)) \
{ \
    return lowLevelF(std::forward<Args>(args)...); \
}

#endif // WINCOPIES_UTIL_MAIN_H
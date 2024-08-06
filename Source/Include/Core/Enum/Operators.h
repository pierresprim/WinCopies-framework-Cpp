#pragma once

#ifndef WINCOPIES_UTIL_ENUM_OPERATORS_HPP
#define WINCOPIES_UTIL_ENUM_OPERATORS_HPP

#include "../../Kernel/Enum/Operators.hxx"
#include "../../Kernel/Typing/Enum.hxx"

#include "../Typing/EnableIf.h"

ENUM_COMPARISON_OPERATOR(== )
ENUM_COMPARISON_OPERATOR2(== )

ENUM_COMPARISON_OPERATOR(!= )
ENUM_COMPARISON_OPERATOR2(!= )

#endif // WINCOPIES_UTIL_ENUM_OPERATORS_HPP
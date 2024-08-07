#pragma once

#ifndef WINCOPIES_ENUM_OPERATORS_H
#define WINCOPIES_ENUM_OPERATORS_H

#include "../../Kernel/Enum/Operators.hxx"
#include "../../Kernel/Typing/Enum.hxx"

#include "../Typing/EnableIf.h"

ENUM_COMPARISON_OPERATOR(== )
ENUM_COMPARISON_OPERATOR2(== )

ENUM_COMPARISON_OPERATOR(!= )
ENUM_COMPARISON_OPERATOR2(!= )

#endif WINCOPIES_ENUM_OPERATORS_H
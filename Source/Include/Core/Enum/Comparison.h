#pragma once

#ifndef WINCOPIES_ENUM_COMPARISON_H
#define WINCOPIES_ENUM_COMPARISON_H

#include "../../Kernel/Enum/Arithmetic.hxx"

#include "Operators.h"

ENUM_COMPARISON_OPERATOR(< )
ENUM_COMPARISON_OPERATOR2(< )

ENUM_COMPARISON_OPERATOR(<= )
ENUM_COMPARISON_OPERATOR2(<= )

ENUM_COMPARISON_OPERATOR(> )
ENUM_COMPARISON_OPERATOR2(> )

ENUM_COMPARISON_OPERATOR(>= )
ENUM_COMPARISON_OPERATOR2(>= )

#endif WINCOPIES_ENUM_COMPARISON_H
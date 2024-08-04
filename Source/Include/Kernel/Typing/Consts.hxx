#pragma once

#ifndef WINCOPIES_KERNEL_TYPING_CONSTS_H
#define WINCOPIES_KERNEL_TYPING_CONSTS_H

#include <type_traits>
#include "../Macros/Template.hxx"
#include "../Macros/Type/TypeBase.hxx"
#include "Defines/Consts.hxx"
#include "Enum.h"

#define __ENABLE_IF_BOOL_CONDITION inline CONST_EXPR bool
#define _ENABLE_IF_BOOL_CONDITION(...) TEMPLATE_EC(__VA_ARGS__) __ENABLE_IF_BOOL_CONDITION
#define ENABLE_IF_BOOL_CONDITION TEMPLATE __ENABLE_IF_BOOL_CONDITION

#endif WINCOPIES_KERNEL_TYPING_CONSTS_H
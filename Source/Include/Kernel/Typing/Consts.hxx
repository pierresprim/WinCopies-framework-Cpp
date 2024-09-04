#pragma once

#ifndef WINCOPIES_KERNEL_TYPING_CONSTS_HXX
#define WINCOPIES_KERNEL_TYPING_CONSTS_HXX

#include <type_traits>

#include "../Macros/Template.hxx"
#include "../Macros/Type/TypeBase.hxx"

#include "Consts.inc.hxx"
#include "Enum.hxx"

#define __ENABLE_IF_BOOL_CONDITION inline CONST_EXPR bool
#define _ENABLE_IF_BOOL_CONDITION(...) TEMPLATE_EC(__VA_ARGS__) __ENABLE_IF_BOOL_CONDITION
#define ENABLE_IF_BOOL_CONDITION TEMPLATE __ENABLE_IF_BOOL_CONDITION

#endif WINCOPIES_KERNEL_TYPING_CONSTS_HXX
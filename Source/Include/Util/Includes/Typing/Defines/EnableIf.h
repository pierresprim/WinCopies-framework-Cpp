#pragma once

#ifndef WINCOPIES_UTIL_TYPING_DEFINES_ENABLE_IF_H
#define WINCOPIES_UTIL_TYPING_DEFINES_ENABLE_IF_H

#include "../../Macros/Template.h"
#include "../../../PP/CountArgs.hpp"
#include "../../../PP/Loop/ForEach.hpp"

#define __ENABLE_IF(valuePrefix, n, prefix, suffix, ...) FOR_EACH_C(SURROUND, && ::valuePrefix::prefix, suffix<T##n>, __VA_ARGS__)
#define _ENABLE_IF(prefix, value, n, type, extra, ...) SURROUND(::WinCopies::Typing::Enable, type, If)<::prefix::value<T##n> SINGLE_ARG(IF(VA_ARGS_FILLED(__VA_ARGS__), __ENABLE_IF, DISCARD)(prefix, n, __VA_ARGS__)) extra>
#define ENABLE_IF(prefix, value, ...) _ENABLE_IF(prefix, value, , Bool, , __VA_ARGS__)
#define ENABLE_TYPE_IF(prefix, value, ...) _ENABLE_IF(prefix, value, 1, , COMMA T2, __VA_ARGS__)
#define ENABLE_WHEN(prefix, value, ...) _ENABLE_IF(prefix, value, , , COMMA T, __VA_ARGS__)

#define __MAKE_ENABLE_IF(enableType, prefix, enableFor, ...) TEMPLATE using CONCATENATE(EnableIf, enableType) = ENABLE_IF(prefix, enableFor, __VA_ARGS__); \
	TEMPLATE_NC(2) using CONCATENATE(EnableTypeIf, enableType) = ENABLE_TYPE_IF(prefix, enableFor, __VA_ARGS__); \
	TEMPLATE using CONCATENATE(EnableWhen, enableType) = ENABLE_WHEN(prefix, enableFor, __VA_ARGS__);
#define _MAKE_ENABLE_IF(enableType, prefix, subprefix, suffix, enableFor, ...) __MAKE_ENABLE_IF(enableType, prefix, SURROUND(subprefix, enableFor, suffix), IF(COMPL(VA_ARGS_FILLED(__VA_ARGS__)), , subprefix, suffix, __VA_ARGS__))
#define MAKE_ENABLE_IF_STD(enableType, enableFor, ...) _MAKE_ENABLE_IF(enableType, std, is_, _v, enableFor, __VA_ARGS__)
#define MAKE_ENABLE_IF(enableFor, ...) _MAKE_ENABLE_IF(enableFor, WinCopies::Typing, , , Is##enableFor, __VA_ARGS__)

#endif // WINCOPIES_UTIL_TYPING_DEFINES_ENABLE_IF_H
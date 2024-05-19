#pragma once

#ifndef WINCOPIES_UTIL_ENUM_MAKE_ENUM_HPP
#define WINCOPIES_UTIL_ENUM_MAKE_ENUM_HPP

#include "../MISC.hpp"
#include "../Loop/ForEach.hpp"
#include "../../Includes/Macros/Type/Type.h"

#define TRANSCRIBE_ENUM_ARG(i, value) value = i

#define MAKE_ENUM(name, ...) ENUM name \
	{ \
	TRANSCRIBE_ENUM_ARG(1, FIRST_ARG(__VA_ARGS__)) FOR_EACH_I(2, TRANSCRIBE_ARGS_CS, , TRANSCRIBE_ENUM_ARG, , ALL_BUT_FIRST_ARG(__VA_ARGS__)) \
	};

#endif // WINCOPIES_UTIL_ENUM_MAKE_ENUM_HPP
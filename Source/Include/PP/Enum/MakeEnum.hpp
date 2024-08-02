#pragma once

#ifndef WINCOPIES_UTIL_ENUM_MAKE_ENUM_HPP
#define WINCOPIES_UTIL_ENUM_MAKE_ENUM_HPP

#include "../MISC.hpp"
#include "../Loop/ForEach.hpp"
#include "../../Includes/Macros/Type/Type.h"
#include "../Math/Math.hpp"
#include "Flags.hpp"
#include "Bitwise.hpp"

#define TRANSCRIBE_ENUM_ARG(i, value) value = i
#define TRANSCRIBE_NEGATIVE_ENUM_ARG(i, value) TRANSCRIBE_ENUM_ARG(- i, value)
#define TRANSCRIBE_FLAGS_ENUM_ARG(i, value) TRANSCRIBE_ENUM_ARG(ENUM_FLAG(DECREMENT(i)), value)

#define TRY_ACTIVATE_NULL_ENUM_FLAG(activateNone) IF(activateNone, TRANSCRIBE_ENUM_ARG(ENUM_FLAG_NONE, None) GET_COMMA, DISCARD)()

#define __MAKE_ENUM_FIELDS(macro, ...) macro(1, FIRST_ARG(__VA_ARGS__)) FOR_EACH_I(2, TRANSCRIBE_ARGS_CS, , macro, , ALL_BUT_FIRST_ARG(__VA_ARGS__))
#define _MAKE_ENUM_FIELDS(activateNone, negative, ...) TRY_ACTIVATE_NULL_ENUM_FLAG(activateNone) __MAKE_ENUM_FIELDS(SURROUND(TRANSCRIBE, IF(negative, _NEGATIVE, ), _ENUM_ARG), __VA_ARGS__)
#define MAKE_ENUM_FIELDS(...) _MAKE_ENUM_FIELDS(0, 0, __VA_ARGS__)

#define _MAKE_ENUM(activateNone, bitwise, negative, name, type, ...) ENUM_HEADER(name, type) \
	{ \
		_MAKE_ENUM_FIELDS(activateNone, negative, __VA_ARGS__) \
	}; \
	IF(bitwise, ENABLE_ENUM_BITWISE_OPERATORS, DISCARD)(name)

#define _MAKE_FLAGS_ENUM(activateNone, name, type, ...) ENUM name : type \
	{ \
		TRY_ACTIVATE_NULL_ENUM_FLAG(activateNone) TRANSCRIBE_ENUM_ARG(ENUM_FLAG(0), FIRST_ARG(__VA_ARGS__)) FOR_EACH_I(2, TRANSCRIBE_ARGS_CS, , TRANSCRIBE_FLAGS_ENUM_ARG, , ALL_BUT_FIRST_ARG(__VA_ARGS__)) \
	}; \
	static_assert(IS_UNSIGNED_ENUM(name), "T must be a unsigned enum."); \
	ENABLE_ENUM_BITWISE_OPERATORS(name)

#define MAKE_ENUM(name, type, ...) _MAKE_ENUM(0, 0, 0, name, type, __VA_ARGS__)
#define MAKE_NULLABLE_ENUM(name, type, ...) _MAKE_ENUM(1, 0, 0, name, type, __VA_ARGS__)

#define MAKE_BITWISE_ENUM(name, type, ...) _MAKE_ENUM(0, 1, 0, name, type, __VA_ARGS__)
#define MAKE_NULLABLE_BITWISE_ENUM(name, type, ...) _MAKE_ENUM(1, 1, 0, name, type, __VA_ARGS__)

#define MAKE_FLAGS_ENUM(name, type, ...) _MAKE_FLAGS_ENUM(0, name, type, __VA_ARGS__)
#define MAKE_NULLABLE_FLAGS_ENUM(name, type, ...) _MAKE_FLAGS_ENUM(1, name, type, __VA_ARGS__)

#endif // WINCOPIES_UTIL_ENUM_MAKE_ENUM_HPP
#pragma once

#ifndef WINCOPIES_MISC_BASE_HPP
#define WINCOPIES_MISC_BASE_HPP

#define CONCATENATE(value, ...) value##__VA_ARGS__
#define SINGLE_ARG(...) __VA_ARGS__

#define IF_B(value, ifTrue, ...) CONCATENATE(IF, value)(ifTrue, __VA_ARGS__)
#define IF0(value, ...) __VA_ARGS__
#define IF1(value, ...) value
#define IF2(value, ...) value, __VA_ARGS__

#define FIRST_ARG(value, ...) IF1(value, __VA_ARGS__)
#define SECOND_ARG(x, y, ...) y
#define THIRD_ARG(x, y, z, ...) z

#define ALL_BUT_FIRST_ARG(value, ...) IF0(value, __VA_ARGS__)
#define FIRST_TWO_ARGS(x, y, ...) x, y
#define FIRST_THIRD_ARGS(x, y, z, ...) x, y, z
#define ALL_ARGS(value, ...) IF2(value, __VA_ARGS__)

#define GET_FIRST_ARG(...) FIRST_ARG(__VA_ARGS__)
#define GET_SECOND_ARG(...) SECOND_ARG(__VA_ARGS__)
#define GET_THIRD_ARG(...) THIRD_ARG(__VA_ARGS__)

#define REMOVE_FIRST_ARG(...) ALL_BUT_FIRST_ARG(__VA_ARGS__)
#define GET_FIRST_TWO_ARGS(...) FIRST_TWO_ARGS(__VA_ARGS__)
#define GET_FIRST_THIRD_ARGS(...) FIRST_THIRD_ARGS(__VA_ARGS__)
#define GET_ALL_ARGS(...) ALL_ARGS(__VA_ARGS__)

#define CALL_VA_MACRO(macro, ...) macro(__VA_ARGS__)

#define EXPAND(_array) CONCATENATE(SINGLE_ARG, _array)
#define EXTRACT_AND_EXPAND(...) CALL_VA_MACRO(FIRST_ARG(__VA_ARGS__), ALL_BUT_FIRST_ARG(__VA_ARGS__))

#define _HAS_VA_OPT(...) THIRD_ARG(__VA_OPT__(,), 1, 0, )
#define HAS_VA_OPT _HAS_VA_OPT(?)

#endif // WINCOPIES_MISC_BASE_HPP
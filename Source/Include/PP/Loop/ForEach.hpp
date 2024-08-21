// WARNING: Concatenation of (FOR_EACH, n) is required for MSVC.

#pragma once

#ifndef WINCOPIES_FOR_EACH_HPP
#define WINCOPIES_FOR_EACH_HPP

#include "../Variadic/CountArgs.hpp"

#define __FOR_EACH(concatenator, prefix, value, suffix) concatenator(prefix, SINGLE_ARG(value), suffix)
#define _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) __FOR_EACH(concatenator, prefix, CALL_VA_MACRO(macro, SINGLE_ARG(IF_TRUE(bi, bi COMMA) value)), suffix)
#define _FOR_EACH_INCREMENTATION(bi) IF(bi, INCREMENT(bi), 0)

#define FOR_EACH0(bi, printExtra, concatenator, prefix, macro, suffix, ...) CALL_IF_B(printExtra, SINGLE_ARG)(__VA_ARGS__)
#define FOR_EACH1(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 0)(bi, printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH2(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 1)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH3(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 2)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH4(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 3)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH5(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 4)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH6(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 5)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH7(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 6)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH8(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 7)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH9(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 8)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH10(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 9)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH11(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 10)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH12(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 11)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH13(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 12)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH14(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 13)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH15(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 14)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH16(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value)CONCATENATE(FOR_EACH, 15)(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)

#define SELECT_I(bi, n, printExtra, concatenator, prefix, macro, suffix, ...) CONCATENATE(FOR_EACH, n)(bi, printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define SELECT(n, printExtra, concatenator, prefix, macro, suffix, ...) SELECT_I(0, n, printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)

#define FOR_EACH_I(bi, concatenator, prefix, macro, suffix, ...) SELECT_I(bi, COUNT_ARGS(__VA_ARGS__), 0, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH(concatenator, prefix, macro, suffix, ...) FOR_EACH_I(0, concatenator, prefix, macro, suffix, __VA_ARGS__)

#define FOR_EACH_CI(bi, concatenator, prefix, suffix, ...) FOR_EACH_I(bi, concatenator, prefix, SINGLE_ARG, suffix, __VA_ARGS__)
#define FOR_EACH_C(concatenator, prefix, suffix, ...) FOR_EACH_CI(0, concatenator, prefix, suffix, __VA_ARGS__)

#endif WINCOPIES_FOR_EACH_HPP
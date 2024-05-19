#pragma once

#ifndef WINCOPIES_FOR_EACH_HPP
#define WINCOPIES_FOR_EACH_HPP

#include "../Conditional/If.hpp"
#include "../Variadic/CountArgs.hpp"

#define __FOR_EACH(concatenator, prefix, value, suffix) concatenator(prefix, value, suffix)
#define _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) __FOR_EACH(concatenator, prefix, CALL_VA_MACRO(macro, SINGLE_ARG(IF(NOT(bi), , bi COMMA) value)), suffix)
#define _FOR_EACH_INCREMENTATION(bi) IF(bi, INCREMENT(bi), 0)

#define FOR_EACH0(bi, printExtra, concatenator, prefix, macro, suffix, ...) IF_B(printExtra, SINGLE_ARG, DISCARD)(__VA_ARGS__)
#define FOR_EACH1(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH0(bi, printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH2(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH1(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH3(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH2(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH4(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH3(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH5(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH4(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH6(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH5(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH7(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH6(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH8(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH7(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH9(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH8(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH10(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH9(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH11(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH10(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH12(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH11(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH13(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH12(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH14(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH13(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH15(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH14(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH16(bi, printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(bi, concatenator, prefix, macro, suffix, value) FOR_EACH15(_FOR_EACH_INCREMENTATION(bi), printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)

#define SELECT_I(bi, n, printExtra, concatenator, prefix, macro, suffix, ...) CONCATENATE(FOR_EACH, n)(bi, printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define SELECT(n, printExtra, concatenator, prefix, macro, suffix, ...) SELECT_I(0, n, printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)

#define FFOR_EACH_I(bi, count, concatenator, prefix, macro, suffix, ...) SELECT_I(bi, count, 0, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FFOR_EACH(count, concatenator, prefix, macro, suffix, ...) FFOR_EACH_I(0, count, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH_I(bi, concatenator, prefix, macro, suffix, ...) FFOR_EACH_I(bi, COUNT_ARGS(__VA_ARGS__), concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH(concatenator, prefix, macro, suffix, ...) FOR_EACH_I(0, concatenator, prefix, macro, suffix, __VA_ARGS__)

#define FFOR_EACH_CI(bi, count, concatenator, prefix, suffix, ...) FFOR_EACH_I(bi, count, concatenator, prefix, SINGLE_ARG, suffix, __VA_ARGS__)
#define FFOR_EACH_C(count, concatenator, prefix, suffix, ...) FFOR_EACH_CI(0, count, concatenator, prefix, suffix, __VA_ARGS__)
#define FOR_EACH_CI(bi, concatenator, prefix, suffix, ...) FFOR_EACH_CI(bi, COUNT_ARGS(__VA_ARGS__), concatenator, prefix, suffix, __VA_ARGS__)
#define FOR_EACH_C(concatenator, prefix, suffix, ...) FOR_EACH_CI(0, concatenator, prefix, suffix, __VA_ARGS__)

#endif // WINCOPIES_FOR_EACH_HPP
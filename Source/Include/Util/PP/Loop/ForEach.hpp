#pragma once

#ifndef WINCOPIES_FOR_EACH_HPP
#define WINCOPIES_FOR_EACH_HPP

#include "../CountArgs.hpp"

#define __FOR_EACH(concatenator, prefix, value, suffix) concatenator(prefix, value, suffix)
#define _FOR_EACH(concatenator, prefix, macro, suffix, value) __FOR_EACH(concatenator, prefix, macro(value), suffix)

#define FOR_EACH0(printExtra, concatenator, prefix, macro, suffix, ...) IF_B(printExtra, SINGLE_ARG, DISCARD)(__VA_ARGS__)
#define FOR_EACH1(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH0(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH2(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH1(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH3(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH2(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH4(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH3(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH5(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH4(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH6(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH5(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH7(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH6(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH8(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH7(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH9(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH8(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH10(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH9(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH11(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH10(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH12(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH11(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH13(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH12(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH14(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH13(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH15(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH14(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH16(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH15(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)

#define SELECT(n, printExtra, concatenator, prefix, macro, suffix, ...) CONCATENATE(FOR_EACH, n)(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)

#define FFOR_EACH(count, concatenator, prefix, macro, suffix, ...) SELECT(count, 0, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH(concatenator, prefix, macro, suffix, ...) FFOR_EACH(COUNT_ARGS(__VA_ARGS__), concatenator, prefix, macro, suffix, __VA_ARGS__)

#define FFOR_EACH_C(count, concatenator, prefix, suffix, ...) FFOR_EACH(count, concatenator, prefix, SINGLE_ARG, suffix, __VA_ARGS__)
#define FOR_EACH_C(concatenator, prefix, suffix, ...) FFOR_EACH_C(COUNT_ARGS(__VA_ARGS__), concatenator, prefix, suffix, __VA_ARGS__)

#endif // WINCOPIES_FOR_EACH_HPP
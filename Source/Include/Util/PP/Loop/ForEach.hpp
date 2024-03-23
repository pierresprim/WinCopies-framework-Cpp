#pragma once

#ifndef WINCOPIES_FOR_EACH_HPP
#define WINCOPIES_FOR_EACH_HPP

#include "../Conditional/Conditional.hpp"
#include "../CountArgs.hpp"

#define _FOR_EACH(concatenator, prefix, macro, suffix, value) concatenator(prefix, macro(value), suffix)

#define FOR_EACH0(printExtra, concatenator, prefix, macro, suffix, ...) IF_B(printExtra, SINGLE_ARG, DISCARD)(__VA_ARGS__)
#define FOR_EACH1(printExtra, concatenator, prefix, macro, suffix, value, ...) concatenator(prefix, macro(value), suffix) FOR_EACH0(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH2(printExtra, concatenator, prefix, macro, suffix, x, y, ...) _FOR_EACH(concatenator, prefix, macro, suffix, x) FOR_EACH1(printExtra, concatenator, prefix, macro, suffix, y, __VA_ARGS__)
#define FOR_EACH3(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH2(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH4(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH3(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH5(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH4(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH6(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH5(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH7(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH6(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH8(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH7(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH9(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH8(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH10(printExtra, concatenator, prefix, macro, suffix, value, ...) _FOR_EACH(concatenator, prefix, macro, suffix, value) FOR_EACH9(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)

#define SELECT(n, printExtra, concatenator, prefix, macro, suffix, ...) CONCATENATE(FOR_EACH, n)(printExtra, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH(concatenator, prefix, macro, suffix, ...) SELECT(COUNT_ARGS(__VA_ARGS__), 0, concatenator, prefix, macro, suffix, __VA_ARGS__)
#define FOR_EACH_C(concatenator, prefix, suffix, ...) FOR_EACH(concatenator, prefix, SINGLE_ARG, suffix, __VA_ARGS__)

#endif // WINCOPIES_FOR_EACH_HPP
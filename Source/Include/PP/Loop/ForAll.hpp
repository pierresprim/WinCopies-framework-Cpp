#pragma once

#ifndef WINCOPIES_FOR_ALL_HPP
#define WINCOPIES_FOR_ALL_HPP

#include "Include/FOR_ALL.hpp"

#define FOR_ALL1(macro, first, _array, ...) EXPAND(first)
#define FOR_ALL2(macro, first, _array, ...) ___FOR_ALL(1, macro, first, _array, __VA_ARGS__)
#define FOR_ALL3(macro, first, _array, ...) EXPAND(first), _FOR_ALL2(macro, macro(_array, __VA_ARGS__), ALL_BUT_FIRST_ARG(__VA_ARGS__))
#define FOR_ALL4(macro, first, _array, ...) EXPAND(first), _FOR_ALL3(macro, macro(_array, __VA_ARGS__), ALL_BUT_FIRST_ARG(__VA_ARGS__))
#define FOR_ALL5(macro, first, _array, ...) EXPAND(first), _FOR_ALL4(macro, macro(_array, __VA_ARGS__), ALL_BUT_FIRST_ARG(__VA_ARGS__))

#define FOR_ALL(macro, _array, ...) _FOR_ALL(COUNT_ARGS(__VA_ARGS__), macro, _array, __VA_ARGS__)

#endif WINCOPIES_FOR_ALL_HPP
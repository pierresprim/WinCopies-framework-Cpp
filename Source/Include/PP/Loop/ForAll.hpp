#pragma once

#ifndef WINCOPIES_FOR_ALL_HPP
#define WINCOPIES_FOR_ALL_HPP

#include "Include/FOR_ALL.hpp"

#define FOR_ALL1(renderer, macro, first, _array, ...) EXPAND(first)
#define FOR_ALL2(renderer, macro, first, _array, ...) renderer(EXPAND(first), _FOR_ALL1(renderer, macro, ___FOR_ALL(macro, _array, __VA_ARGS__)))
#define FOR_ALL3(renderer, macro, first, _array, ...) renderer(EXPAND(first), _FOR_ALL2(renderer, macro, ___FOR_ALL(macro, _array, __VA_ARGS__)))
#define FOR_ALL4(renderer, macro, first, _array, ...) renderer(EXPAND(first), _FOR_ALL3(renderer, macro, ___FOR_ALL(macro, _array, __VA_ARGS__)))
#define FOR_ALL5(renderer, macro, first, _array, ...) renderer(EXPAND(first), _FOR_ALL4(renderer, macro, ___FOR_ALL(macro, _array, __VA_ARGS__)))

#define FOR_ALL(macro, _array, ...) _FOR_ALL(COUNT_ARGS(__VA_ARGS__), renderer, macro, _array, __VA_ARGS__)

#endif WINCOPIES_FOR_ALL_HPP
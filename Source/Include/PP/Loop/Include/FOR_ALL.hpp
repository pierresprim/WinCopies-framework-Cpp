#pragma once

#ifndef WINCOPIES_META_FOR_ALL_HPP
#define WINCOPIES_META_FOR_ALL_HPP

#include "../Conditional/If.hpp"

#define _FOR_ALL1(macro, ...) CONCATENATE(FOR_ALL, 1)(macro, __VA_ARGS__)
#define _FOR_ALL2(macro, ...) CONCATENATE(FOR_ALL, 2)(macro, __VA_ARGS__)
#define _FOR_ALL3(macro, ...) CONCATENATE(FOR_ALL, 3)(macro, __VA_ARGS__)
#define _FOR_ALL4(macro, ...) CONCATENATE(FOR_ALL, 4)(macro, __VA_ARGS__)
#define _FOR_ALL5(macro, ...) CONCATENATE(FOR_ALL, 5)(macro, __VA_ARGS__)

#define ___FOR_ALL(n, macro, first, _array, ...) EXPAND(first), CONCATENATE(_FOR_ALL, n)(macro, macro(_array, __VA_ARGS__), ALL_BUT_FIRST_ARG(__VA_ARGS__))

#define __FOR_ALL(entryPoint, macro, _array, ...) entryPoint(macro, macro(_array, __VA_ARGS__), ALL_BUT_FIRST_ARG(__VA_ARGS__))
#define _FOR_ALL(count, macro, _array, ...) IF(count, __FOR_ALL, DISCARD)(CONCATENATE(_FOR_ALL, count), macro, _array, __VA_ARGS__)

#endif WINCOPIES_META_FOR_ALL_HPP
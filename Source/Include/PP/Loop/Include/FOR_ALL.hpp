#pragma once

#ifndef WINCOPIES_META_FOR_ALL_HPP
#define WINCOPIES_META_FOR_ALL_HPP

#include "../../Conditional/If.hpp"

#define _FOR_ALL1(renderer, macro, ...) CONCATENATE(FOR_ALL, 1)(renderer, macro, __VA_ARGS__)
#define _FOR_ALL2(renderer, macro, ...) CONCATENATE(FOR_ALL, 2)(renderer, macro, __VA_ARGS__)
#define _FOR_ALL3(renderer, macro, ...) CONCATENATE(FOR_ALL, 3)(renderer, macro, __VA_ARGS__)
#define _FOR_ALL4(renderer, macro, ...) CONCATENATE(FOR_ALL, 4)(renderer, macro, __VA_ARGS__)
#define _FOR_ALL5(renderer, macro, ...) CONCATENATE(FOR_ALL, 5)(renderer, macro, __VA_ARGS__)

#define ___FOR_ALL(macro, _array, ...) macro(_array, __VA_ARGS__), ALL_BUT_FIRST_ARG(__VA_ARGS__)

#define __FOR_ALL(count, renderer, macro, _array, ...) CONCATENATE(_FOR_ALL, count)(renderer, macro, ___FOR_ALL(macro, _array, __VA_ARGS__))
#define _FOR_ALL(count, renderer, macro, _array, ...) CALL_IF(count, __FOR_ALL)(count, renderer, macro, _array, __VA_ARGS__)

#endif WINCOPIES_META_FOR_ALL_HPP
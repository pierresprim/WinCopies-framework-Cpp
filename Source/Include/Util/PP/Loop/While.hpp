#pragma once

#ifndef WINCOPIES_WHILE_HPP
#define WINCOPIES_WHILE_HPP

#include "../Conditional/If.hpp"

#define WHILE0(predicate, macro, ...) __VA_ARGS__
#define __WHILE(i) CONCATENATE(WHILE, i)
#define _WHILE(predicate, i, ...) __WHILE(IF(predicate(__VA_ARGS__), i, 0))

#define _WHILE11(predicate, macro, ...) IF(predicate(__VA_ARGS__), macro, SINGLE_ARG)(__VA_ARGS__)
#define WHILE10(predicate, macro, ...) _WHILE11(predicate, macro, macro(__VA_ARGS__))
#define _WHILE10(predicate, macro, ...) _WHILE(predicate, 10, __VA_ARGS__)(predicate, macro, __VA_ARGS__)
#define WHILE9(predicate, macro, ...) _WHILE10(predicate, macro, macro(__VA_ARGS__))
#define _WHILE9(predicate, macro, ...) _WHILE(predicate, 9, __VA_ARGS__)(predicate, macro, __VA_ARGS__)
#define WHILE8(predicate, macro, ...) _WHILE9(predicate, macro, macro(__VA_ARGS__))
#define _WHILE8(predicate, macro, ...) _WHILE(predicate, 8, __VA_ARGS__)(predicate, macro, __VA_ARGS__)
#define WHILE7(predicate, macro, ...) _WHILE8(predicate, macro, macro(__VA_ARGS__))
#define _WHILE7(predicate, macro, ...) _WHILE(predicate, 7, __VA_ARGS__)(predicate, macro, __VA_ARGS__)
#define WHILE6(predicate, macro, ...) _WHILE7(predicate, macro, macro(__VA_ARGS__))
#define _WHILE6(predicate, macro, ...) _WHILE(predicate, 6, __VA_ARGS__)(predicate, macro, __VA_ARGS__)
#define WHILE5(predicate, macro, ...) _WHILE6(predicate, macro, macro(__VA_ARGS__))
#define _WHILE5(predicate, macro, ...) _WHILE(predicate, 5, __VA_ARGS__)(predicate, macro, __VA_ARGS__)
#define WHILE4(predicate, macro, ...) _WHILE5(predicate, macro, macro(__VA_ARGS__))
#define _WHILE4(predicate, macro, ...) _WHILE(predicate, 4, __VA_ARGS__)(predicate, macro, __VA_ARGS__)
#define WHILE3(predicate, macro, ...) _WHILE4(predicate, macro, macro(__VA_ARGS__))
#define _WHILE3(predicate, macro, ...) _WHILE(predicate, 3, __VA_ARGS__)(predicate, macro, __VA_ARGS__)
#define WHILE2(predicate, macro, ...) _WHILE3(predicate, macro, macro(__VA_ARGS__))
#define _WHILE2(predicate, macro, ...) _WHILE(predicate, 2, __VA_ARGS__)(predicate, macro, __VA_ARGS__)
#define WHILE1(predicate, macro, ...) _WHILE2(predicate, macro, macro(__VA_ARGS__))
#define ___WHILE(n, predicate, macro, ...) CONCATENATE(WHILE, n)(predicate, macro, __VA_ARGS__)
#define WHILE(predicate, macro, ...) ___WHILE(BOOL(predicate(__VA_ARGS__)), predicate, macro, __VA_ARGS__)

#endif // WINCOPIES_WHILE_HPP
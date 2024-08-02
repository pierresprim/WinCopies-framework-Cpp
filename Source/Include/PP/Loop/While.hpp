#pragma once

#ifndef WINCOPIES_WHILE_HPP
#define WINCOPIES_WHILE_HPP

#include "Include/WHILE.hpp"

#define WHILE0(predicate, macro, ...) __VA_ARGS__

#define WHILE10(predicate, macro, ...) _WHILE11(predicate, macro, macro(__VA_ARGS__))
#define WHILE9(predicate, macro, ...) _WHILE10(predicate, macro, macro(__VA_ARGS__))
#define WHILE8(predicate, macro, ...) _WHILE9(predicate, macro, macro(__VA_ARGS__))
#define WHILE7(predicate, macro, ...) _WHILE8(predicate, macro, macro(__VA_ARGS__))
#define WHILE6(predicate, macro, ...) _WHILE7(predicate, macro, macro(__VA_ARGS__))
#define WHILE5(predicate, macro, ...) _WHILE6(predicate, macro, macro(__VA_ARGS__))
#define WHILE4(predicate, macro, ...) _WHILE5(predicate, macro, macro(__VA_ARGS__))
#define WHILE3(predicate, macro, ...) _WHILE4(predicate, macro, macro(__VA_ARGS__))
#define WHILE2(predicate, macro, ...) _WHILE3(predicate, macro, macro(__VA_ARGS__))
#define WHILE1(predicate, macro, ...) _WHILE2(predicate, macro, macro(__VA_ARGS__))
#define WHILE(predicate, macro, ...) ___WHILE(PP_BOOL(predicate(__VA_ARGS__)), predicate, macro, __VA_ARGS__)

#endif // WINCOPIES_WHILE_HPP
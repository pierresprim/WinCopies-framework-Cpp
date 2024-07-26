#pragma once

#ifndef WINCOPIES_MACROS_METHOD_ABSTRACT_H
#define WINCOPIES_MACROS_METHOD_ABSTRACT_H

#define _ABSTRACT_ARG_METHOD(typeAndName, constKeyword, virtualityType, ...) virtual typeAndName(__VA_ARGS__) constKeyword virtualityType

#define ABSTRACT_ARG_METHOD(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, , = 0, __VA_ARGS__)
#define ABSTRACT_ARG_CONST(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, CONST, = 0, __VA_ARGS__)
#define ABSTRACT_METHOD(typeAndName) ABSTRACT_ARG_METHOD(typeAndName, )
#define ABSTRACT_CONST(typeAndName) ABSTRACT_ARG_CONST(typeAndName, )

#define OVERRIDE_ARG_METHOD(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, , override, __VA_ARGS__)
#define OVERRIDE_ARG_CONST(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, CONST, override, __VA_ARGS__)
#define OVERRIDE_METHOD(typeAndName) OVERRIDE_ARG_METHOD(typeAndName, )
#define OVERRIDE_CONST(typeAndName) OVERRIDE_ARG_CONST(typeAndName, )

#define FINAL_ARG_METHOD(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, , final, __VA_ARGS__)
#define FINAL_ARG_CONST(typeAndName, ...) _ABSTRACT_ARG_METHOD(typeAndName, CONST, final, __VA_ARGS__)
#define FINAL_METHOD(typeAndName) FINAL_ARG_METHOD(typeAndName, )
#define FINAL_CONST(typeAndName) FINAL_ARG_CONST(typeAndName, )

#endif WINCOPIES_MACROS_METHOD_ABSTRACT_H
#pragma once

#ifndef WINCOPIES_UTIL_BASE_DEFINES_H
#define WINCOPIES_UTIL_BASE_DEFINES_H

#define DLLEXPORT __declspec(dllexport)

/// WinCopies Framework Error codes

constexpr auto ARGUMENT_EXCEPTION = -1;
constexpr auto ARGUMENT_OUT_OF_RANGE_EXCEPTION = -2;
constexpr auto INVALID_OPERATION_EXCEPTION = -3;
constexpr auto READ_ONLY_EXCEPTION = -4;
constexpr auto EMPTY_OBJECT_EXCEPTION = -5;
#endif

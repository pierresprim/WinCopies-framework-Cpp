#pragma once

#ifndef WINCOPIES_LIBRARIES_H
#define WINCOPIES_LIBRARIES_H

/// Std

#include <functional>
#include <string>
#include <string_view>
#include <stdexcept>
#include <cstdlib>
#include <memory>
#include <type_traits>
#include <typeinfo>

#include "Environment.h"

#ifdef WINDOWS
#include <format>

#include <Windows.h>
#endif
#endif WINCOPIES_LIBRARIES_H
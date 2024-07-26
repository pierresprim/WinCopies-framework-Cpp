#pragma once

#ifndef WINCOPIES_MACROS_METHOD_BASE_H
#define WINCOPIES_MACROS_METHOD_BASE_H

#define _METHOD(modifiers) DLLEXPORT modifiers void

#define METHOD _METHOD()

#define INLINE_METHOD _METHOD(inline)
#define INLINE_FUNCTION DLLEXPORT inline

#endif WINCOPIES_MACROS_METHOD_BASE_H
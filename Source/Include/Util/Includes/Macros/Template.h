#pragma once

#ifndef WINCOPIES_UTIL_TEMPLATE_H
#define WINCOPIES_UTIL_TEMPLATE_H

#include "../../PP/Loop/For.hpp"
#include "../../PP/Loop/ForEach.hpp"
#include "../../PP/Util.hpp"
#include "../Main.h"

#define __TEMPLATE(typeKind, extraParameters) template<typeKind T extraParameters>
#define _TEMPLATE(typeKind) __TEMPLATE(typeKind, )

#define TEMPLATE _TEMPLATE(class)
#define TEMPLATE_N(n, templateType) template<FOR_I(n, SURROUND, templateType T, )>
#define TEMPLATE_NC(n) TEMPLATE_N(n, class)

#define MULTI_TEMPLATE _TEMPLATE(class...)

#define METHOD_TEMPLATE template<class F>

#define MAKE_TEMPLATE_PARAMS(count, prefix, suffix) FOR_I(count, SURROUND, prefix T##suffix, )

#define CEA_OPERATOR constexpr auto operator

#define CEA_OPERATOR_TEMPLATE TEMPLATE CEA_OPERATOR
#define CEA_OPERATOR_TEMPLATE_N(n, templateType) TEMPLATE_N(n, templateType) CEA_OPERATOR
#define CEA_OPERATOR_TEMPLATE_NC(n) CEA_OPERATOR_TEMPLATE_N(n, class)

// Named templates

#define NAMED_TEMPLATE(typeName) template<class typeName>
#define NAMED_TEMPLATE_N(templateType, ...) template<TRANSCRIBE_ARGS_WITH(templateType, , __VA_ARGS__)>
#define NAMED_TEMPLATE_NC(...) NAMED_TEMPLATE_N(class, __VA_ARGS__)

#endif
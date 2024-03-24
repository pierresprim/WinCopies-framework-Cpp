#pragma once

#ifndef WINCOPIES_UTIL_TEMPLATE_H
#define WINCOPIES_UTIL_TEMPLATE_H

#include "../../PP/Loop/For.hpp"
#include "../Main.h"

#define __TEMPLATE(typeKind, extraParameters) template<typeKind T extraParameters>
#define _TEMPLATE(typeKind) __TEMPLATE(typeKind, )

#define TEMPLATE _TEMPLATE(class)
#define TEMPLATE_N(n, templateType) template<FOR_I(n, SURROUND, class T, )>
#define TEMPLATE_NC(n) TEMPLATE_N(n, class)

#define MULTI_TEMPLATE _TEMPLATE(class...)

#define METHOD_TEMPLATE template<class F>

#define CEA_OPERATOR constexpr auto operator

#define CEA_OPERATOR_TEMPLATE TEMPLATE CEAOPERATOR
#define CEA_OPERATOR_TEMPLATE_N(n, templateType) TEMPLATE_N(n, templateType) CEAOPERATOR
#define CEA_OPERATOR_TEMPLATE_NC(n) CEA_OPERATOR_TEMPLATE_N(n, class)

// Named templates

#define NAMED_TEMPLATE(typeName) template<class typeName>
#define NAMED_TEMPLATE2(t1, t2) template<class t1, class t2>
#define NAMED_TEMPLATE3(t1, t2, t3) template<class t1, class t2, class t3>

#endif
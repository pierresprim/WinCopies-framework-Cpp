#pragma once

#ifndef WINCOPIES_TEMPLATE_H
#define WINCOPIES_TEMPLATE_H

#include "../../PP/Loop/For.hpp"
#include "../../PP/Loop/ForEach.hpp"
#include "../../PP/Variadic/Util.hpp"
#include "../../PP/Variadic/Variadic.hpp"
#include "../Main.h"
#include "../Types/DefsBase.h"

#define __TEMPLATE(typeKind, extraParameters) template<typeKind T extraParameters>
#define _TEMPLATE(typeKind) __TEMPLATE(typeKind, )

#define MAKE_TEMPLATE_PARAMS(count, prefix, suffix) FOR_I(count, SURROUND, prefix T##suffix, )
#define TEMPLATE_PARAMS(count) MAKE_TEMPLATE_PARAMS(count, , )

#define TEMPLATE _TEMPLATE(class)

#define TEMPLATE_N(n, kind, ...) template<MAKE_TEMPLATE_PARAMS(n, kind, ) VA_OPT(IF_NOT(n, COMMA), __VA_ARGS__) __VA_ARGS__>
#define TEMPLATE_NC(n, ...) TEMPLATE_N(n, class, __VA_ARGS__)

#define TEMPLATE_E(kind, ...) TEMPLATE_N(0, , TRANSCRIBE_SURROUNDED(kind, , __VA_ARGS__))
#define TEMPLATE_EC(...) TEMPLATE_E(class, __VA_ARGS__)

#define TEMPLATE_NE(n, kind, ...) TEMPLATE_N(n, kind, TRANSCRIBE_SURROUNDED(kind, , __VA_ARGS__))
#define TEMPLATE_NEC(n, ...) TEMPLATE_NE(n, class, __VA_ARGS__)

#define MULTI_TEMPLATE _TEMPLATE(class...)

#define METHOD_TEMPLATE template<class F>

#define CEA_OPERATOR constexpr auto operator

#define CEA_OPERATOR_TEMPLATE TEMPLATE CEA_OPERATOR
#define CEA_OPERATOR_TEMPLATE_N(n, templateType) TEMPLATE_N(n, templateType) CEA_OPERATOR
#define CEA_OPERATOR_TEMPLATE_NC(n) CEA_OPERATOR_TEMPLATE_N(n, class)

// Named templates

#define NAMED_TEMPLATE(typeName) template<class typeName>
#define NAMED_TEMPLATE_N(templateType, ...) template<TRANSCRIBE_ARGS_WITH(templateType, , __VA_ARGS__)>
#define NAMED_TEMPLATE_NC(...) NAMED_TEMPLATE_N(class, __VA_ARGS__)

#define TEMPLATE_SPECIALIZATION(isTemplate, type, prefix, name) IF(isTemplate, TEMPLATE) using SURROUND(I, prefix, name) = I##name<IF_NOT(isTemplate, T,) type>
#define COLLECTION_TEMPLATE_SPECIALIZATION(isTemplate, name) TEMPLATE_SPECIALIZATION(isTemplate, UINT, UInt, name); TEMPLATE_SPECIALIZATION(isTemplate, ULONGLONG, ULong, name);
#define LIST_TEMPLATE_SPECIALIZATION(name) COLLECTION_TEMPLATE_SPECIALIZATION(1, name##R) COLLECTION_TEMPLATE_SPECIALIZATION(1, name##W) COLLECTION_TEMPLATE_SPECIALIZATION(1, name)

#endif WINCOPIES_TEMPLATE_H
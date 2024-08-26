#pragma once

#ifndef WINCOPIES_MACROS_SHARED_HXX
#define WINCOPIES_MACROS_SHARED_HXX

#include "../../../Core/Typing/Typing.h"

#define SHARED_TYPE(...) ::WinCopies::Typing::SharedType<__VA_ARGS__>
#define SHARED_FROM_THIS(...) public SHARED_TYPE(__VA_ARGS__)
#define SHARED_TYPE_HEADER(typeKind, typeName, ...) typeKind typeName : SHARED_FROM_THIS(typeName IF_TRUE(VA_ARGS_FILLED(__VA_ARGS__), <__VA_ARGS__>))

#define SHARED_CLASS(className, ...) SHARED_TYPE_HEADER(CLASS, className, __VA_ARGS__)
#define SHARED_TEMPLATE(className) TEMPLATE SHARED_CLASS(className, T)
#define SHARED_TEMPLATE_CLASS(className) TEMPLATE SHARED_TYPE_HEADER(class, className, T)

#endif
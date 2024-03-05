#pragma once

#ifndef WINCOPIES_UTIL_TEMPLATE_H
#define WINCOPIES_UTIL_TEMPLATE_H

#define __TEMPLATE(typeKind, extraParameters) template<typeKind T extraParameters>
#define _TEMPLATE(typeKind) __TEMPLATE(typeKind, )

#define TEMPLATE _TEMPLATE(class)
#define TEMPLATE2 template<class T1, class T2>
#define TEMPLATE3 template<class T1, class T2, class T3>
#define TEMPLATE4 template<class T1, class T2, class T3, class T4>
#define TEMPLATE5 template<class T1, class T2, class T3, class T4, class T5>

#define MULTI_TEMPLATE _TEMPLATE(class...)

#define METHOD_TEMPLATE template<class F>

#define OPERATOR constexpr auto operator

#define OPERATOR_TEMPLATE TEMPLATE OPERATOR
#define OPERATOR_TEMPLATE2 TEMPLATE2 OPERATOR

// Named templates

#define NAMED_TEMPLATE(typeName) template<class typeName>
#define NAMED_TEMPLATE2(t1, t2) template<class t1, class t2>
#define NAMED_TEMPLATE3(t1, t2, t3) template<class t1, class t2, class t3>

#endif
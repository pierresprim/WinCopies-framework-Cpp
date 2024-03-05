#pragma once

#ifndef WINCOPIES_UTIL_DELEGATE_USINGS_H
#define WINCOPIES_UTIL_DELEGATE_USINGS_H

typedef void(*ActionVoid)();
typedef std::function<void()> ActionFunctionVoid;

#define _DELEGATE_ACTION(typeName, name, ...) using name = void(typeName *)(__VA_ARGS__);

#define DELEGATE_ACTION(count, ...) _DELEGATE_ACTION(, Action##count, __VA_ARGS__)
#define INSTANCE_ACTION(count, ...) _DELEGATE_ACTION(TObj::, InstanceAction##count, __VA_ARGS__)
#define ACTION_FUNCTION(count, ...) using ActionFunction##count = std::function<void(__VA_ARGS__)>;

TEMPLATE DELEGATE_ACTION(, T)
template<class TObj, class T> INSTANCE_ACTION(, T)
TEMPLATE ACTION_FUNCTION(, T)

TEMPLATE2 DELEGATE_ACTION(2, T1, T2)
template<class TObj, class T1, class T2> INSTANCE_ACTION(2, T1, T2)
TEMPLATE2 ACTION_FUNCTION(2, T1, T2)

template<class T1, class T2, class T3>
using Action3 = void(*)(T1, T2, T3);
template<class T1, class T2, class T3>
using ActionFunction3 = std::function<void(T1, T2, T3)>;

template<class T1, class T2, class T3, class T4>
using Action4 = void(*)(T1, T2, T3, T4);
template<class T1, class T2, class T3, class T4>
using ActionFunction4 = std::function<void(T1, T2, T3, T4)>;

TEMPLATE
using Function = T(*)();
TEMPLATE
using FunctionFunction = std::function<T()>;

template<class TIn, class TOut>
using Selector = TOut(*)(TIn);
template<class TIn, class TOut>
using SelectorFunction = std::function<TOut(TIn)>;

template<class TIn1, class TIn2, class TOut>
using Selector2 = TOut(*)(TIn1, TIn2);
template<class TIn1, class TIn2, class TOut>
using SelectorFunction2 = std::function<TOut(TIn1, TIn2)>;

template<class TIn1, class TIn2, class TIn3, class TOut>
using Selector3 = TOut(*)(TIn1, TIn2, TIn3);
template<class TIn1, class TIn2, class TIn3, class TOut>
using SelectorFunction3 = std::function<TOut(TIn1, TIn2, TIn3)>;

TEMPLATE
using Converter = Selector<T, T>;
TEMPLATE
using ConverterFunction = SelectorFunction<T, T>;

TEMPLATE
using Predicate = Selector<T, bool>;
TEMPLATE
using PredicateFunction = SelectorFunction<T, bool>;

template<class T1, class T2>
using Predicate2 = Selector2<T1, T2, bool>;
template<class T1, class T2>
using PredicateFunction2 = SelectorFunction2<T1, T2, bool>;

template<class T1, class T2>
using Comparison2 = Selector2<T1, T2, BYTE>;
template<class T1, class T2>
using ComparisonFunction2 = SelectorFunction2<T1, T2, BYTE>;

template<class T1, class T2>
using EqualityComparison2 = Predicate2<T1, T2>;
template<class T1, class T2>
using EqualityComparisonFunction2 = PredicateFunction2<T1, T2>;

TEMPLATE
using Comparison = Comparison2<T, T>;
TEMPLATE
using ComparisonFunction = ComparisonFunction2<T, T>;

TEMPLATE
using EqualityComparison = EqualityComparison2<T, T>;
TEMPLATE
using EqualityComparisonFunction = EqualityComparisonFunction2<T, T>;

#endif
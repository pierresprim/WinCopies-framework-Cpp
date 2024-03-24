#pragma once

#ifndef WINCOPIES_UTIL_DELEGATE_DEFINES_H
#define WINCOPIES_UTIL_DELEGATE_DEFINES_H

#define FUNC T(*Func)()
#define FUNC_PARAMETER T(*func)()
#define FUNC_FIELD T(*_func)();

#define NAMED_FUNC(funcName) T(*funcName)()
#define NAMED_FUNC_FIELD(funcName) T(*funcName)();

#define PREDICATE bool(*Predicate)(T)
#define PREDICATE_PARAMETER bool(*predicate)(T)
#define PREDICATE_FIELD bool(*_predicate)(T);

#define NAMED_PREDICATE(predicateName) bool(*predicateName)(T)
#define NAMED_PREDICATE_FIELD(predicateName) bool(*predicateName)(T);

#define SELECTOR(t1, t2) t2(*Selector)(t1)
#define SELECTOR_PARAMETER(t1, t2) t2(*selector)(t1)
#define SELECTOR_FIELD(t1, t2) t2(*_selector)(t1);

#define NAMED_SELECTOR(selectorName, t1, t2) t2(*selectorName)(t1)
#define NAMED_SELECTOR_FIELD(selectorName, t1, t2) t2(*selectorName)(t1);

#define COMPARISON(t) BYTE(*comparison)(t, t)

#define NAMED_COMPARISON(comparisonName, t) BYTE(*comparisonName)(t, t)

#endif
#pragma once

#ifndef WINCOPIES_UTIL_TYPING_H
#define WINCOPIES_UTIL_TYPING_H

#include <memory>
#include <type_traits>

#include "../Kernel/Macros/Method/Inline.hxx"
#include "../Kernel/Macros/Type/Shared.hxx"

#include "../Core/Typing/EnableIf.h"

#include "Delegate.h"
#include "UtilBase.h"

using namespace WinCopies::Delegate;

namespace WinCopies
{
	namespace Typing
	{
		template<Action<void*> freer> STRUCT Freer
		{
			void operator()(void* ptr) const noexcept { freer(ptr); };
		};

		template<class T, Action<void*> freer> using FreeableUnique = unique_ptr<T, Freer<freer>>;
		TEMPLATE using FreeableUniqueStd = FreeableUnique<T, free>;

#define WINCOPIES_AS_FROM_TYPE_HEADER(tOut) TEMPLATE_NC(2, IF_NOT(tOut, , class TOut COMMA) ENABLE_IF_BASE_OF(T1, T2) = true)
#define WINCOPIES_AS_FROM_TYPE(modifier) WINCOPIES_AS_FROM_TYPE_HEADER(0) INLINE_METHOD_RETURN(0, VIRTUALITY_NONE, T1##modifier, AsFromType, value, T2##modifier value)

		WINCOPIES_AS_FROM_TYPE()
		WINCOPIES_AS_FROM_TYPE(*)
		WINCOPIES_AS_FROM_TYPE(&)
#undef WINCOPIES_AS_FROM_TYPE

		WINCOPIES_AS_FROM_TYPE_HEADER(1) TOut AsFromType(T1** result, T2** _result, SelectorFunction<T2**, TOut> func)
		{
			TOut __result = func(_result);

			*result = *_result;

			return __result;
		}
		WINCOPIES_AS_FROM_TYPE_HEADER(1) TOut AsFromType(T1** result, SelectorFunction<T2**, TOut> func)
		{
			T2* ptr = 0;

			return AsFromType(result, &ptr, func);
		}
#undef WINCOPIES_AS_FROM_TYPE_HEADER

		TEMPLATE inline ErrorCodePredicate<T>* AsErrorCodePredicate(shared_ptr<PredicateFunction<T>> const predicate, ErrorCode const errorValue = ErrorCode::UnknownException)
		{
			return new ErrorCodePredicate<T>([predicate, errorValue](T value) { return (*predicate)(value) ? ErrorCode::Success : errorValue; });
		}
		TEMPLATE inline PredicateFunction<T>* AsPredicate(shared_ptr<ErrorCodePredicate<T>> const predicate)
		{
			return new PredicateFunction<T>([predicate](T value) { return CheckSuccess((*predicate)(value)); });
		}
	}
}
#endif WINCOPIES_UTIL_TYPING_H
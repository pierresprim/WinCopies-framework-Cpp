#pragma once

#ifndef WINCOPIES_UTIL_H
#define WINCOPIES_UTIL_H

#include <cstdlib>

#include "../Kernel/Macros/Type/Interface.hxx"
#include "../Kernel/Macros/Method/Inline.hxx"
#include "../Kernel/Enum/Arithmetic.hxx"

#include "../Core/Enum/Comparison.h"
#include "../Core/Typing/Typing.h"

#include "Math.h"
#include "Delegate.h"
#include "Nullable.h"

using namespace WinCopies::Delegate;
using namespace WinCopies::Typing;

namespace WinCopies
{
#define MAKE_KEY_VALUE_PAIR(structName, keyType, keyName, valueType, valueName) STRUCT structName { keyType keyName; valueType valueName; };

	TEMPLATE_NC(2) MAKE_KEY_VALUE_PAIR(KeyValuePair, T1, Key, T2, Value)

#define _MAKE_ACTION_PAIR(structNameSuffix, fieldType) MAKE_KEY_VALUE_PAIR(CONCATENATE(ActionPair, structNameSuffix), fieldType, PreProcess, fieldType, PostProcess)
#define MAKE_ACTION_PAIR(structNameSuffix, fieldTypeSuffix) _MAKE_ACTION_PAIR(structNameSuffix, CONCATENATE(ActionFunction, fieldTypeSuffix))

		MAKE_ACTION_PAIR(Void, Void)
		TEMPLATE MAKE_ACTION_PAIR(, <T>)

		namespace
	{
		TEMPLATE_IF_SIGNED() struct SetOffsetStruct
		{
		private:
			T& _outStart;
			T& _length;

		public:
			SetOffsetStruct(T& outStart, T& length)
			{
				_outStart = outStart;
				_length = length;
			}

			bool Check(const T value)
			{
				if (Math::Outside(0, value, _length, ByteSelector::First))
				{
					_outStart = 0;

					return true;
				}

				return false;
			}
		};
	}

	TEMPLATE inline SystemErrorCode MemoryReset(T* ptr)
	{
		if (ptr)
		{
			*ptr = T{};

			return SystemErrorCode::Success;
		}

		return SystemErrorCode::BadArguments;
	}

	DLLEXPORT SystemErrorCode MemoryAlloc(size_t const length, void** const result);

#define _MEMORY_ALLOC_FUNC_HEADER(allocKind, nameSuffix, ...) TEMPLATE DLLEXPORT SystemErrorCode Memory##allocKind##nameSuffix
#define MEMORY_ALLOC_FUNC_HEADER(nameSuffix, ...) _MEMORY_ALLOC_FUNC_HEADER(Alloc, nameSuffix, )(VA_OPT(__VA_ARGS__ COMMA, __VA_ARGS__) T** const result)
#define CREATE_MEMORY_ALLOC_FUNC(nameSuffix, prefix, suffix, ...) MEMORY_ALLOC_FUNC_HEADER(nameSuffix, __VA_ARGS__) \
	{ \
		void* _result = 0; \
\
		SystemErrorCode errorCode = MemoryAlloc(sizeof(T), &_result); \
\
		if (errorCode == SystemErrorCode::Success) \
		{ \
			*result = (T*)_result; \
\
			return SystemErrorCode::Success; \
		} \
\
		return errorCode; \
	}
#define CREATE_MEMORY_ALLOC_FUNCS(nameSuffix, prefix, suffix) CREATE_MEMORY_ALLOC_FUNC(nameSuffix, prefix, suffix, size_t* const count) MEMORY_ALLOC_FUNC_HEADER(nameSuffix, size_t count) \
	{ \
		MemoryAlloc##nameSuffix(&count, result); \
	}

	CREATE_MEMORY_ALLOC_FUNC(, , , )
	CREATE_MEMORY_ALLOC_FUNCS(, *count *=, )
	CREATE_MEMORY_ALLOC_FUNCS(Shift, *count = , << *count)
#undef CREATE_MEMORY_ALLOC_FUNCS
#undef CREATE_MEMORY_ALLOC_FUNC
#undef MEMORY_ALLOC_FUNC_HEADER

#define MEMORY_INIT_FUNC_HEADER(nameSuffix, ...) _MEMORY_ALLOC_FUNC_HEADER(Init, nameSuffix)(RENDER_WHEN_VA_ARGS(RENDER_CE, TRANSCRIBE_ARGS, __VA_ARGS__) T** const result)
#define CREATE_MEMORY_INIT_FUNC(nameSuffix, ...) MEMORY_INIT_FUNC_HEADER(nameSuffix, __VA_ARGS__) \
	{ \
		SystemErrorCode errorCode = MemoryAlloc##nameSuffix(CALL_IF_VA_ARGS(RENDER_CE, __VA_ARGS__)(GET_ARG, 1, __VA_ARGS__) result); \
\
		if (errorCode == SystemErrorCode::Success) \
		{ \
			MemoryReset(*result); \
\
			return SystemErrorCode::Success; \
		} \
\
		return errorCode; \
	}
#define CREATE_MEMORY_INIT_FUNCS(nameSuffix) CREATE_MEMORY_INIT_FUNC(nameSuffix, size_t* const, count) MEMORY_INIT_FUNC_HEADER(nameSuffix, size_t, count) \
	{ \
		return MemoryInit##nameSuffix(&count, result); \
	}

	CREATE_MEMORY_INIT_FUNC(, )
	CREATE_MEMORY_INIT_FUNCS()
	CREATE_MEMORY_INIT_FUNCS(Shift)
#undef CREATE_MEMORY_INIT_FUNCS
#undef CREATE_MEMORY_INIT_FUNC
#undef MEMORY_INIT_FUNC_HEADER
#undef _MEMORY_ALLOC_FUNC_HEADER

	SIGNED_FUNC() ErrorCode SetOffset(T inStart, T* const outStart, const T length)
	{
		if (length == 0)

			return ErrorCode::ArgumentOutOfRange;

		int _length = std::abs(length);
		SetOffsetStruct<T> setOffsetStruct(outStart, length);

		if (setOffsetStruct.Check(inStart))

			return ErrorCode::ArgumentOutOfRange;

		if (inStart == outStart)
		{
			*outStart = 0;

			return ErrorCode::Success;
		}

		if (setOffsetStruct.Check(outStart))

			return ErrorCode::ArgumentOutOfRange;

		*outStart = (inStart = outStart - inStart) < 0 ? (length < 0 ? inStart : inStart - length) : (length < 0 ? length + inStart : inStart);

		return ErrorCode::Success;
	}
	SIGNED_FUNC() ErrorCode GetOffset(T const inStart, T outStart, T const length, T* const offset)
	{
		ErrorCode errorCode = SetOffset<T>(inStart, &outStart, length);

		*offset = errorCode == ErrorCode::Success ? outStart : 0;

		return errorCode;
	}

	TEMPLATE ErrorCode TrySetValue(T* const value, bool const test, const FunctionFunction<T>& provider, ErrorCode const onError = ErrorCode::InvalidOperation)
	{
		if (test)
		{
			*value = provider();

			return ErrorCode::Success;
		}

		*value = NULL;

		return onError;
	}
	TEMPLATE INLINE_METHOD_RETURN(0, VIRTUALITY_NONE, ErrorCode, TrySetValue, TrySetValue(value, func(), provider, onError), T* const value, const BoolFunction& func, const FunctionFunction<T>& provider, ErrorCode const onError = ErrorCode::InvalidOperation)

	TEMPLATE ErrorCode TrySetValueOrDefault(T* const value, bool const test, const FunctionFunction<T>& provider, ErrorCode const onError = ErrorCode::InvalidOperation)
	{
		if (test)
		{
			*value = provider();

			return ErrorCode::Success;
		}

		*value = default(T);

		return onError;
	}
	TEMPLATE INLINE_METHOD_RETURN(0, VIRTUALITY_NONE, ErrorCode, TrySetValueOrDefault, TrySetValueOrDefault(value, func(), provider, onError), T* const value, const BoolFunction& func, const FunctionFunction<T>& provider, ErrorCode const onError = ErrorCode::InvalidOperation)

	TEMPLATE INLINE_METHOD_RETURN(0, VIRTUALITY_NONE, ErrorCode, TrySetValue, TrySetValue(value, CheckSuccess(test), provider, onError.GetValueOrCustom(test)), T* const value, ErrorCode const test, const FunctionFunction<T>& provider, Nullable<ErrorCode> const onError)
	TEMPLATE INLINE_METHOD_RETURN(0, VIRTUALITY_NONE, ErrorCode, TrySetValue, TrySetValue(value, CheckSuccess(func()), provider, onError), T* const value, const FunctionFunction<ErrorCode>& func, const FunctionFunction<T>& provider, Nullable<ErrorCode> const onError)

	TEMPLATE INLINE_METHOD_RETURN(0, VIRTUALITY_NONE, ErrorCode, TrySetValueOrDefault, TrySetValueOrDefault(value, CheckSuccess(test), provider, onError.GetValueOrCustom(test)), T* const value, ErrorCode const test, const FunctionFunction<T>& provider, Nullable<ErrorCode> const onError)
	TEMPLATE INLINE_METHOD_RETURN(0, VIRTUALITY_NONE, ErrorCode, TrySetValueOrDefault, TrySetValueOrDefault(value, CheckSuccess(func()), provider, onError), T* const value, const FunctionFunction<ErrorCode>& func, const FunctionFunction<T>& provider, Nullable<ErrorCode> const onError)
}
#endif
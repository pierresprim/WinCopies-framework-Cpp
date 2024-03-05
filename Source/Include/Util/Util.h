#pragma once

#ifndef WINCOPIES_UTIL_H
#define WINCOPIES_UTIL_H

#include <cstdlib>
#include "Math.h"

namespace WinCopies
{
	TEMPLATE2 STRUCT KeyValuePair
	{
		T1 Key;
		T2 Value;
	};
	STRUCT ActionPair
	{
		ActionFunctionVoid PreProcess;
		ActionFunctionVoid PostProcess;
	};
	TEMPLATE STRUCT ActionPair1
	{
		ActionFunction<T> PreProcess;
		ActionFunction<T> PostProcess;
	};

	namespace
	{
		TEMPLATE_IF_SIGNED struct SetOffsetStruct
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

		TEMPLATE static SystemErrorCode _MemoryAlloc(FreeableUniquePtr<T>* const ptr, T* const _ptr)
		{
			if (_ptr == NULL)
			{
				*ptr = NULL;

				return SystemErrorCode::OutOfMemory;
			}

			FREEABLE_UNIQUE_PTR_BASE(*ptr, T, _ptr);

			return SystemErrorCode::Success;
		}
	}

	TEMPLATE INLINE_METHOD MemoryReset(T* ptr) { *ptr = T{}; }

	TEMPLATE DLLEXPORT SystemErrorCode MemoryAlloc(FreeableUniquePtr<T>* const ptr)
	{
		if (*ptr == NULL)
		{
			SystemErrorCode errorCode = _MemoryAlloc(ptr, MALLOC(T));

			if (errorCode != SystemErrorCode::Success)

				return errorCode;
		}

		MemoryReset(ptr->get());

		return SystemErrorCode::Success;
	}

	MULTI_UNSIGNED_INTEGRAL_FUNC(class T2) SystemErrorCode MemoryAllocShift(FreeableUniquePtr<T>* const ptr, T2* const count)
	{
		if (*ptr == NULL)
		{
			SystemErrorCode errorCode = _MemoryAlloc(ptr, MALLOC_SHIFT(T, *count));

			if (errorCode != SystemErrorCode::Success)

				return errorCode;
		}

		MemoryReset(ptr->get());

		return SystemErrorCode::Success;
	}

	MULTI_UNSIGNED_INTEGRAL_FUNC(class T2) SystemErrorCode MemoryAllocMult(FreeableUniquePtr<T>* const ptr, T2* const count)
	{
		if (*ptr == NULL)
		{
			SystemErrorCode errorCode = _MemoryAlloc(ptr, MALLOC_MULT(T, *count));

			if (errorCode != SystemErrorCode::Success)

				return errorCode;
		}

		MemoryReset(ptr->get());

		return SystemErrorCode::Success;
	}

	SIGNED_FUNC ErrorCode SetOffset(T inStart, T* const outStart, const T length)
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
	SIGNED_FUNC ErrorCode GetOffset(T const inStart, T outStart, T const length, T* const offset)
	{
		ErrorCode errorCode = SetOffset<T>(inStart, &outStart, length);

		*offset = errorCode == ErrorCode::Success ? outStart : 0;

		return errorCode;
	}
}

#endif
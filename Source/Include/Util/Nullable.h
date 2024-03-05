#pragma once
#ifndef WINCOPIES_NULLABLE_H
#define WINCOPIES_NULLABLE_H

#include "Exception.h"

namespace WinCopies
{
	TEMPLATE STRUCT Nullable
	{
	private:
		T _value;
		bool _hasValue;

	public:
		INLINE_SET_FIELD(Nullable, T& const, value)

		INLINE_FIELD_RETURN(bool, HasValue, hasValue)

		ErrorCode GetValue(T* value)
		{
			if (_hasValue)
			{
				*value = _value;

				return ErrorCode::Success;
			}

			*value = default;

			return ErrorCode::EmptyObject;
		}
	};
}

#endif // NULLABLE_H

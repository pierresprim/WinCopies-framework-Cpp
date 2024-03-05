#pragma once
#ifndef WINCOPIES_NULLABLE_H
#define WINCOPIES_NULLABLE_H

#include "Exception.h"

namespace WinCopies
{
	TEMPLATE
		struct Nullable
	{
	private:
		T _value;
		bool _hasValue;

	public:
		Nullable(T& const value) { _value = value; }

		bool HasValue() { return _hasValue; }

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

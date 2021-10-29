#pragma once
#ifndef NULLABLE_H
#define NULLABLE_H

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
		Nullable(T value)
		{
			_value = value;
		}

		bool GetHasValue()
		{
			return _hasValue;
		}

		T GetValue()
		{
			if (_hasValue)

				return _value;

			throw new InvalidOperationException(L"There is no value.");
		}
	};
}

#endif // NULLABLE_H

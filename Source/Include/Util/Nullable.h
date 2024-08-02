#pragma once

#ifndef WINCOPIES_NULLABLE_H
#define WINCOPIES_NULLABLE_H

#include "Exception.h"
#include "Misc.h"

namespace WinCopies
{
	TEMPLATE STRUCT Nullable
	{
	private:
		T _value;
		bool _hasValue;

	public:
		INLINE_FIELD_SET(Nullable, T& const, value)

		IINLINE_FIELD_RETURN(bool, HasValue, hasValue)

		GET_FIELD_IF_ELSE(ErrorCode, GetValue, T, value, _hasValue, ErrorCode::Success, default, ErrorCode::EmptyObject)
	};
}

#endif // NULLABLE_H

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
		bool _hasValue;
		T _value;

	public:
		Nullable() = default;
		INLINE_FIELD_SET(Nullable, T& const, value)

		IINLINE_FIELD_RETURN(bool, HasValue, hasValue)

		GET_FIELD_IF_ELSE(ErrorCode, TryGetValue, T, value, _hasValue, ErrorCode::Success, default(T), ErrorCode::EmptyObject)
	};
}

#endif NULLABLE_H
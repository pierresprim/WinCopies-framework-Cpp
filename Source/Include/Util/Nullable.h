#pragma once

#ifndef WINCOPIES_NULLABLE_H
#define WINCOPIES_NULLABLE_H

#include "../Kernel/Macros/Method/Inline.hxx"

#include "UtilBase.h"

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

		IINLINE_FIELD_RETURN(VIRTUALITY_NONE, bool, HasValue, hasValue)

		GET_FIELD_IF_ELSE(ErrorCode, TryGetValue, T, value, _hasValue, ErrorCode::Success, default(T), ErrorCode::EmptyObject)

		INLINE_METHOD_RETURN(1, VIRTUALITY_NONE, T, GetValueOrDefault, _hasValue ? _value : default(T))
		INLINE_METHOD_RETURN(1, VIRTUALITY_NONE, T, GetValueOrCustom, _hasValue ? _value : custom, T custom)
	};
}

#endif NULLABLE_H
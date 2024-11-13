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
		explicit Nullable()
		{
			_hasValue = false;
			_value = NULL;
		}
		explicit Nullable(T const value)
		{
			_hasValue = true;
			_value = value;
		}

		IINLINE_FIELD_RETURN(VIRTUALITY_NONE, bool, HasValue, hasValue)

		GET_FIELD_IF_ELSE(ErrorCode, TryGetValue, T, value, _hasValue, ErrorCode::Success, NULL, ErrorCode::EmptyObject)

		INLINE_METHOD_RETURN(1, VIRTUALITY_NONE, T, GetValueOrDefault, _hasValue ? _value : NULL)
		INLINE_METHOD_RETURN(1, VIRTUALITY_NONE, T, GetValueOrCustom, _hasValue ? _value : custom, T custom)

		STRUCT_DESTRUCTOR_DEFINITION(Nullable);
	};
}

#endif NULLABLE_H
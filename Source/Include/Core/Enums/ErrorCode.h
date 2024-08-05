#pragma once

#ifndef WINCOPIES_UTIL_ERROR_CODE_H
#define WINCOPIES_UTIL_ERROR_CODE_H

#include "../../Kernel/Enum/MakeEnum.hxx"

namespace WinCopies
{
	ENUM_HEADER(ErrorCode, LONG)
	{
		SystemNotification = 1,
		Success = 0,
		_MAKE_ENUM_FIELDS(0, 1, UnknownException, ArgumentException, ArgumentOutOfRange, InvalidOperation, ReadOnly, EmptyObject, ObjectHasChangedDuringEnumeration, ObjectHasNoValue, InvalidCast, NullPtrValue, ObjectIsDisposed, SystemException, NotFound)
	};
}

#endif // WINCOPIES_UTIL_ERROR_CODE_H
#pragma once

#ifndef WINCOPIES_UTIL_ERROR_CODE_H
#define WINCOPIES_UTIL_ERROR_CODE_H

namespace WinCopies
{
	ENUM ErrorCode : LONG
	{
		SystemNotification = 1,
		Success = 0,
		UnknownException = -1,
		ArgumentException = -2,
		ArgumentOutOfRange = -3,
		InvalidOperation = -4,
		ReadOnly = -5,
		EmptyObject = -6,
		ObjectHasChangedDuringEnumeration = -7,
		ObjectHasNoValue = -8,
		InvalidCast = -9,
		NullPtrValue = -10,
		ObjectIsDisposed = -11,
		SystemException = -12,
		NotFound = -13
	};
}

#endif // WINCOPIES_UTIL_ERROR_CODE_H
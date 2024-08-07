#pragma once

#ifndef SYSTEM_API_H
#define SYSTEM_API_H

#include "../Kernel/Enum/Bitwise.hxx"

#include "../Core/Enums/ErrorCode.h"
#include "../Core/Enums/SystemErrorCode.h"

using namespace WinCopies;

#ifdef WINDOWS
_BITWISE_ENUM(1, FormatMessageFlags, System)
{
	MaxWidthMask = FORMAT_MESSAGE_MAX_WIDTH_MASK,
	AllocateBuffer = FORMAT_MESSAGE_ALLOCATE_BUFFER,
	IgnoreInserts = FORMAT_MESSAGE_IGNORE_INSERTS,
	FromString = FORMAT_MESSAGE_FROM_STRING,
	FromHModule = FORMAT_MESSAGE_FROM_HMODULE,
	FromSystem = FORMAT_MESSAGE_FROM_SYSTEM,
	ArgumentArray = FORMAT_MESSAGE_ARGUMENT_ARRAY
};
}
#endif
namespace System
{
#ifdef WINDOWS
#pragma push_macro("FormatMessage")
#undef FormatMessage
	INLINE_FUNCTION DWORD FormatMessage(FormatMessageFlags dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPWSTR lpBuffer, DWORD nSize, va_list* Arguments);
#endif

	namespace ErrorHandling
	{
		INLINE_FUNCTION SystemErrorCode GetLastError();
		INLINE_METHOD SetLastError(const SystemErrorCode& errorCode);
		INLINE_METHOD SetLastError(const SystemErrorCode& systemErrorCode);
		DLLEXPORT ErrorCode SetSystemNotification(const SystemErrorCode& systemErrorCode);
		DLLEXPORT ErrorCode SetSystemError(const SystemErrorCode& systemErrorCode);

		METHOD ThrowIfNullPtrValue(const void* value, const wchar_t* const argumentName);

		static inline Bool CheckMessage(const ErrorCode& x, const ErrorCode& y, const SystemErrorCode& systemErrorCode);
		static inline bool CheckMessage2(const ErrorCode& x, const ErrorCode& y, const SystemErrorCode& systemErrorCode);

		INLINE_FUNCTION Bool CheckNotification(const ErrorCode& errorCode, const SystemErrorCode& systemErrorCode);
		INLINE_FUNCTION Bool CheckError(const ErrorCode& errorCode, const SystemErrorCode& systemErrorCode);

		INLINE_FUNCTION bool CheckNotification2(const ErrorCode& errorCode, const SystemErrorCode& systemErrorCode);
		INLINE_FUNCTION bool CheckError2(const ErrorCode& errorCode, const SystemErrorCode& systemErrorCode);
#ifdef WINDOWS
		INLINE_FUNCTION DWORD FormatMessage(FormatMessageFlags dwFlags, LPCVOID lpSource, SystemErrorCode dwMessageId, DWORD dwLanguageId, LPWSTR lpBuffer, DWORD nSize, va_list* Arguments);
		METHOD FormatMessage(SystemErrorCode* dwMessageId, DWORD dwLanguageId, STDSTRING* const message);
		DLLEXPORT STDSTRING FormatMessage(SystemErrorCode* dwMessageId, DWORD dwLanguageId);
#endif
	}
#ifdef WINDOWS
#pragma pop_macro("FormatMessage")
#endif
}
#endif
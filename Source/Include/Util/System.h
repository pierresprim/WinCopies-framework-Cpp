#pragma once

#ifndef SYSTEM_API_H
#define SYSTEM_API_H

#include "Enum/Bitwise.h"

using namespace WinCopies;

namespace System
{
#ifdef WINDOWS
	ENUM FormatMessageFlags
	{
		MaxWidthMask = FORMAT_MESSAGE_MAX_WIDTH_MASK,
		AllocateBuffer = FORMAT_MESSAGE_ALLOCATE_BUFFER,
		IgnoreInserts = FORMAT_MESSAGE_IGNORE_INSERTS,
		FromString = FORMAT_MESSAGE_FROM_STRING,
		FromHModule = FORMAT_MESSAGE_FROM_HMODULE,
		FromSystem = FORMAT_MESSAGE_FROM_SYSTEM,
		ArgumentArray = FORMAT_MESSAGE_ARGUMENT_ARRAY
	};

	ENABLE_ENUM_BITWISE_OPERATORS(FormatMessageFlags);

#pragma push_macro("FormatMessage")
#undef FormatMessage
	FUNCTION DWORD FormatMessage(FormatMessageFlags dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPWSTR lpBuffer, DWORD nSize, va_list* Arguments);
#endif

	namespace ErrorHandling
	{
		FUNCTION SystemErrorCode GetLastError();
		INLINE_METHOD SetLastError(const SystemErrorCode& errorCode);
		INLINE_METHOD SetLastError(const SystemErrorCode& systemErrorCode);
		DLLEXPORT ErrorCode SetSystemNotification(const SystemErrorCode& systemErrorCode);
		DLLEXPORT ErrorCode SetSystemError(const SystemErrorCode& systemErrorCode);

		METHOD ThrowIfNullPtrValue(const void* value, const wchar_t* const argumentName);

		static inline Bool CheckMessage(const ErrorCode& x, const ErrorCode& y, const SystemErrorCode& systemErrorCode);
		static inline bool CheckMessage2(const ErrorCode& x, const ErrorCode& y, const SystemErrorCode& systemErrorCode);

		FUNCTION Bool CheckNotification(const ErrorCode& errorCode, const SystemErrorCode& systemErrorCode);
		FUNCTION Bool CheckError(const ErrorCode& errorCode, const SystemErrorCode& systemErrorCode);

		FUNCTION bool CheckNotification2(const ErrorCode& errorCode, const SystemErrorCode& systemErrorCode);
		FUNCTION bool CheckError2(const ErrorCode& errorCode, const SystemErrorCode& systemErrorCode);
#ifdef WINDOWS
		FUNCTION DWORD FormatMessage(FormatMessageFlags dwFlags, LPCVOID lpSource, SystemErrorCode dwMessageId, DWORD dwLanguageId, LPWSTR lpBuffer, DWORD nSize, va_list* Arguments);
		METHOD FormatMessage(SystemErrorCode* dwMessageId, DWORD dwLanguageId, STDSTRING* const message);
		DLLEXPORT STDSTRING FormatMessage(SystemErrorCode* dwMessageId, DWORD dwLanguageId);
#endif
	}
#ifdef WINDOWS
#pragma pop_macro("FormatMessage")
#endif
}
#endif
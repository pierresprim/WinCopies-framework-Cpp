#include "pch.h"


#include "../../Include/Util/System.h"
#include "../../Include/Util/Exception.h"

using namespace WinCopies;

namespace System
{
	namespace ErrorHandling
	{
		SystemErrorCode GetLastError()
		{
			return (SystemErrorCode)::GetLastError();
		}
		void SetLastError(const SystemErrorCode& errorCode)
		{
			::SetLastError((DWORD)errorCode);
		}

		ErrorCode SetSystemNotification(const SystemErrorCode& systemErrorCode)
		{
			System::ErrorHandling::SetLastError(systemErrorCode);

			return ErrorCode::SystemNotification;
		}
		ErrorCode SetSystemError(const SystemErrorCode& systemErrorCode)
		{
			System::ErrorHandling::SetLastError(systemErrorCode);

			return ErrorCode::SystemException;
		}

		void ThrowIfNullPtrValue(const void* value, const wchar_t* const argumentName)
		{
			if (value == nullptr)

				throw new NullPtrValueException(argumentName);
		}

		Bool CheckMessage(const ErrorCode& x, const ErrorCode& y, const SystemErrorCode& systemErrorCode)
		{
			return x == y ? (GetLastError() == systemErrorCode ? Bool::True : Bool::False) : Bool::None;
		}
		bool CheckMessage2(const ErrorCode& x, const ErrorCode& y, const SystemErrorCode& systemErrorCode)
		{
			return CheckMessage(x, y, systemErrorCode) == Bool::True;
		}

		Bool CheckNotification(const ErrorCode& errorCode, const SystemErrorCode& systemErrorCode)
		{
			return CheckMessage(ErrorCode::SystemNotification, errorCode, systemErrorCode);
		}
		Bool CheckError(const ErrorCode& errorCode, const SystemErrorCode& systemErrorCode)
		{
			return CheckMessage(ErrorCode::SystemException, errorCode, systemErrorCode);
		}

		bool CheckNotification2(const ErrorCode& errorCode, const SystemErrorCode& systemErrorCode)
		{
			return CheckMessage2(ErrorCode::SystemNotification, errorCode, systemErrorCode);
		}
		bool CheckError2(const ErrorCode& errorCode, const SystemErrorCode& systemErrorCode)
		{
			return CheckMessage2(ErrorCode::SystemException, errorCode, systemErrorCode);
		}
#ifdef _WIN32
#pragma push_macro("FormatMessage")
#undef FormatMessage
#endif
		DWORD FormatMessage(FormatMessageFlags dwFlags, LPCVOID lpSource, SystemErrorCode dwMessageId, DWORD dwLanguageId, LPWSTR lpBuffer, DWORD nSize, va_list* Arguments)
		{
			return System::FormatMessage(dwFlags, lpSource, (DWORD)dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments);
		}
		void FormatMessage(SystemErrorCode* dwMessageId, DWORD dwLanguageId, STDSTRING* const message)
		{
			LPWSTR lpMsgBuf = NULL;

			DWORD size = System::ErrorHandling::FormatMessage(FormatMessageFlags::AllocateBuffer | FormatMessageFlags::FromSystem | FormatMessageFlags::IgnoreInserts, NULL, *dwMessageId, dwLanguageId, (LPTSTR)&lpMsgBuf, 0, NULL);

			if (size)
			{
				*message = STDSTRING(lpMsgBuf, size);

				LocalFree(lpMsgBuf);

				*dwMessageId = SystemErrorCode::Success;
			}

			*dwMessageId = GetLastError();

			*message = STDSTRING();
		}
		STDSTRING FormatMessage(SystemErrorCode* dwMessageId, DWORD dwLanguageId)
		{
			STDSTRING message;

			FormatMessage(dwMessageId, dwLanguageId, &message);

			return message;
		}
	}

	DWORD FormatMessage(FormatMessageFlags dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPWSTR lpBuffer, DWORD nSize, va_list* Arguments)
	{
#ifdef _WIN32
#pragma pop_macro("FormatMessage")
#endif
		return ::FormatMessage((DWORD)dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments);
	}
}
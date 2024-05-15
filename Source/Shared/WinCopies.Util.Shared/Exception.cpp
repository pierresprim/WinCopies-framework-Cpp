#include "pch.h"

#include "../../Include/Util/Exception.h"

using namespace std::string_literals;
using namespace std::string_view_literals;

namespace WinCopies
{
	Exception::Exception(const ErrorCode errorCode, STDSTRING* const message) : ExceptionBase(errorCode, (char*)(message ? message : new STDSTRING(UNKNOWN_ERROR)))
	{
		// Left empty.
	}
	Exception::Exception(const ErrorCode errorCode, const LPCWSTR message) : Exception(errorCode, new STDSTRING(message ? message : UNKNOWN_ERROR))
	{
		// Left empty.
	}

	Exception::~Exception()
	{
		delete GetErrorMessage();
	}

	STDSTRING* Exception::GetErrorMessage() const
	{
		return (STDSTRING*)what();
	}

	WinCopiesException::~WinCopiesException()
	{
		// Left empty.
	}

	ArgumentException::ArgumentException(const ErrorCode errorCode, STDSTRING* const message, STDSTRING* const argumentName) : WinCopiesException(errorCode, message)
	{
		_argumentName = argumentName;
	}
	ArgumentException::ArgumentException(const ErrorCode errorCode, const LPCWSTR message, const LPCWSTR argumentName) : WinCopiesException(errorCode, message)
	{
		_argumentName = argumentName ? new STDSTRING(argumentName) : NULL;
	}
	ArgumentException::ArgumentException(STDSTRING* const message, STDSTRING* const argumentName) : ArgumentException(ErrorCode::ArgumentException, message, argumentName)
	{
		// Left empty.
	}
	ArgumentException::ArgumentException(const LPCWSTR message, const LPCWSTR argumentName) : ArgumentException(ErrorCode::ArgumentException, message, argumentName)
	{
		// Left empty.
	}

	ArgumentException::~ArgumentException()
	{
		if (_argumentName)
		{
			delete _argumentName;
			_argumentName = NULL;
		}
	}

	STDSTRING* ArgumentException::GetArgumentName() const
	{
		return _argumentName;
	}

	ArgumentOutOfRangeException::ArgumentOutOfRangeException(STDSTRING* const argumentName) : ArgumentException(ErrorCode::ArgumentOutOfRange, new STDSTRING(*argumentName + L" is out of range."), argumentName)
	{
		// Left empty.
	}
	ArgumentOutOfRangeException::ArgumentOutOfRangeException(const LPCWSTR argumentName) : ArgumentOutOfRangeException(new STDSTRING(argumentName))
	{
		// Left empty.
	}

	ArgumentOutOfRangeException::~ArgumentOutOfRangeException()
	{
		// Left empty.
	}

	InvalidOperationException::InvalidOperationException(STDSTRING* const message) : InvalidOperationException(ErrorCode::InvalidOperation, message)
	{
		// Left empty.
	}
	InvalidOperationException::InvalidOperationException(const ErrorCode errorCode, STDSTRING* const message) : WinCopiesException(errorCode, message)
	{
		// Left empty.
	}
	InvalidOperationException::InvalidOperationException(const LPCWSTR message) : InvalidOperationException(new STDSTRING(message))
	{
		// Left empty.
	}
	InvalidOperationException::InvalidOperationException(const ErrorCode errorCode, const LPCWSTR message) : WinCopiesException(errorCode, new STDSTRING(message))
	{
		// Left empty.
	}

	InvalidOperationException::~InvalidOperationException()
	{
		// Left empty.
	}

	ReadOnlyException::ReadOnlyException() : WinCopiesException(ErrorCode::ReadOnly, L"The current object is read-only.")
	{
		// Left empty.
	}

	ReadOnlyException::~ReadOnlyException()
	{
		// Left empty;
	}

	EmptyObjectException::EmptyObjectException() : InvalidOperationException(ErrorCode::ReadOnly, L"The current object is empty.")
	{
		// Left empty.
	}

	EmptyObjectException::~EmptyObjectException()
	{
		// Left empty.
	}

	NullPtrValueException::NullPtrValueException(STDSTRING* const argumentName) : ArgumentException(ErrorCode::NullPtrValue, new STDSTRING(L"The given value is nullptr."), argumentName)
	{
		// Left empty.
	}
	NullPtrValueException::NullPtrValueException(const LPCWSTR argumentName) : NullPtrValueException(new STDSTRING(argumentName))
	{
		// Left empty.
	}

	NullPtrValueException::~NullPtrValueException()
	{
		// Left empty.
	}

	SystemException::SystemException(const SystemErrorCode errorCode, STDSTRING* const message) : ExceptionBase(errorCode, message ? (char*)message : &_empty)
	{
		// Left empty.
	}
	SystemException::SystemException(const SystemErrorCode errorCode) : SystemException(errorCode, NULL) { /* Left empty. */ }

	STDSTRING SystemException::GetErrorMessage(STDSTRING** errorMessage) const
	{
		char const* const _what = what();

		if (_what != &_empty)
		{
			*errorMessage = (STDSTRING*)_what;

			return STDSTRING();
		}

		SystemErrorCode errorCode = GetErrorCode();
		SystemErrorCode msgErrorCode = SystemErrorCode::Error;

		if (*errorMessage = (STDSTRING*)malloc(sizeof(STDSTRING)))
		{
#ifdef _WIN32
#pragma push_macro("FormatMessage")
#undef FormatMessage
#endif
			System::ErrorHandling::FormatMessage(&msgErrorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), *errorMessage);
#ifdef _WIN32
#pragma pop_macro("FormatMessage")
#endif
			if (msgErrorCode == SystemErrorCode::Success)
			{
				SystemException* ptr = (SystemException*)this;

				*ptr = SystemException(errorCode, *errorMessage);

				return STDSTRING();
			}
		}

		else

			msgErrorCode = SystemErrorCode::OutOfMemory;

		*errorMessage = NULL;

		auto _errorCode = TO_UNDERLYING_TYPE(errorCode);
		auto _msgErrorCode = TO_UNDERLYING_TYPE(msgErrorCode);

		return WinCopies::Format(L"Could not retrieve error message. The exception error is {} and the message retrieval error is {}."sv, _errorCode, _msgErrorCode);
	}
}

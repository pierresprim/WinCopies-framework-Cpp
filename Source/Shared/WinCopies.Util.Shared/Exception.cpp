#include "pch.h"
#include "..\Include\Util\Exception.h"

namespace WinCopies
{
	Exception::Exception(const int errorCode, const wchar_t* const message)
	{
		_errorCode = errorCode;
		_message = message;
	}

	Exception::~Exception()
	{
		delete _message;

		_message = nullptr;
	}

	int Exception::GetErrorCode() const
	{
		return _errorCode;
	}

	wchar_t const* Exception::GetErrorMessage() const
	{
		return _message;
	}

	WinCopiesException::~WinCopiesException()
	{
		// Left empty.
	}

	ArgumentException::ArgumentException(const wchar_t* const message, const wchar_t* const argumentName) : ArgumentException(ARGUMENT_EXCEPTION, message, argumentName)
	{
		// Left empty.
	}

	ArgumentException::ArgumentException(const int errorCode, const wchar_t* const message, const wchar_t* const argumentName) : WinCopiesException(errorCode, message)
	{
		_argumentName = argumentName;
	}

	ArgumentException::~ArgumentException()
	{
		delete _argumentName;

		_argumentName = nullptr;
	}

	const wchar_t* ArgumentException::GetArgumentName()
	{
		return _argumentName;
	}

	ArgumentOutOfRangeException::ArgumentOutOfRangeException(const wchar_t* const argumentName) : ArgumentException(ARGUMENT_OUT_OF_RANGE_EXCEPTION, std::wstring(argumentName, L" is out of range.").c_str(), argumentName)
	{
		// Left empty.
	}

	ArgumentOutOfRangeException::~ArgumentOutOfRangeException()
	{
		// Left empty.
	}

	InvalidOperationException::InvalidOperationException(const wchar_t* const message) : InvalidOperationException(INVALID_OPERATION_EXCEPTION, message)
	{
		// Left empty.
	}

	InvalidOperationException::InvalidOperationException(const int errorCode, const wchar_t* const message) : WinCopiesException(errorCode, message)
	{
		// Left empty.
	}

	InvalidOperationException::~InvalidOperationException()
	{
		// Left empty.
	}

	ReadOnlyException::ReadOnlyException() : WinCopiesException(READ_ONLY_EXCEPTION, L"The current object is read-only.")
	{
		// Left empty.
	}

	ReadOnlyException::~ReadOnlyException()
	{
		// Left empty;
	}

	EmptyObjectException::EmptyObjectException() : InvalidOperationException(READ_ONLY_EXCEPTION, L"The current object is empty.")
	{
		// Left empty.
	}

	EmptyObjectException::~EmptyObjectException()
	{
		// Left empty.
	}

	NullPtrValueException::NullPtrValueException(const wchar_t* const argumentName) : ArgumentException(NULLPTR_VALUE_EXCEPTION, L"The given value is nullptr.", argumentName)
	{
		// Left empty.
	}

	NullPtrValueException::~NullPtrValueException()
	{
		// Left empty.
	}
}

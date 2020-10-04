#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
#include "wincopies_defines.h"

namespace WinCopies
{
    class DLLEXPORT Exception
	{
	private:
		int _errorCode;
		const wchar_t* _message;
	public:
		explicit Exception(const int errorCode, const wchar_t* const message)
		{
			_errorCode = errorCode;
			_message = message;
		}

		~Exception()
		{
			delete _message;
		}

		int GetErrorCode() const
		{
			return _errorCode;
		}

		wchar_t const* GetErrorMessage() const
		{
			return _message;
		}
	};

	/// <summary>
	/// This exception should have an error code defined in the WinCopies.Util.Base.Shared's defines header file.
	/// </summary>
	class DLLEXPORT WinCopiesException : public Exception
	{
		using Exception::Exception;
	};

	class DLLEXPORT ArgumentException : public WinCopiesException
	{
	private:
		const wchar_t* _argumentName;
	public:
		explicit ArgumentException(const wchar_t* const message, const wchar_t* const argumentName) : ArgumentException(ARGUMENT_EXCEPTION, message, argumentName)
		{
			// Left empty.
		}

		explicit ArgumentException(const int errorCode, const wchar_t* const message, const wchar_t* const argumentName) : WinCopiesException(errorCode, message)
		{
			_argumentName = argumentName;
		}

		~ArgumentException()
		{
			delete _argumentName;
		}

        const wchar_t* GetArgumentName()
		{
			return _argumentName;
		}
	};

	class DLLEXPORT ArgumentOutOfRangeException : public ArgumentException
	{
	public:
		explicit ArgumentOutOfRangeException(const wchar_t* const argumentName) : ArgumentException(ARGUMENT_OUT_OF_RANGE_EXCEPTION, std::wstring(argumentName, L" is out of range.").c_str(), argumentName)
		{
			// Left empty.
		}
	};

	class DLLEXPORT InvalidOperationException : public WinCopiesException
	{
	public:
		explicit InvalidOperationException(const wchar_t* const message) : InvalidOperationException(INVALID_OPERATION_EXCEPTION, message)
		{
			// Left empty.
		}

		explicit InvalidOperationException(const int errorCode, const wchar_t* const message) : WinCopiesException(errorCode, message)
		{
			// Left empty.
		}
	};

	class DLLEXPORT ReadOnlyException : public WinCopiesException
	{
	public:
		ReadOnlyException() : WinCopiesException(READ_ONLY_EXCEPTION, L"The current object is read-only.")
		{
			// Left empty.
		}
	};

	class DLLEXPORT EmptyObjectException : public InvalidOperationException
	{
	public:
		EmptyObjectException() : InvalidOperationException(READ_ONLY_EXCEPTION, L"The current object is empty.")
		{
			// Left empty.
		}
	};
}

#endif

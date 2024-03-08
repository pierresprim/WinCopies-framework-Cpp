#pragma once

#ifndef WINCOPIES_EXCEPTION_H
#define WINCOPIES_EXCEPTION_H

#include "UtilBase.h"
#include "System.h"

namespace WinCopies
{
	TEMPLATE
	CLASS ExceptionBase : public std::exception
	{
	private:
		T _errorCode;

	public:
		explicit ExceptionBase(const T errorCode, const LPCSTR message) : std::exception(message, 1)
		{
			_errorCode = errorCode;
		}

		T GetErrorCode() const
		{
			return _errorCode;
		}
	};

	CLASS Exception : public ExceptionBase<ErrorCode>
	{
	private:
		LPCWSTR UNKNOWN_ERROR = L"Unknown error.";

	public:
		explicit Exception(const ErrorCode errorCode, STDSTRING* const message);
		explicit Exception(const ErrorCode errorCode, const LPCWSTR message);

		virtual ~Exception();

		inline STDSTRING* GetErrorMessage() const;
	};

	CLASS WinCopiesException : public Exception
	{
	public:
		using Exception::Exception;

		virtual ~WinCopiesException() override;
	};

	CLASS ArgumentException : public WinCopiesException
	{
	private:
		STDSTRING* _argumentName;
	public:
		explicit ArgumentException(const ErrorCode errorCode, STDSTRING* const message, STDSTRING* const argumentName);
		explicit ArgumentException(const ErrorCode errorCode, const LPCWSTR message, const LPCWSTR argumentName);
		explicit ArgumentException(STDSTRING* const message, STDSTRING* const argumentName);
		explicit ArgumentException(const LPCWSTR message, const LPCWSTR argumentName);

		virtual ~ArgumentException() override;

		inline STDSTRING* GetArgumentName() const;
	};

	CLASS ArgumentOutOfRangeException : public ArgumentException
	{
	public:
		explicit ArgumentOutOfRangeException(STDSTRING* const argumentName);
		explicit ArgumentOutOfRangeException(const LPCWSTR argumentName);

		virtual ~ArgumentOutOfRangeException() override;
	};

	CLASS InvalidOperationException : public WinCopiesException
	{
	public:
		explicit InvalidOperationException(STDSTRING* const message);
		explicit InvalidOperationException(const LPCWSTR message);
		explicit InvalidOperationException(const ErrorCode errorCode, STDSTRING* const message);
		explicit InvalidOperationException(const ErrorCode errorCode, const LPCWSTR message);

		virtual ~InvalidOperationException() override;
	};

	CLASS ReadOnlyException : public WinCopiesException
	{
	public:
		ReadOnlyException();

		virtual ~ReadOnlyException() override;
	};

	CLASS EmptyObjectException : public InvalidOperationException
	{
	public:
		EmptyObjectException();

		virtual ~EmptyObjectException() override;
	};

	CLASS NullPtrValueException : public ArgumentException
	{
	public:
		NullPtrValueException(STDSTRING* const argumentName);
		NullPtrValueException(const LPCWSTR argumentName);

		virtual ~NullPtrValueException() override;
	};

	CLASS SystemException : public ExceptionBase<SystemErrorCode>
	{
	private:
		char _empty = '\0';

	public:
		explicit SystemException(const SystemErrorCode errorCode, STDSTRING* const message);
		explicit SystemException(const SystemErrorCode errorCode);

		virtual ~SystemException() = default;

		STDSTRING GetErrorMessage(STDSTRING** const errorMessage) const;
	};
}
#endif

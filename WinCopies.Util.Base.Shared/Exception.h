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
        explicit Exception(const int errorCode, const wchar_t* const message);

        ~Exception();

        int GetErrorCode() const;

        wchar_t const* GetErrorMessage() const;
	};

	class DLLEXPORT WinCopiesException : public Exception
	{
    public:
		using Exception::Exception;

        virtual ~WinCopiesException();
	};

	class DLLEXPORT ArgumentException : public WinCopiesException
	{
	private:
		const wchar_t* _argumentName;
	public:
        explicit ArgumentException(const wchar_t* const message, const wchar_t* const argumentName);

        explicit ArgumentException(const int errorCode, const wchar_t* const message, const wchar_t* const argumentName);

        virtual ~ArgumentException();

        const wchar_t* GetArgumentName();
	};

	class DLLEXPORT ArgumentOutOfRangeException : public ArgumentException
	{
	public:
        explicit ArgumentOutOfRangeException(const wchar_t* const argumentName);

        virtual ~ArgumentOutOfRangeException();
	};

	class DLLEXPORT InvalidOperationException : public WinCopiesException
	{
	public:
        explicit InvalidOperationException(const wchar_t* const message);

        explicit InvalidOperationException(const int errorCode, const wchar_t* const message);

        virtual ~InvalidOperationException();
	};

	class DLLEXPORT ReadOnlyException : public WinCopiesException
	{
	public:
        ReadOnlyException();

        virtual ~ReadOnlyException();
	};

	class DLLEXPORT EmptyObjectException : public InvalidOperationException
	{
	public:
        EmptyObjectException();

        virtual ~EmptyObjectException();
	};
}

#endif

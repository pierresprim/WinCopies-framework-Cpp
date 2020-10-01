#pragma once
#define DLLEXPORT __declspec(dllexport)
#include <Windows.h>

namespace WinCopies
{
	namespace IO
	{
		class DLLEXPORT FileSystemObject abstract
		{
		private:
			wchar_t const* _path;

		public:
			FileSystemObject() = delete;
			FileSystemObject(wchar_t const* const path);
			wchar_t const* const GetPath();
		};
	}
}


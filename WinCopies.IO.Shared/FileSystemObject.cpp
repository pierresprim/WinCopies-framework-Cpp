#include "pch.h"
#include "FileSystemObject.h"

namespace WinCopies
{
	namespace IO
	{
		FileSystemObject::FileSystemObject(wchar_t const* const path)
		{
			_path = path;
		}

		wchar_t const* const FileSystemObject::GetPath()
		{
			return _path;
		}
	}
}

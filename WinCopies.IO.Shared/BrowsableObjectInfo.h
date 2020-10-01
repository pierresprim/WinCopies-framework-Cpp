#pragma once
#include "FileSystemObject.h"
namespace WinCopies
{
	namespace IO
	{
		class __declspec(dllexport) BrowsableObjectInfo abstract : public FileSystemObject
		{
		public:
			BrowsableObjectInfo(wchar_t const* const path) : FileSystemObject(path) { }
			virtual bool GetIsBrowsable()=0;
		};
	}
}


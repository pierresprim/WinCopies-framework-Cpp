#pragma once
#include "BrowsableObjectInfo.h"
namespace WinCopies
{
	namespace IO
	{
		class __declspec(dllexport) ShellObjectInfo : public BrowsableObjectInfo
		{
		public:
			ShellObjectInfo(wchar_t const* const path) :BrowsableObjectInfo(path) { }
			bool GetIsBrowsable();
		};
	}
}


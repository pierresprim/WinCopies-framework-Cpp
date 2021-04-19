#pragma once
#ifndef COUNTABLE
#define COUNTABLE

#include "defines.h"

namespace WinCopies
{
	namespace Collections
	{
		INTERFACE(ICountable)
		{
		public:
			virtual ~ICountable() {}

			ABSTRACT_METHOD_CONST(int GetCount);
		};

		INTERFACE(IUIntCountable)
		{
		public:
			virtual ~IUIntCountable() {}

			ABSTRACT_METHOD_CONST(UINT GetCount);
		};

		INTERFACE(ILongCountable)
		{
		public:
			virtual ~ILongCountable() {}

			ABSTRACT_METHOD_CONST(long long GetCount);
		};

		INTERFACE(IULongCountable)
		{
			virtual ~IULongCountable() {}

			ABSTRACT_METHOD_CONST(ULONGLONG GetCount);
		};
	}
}

#endif

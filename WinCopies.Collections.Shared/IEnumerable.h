#pragma once
#ifndef IENUMERABLE_H
#define IENUMERABLE_H
#include "defines.h"
#include "IEnumerator.h"

namespace WinCopies
{
	namespace Collections
	{
		_T
		class DLLEXPORT IEnumerable abstract
		{
		public:
			~IEnumerable() {}

			virtual IEnumerator<T>* GetEnumerator() const = 0;
		};
	}
}

#endif

#pragma once
#ifndef IENUMERABLE_H
#define IENUMERABLE_H
#include "defines.h"
#include "IEnumerator.h"

namespace WinCopies
{
	namespace Collections
	{
        TEMPLATE
        class DLLEXPORT IEnumerable ABSTRACT
		{
		public:
            virtual ~IEnumerable() {}

            virtual IEnumerator<T>* GetEnumerator() = 0;
		};
	}
}

#endif

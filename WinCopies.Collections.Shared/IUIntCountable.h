#pragma once
#ifndef IUINTCOUNTABLE_H
#define IUINTCOUNTABLE_H

#include "defines.h"

namespace WinCopies
{
	namespace Collections
	{
        class DLLEXPORT IUIntCountable ABSTRACT
		{
        public:
            virtual ~IUIntCountable() {}

			virtual unsigned int GetCount() const = 0;
		};
	}
}

#endif

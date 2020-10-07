#pragma once
#ifndef IENUMERABLE_H
#define IENUMERABLE_H
#include "defines.h"
#include "IEnumerator.h"
#include "IUIntCountable.h"

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

            template <class F>
            int ForEach(F func)
            {
IEnumerator<T>* enumerator = GetEnumerator();

int errorCode;
bool moveNextSucceeded = false;

while ((errorCode = enumerator->MoveNext(&moveNextSucceeded)) > 0 && moveNextSucceeded)
{
    func(enumerator->Current);
}

return errorCode;
            }
		};

        TEMPLATE
        class DLLEXPORT IUIntCountableEnumerable ABSTRACT :
                public virtual IUIntCountable,
                public virtual IEnumerable<T>
        {
public:
            virtual ~IUIntCountableEnumerable() override = default;
        };
	}
}

#endif

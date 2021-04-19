#pragma once
#ifndef IENUMERATOR_H
#define IENUMERATOR_H
#include "defines.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			enum class DLLEXPORT EnumerationDirection
			{
				Undetermined = 0,

				FIFO = 1,

				LIFO = 2
			};

			TEMPLATE
				class DLLEXPORT IEnumerator ABSTRACT
			{
			public:
				virtual ~IEnumerator()
				{
					// Left empty.
				}

				virtual bool GetIsStarted() const = 0;
				virtual bool GetIsCompleted() const = 0;
				virtual bool GetIsResetSupported() const = 0;
				virtual EnumerationDirection GetEnumerationDirection() const = 0;

				virtual T GetCurrent() const = 0;

				virtual int MoveNext(bool* result) = 0;
				virtual int Reset() = 0;
			};
		}
	}
}

#endif

#pragma once
#ifndef IENUMERATOR_H
#define IENUMERATOR_H
#include "defines.h"

namespace WinCopies
{
	namespace Collections
	{
		_T
		class DLLEXPORT IEnumerator abstract
		{
		public:
			~IEnumerator() {}

			virtual bool GetIsStarted() const = 0;
			virtual bool GetIsCompleted() const = 0;
			virtual bool GetIsResetSupported() const = 0;

			virtual T GetCurrent() const = 0;

			virtual int MoveNext(bool *result) = 0;
			virtual int Reset() = 0;
		};
	}
}

#endif

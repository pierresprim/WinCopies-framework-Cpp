#pragma once
#ifndef ENUMERATORBASE_H
#define ENUMERATORBASE_H
#include "defines.h"
#include "../WinCopies.Util.Base.Shared/Exception.h"

namespace WinCopies
{
	namespace Collections
	{
		_T
			class DLLEXPORT EnumeratorBase abstract:
		public virtual IEnumerator<T>
		{
		private:
			bool _isStarted = false;
			bool _isCompleted = false;
		public:
			~EnumeratorBase()
			{
				delete _isStarted;
				delete _isCompleted;
			}

			bool GetIsStarted()
			{
				return _isStarted;
			}

			bool GetIsCompleted()
			{
				return _isCompleted;
			}

			virtual bool GetIsResetSupported() const = 0;

			T GetCurrent()
			{
				if (_isStarted && !_isCompleted)

					return GetCurrentOverride();

				throw new InvalidOperationException("The enumeration is not started or is completed.");
			}

			int MoveNext(bool* result)
			{
				if (_isCompleted)
				{
					&result = false;

					return EXIT_SUCCESS;
				}

				if (MoveNextOverride(result) < 0 || !&result)
				{
					_isCompleted = true;

					_isStarted = false;
				}
			}

			int Reset()
			{
				if (!_isStarted)

					return;

				int result = ResetOverride();

				if (result >= 0)
				{
					_isStarted = false;

					_isCompleted = false;
				}

				return result;
			}

			virtual T GetCurrentOverride() = 0;
			virtual int MoveNextOverride(bool* result) = 0;
			virtual int ResetOverride() = 0;
		};
	}
}

#include "EnumeratorBase.cpp"

#endif

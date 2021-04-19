#pragma once
#ifndef ENUMERATORBASE_H
#define ENUMERATORBASE_H

#include "defines.h"
#include "IEnumerator.h"
#include "IEnumerable.h"
#include "../WinCopies.Util.Shared/Exception.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				INTERFACE(EnumeratorBase) :
			public virtual IEnumerator<T>
			{
			private:
				bool _isStarted = false;
				bool _isCompleted = false;
			public:
				virtual ~EnumeratorBase() override = default;

				virtual bool GetIsStarted() const final
				{
					return _isStarted;
				}

				virtual bool GetIsCompleted() const final
				{
					return _isCompleted;
				}

				virtual T GetCurrent() const final
				{
					if (_isStarted && !_isCompleted)

						return GetCurrentOverride();

					throw new InvalidOperationException(L"The enumeration is not started or is completed.");
				}

				virtual int MoveNext(bool* result) final
				{
					if (_isCompleted)
					{
						*result = false;

						return EXIT_SUCCESS;
					}

					_isStarted = true;

					int errorCode = MoveNextOverride(result);

					if (errorCode < 0 || !*result)
					{
						_isCompleted = true;

						_isStarted = false;
					}

					return errorCode;
				}

				virtual int Reset() final
				{
					if (!_isStarted)

						return 0;

					int result = ResetOverride();

					if (result >= 0)
					{
						_isStarted = false;

						_isCompleted = false;
					}

					return result;
				}

				virtual T GetCurrentOverride() const = 0;
				virtual int MoveNextOverride(bool* result) = 0;
				virtual int ResetOverride() = 0;
			};
		}
	}
}

#endif

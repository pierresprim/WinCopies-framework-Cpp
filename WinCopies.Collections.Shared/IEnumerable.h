#pragma once
#ifndef IENUMERABLE_H
#define IENUMERABLE_H

#include <stdlib.h>

#include "defines.h"
#include "IEnumerator.h"
#include "Countable.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			typedef bool(*ForEach_t)(int);
			TEMPLATE
				INTERFACE(IEnumerable)
			{
			private:
				int _ForEach(ForEach_t func, IEnumerator<T>*enumerator)
				{
					int errorCode;
					bool moveNextSucceeded = false;

					while ((errorCode = enumerator->MoveNext(&moveNextSucceeded)) >= 0 && moveNextSucceeded)

						if (func(enumerator->GetCurrent()))

							break;

					delete enumerator;
					enumerator = nullptr;

					return errorCode;
				}

			public:
				virtual ~IEnumerable()
				{
					// Left empty.
				}

				virtual IEnumerator<T>* GetEnumerator() = 0;

				virtual bool GetSupportsReversedEnumeration() const = 0;

				virtual IEnumerator<T>* GetReversedEnumerator() = 0;

				int ForEach(ForEach_t func)
				{
					return _ForEach(func, GetEnumerator());
				}

				METHOD_TEMPLATE
					int ReversedForEach(ForEach_t func)
				{
					return GetSupportsReversedEnumeration() ? _ForEach(func, GetReversedEnumerator()) : INVALID_OPERATION_EXCEPTION;
				}

				/*int First(PREDICATE_PARAMETER, T** result)
				{
					auto func = [](T item) -> bool
					{

					};

					bool(IEnumerable<T>:: * func)(T)

						int retVal = ForEach();

					if (retVal < 0)

						*result = nullptr;
				}*/
			};

			TEMPLATE
				INTERFACE(IUIntCountableEnumerable) :
				public virtual IUIntCountable,
				BASE_INTERFACE IEnumerable<T>
			{
	public:
				int First(T * result)
				{
						IEnumerator<T>* enumerator = this->GetEnumerator();

						int retVal = 0;

						bool moveNextSucceeded = false;

						__try
						{
							if ((retVal = enumerator->MoveNext(&moveNextSucceeded)) >= 0)
							{
								if (moveNextSucceeded)
								{
									*result = enumerator->GetCurrent();

									return EXIT_SUCCESS;
								}

								else

									return EMPTY_OBJECT_EXCEPTION;
							}

							return retVal;
						}

						__finally
						{
							delete enumerator;
							enumerator = nullptr;
						}
				}
				virtual ~IUIntCountableEnumerable() override = default;
			};
		}
	}
}

#endif

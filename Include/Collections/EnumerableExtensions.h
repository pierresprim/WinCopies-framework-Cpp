#pragma once
#ifndef ENUMERABLEEXTENSIONS_H
#define ENUMERABLEEXTENSIONS_H

#include "defines.h"
#include "IEnumerable.h"
#include "../Util/Nullable.h"
#include "WhereEnumerable.h"

using namespace WinCopies;

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				CLASS EnumerableExtensions
			{
			private:
				EnumerableExtensions() { /* Left empty. */ }

			public:
				static int FirstOrValue(IEnumerable<T>*const enumerable, T* const result, bool* const succeeded, const T defaultValue)
				{
					IEnumerator<T>* enumerator = enumerable->GetEnumerator();

					int retVal = 0;

					bool moveNextSucceeded = false;

					__try
					{
						if ((retVal = enumerator->MoveNext(&moveNextSucceeded)) >= 0)
						{
							if (moveNextSucceeded)
							{
								*result = enumerator->GetCurrent();

								*succeeded = true;

								return retVal;
							}
						}

						*result = defaultValue;

						*succeeded = false;

						return retVal;
					}

					__except
					{
						throw;
					}

					__finally
					{
						delete enumerator;
						enumerator = nullptr;
					}
				}

				static int FirstOrValue(IEnumerable<T>*const enumerable, T* const result, bool* const succeeded, const T defaultValue, const PREDICATE_PARAMETER)
				{
					WhereEnumerable<T>* _enumerable = new WhereEnumerable<T>(enumerable, predicate, false);

					int retVal = FirstOrValue(_enumerable, result, succeeded, defaultValue);

					delete _enumerable;

					_enumerable = nullptr;

					return retVal;
				}

				static int FirstOrValue(IEnumerable<T>*const enumerable, T* const result, bool* const succeeded, const NAMED_FUNC_PARAMETER(defaultValueFunc))
				{
					IEnumerator<T>* enumerator = enumerable->GetEnumerator();

					int retVal = 0;

					bool moveNextSucceeded = false;

					__try
					{
						if ((retVal = enumerator->MoveNext(&moveNextSucceeded)) >= 0)
						{
							if (moveNextSucceeded)
							{
								*result = enumerator->GetCurrent();

								*succeeded = true;

								return retVal;
							}
						}

						*result = defaultValueFunc();

						*succeeded = false;

						return retVal;
					}

					__except
					{
						throw;
					}

					__finally
					{
						delete enumerator;
						enumerator = nullptr;
					}
				}

				static int FirstOrValue(IEnumerable<T>*const enumerable, T* const result, bool* const succeeded, const NAMED_FUNC_PARAMETER(defaultValueFunc), const PREDICATE_PARAMETER)
				{
					WhereEnumerable<T>* _enumerable = new WhereEnumerable<T>(enumerable, predicate, false);

					int retVal = FirstOrValue(_enumerable, result, succeeded, defaultValueFunc);

					delete _enumerable;

					_enumerable = nullptr;

					return retVal;
				}

				static int FirstOrDefault(IEnumerable<T>*const enumerable, T* const result, bool* const succeeded)
				{
					return FirstOrValue(enumerable, result, succeeded, default(T));
				}

				static int FirstOrDefault(IEnumerable<T>*const enumerable, T* const result, bool* const succeeded, const PREDICATE_PARAMETER)
				{
					WhereEnumerable<T>* _enumerable = new WhereEnumerable<T>(enumerable, predicate, false);

					int retVal = FirstOrValue(_enumerable, result, succeeded, default(T));

					delete _enumerable;

					_enumerable = nullptr;

					return retVal;
				}

				static int First(IEnumerable<T>*const enumerable, Nullable<T>*const result)
				{
					T _result;
					bool succeeded;

					int retVal = FirstOrDefault(enumerable, &_result, &succeeded);

					if (succeeded)

						*result = new Nullable<T>(_result);

					else

						*result = new Nullable<T>();

					return retVal;
				}

				static int First(IEnumerable<T>* const enumerable, Nullable<T>* const result, PREDICATE_PARAMETER)
				{
					T _result;
					bool succeeded;
					WhereEnumerable<T>* _enumerable = new WhereEnumerable<T>(enumerable, predicate, false);

					int retVal = FirstOrValueDefault(_enumerable, &_result, &succeeded);

					if (succeeded)

						*result = new Nullable<T>(_result);

					else

						*result = new Nullable<T>();

					delete _enumerable;

					_enumerable = nullptr;

					return retVal;
				}
			};
		}
	}
}

#endif // ENUMERABLEEXTENSIONS_H

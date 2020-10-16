#pragma once
#ifndef SAFEARRAY_H
#define SAFEARRAY_H

#include "EnumeratorBase.h"
#include "../WinCopies.Util.Base.Shared/Nullable.h"

namespace WinCopies
{
	namespace Collections
	{
		TEMPLATE
			class DLLEXPORT SafeArray :
			public virtual IUIntCountableEnumerable<T>
		{
		private:
			T* _array;

			unsigned int _length;
		public:
			explicit SafeArray(const T array[], const unsigned int length)
			{
				_array = array;

				_length = length;
			}

			virtual unsigned int GetCount() const final
			{
				return _length;
			}

			virtual IEnumerator<T>* GetEnumerator() final
			{
				return new ArrayEnumerator(this);
			}

			class DLLEXPORT ArrayEnumerator :
				public virtual EnumeratorBase<T>
			{
			private:
				SafeArray<T>* _array;

				Nullable<uint> _currentIndex = Nullable<uint>();
			public:
				~ArrayEnumerator()
				{
					_array = nullptr;

					ResetOverride();
				}

				explicit ArrayEnumerator(SafeArray<T>* array)
				{
					_array = array;
				}

			protected:
				virtual bool GetIsResetSupported()
				{
					return true;
				}

				virtual T GetCurrentOverride() const final
				{
					return *(_array + _currentIndex);
				}

				virtual int MoveNextOverride(bool* result)
				{
					if (_array->_length == 0)
					{
						*result = false;

						return 0;
					}

					if (_currentIndex.HasValue())
					{
						uint currentIndex;

						_currentIndex.GetValue(&currentIndex);

						if (currentIndex == _array->_length)

							*result = false;

						else
						{
							_currentIndex.Update(++currentIndex);

							*result = true;
						}

						return 0;
					}

					_currentIndex.Update(0); // We have already checked that there is at leat one value in the array, so we do not have to re-check it here.

					*result = true;

					return 0;
				}

				virtual int ResetOverride()
				{
					if (_currentIndex != nullptr)
					{
						delete _currentIndex;

						_currentIndex = nullptr;
					}
				}
			};
		};
	}
}


#endif // SAFEARRAY_H

#pragma once
#ifndef SAFEARRAY_H
#define SAFEARRAY_H

#include "defines.h"
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
			explicit SafeArray( T array[], const unsigned int length)
			{
				_array = array;

				_length = length;
			}

			virtual unsigned int GetCount() const final
			{
				return _length;
			}

			T GetAt(const int index) const
			{
				return *(_array + index);
			}

			virtual IEnumerator<T>* GetEnumerator() final
			{
				return new ArrayEnumerator(this, EnumerationDirection::FIFO);
			}

			virtual bool GetSupportsReversedEnumeration() const final
			{
				return true;
			}

			virtual IEnumerator<T>* GetReversedEnumerator() final
			{
				return new ArrayEnumerator(this, EnumerationDirection::LIFO);
			}

			~SafeArray()
			{
				delete[] _array;

				_array = nullptr;
			}

			class DLLEXPORT ArrayEnumerator :
				public virtual EnumeratorBase<T>
			{
			private:
				SafeArray<T>* _array;
				int _currentIndex;
				EnumerationDirection _enumerationDirection;
				typedef bool(*_moveNext)();
				_moveNext _moveNextPtr;

			public:
				~ArrayEnumerator()
				{
					_array = nullptr;

					ResetOverride();
				}

				explicit ArrayEnumerator(const SafeArray<T>* const array, const EnumerationDirection enumerationDirection)
				{
					_array = array;

					_enumerationDirection = enumerationDirection;

					switch (enumerationDirection)
					{
					case EnumerationDirection::FIFO:

						_currentIndex = -1;

						// auto _moveNextMethod = 

						*_moveNextPtr = []() -> bool
						{
							++_currentIndex;

							return _currentIndex == _array->_length;
						};

						break;

					case EnumerationDirection::LIFO:

						_currentIndex = _array->_length;

						*_moveNextPtr = []() -> bool
						{
							--_currentIndex;

							return _currentIndex == -1;
						};

						break;

					default:

						throw new ArgumentException(ARGUMENT_EXCEPTION, L"Invalid enumeration direction.", L"enumerationDirection");
					}
				}

				virtual EnumerationDirection GetEnumerationDirection() const final
				{
					return _enumerationDirection;
				}

			protected:
				virtual bool GetIsResetSupported() const final
				{
					return true;
				}

				virtual T GetCurrentOverride() const final
				{
					return _array->GetAt(_currentIndex);
				}

				virtual int MoveNextOverride(const bool* result) override
				{
					*result = _moveNextPtr();

					return 0;
				}

				virtual int ResetOverride() override
				{
					if (_enumerationDirection == EnumerationDirection::FIFO)

						_currentIndex = -1;

					else

						_currentIndex = _array->_length;
				}
			};
		};
	}
}

#endif // SAFEARRAY_H

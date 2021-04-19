#pragma once
#ifndef SAFEARRAY_H
#define SAFEARRAY_H

#include "EnumeratorBase.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				class DLLEXPORT SafeArray :
				public virtual IUIntCountableEnumerable<T>
			{
			private:
				T* _array;

				unsigned int _length;
			public:
				explicit SafeArray(T array[], const UINT length)
				{
					_array = array;

					_length = length;
				}

				explicit SafeArray(const UINT length)
				{
					_array = new T[length];

					_length = length;
				}

				virtual UINT GetCount() const final
				{
					return _length;
				}

				T GetAt(const int index) const
				{
					if (index < 0 || index >= _length)

						throw new ArgumentOutOfRangeException(L"index");

					return *(_array + index);
				}

				void SetAt(const int index, T value)
				{
					*(_array + index) = value;
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
					delete[]_array;

					_array = nullptr;
				}

				class DLLEXPORT ArrayEnumerator :
					public virtual EnumeratorBase<T>
				{
				private:
					SafeArray<T>* _array;
					int _currentIndex;
					EnumerationDirection _enumerationDirection;

					class IMoveNextDelegate ABSTRACT
					{
					private:
						ArrayEnumerator* _enumerator;
					protected:
						ArrayEnumerator* GetEnumerator()
						{
							return _enumerator;
						}
					public:
						virtual bool MoveNext() = 0;
						explicit IMoveNextDelegate(ArrayEnumerator* enumerator)
						{
							_enumerator = enumerator;
						}
						virtual ~IMoveNextDelegate()
						{
							// Left empty.
						}
					};

					class MoveNextFIFO :
						public virtual IMoveNextDelegate
					{
					public:
						explicit MoveNextFIFO(ArrayEnumerator* enumerator) :IMoveNextDelegate(enumerator)
						{
							// Left empty.
						}

						virtual bool MoveNext() final
						{
							++(this->GetEnumerator()->_currentIndex);

							return this->GetEnumerator()->_currentIndex < this->GetEnumerator()->_array->_length;
						}
					};

					class MoveNextLIFO :
						public IMoveNextDelegate
					{
					public:
						explicit MoveNextLIFO(ArrayEnumerator* enumerator) : IMoveNextDelegate(enumerator)
						{
							// Left empty.
						}

						virtual bool MoveNext() final
						{
							--(this->GetEnumerator()->_currentIndex);

							return this->GetEnumerator()->_currentIndex > -1;
						}
					};
					IMoveNextDelegate* _moveNext;

				public:
					~ArrayEnumerator()
					{
						_array = nullptr;

						ResetOverride();
					}

					explicit ArrayEnumerator(SafeArray<T>* array, const EnumerationDirection enumerationDirection)
					{
						_array = array;

						_enumerationDirection = enumerationDirection;

						switch (enumerationDirection)
						{
						case EnumerationDirection::FIFO:

							_currentIndex = -1;

							_moveNext = new MoveNextFIFO(this);

							break;

						case EnumerationDirection::LIFO:

							_currentIndex = _array->_length;

							_moveNext = new MoveNextLIFO(this);

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
					virtual bool GetIsResetSupported() const
					{
						return true;
					}

					virtual T GetCurrentOverride() const final
					{
						return _array->GetAt(_currentIndex);
					}

					virtual int MoveNextOverride(bool* result) final
					{
						*result = _moveNext->MoveNext();

						return 0;
					}

					virtual int ResetOverride() final
					{
						if (_enumerationDirection == EnumerationDirection::FIFO)

							_currentIndex = -1;

						else

							_currentIndex = _array->_length;

						return EXIT_SUCCESS;
					}
				};
			};
		}
	}
}

#endif // SAFEARRAY_H

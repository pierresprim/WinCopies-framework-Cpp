#pragma once
#ifndef SELECTENUMERABLE_H
#define SELECTENUMERABLE_H
#include "defines.h"
#include "IEnumerable.h"
#include "IEnumerator.h"
#include "IUIntCountable.h"
#include "EnumeratorBase.h"

namespace WinCopies
{
	namespace Collections
	{
		template <typename T, typename U>
		class SelectEnumerable :
			public virtual IEnumerable<T>
		{
		private:
			IEnumerable<T>* _enumerable;
			U(*_func)(T);
		public:
			class SelectEnumerator :
				public virtual EnumeratorBase<U>
			{
			private:
				SelectEnumerable<T, U>* _enumerable;
				IEnumerator<T>* _enumerator;

			protected:
				virtual T GetCurrentOverride()  const override
				{
					return _enumerator->GetCurrent();
				}

				virtual int MoveNextOverride(bool* result) override
				{
					return _enumerator->MoveNext(result);
				}

				virtual int ResetOverride() override
				{
					if (_enumerator->GetIsResetSupported())
					{
						_enumerator->Reset();

						return EXIT_SUCCESS;
					}

					return -1;
				}

			public:
				explicit SelectEnumerator(SelectEnumerable<T>* enumerable)
				{
					_enumerable = enumerable;

					_enumerator = enumerable->_enumerable->GetEnumerator();
				}

				virtual bool GetIsResetSupported() const override
				{
					return true;
				}

				~SelectEnumerator()
				{
					delete _enumerator;

					_enumerator = nullptr;

					_enumerable = nullptr;
				}
			};

			explicit SelectEnumerable(IEnumerable<T>* enumerable, bool(*func)(T))
			{
				_enumerable = enumerable;

				_func = func;
			}

			virtual ~SelectEnumerable()
			{
				// Left empty.
			}

			virtual IEnumerator<T>* GetEnumerator() override
			{
				return new SelectEnumerator(this);
			}
		};
	}
}

#endif

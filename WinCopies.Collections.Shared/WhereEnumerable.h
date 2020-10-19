#pragma once
#ifndef WHEREENUMERABLE_H
#define WHEREENUMERABLE_H
#include "defines.h"
#include "IEnumerable.h"
#include "IEnumerator.h"
#include "IUIntCountable.h"
#include "EnumeratorBase.h"

namespace WinCopies
{
	namespace Collections
	{
		template <typename T>
		class WhereEnumerable :
			public virtual IEnumerable<T>
		{
		private:
			IEnumerable<T>* _enumerable;
			bool(*_func)(T);
		public:
			class WhereEnumerator :
				public virtual EnumeratorBase<T>
			{
			private:
				WhereEnumerable<T>* _enumerable;
				IEnumerator<T>* _enumerator;

			protected:
				virtual T GetCurrentOverride()  const override
				{
					return _enumerator->GetCurrent();
				}

				virtual int MoveNextOverride(const bool* result) override
				{
					*result = false;

					bool moveNextSucceeded = false;

					while (_enumerator->MoveNext(&moveNextSucceeded) >= 0 && moveNextSucceeded)

						if (_enumerable->_func(_enumerator->GetCurrent()))
						{
							*result = true;

							break;
						}

					return EXIT_SUCCESS;
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
				explicit WhereEnumerator(WhereEnumerable<T>* enumerable)
				{
					_enumerable = enumerable;

					_enumerator = enumerable->_enumerable->GetEnumerator();
				}

				virtual bool GetIsResetSupported() const override
				{
					return true;
				}

				~WhereEnumerator()
				{
					delete _enumerator;

					_enumerator = nullptr;

					_enumerable = nullptr;
				}
			};

			explicit WhereEnumerable(IEnumerable<T>* enumerable, bool(*func)(T))
			{
				_enumerable = enumerable;

				_func = func;
			}

			virtual ~WhereEnumerable()
			{
				// Left empty.
			}

			virtual IEnumerator<T>* GetEnumerator() override
			{
				return new WhereEnumerator(this);
			}
		};
	}
}

#endif

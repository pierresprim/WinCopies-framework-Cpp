#pragma once
#ifndef WHEREENUMERABLE_H
#define WHEREENUMERABLE_H

#include "defines.h"
#include "Enumerable.h"
#include "IEnumerator.h"
#include "IUIntCountable.h"
#include "EnumeratorBase.h"

namespace WinCopies
{
	namespace Collections
	{
		template <typename T>
		class WhereEnumerable :
			public virtual EnumerableEnumerable<T>
		{
		private:
			PREDICATE_FIELD
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

						if (_enumerable->_predicate(_enumerator->GetCurrent()))
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

					_enumerator = enumerable->GetEnumerable()->GetEnumerator();
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

			explicit WhereEnumerable(const IEnumerable<T>* enumerable, const PREDICATE_PARAMETER, const bool autoDispose) : EnumerableEnumerable<T>(enumerable, autoDispose)
			{
				_predicate = predicate;
			}

			virtual IEnumerator<T>* GetEnumerator() override
			{
				return new WhereEnumerator(this);
			}

			virtual ~WhereEnumerable()
			{
				if (this->GetAutoDispose())

					delete _predicate;

				_predicate = nullptr;
			}
		};
	}
}

#endif

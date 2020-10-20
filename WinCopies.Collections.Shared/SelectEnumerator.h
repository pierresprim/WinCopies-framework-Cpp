#pragma once

#ifndef SELECTENUMERATOR_H
#define SELECTENUMERATOR_H

#include "defines.h"
#include "EnumeratorBase.h"
#include "IEnumerable.h"

namespace WinCopies
{
	namespace Collections
	{
		TEMPLATE2
			class SelectEnumerator :
			public virtual EnumeratorBase<U>
		{
		private:
			IEnumerator<T>* _enumerator;
			SELECTOR_FIELD

		protected:
			virtual U GetCurrentOverride()  const override
			{
				return _selector(_enumerator->GetCurrent());
			}

			virtual int MoveNextOverride(const bool* result) override
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
			explicit SelectEnumerator(IEnumerable<T>* enumerable)
			{
				_enumerator = enumerable->_enumerable->GetEnumerator();
			}

			virtual bool GetIsResetSupported() const override
			{
				return _enumerator->GetIsResetSupported();
			}

			~SelectEnumerator()
			{
				delete _enumerator;

				_enumerator = nullptr;
			}
		};
	}
}

#endif

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
		namespace Generic
		{
			NAMED_TEMPLATE2(TSource, TDestination)
				class SelectEnumerator :
				BASE_INTERFACE EnumeratorBase<TDestination>
			{
			private:
				IEnumerator<TSource>* _enumerator;
				SELECTOR_FIELD(TSource, TDestination)

			protected:
				virtual TDestination GetCurrentOverride() const override
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
				explicit SelectEnumerator(IEnumerable<TSource>* enumerable)
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
}

#endif

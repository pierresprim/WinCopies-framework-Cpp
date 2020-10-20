#pragma once
#ifndef SELECTENUMERABLE_H
#define SELECTENUMERABLE_H

#include "defines.h"
#include "IEnumerable.h"
#include "IEnumerator.h"
#include "IUIntCountable.h"
#include "Enumerable.h"
#include "SelectEnumerator.h"

namespace WinCopies
{
	namespace Collections
	{
		TEMPLATE2
			class SelectEnumerable :
			public virtual EnumeratorEnumerable<T>
		{
		private:
			SELECTOR_FIELD;
		public:
			explicit SelectEnumerable(const IEnumerable<T>* enumerable, const bool autoDispose, const SELECTOR_PARAMETER) : EnumeratorEnumerable<T>(enumerable, autoDispose)
			{
				_selector = selector;
			}

			virtual IEnumerator<T>* GetEnumerator() override
			{
				return new SelectEnumerator<T, U>(this);
			}

			virtual ~SelectEnumerable()
			{
				// Left empty.
			}
		};
	}
}

#endif

#pragma once
#ifndef SELECTENUMERABLE_H
#define SELECTENUMERABLE_H

#include "defines.h"
#include "IEnumerable.h"
#include "IEnumerator.h"
#include "Enumerable.h"
#include "SelectEnumerator.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			NAMED_TEMPLATE2(TSource, TDestination)
				class SelectEnumerable :
				public virtual EnumeratorEnumerable<TDestination>
			{
			private:
				SELECTOR_FIELD(TSource, TDestination)
			public:
				explicit SelectEnumerable(const IEnumerable<TSource>* enumerable, const bool autoDispose, const SELECTOR_PARAMETER(TSource, TDestination)) : EnumeratorEnumerable<TDestination>(enumerable, autoDispose)
				{
					_selector = selector;
				}

				virtual IEnumerator<TDestination>* GetEnumerator() override
				{
					return new SelectEnumerator<TSource, TDestination>(this);
				}

				virtual ~SelectEnumerable()
				{
					// Left empty.
				}
			};
		}
	}
}

#endif

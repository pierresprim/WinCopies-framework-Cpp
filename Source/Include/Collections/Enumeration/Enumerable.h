#pragma once

#ifndef WINCOPIES_ENUMERABLE_H
#define WINCOPIES_ENUMERABLE_H

#include <functional>
#include <memory>

#include <Windows.h>

#include "IEnumerable.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE CLASS EnumeratorEnumerable :
			BASE_TEMPLATE(IEnumerable)
			{
			private:
				std::shared_ptr<IEnumerator<T>> _enumerator;

			public:
				explicit EnumeratorEnumerable(const std::shared_ptr<IEnumerator<T>> enumerator)
				{
					_enumerator = enumerator;
				}

				virtual IEnumerator<T>* GetEnumerator() override
				{
					return _enumerator;
				}

				~EnumeratorEnumerable()
				{
					_enumerator = NULL;
				}
			};

			TEMPLATE CLASS EnumeratorProviderEnumerable :
			BASE_TEMPLATE(IEnumerable)
			{
			private:
				FunctionFunction<std::shared_ptr<IEnumerator<T>>> _func;

			public:
				explicit EnumeratorProviderEnumerable(const FunctionFunction<std::shared_ptr<IEnumerator<T>>>& func)
				{
					_func = func;
				}

				virtual std::shared_ptr<IEnumerator<T>> GetEnumerator() override
				{
					return _func();
				}

				~EnumeratorProviderEnumerable()
				{
					_func = NULL;
				}
			};
		}
	}
}
#endif
#pragma once
#ifndef ENUMERABLE_H
#define ENUMERABLE_H

#include "defines.h"
#include "IEnumerable.h"

namespace WinCopies
{
	namespace Collections
	{
		TEMPLATE
			class DLLEXPORT Enumerable :
			public virtual IEnumerable<T>
		{
		private:
			bool _autoDispose;
		protected:
			bool GetAutoDispose()
			{
				return _autoDispose;
			}
		public:
			Enumerable() : Enumerable(false)
			{
				// Left empty.
			}

			Enumerable(const bool autoDispose)
			{
				_autoDispose = autoDispose;
			}

			~Enumerable()
			{
				// Left empty.
			}
		};

		TEMPLATE
			class DLLEXPORT EnumerableEnumerable :
			public virtual Enumerable<T>
		{
		private:
			IEnumerable<T>* _enumerable;
		protected:
			IEnumerable<T>* GetEnumerable()
			{
				return _enumerable;
			}
		public:
			explicit EnumerableEnumerable(const IEnumerable<T>* enumerable, const bool autoDispose) : Enumerable<T>(autoDispose)
			{
				_enumerable = enumerable;
			}

			~EnumerableEnumerable()
			{
				if (this->GetAutoDispose())

					delete _enumerable;

				_enumerable = nullptr;
			}
		};

		TEMPLATE
			class DLLEXPORT EnumeratorEnumerable :
			public virtual Enumerable<T>
		{
		private:
			IEnumerator<T>* _enumerator;
		public:
			explicit EnumeratorEnumerable(const IEnumerator<T>* enumerator, const bool autoDispose) : Enumerable<T>(autoDispose)
			{
				_enumerator = enumerator;
			}

			virtual IEnumerator<T>* GetEnumerator() override
			{
				return _enumerator;
			}

			~EnumeratorEnumerable()
			{
				if (this->GetAutoDispose())

					delete _enumerator;

				_enumerator = nullptr;
			}
		};

		TEMPLATE
			class DLLEXPORT EnumeratorProviderEnumerable :
			public virtual Enumerable<T>
		{
		private:
			IEnumerator<T>* (*_func)();
		public:
			explicit EnumeratorProviderEnumerable(const IEnumerator<T>* (*func)(), const bool autoDispose) : Enumerable<T>(autoDispose)
			{
				_func = func;
			}

			virtual IEnumerator<T>* GetEnumerator() override
			{
				return (*_func)();
			}

			~EnumeratorProviderEnumerable()
			{
				if (this->GetAutoDispose())

					delete _func;

				_func = nullptr;
			}
		};
	}
}

#endif

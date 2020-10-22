#pragma once
#ifndef DELEGATES_H
#define DELEGATES_H

#include "../WinCopies.Util.Base.Shared/wincopies_defines.h"
#include "../WinCopies.Util.Base.Shared/IActionDelegate.h"
#include "../WinCopies.Collections.Shared/SafeArray.h"

using namespace WinCopies::Collections;

namespace WinCopies
{
	TEMPLATE
		class DLLEXPORT IParameterizedActionDelegate ABSTRACT :
	public virtual IActionDelegate
	{
	public:
		virtual void Action(SafeArray<T> * params) = 0;

		virtual void Action() override
		{
			T* _array = new T[0];

			this->Action(new SafeArray<T>(_array, 0));
		}

		virtual ~IParameterizedActionDelegate()
		{
			// Left empty.
		}
	};

	TEMPLATE
		class DLLEXPORT IFixedParameterActionDelegate ABSTRACT :
	public virtual IActionDelegate
	{
	private:
		T _param;
	protected:
		T GetParameter()
		{
			return _param;
		}
	public:
		explicit IFixedParameterActionDelegate(T param)
		{
			_param = param;
		}

		virtual ~IFixedParameterActionDelegate()
		{
			// Left empty.
		}
	};

	TEMPLATE2
		class DLLEXPORT IFixedParameterizedActionDelegate ABSTRACT :
	public virtual IParameterizedActionDelegate<U>,
		public virtual IFixedParameterActionDelegate<T>
	{
	public:
		virtual ~IFixedParameterizedActionDelegate() override = default;
	};
}

#endif

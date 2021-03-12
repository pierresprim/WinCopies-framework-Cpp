#pragma once
#ifndef DELEGATES_H
#define DELEGATES_H

#include "../WinCopies.Util.Base.Shared/wincopies_defines.h"
#include "../WinCopies.Util.Base.Shared/Delegates.h"
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
	public virtual IParameterizedActionDelegate<T2>,
		public virtual IFixedParameterActionDelegate<T1>
	{
	public:
		virtual ~IFixedParameterizedActionDelegate() override = default;
	};



	NAMED_TEMPLATE2(TParams, TReturn)
		class DLLEXPORT IParameterizedFuncDelegate ABSTRACT :
	public virtual IParameterizedActionDelegate<TParams>,
		public virtual IFuncDelegate<TReturn>
	{
	public:
		virtual TReturn Func(SafeArray<TParams> * params) = 0;

		virtual TReturn Func() override
		{
			T* _array = new T[0];

			return this->Func(new SafeArray<TParams>(_array, 0));
		}

		virtual void Action(SafeArray<TParams>* params) override
		{
			Func(params);
		}

		virtual void Action() override
		{
			Func();
		}

		virtual ~IParameterizedFuncDelegate()
		{
			// Left empty.
		}
	};

	NAMED_TEMPLATE2(TParam, TReturn)
		class DLLEXPORT IFixedParameterFuncDelegate ABSTRACT :
	public virtual IFixedParameterActionDelegate<TParam>,
		public virtual IFuncDelegate<TReturn>
	{
	public:
		explicit IFixedParameterFuncDelegate(TParam param) : IFixedParameterActionDelegate<TParam>(param)
		{
			// Left empty.
		}

		virtual ~IFixedParameterFuncDelegate()
		{
			// Left empty.
		}
	};

	NAMED_TEMPLATE3(TParam, TParams, TReturn)
		class DLLEXPORT IFixedParameterizedFuncDelegate ABSTRACT :
	public virtual IParameterizedFuncDelegate<TParams, TReturn>,
		public virtual IFixedParameterFuncDelegate<TParam, TReturn>
	{
	public:
		virtual ~IFixedParameterizedFuncDelegate() override = default;
	};



	TEMPLATE
		class DLLEXPORT IParameterizedPredicate ABSTRACT :
	public virtual IParameterizedFuncDelegate<T, bool>
	{
	public:
		virtual bool Func(SafeArray<T> * params) override = 0;

		virtual ~IParameterizedPredicate()
		{
			// Left empty.
		}
	};

	TEMPLATE
		class DLLEXPORT IFixedParameterPredicate ABSTRACT :
	public virtual IFixedParameterFuncDelegate<T, bool>
	{
	public:
		explicit IFixedParameterPredicate(T param) : IFixedParameterFuncDelegate<T, bool>(param)
		{
			// Left empty.
		}

		virtual ~IFixedParameterPredicate()
		{
			// Left empty.
		}
	};

	NAMED_TEMPLATE2(TParam, TParams)
		class DLLEXPORT IFixedParameterizedPredicate ABSTRACT :
	public virtual IFixedParameterizedFuncDelegate<TParam, TParams, bool>
	{
	public:
		virtual ~IFixedParameterizedPredicate() override = default;
	};
}

#endif

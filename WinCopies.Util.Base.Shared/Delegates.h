#pragma once
#ifndef BASEDELEGATES_H
#define BASEDELEGATES_H

#include "wincopies_defines.h"

namespace WinCopies
{
	class DLLEXPORT IActionDelegate ABSTRACT
	{
	public:
		virtual void Action() = 0;

		virtual ~IActionDelegate();
	};

	TEMPLATE
		class DLLEXPORT IFuncDelegate ABSTRACT :
	public virtual IActionDelegate
	{
	public:
		virtual T Func() = 0;

		virtual void Action() override
		{
			Func();
		}

		virtual ~IFuncDelegate()
		{
			// Left empty.
		}
	};

	class DLLEXPORT IPredicate ABSTRACT :
	public virtual IFuncDelegate<bool>
	{
	public:
		virtual bool Func() override = 0;

		virtual ~IPredicate()
		{
			// Left empty.
		}
	};
}

#endif

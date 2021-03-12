#pragma once
#ifndef SOMEFIXEDPARAMETERDELEGATE_H
#define SOMEFIXEDPARAMETERDELEGATE_H

#include "../WinCopies.Util.Shared/Delegates.h"
#include "SomeFixedParameterDelegateParameter.h"

namespace WinCopies
{
		namespace Tests
		{
			class SomeFixedParameterDelegate :
				public virtual IFixedParameterActionDelegate<SomeFixedParameterDelegateParameter*>
			{
			public:
				explicit SomeFixedParameterDelegate(SomeFixedParameterDelegateParameter* param);

				virtual void Action() final;
				virtual ~SomeFixedParameterDelegate();
			};

			class SomeFuncFixedParameterDelegate :
				public virtual IFixedParameterFuncDelegate<SomeFixedParameterDelegateParameter*, bool>
			{
			public:
				explicit SomeFuncFixedParameterDelegate(SomeFixedParameterDelegateParameter* param);

				virtual bool Func() final;
				virtual ~SomeFuncFixedParameterDelegate();
			};
		}
}

#endif

#pragma once
#ifndef SOMEFIXEDPARAMETERDELEGATE_H
#define SOMEFIXEDPARAMETERDELEGATE_H

#include "../WinCopies.Util.Shared/Delegates.h"
#include "SomeFixedParameterDelegateParameter.h"

namespace WinCopies
{
	namespace Util
	{
		namespace Tests
		{
			class SomeFixedParameterDelegate :
				public virtual IFixedParameterActionDelegate<SomeFixedParameterDelegateParameter*>
			{
			public:
				explicit SomeFixedParameterDelegate(SomeFixedParameterDelegateParameter* param);

				virtual void Action() final;
			};
		}
	}
}

#endif

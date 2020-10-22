#pragma once
#ifndef SOMEFIXEDPARAMETERIZEDDELEGATE_H
#define SOMEFIXEDPARAMETERIZEDDELEGATE_H

#include "../WinCopies.Util.Shared/Delegates.h"
#include "../WinCopies.Collections.Shared/Queue.h"
#include "SomeFixedParameterDelegateParameter.h"

namespace WinCopies
{
	namespace Util
	{
		namespace Tests
		{
			class SomeFixedParameterizedDelegate :
				public virtual IFixedParameterizedActionDelegate<SomeFixedParameterDelegateParameter*, int>
			{
			public:
				static bool emptyArrayFound;
				static Queue<int>* queue;

				explicit SomeFixedParameterizedDelegate(SomeFixedParameterDelegateParameter* param);

				virtual void Action(SafeArray<int>* params) final;

				virtual ~SomeFixedParameterizedDelegate();
			};
		}
	}
}

#endif

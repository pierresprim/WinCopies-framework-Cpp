#pragma once
#ifndef SOMEDELEGATE_H
#define SOMEDELEGATE_H

#include "../WinCopies.Util.Base.Shared/Delegates.h"

namespace WinCopies
{
		namespace Tests
		{
			class SomeDelegate :
				public virtual IActionDelegate
			{
			public:
				static bool result;
				virtual void Action() final;
				virtual ~SomeDelegate();
			};

			class SomeFuncDelegate :
				public virtual IFuncDelegate<bool>
			{
			public:
				virtual bool Func() final;
				virtual ~SomeFuncDelegate();
			};
		}
}

#endif

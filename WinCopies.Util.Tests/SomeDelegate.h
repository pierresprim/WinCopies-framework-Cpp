#pragma once
#ifndef SOMEDELEGATE_H
#define SOMEDELEGATE_H

#include "../WinCopies.Util.Base.Shared/IActionDelegate.h"

namespace WinCopies
{
	namespace Util
	{
		namespace Tests
		{
			class SomeDelegate :
				public virtual IActionDelegate
			{
			public:
				static bool result;
				virtual void Action() final;
			};
		}
	}
}

#endif

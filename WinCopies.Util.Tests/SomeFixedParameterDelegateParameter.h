#pragma once
#ifndef SOMEFIXEDPARAMETERDELEGATEPARAMETER_H
#define SOMEFIXEDPARAMETERDELEGATEPARAMETER_H

#include "../WinCopies.Util.Base.Shared/wincopies_defines.h"

namespace WinCopies
{
	namespace Util
	{
		namespace Tests
		{
			class SomeFixedParameterDelegateParameter
			{
			private:
				UINT _count = 0;
			public:
				void IncrementCount();
				UINT GetCount();
			};
		}
	}
}

#endif

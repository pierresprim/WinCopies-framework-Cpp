#pragma once
#ifndef SOMEPARAMETERIZEDDELEGATE_H
#define SOMEPARAMETERIZEDDELEGATE_H

#include "../WinCopies.Util.Shared/Delegates.h"
#include "../WinCopies.Collections.Shared/Queue.h"

namespace WinCopies
{
	namespace Tests
	{
		class SomeParameterizedDelegate :
			public virtual IParameterizedActionDelegate<int>
		{
		public:
			static bool emptyArrayFound;
			static Queue<int>* queue;

			virtual void Action(SafeArray<int>* params) final;
			virtual ~SomeParameterizedDelegate();
		};

		class SomeFuncParameterizedDelegate :
			public virtual IParameterizedFuncDelegate<int, bool>
		{
		public:
			static bool emptyArrayFound;
			static Queue<int>* queue;

			virtual bool Func(SafeArray<int>* params) final;
			virtual ~SomeFuncParameterizedDelegate();
		};
	}
}

#endif

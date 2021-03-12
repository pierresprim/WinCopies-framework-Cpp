#include "pch.h"
#include "SomeParameterizedDelegate.h"

namespace WinCopies
{
	namespace Tests
	{
		bool SomeParameterizedDelegate::emptyArrayFound = false;
		Queue<int>* SomeParameterizedDelegate::queue = nullptr;

		void SomeParameterizedDelegate::Action(SafeArray<int>* params)
		{
			if (params->GetCount() == 0)
			{
				emptyArrayFound = true;

				return;
			}

			for (UINT i = 0u; i < params->GetCount(); i++)

				queue->Enqueue(11 - params->GetAt(i));

		}

		SomeParameterizedDelegate::~SomeParameterizedDelegate()
		{
			// Left empty.
		}

		bool SomeFuncParameterizedDelegate::Func(SafeArray<int>* params)
		{
			if (params->GetCount() == 0)
			{
				emptyArrayFound = true;

				return;
			}

			for (UINT i = 0u; i < params->GetCount(); i++)

				queue->Enqueue(11 - params->GetAt(i));

		}

		SomeFuncParameterizedDelegate::~SomeFuncParameterizedDelegate()
		{
			// Left empty.
		}
	}
}

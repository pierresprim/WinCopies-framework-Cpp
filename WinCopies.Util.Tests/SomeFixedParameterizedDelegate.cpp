#include "pch.h"
#include "SomeFixedParameterizedDelegate.h"

namespace WinCopies
{
		namespace Tests
		{
			bool SomeFixedParameterizedDelegate::emptyArrayFound = false;
			Queue<int>* SomeFixedParameterizedDelegate::queue = nullptr;

			SomeFixedParameterizedDelegate::SomeFixedParameterizedDelegate(SomeFixedParameterDelegateParameter* param) :IFixedParameterActionDelegate(param)
			{
				// Left empty.
			}

			void SomeFixedParameterizedDelegate::Action(SafeArray<int>* params)
			{
				if (params->GetCount() == 0)
				{
					emptyArrayFound = true;

					GetParameter()->IncrementCount();

					return;
				}

				for (UINT i = 0u; i < params->GetCount(); i++)

					queue->Enqueue(11 - params->GetAt(i));
			}

			SomeFixedParameterizedDelegate::~SomeFixedParameterizedDelegate()
			{
				// Left empty.
			}

			SomeFuncFixedParameterizedDelegate::SomeFuncFixedParameterizedDelegate(SomeFixedParameterDelegateParameter* param) :IFixedParameterFuncDelegate(param)
			{
				// Left empty.
			}

			bool SomeFuncFixedParameterizedDelegate::Func(SafeArray<int>* params)
			{
				if (params->GetCount() == 0)
				{
					emptyArrayFound = true;

					GetParameter()->IncrementCount();

					return;
				}

				for (UINT i = 0u; i < params->GetCount(); i++)

					queue->Enqueue(11 - params->GetAt(i));
			}

			SomeFuncFixedParameterizedDelegate::~SomeFuncFixedParameterizedDelegate()
			{
				// Left empty.
			}
		}
}

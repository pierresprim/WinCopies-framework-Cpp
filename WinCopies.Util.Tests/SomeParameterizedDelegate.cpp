#include "pch.h"
#include "SomeParameterizedDelegate.h"

namespace WinCopies
{
	namespace Util
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
		}
	}
}

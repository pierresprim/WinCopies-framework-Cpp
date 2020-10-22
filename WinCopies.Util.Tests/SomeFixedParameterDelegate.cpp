#include "pch.h"
#include "SomeFixedParameterDelegate.h"

namespace WinCopies
{
	namespace Util
	{
		namespace Tests
		{
			void SomeFixedParameterDelegateParameter::IncrementCount()
			{
				_count++;
			}

			UINT SomeFixedParameterDelegateParameter::GetCount()
			{
				return _count;
			}

			SomeFixedParameterDelegate::SomeFixedParameterDelegate(SomeFixedParameterDelegateParameter* param) : IFixedParameterActionDelegate(param)
			{
				// Left empty.
			}

			void SomeFixedParameterDelegate::Action()
			{
				GetParameter()->IncrementCount();
			}
		}
	}
}

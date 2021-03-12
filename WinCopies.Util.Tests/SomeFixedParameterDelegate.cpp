#include "pch.h"
#include "SomeFixedParameterDelegate.h"

namespace WinCopies
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

		SomeFixedParameterDelegate::~SomeFixedParameterDelegate()
		{
			// Left empty.
		}

		SomeFuncFixedParameterDelegate::SomeFuncFixedParameterDelegate(SomeFixedParameterDelegateParameter* param) : IFixedParameterFuncDelegate(param)
		{
			// Left empty.
		}

		bool SomeFuncFixedParameterDelegate::Func()
		{
			GetParameter()->IncrementCount();

			return true;
		}

		SomeFuncFixedParameterDelegate::~SomeFuncFixedParameterDelegate()
		{
			// Left empty.
		}
	}
}

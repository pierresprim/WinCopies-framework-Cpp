#include "pch.h"
#include "SomeDelegate.h"

namespace WinCopies
{
		namespace Tests
		{
			bool SomeDelegate::result = false;

			void SomeDelegate::Action()
			{
				result = true;
			}

			SomeDelegate::~SomeDelegate()
			{
				// Left empty.
			}

			bool SomeFuncDelegate::Func()
			{
				SomeDelegate::result = true;

				return true;
			}

			SomeFuncDelegate::~SomeFuncDelegate()
			{
				// Left empty.
			}
		}
}

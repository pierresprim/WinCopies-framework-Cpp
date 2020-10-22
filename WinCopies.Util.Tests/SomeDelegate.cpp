#include "pch.h"
#include "SomeDelegate.h"

namespace WinCopies
{
	namespace Util
	{
		namespace Tests
		{
			bool SomeDelegate::result = false;

			void SomeDelegate::Action()
			{
				result = true;
			}
		}
	}
}

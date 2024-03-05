#include "pch.h"
#include "Something.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			namespace Tests
			{
				Something::Something(const int id)
				{
					_id = id;
				}

				const int	Something::GetId()
				{
					return _id;
				}
			}
		}
	}
}

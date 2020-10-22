#pragma once
#ifndef SOMETHING_H
#define SOMETHING_H

namespace WinCopies
{
	namespace Collections
	{
		namespace Tests
		{
			class Something
			{
			private:
				int _id = 0;
			public:
				explicit Something(const int id);

				const int GetId();
			};
		}
	}
}

#endif

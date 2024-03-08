#pragma once

#ifndef WINCOPIES_IENUMERATOR_H
#define WINCOPIES_IENUMERATOR_H

#include "../Util.h"
#include "../../Util/Enum/Bitwise.h"

namespace WinCopies
{
	namespace Collections
	{
		ENUM EnumerationState : BYTE
		{
			None = 0,
			Started = 1,
			Completed = 2
		};

		ENUM EnumerationDirection : BYTE
		{
			Undetermined = 0,
			FIFO = 1,
			LIFO = 2
		};

		INTERFACE_CLASS(IEnumerator)
		{
		public:
			virtual ~IEnumerator() = default;

			virtual EnumerationState GetState() const = 0;

			virtual bool IsStarted() const = 0;
			virtual bool IsCompleted() const = 0;

			virtual bool IsResetSupported() const = 0;
			virtual EnumerationDirection GetEnumerationDirection() const = 0;

			virtual ErrorCode MoveNext() = 0;
			virtual ErrorCode Reset() = 0;
		};

		namespace Generic
		{
			TEMPLATE
				INTERFACE_CLASS(IEnumerator) :
				public virtual WinCopies::Collections::IEnumerator
			{
			public:
				virtual ~IEnumerator() = default;

				virtual ErrorCode GetCurrent(T* result) const = 0;
			};
		}
	}
}

#endif

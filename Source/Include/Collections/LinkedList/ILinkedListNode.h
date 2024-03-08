#pragma once
#ifndef ILINKEDLISTNODE_H
#define ILINKEDLISTNODE_H

#include "defines.h"
//#include "IEnumerable.h"
//#include "EnumeratorBase.h"
#include "IReadOnlyLinkedList.h"
//#include "../WinCopies.Util.Shared/Exception.h"
//#include "../WinCopies.Util.Shared/ThrowHelper.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				class IReadOnlyLinkedList;

			TEMPLATE
				INTERFACE(IReadOnlyLinkedListNode)
			{
			public:
				virtual T GetValue() = 0;

				virtual WinCopies::Collections::DotNetFix::Generic::IReadOnlyLinkedList<T>* GetList() = 0;

				virtual IReadOnlyLinkedListNode<T>* GetPrevious() = 0;

				virtual IReadOnlyLinkedListNode<T>* GetNext() final
				{
					return GetNextGeneric();
				}
			};

			TEMPLATE
				INTERFACE(ILinkedListNodeBase) :
				BASE_INTERFACE IReadOnlyLinkedListNode<T>
			{
			public:
				virtual bool GetIsReadOnly() = 0;

				virtual T GetValue() = 0;

				virtual T SetValue() = 0;
			};

			TEMPLATE
				INTERFACE(ILinkedListNode) :
				BASE_INTERFACE ILinkedListNodeBase<T>,
				BASE_INTERFACE IReadOnlyLinkedListNode<T>
			{
				// Left empty.
			};

			TEMPLATE
				INTERFACE(ILinkedListNode) :
				BASE_INTERFACE ILinkedListNode<T>,
				BASE_INTERFACE IReadOnlyLinkedListNode<T>
			{
				// Left empty.
			};

			TEMPLATE
				INTERFACE(ILinkedListNode) :
				BASE_INTERFACE ILinkedListNode<T>,
				BASE_INTERFACE IReadOnlyLinkedListNode<T>
			{
				// Left empty.
			};
		}
	}
}
#endif // ILINKEDLISTNODE_H

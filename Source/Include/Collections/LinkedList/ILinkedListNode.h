#pragma once

#ifndef WINCOPIES_COLLECTIONS_ILINKEDLISTNODE_H
#define WINCOPIES_COLLECTIONS_ILINKEDLISTNODE_H

#include "../Util.h"
#include "IReadOnlyLinkedList.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				class IReadOnlyLinkedList;

			TEMPLATE
				INTERFACE_CLASS(IReadOnlyLinkedListNode)
			{
			public:
				virtual T GetValue() = 0;

				ABSTRACT_CONST(WinCopies::Collections::DotNetFix::Generic::IReadOnlyLinkedList<T>*GetList);

				ABSTRACT_CONST(IReadOnlyLinkedListNode<T>*GetPrevious);

				FINAL_CONST(IReadOnlyLinkedListNode<T>*GetNext)
				{
					return GetNextGeneric();
				}
			};

			TEMPLATE
				INTERFACE_CLASS(ILinkedListNodeBase) :
				BASE_INTERFACE IReadOnlyLinkedListNode<T>
			{
			public:
				ABSTRACT_CONST(bool GetIsReadOnly);

				ABSTRACT_CONST(T GetValue);
				ABSTRACT_CONST(T SetValue);
			};

			TEMPLATE
				INTERFACE_CLASS(ILinkedListNode) :
				BASE_INTERFACE ILinkedListNodeBase<T>,
				BASE_INTERFACE IReadOnlyLinkedListNode<T>
			{
				// Left empty.
			};
		}
	}
}
#endif // WINCOPIES_COLLECTIONS_ILINKEDLISTNODE_H
#pragma once
#ifndef WINCOPIES_COLLECTIONS_THROWHELPER_H
#define WINCOPIES_COLLECTIONS_THROWHELPER_H

#include "Countable.h"
#include "LinkedList/ILinkedList.h"
#include "LinkedList/ILinkedListNode.h"
#include "../Util/Exception.h"

using namespace WinCopies::Collections;
using namespace WinCopies::Collections::Generic;

namespace WinCopies
{
	namespace Collections
	{
		namespace ThrowHelpers
		{
			DLLEXPORT ArgumentException* GetNotContainedLinkedListNodeException(const wchar_t* const argumentName);

			DLLEXPORT ArgumentException* GetNodesAreEqualException(const wchar_t* const argumentName);

			DLLEXPORT InvalidOperationException* GetEmptyListOrCollectionException();

			UNSIGNED_INTEGRAL_METHOD ThrowIfEmptyListOrCollection(const ICountable<T>* obj)
			{
				if (obj->GetCount() == 0)

					throw GetEmptyListOrCollectionException();
			}

			TEMPLATE METHOD ThrowIfNotContainedNode(const ILinkedListNode<T>* node, const wchar_t* const argumentName, const ILinkedList<T>* list)
			{
				if (node->GetList() != list)

					throw WinCopies::Collections::ThrowHelper::GetNotContainedLinkedListNodeException(argumentName);
			}

			TEMPLATE METHOD ThrowIfNodesAreEqual(const ILinkedListNode<T>* x, const ILinkedListNode<T>* y)
			{
				if (x == y)

					throw WinCopies::Collections::ThrowHelper::GetNodesAreEqualException();
			}
		}
	}
}
#endif

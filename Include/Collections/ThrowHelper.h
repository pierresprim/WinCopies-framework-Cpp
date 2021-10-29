#pragma once
#ifndef THROWHELPER_H
#define THROWHELPER_H

#include "ILinkedList.h"
#include "ILinkedListNode.h"
#include "../Util/Exception.h"

using namespace WinCopies::Collections;
using namespace WinCopies::Collections::Generic;

namespace WinCopies
{
	namespace Collections
	{
		TEMPLATE
			CLASS ThrowHelper
		{
		private:
			ThrowHelper() { /* Left empty. */ }

		public:
			static ArgumentException* GetNotContainedLinkedListNodeException(const wchar_t* const argumentName)
			{
				return new ArgumentException(L"The given node is not contained in the current list.", argumentName);
			}

			static void ThrowIfNotContainedNode(const ILinkedListNode<T>*node, const wchar_t* const argumentName, const ILinkedList<T>*list)
			{
				if (node->GetList() != list)

					throw GetNotContainedLinkedListNodeException(argumentName);
			}

			static ArgumentException* GetNodesAreEqualException()
			{
				return new ArgumentException(L"The given nodes are equal.");
			}

			static void ThrowIfNodesAreEqual<T>(const ILinkedListNode<T>* x, const ILinkedListNode<T>* y)
			{
				if (x == y)

					throw GetNodesAreEqualException();
			}

			public static InvalidOperationException* GetEmptyListOrCollectionException()
			{
				return new InvalidOperationException(L"The current list or collection is empty.");
			}

			public static void ThrowIfEmptyListOrCollection(const ICountable* obj)
			{
				if (obj->GetCount() == 0)

					throw GetEmptyListOrCollectionException();
			}

			public static void ThrowIfEmptyListOrCollection(const IUIntCountable* obj)
			{
				if (obj->GetCount() == 0)

					throw GetEmptyListOrCollectionException();
			}
		};
	}
}
#endif

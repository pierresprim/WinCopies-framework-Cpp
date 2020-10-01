#pragma once
#ifndef ISIMPLELINKEDLISTNODE_H
#define ISIMPLELINKEDLISTNODE_H
#include "defines.h"

namespace WinCopies
{
	namespace Collections
	{
		_T
		class DLLEXPORT ISimpleLinkedListNode abstract
		{
		public:
			~ISimpleLinkedListNode() {}
			// Gets the value of the current node.
			virtual T GetValue() const = 0;
			// Gets the next node in the parent linked list.
			virtual const ISimpleLinkedListNode<T>* GetNext() const = 0;
		};
	}
}

#endif

#pragma once
#ifndef ISIMPLELINKEDLISTNODE_H
#define ISIMPLELINKEDLISTNODE_H

#include "ISimpleLinkedList.h"

namespace WinCopies
{
	namespace Collections
	{
		INTERFACE_CLASS(ISimpleLinkedListNode)
		{
		public:
			ABSTRACT_ARG_CONST(int GetValue, void** const result);

			ABSTRACT_ARG_CONST(int GetNext, ISimpleLinkedListNode** const result);
		};

		namespace Generic
		{
			TEMPLATE
				INTERFACE_CLASS(ISimpleLinkedListNode) :
				BASE_INTERFACE WinCopies::Collections::ISimpleLinkedListNode
			{
			public:
				ABSTRACT_ARG_CONST(int GenericGetValue, T* const result);

				FINAL_ARG_METHOD_CONST(int GetValue, void** const result)
				{
					return GenericGetValue((T*) *result);
				}

				ABSTRACT_ARG_CONST(int GenericGetNext, ISimpleLinkedListNode<T>** const result);

				FINAL_ARG_CONST(int GetNext, WinCopies::Collections::ISimpleLinkedListNode** const result)
				{
					ISimpleLinkedListNode<T>* node;

					int _result = GenericGetNext(&node);

					*result = node;

					return _result;
				}
			};
		}
	}
}
#endif
#pragma once
#ifndef SIMPLELINKEDLISTNODE_H
#define SIMPLELINKEDLISTNODE_H
#include "ISimpleLinkedListNode.h"

namespace WinCopies
{
	namespace Collections
	{
		_T
			class DLLEXPORT SimpleLinkedListNode :
			public virtual ISimpleLinkedListNode<T>
		{
		private:
			T _value;
			const	SimpleLinkedListNode<T>* _next = nullptr;
		public:
			~SimpleLinkedListNode() {			}

			SimpleLinkedListNode(T value)
			{
				_value = value;
			}

			// Gets the value of the current node.
			T GetValue() const
			{
				return _value;
			}

			void SetValue(T value)
			{
				return _next;
			}

			// Gets the next node in the parent linked list.
			const	SimpleLinkedListNode<T>* GetNextNode() const
			{
				return _next;
			}

			const			ISimpleLinkedListNode<T>* GetNext() const
			{
				return GetNextNode();
			}

			void SetNext(const SimpleLinkedListNode<T>* node)
			{
				_next = node;
			}
		};
	}
}

#endif

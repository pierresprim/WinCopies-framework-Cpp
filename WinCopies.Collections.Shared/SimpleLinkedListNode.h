#pragma once
#ifndef SIMPLELINKEDLISTNODE_H
#define SIMPLELINKEDLISTNODE_H

#include "defines.h"
#include "ISimpleLinkedListNode.h"
#include "EnumerableStack.h"
#include "../WinCopies.Util.Base.Shared/IDisposable.h"

namespace WinCopies
{
	namespace Collections
	{
    TEMPLATE
    class StackEnumerator;

        TEMPLATE
			class DLLEXPORT SimpleLinkedListNode :
                public virtual ISimpleLinkedListNode<T>
		{
		private:
			T _value;
			const	SimpleLinkedListNode<T>* _next = nullptr;
            friend class StackEnumerator<T>;
		public:
            virtual ~SimpleLinkedListNode() override
            {
                _next = nullptr;
            }

            SimpleLinkedListNode(T value) { _value = value; }

			// Gets the value of the current node.
            T GetValue() const { return _value; }

			// Gets the next node in the parent linked list.
            const	SimpleLinkedListNode<T>* GetNextNode() const { return _next; }

            const ISimpleLinkedListNode<T>* GetNext() const { return GetNextNode(); }

            void SetNext(const SimpleLinkedListNode<T>* node) { _next = node; }
		};
	}
}

#endif

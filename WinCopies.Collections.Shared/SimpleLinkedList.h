#pragma once
#ifndef SIMPLELINKEDLIST_H
#define SIMPLELINKEDLIST_H

#include "ISimpleLinkedList.h"
#include "SimpleLinkedListNode.h"
#include "StackEnumerator.h"
#include "QueueEnumerator.h"
#include "../WinCopies.Util.Base.Shared/Exception.h"

namespace WinCopies
{
	namespace Collections
	{
    TEMPLATE
    class SimpleLinkedListNode;

    TEMPLATE
    class StackEnumerator;

    TEMPLATE
    class QueueEnumerator;

        TEMPLATE
			class DLLEXPORT SimpleLinkedList :
			public virtual ISimpleLinkedList<T>
		{
		private:
			const SimpleLinkedListNode<T>* _first = nullptr;
			unsigned int _count = 0;
            friend class StackEnumerator<T>;
            friend class QueueEnumerator<T>;
		protected:
            const SimpleLinkedListNode<T>* GetFirst() const
			{
				return _first;
			}

			void AddFirstItem(const SimpleLinkedListNode<T>* const node)
			{
				_first = node;
			}

			void RemoveFirstItem()
			{
				if (_count == 0)

					throw new EmptyObjectException();

				delete _first;

				_first = nullptr;

				_count--;
			}

			void IncrementCount()
			{
				_count++;
			}

			void DecrementCount()
			{
				_count--;
			}

			void OnCleared()
			{
				_count = 0;
			}
		public:
            virtual ~SimpleLinkedList() override
			{
				if (_first != nullptr)
                {
                    Clear();

                    _first = nullptr; // Because all of the items are deleted in the Clear method, we do not need to delete _first here.
                }
			}

            virtual unsigned int GetCount() const final
			{
				return _count;
			}

			virtual bool GetIsReadOnly() const final
			{
				return false;
			}

			virtual T Peek() const final
			{
				if (GetCount() == 0)

					throw new EmptyObjectException();

				return GetFirst()->GetValue();
			}

			virtual bool TryPeek( T*  result) const final
			{
				if (GetCount() == 0)

                    return false;

                *result = GetFirst()->GetValue();

				return true;
			}

            virtual void Clear() final
            {
                if (this->GetCount() == 0)

                    return;

                const	SimpleLinkedListNode<T>* node = this->GetFirst();
                const	SimpleLinkedListNode<T>* nextNode;

                do
                {
                    nextNode = node->GetNextNode();

                    delete node;

                    node = nextNode;

                } while (node->GetNext() != nullptr);

                node = nullptr;

                nextNode = nullptr;

                this->OnCleared();
            }
		};
	}
}

#endif

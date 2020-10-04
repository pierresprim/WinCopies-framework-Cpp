#pragma once
#ifndef STACK_H
#define STACK_H
#include "defines.h"
#include "IStack.h"
#include "SimpleLinkedList.h"
#include "SimpleLinkedListNode.h"
#include "../WinCopies.Util.Base.Shared/Exception.h"

namespace WinCopies
{
	namespace Collections
    {
    TEMPLATE
    class SimpleLinkedList;

    TEMPLATE
    class SimpleLinkedListNode;

    TEMPLATE
    class IStack;

        TEMPLATE
			class DLLEXPORT Stack :
			virtual public SimpleLinkedList<T>,
			virtual public IStack<T>
		{
		protected:
			void OnPush(SimpleLinkedListNode<T>* const node)
			{
				if (this->GetCount() != 0)

					node->SetNext(this->GetFirst());

				this->AddFirstItem(node);

				this->IncrementCount();
			}

			T OnPop()
			{
				T result;

				if (this->GetCount() == 1)
				{
					result = this->GetFirst()->GetValue();

					this->RemoveFirstItem();
				}

				else
				{
					const	SimpleLinkedListNode<T>* node = this->GetFirst();

					result = node->GetValue();

					this->AddFirstItem(node->GetNextNode());

					delete node;

                    this->DecrementCount();
				}

				return result;
			}
		public:
            virtual ~Stack() override = default;

			void Push(const T value) final
			{
				OnPush(new SimpleLinkedListNode<T>(value));
			}

			bool TryPush(const T value) final
			{
				Push(value);

				return true;
			}

			T Pop() final
			{
				if (this->GetCount() == 0)

                    throw new EmptyObjectException();

				return OnPop();
			}

			bool TryPop( T*  result) final
			{
                if (this->GetCount() == 0)

                    return false;

                *result = OnPop();

				return true;
			}

			void Clear() final
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

				this->OnCleared();
			}
		};
	}
}

#endif

#pragma once
#ifndef STACK_H
#define STACK_H

#include "defines.h"
#include "IStack.h"
#include "SimpleLinkedList.h"
#include "SimpleLinkedListNode.h"
#include "../WinCopies.Util.Base.Shared/Exception.h"
#include "../WinCopies.Util.Base.Shared/OutPointer.h"

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

                    node = nullptr;

                    this->DecrementCount();
				}

				return result;
			}
		public:
            virtual ~Stack() override = default;

            virtual void Push(const T value) final
			{
				OnPush(new SimpleLinkedListNode<T>(value));
			}

            virtual bool TryPush(const T value) final
			{
				Push(value);

				return true;
			}

            virtual T Pop() final
			{
				if (this->GetCount() == 0)

                    throw new EmptyObjectException();

				return OnPop();
			}

            virtual bool TryPop(OUTPOINTER result) final
			{
				if (this->GetCount() == 0)
				{
					*result = new OutPointer();

					return false;
				}

                *result = new OutPointer<T>(OnPop());

				return true;
            }
		};
	}
}

#endif

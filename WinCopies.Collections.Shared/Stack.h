#pragma once
#ifndef STACK_H
#define STACK_H
#include "defines.h"
#include "IStack.h"

namespace WinCopies
{
	namespace Collections
	{
		_T
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
			~Stack() {}

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

				T _result = OnPop();

				result = &_result;

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

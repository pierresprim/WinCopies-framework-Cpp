#pragma once
#ifndef STACKENUMERATOR_H
#define STACKENUMERATOR_H

#include "defines.h"
#include "EnumeratorBase.h"
#include "EnumerableStack.h"

namespace WinCopies
{
	namespace Collections
	{
		TEMPLATE
			class EnumerableStack;

		TEMPLATE
			class  SimpleLinkedListNode;

		TEMPLATE
			class DLLEXPORT StackEnumerator :
			public virtual EnumeratorBase<T>
		{
		private:
			EnumerableStack<T>* _stack;
			unsigned int _version;
			const SimpleLinkedListNode<T>* _currentNode;
		public:
			explicit StackEnumerator(EnumerableStack<T>* stack)
			{
				_stack = stack;

				_version = stack->_version;
			}

			virtual EnumerationDirection GetEnumerationDirection() const final
			{
				return EnumerationDirection::LIFO;
			}

			virtual ~StackEnumerator() override
			{
				_stack->_enumeratorsCount--;

				if (_stack->_enumeratorsCount == 0)

					_stack->_version = 0;

				_stack = nullptr;

				_currentNode = nullptr;
			}
		protected:
			virtual bool GetIsResetSupported() const final
			{
				return true;
			}

			virtual T GetCurrentOverride() const final
			{
				return _currentNode->GetValue();
			}

			virtual int MoveNextOverride(bool* result) final
			{
				if (_stack->_version != _version)
				{
					*result = false;

					return OBJECT_HAS_CHANGED_DURING_ENUMERATION_EXCEPTION;
				}

				if (_currentNode == nullptr)

					_currentNode = _stack->_stack->GetFirst();

				else

					_currentNode = _currentNode->GetNextNode();

				*result = _currentNode != nullptr;

				return EXIT_SUCCESS;
			}

			virtual int ResetOverride() final
            {
                if (_stack->_version != _version)

                    return OBJECT_HAS_CHANGED_DURING_ENUMERATION_EXCEPTION;

                _currentNode = _stack->_stack->GetFirst();

				return EXIT_SUCCESS;
			}
		};
	}
}

#endif // STACKENUMERATOR_H

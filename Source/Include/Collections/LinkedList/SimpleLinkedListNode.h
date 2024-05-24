#pragma once
#ifndef SIMPLELINKEDLISTNODE_H
#define SIMPLELINKEDLISTNODE_H

#include <stdlib.h>
#include "../Util.h"
#include "ISimpleLinkedListNode.h"
#include "SimpleLinkedList.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				class SimpleLinkedList;

			TEMPLATE
				CLASS SimpleLinkedListNode :
			BASE_TEMPLATE(ISimpleLinkedListNode)
			{
				friend class SimpleLinkedList<T>;
			private:
				T _value;
				SimpleLinkedListNode<T>* _next;
				bool _isCleared;

				ErrorCode SetNext(SimpleLinkedListNode<T>*const node)
				{
					if (_isCleared)

						return ErrorCode::ObjectIsDisposed;

					_next = node;

					return ErrorCode::Success;
				}

			public:
				INLINE_CONSTRUCTOR(0, SimpleLinkedListNode, _value = value, const T value)

					INLINE_METHOD_RETURN(0, bool, GetIsCleared, _isCleared)

					FINAL_ARG_CONST(ErrorCode GenericGetValue, T* const result)
				{
					if (_isCleared)

						return ErrorCode::ObjectIsDisposed;

					*result = _value;

					return ErrorCode::Success;
				}

				ErrorCode GenericGetNext2(SimpleLinkedListNode<T>**const result) const
				{
					if (_isCleared)

						return ErrorCode::ObjectIsDisposed;

					*result = _next;

					return ErrorCode::Success;
				}

				FINAL_ARG_CONST(ErrorCode GenericGetNext, ISimpleLinkedListNode<T>**const result)
				{
					SimpleLinkedListNode<T>* node;

					ErrorCode _result = GenericGetNext2(&node);

					*result = node;

					return _result;
				}

				void Clear()
				{
					_next = nullptr;

					_isCleared = true;
				}

				INLINE_CONSTRUCTOR(0, ~SimpleLinkedListNode, Clear())
			};
		}
	}
}
#endif
#pragma once
#ifndef SIMPLELINKEDLISTNODE_H
#define SIMPLELINKEDLISTNODE_H

#include <stdlib.h>
#include "defines.h"
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
            BASE_INTERFACE ISimpleLinkedListNode<T>
            {
                friend class SimpleLinkedList<T>;
            private:
                T _value;
                SimpleLinkedListNode<T>* _next;
                bool _isCleared;

                int SetNext(SimpleLinkedListNode<T>* const node)
                {
                    if (_isCleared)

                        return OBJECT_IS_DISPOSED_EXCEPTION;

                    _next = node;

                    return EXIT_SUCCESS;
                }

            public:
                bool GetIsCleared() const
                {
                    return _isCleared;
                }

                FINAL_ARG_METHOD_CONST(int GenericGetValue, T* const result)
                {
                    if (_isCleared)

                        return OBJECT_IS_DISPOSED_EXCEPTION;

                    *result = _value;

                    return EXIT_SUCCESS;
                }

                int GenericGetNext2(SimpleLinkedListNode<T>** const result) const
                {
                    if (_isCleared)

                        return OBJECT_IS_DISPOSED_EXCEPTION;

                    *result = _next;
                }

                FINAL_ARG_METHOD_CONST(int GenericGetNext, ISimpleLinkedListNode<T>** const result)
                {
                    SimpleLinkedListNode<T>* node;

                    int _result = GenericGetNext2(&node);

                    *result = node;

                    return _result;
                }

                void Clear()
                {
                    _next = nullptr;

                    _isCleared = true;
                }

                SimpleLinkedListNode(const T value)
                {
                    _value = value;
                }

                ~SimpleLinkedListNode()
                {
                    Clear();
                }
            };
        }
    }
}

#endif

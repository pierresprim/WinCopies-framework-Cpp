#pragma once
#ifndef QUEUEENUMERATOR_H
#define QUEUEENUMERATOR_H

#include "../WinCopies.Util.Base.Shared/wincopies_defines.h"
#include "defines.h"
#include "EnumeratorBase.h"
#include "EnumerableQueue.h"

namespace WinCopies
{
    namespace Collections
    {
    TEMPLATE
    class EnumerableQueue;

    TEMPLATE
    class  SimpleLinkedListNode;

        TEMPLATE
        class DLLEXPORT QueueEnumerator :
            public virtual EnumeratorBase<T>
        {
        private:
            EnumerableQueue<T>* _queue;
            unsigned int _version;
            const SimpleLinkedListNode<T>* _currentNode;
        public:
            explicit QueueEnumerator(EnumerableQueue<T>* queue)
            {
                _queue = queue;

                _version = queue->_version;
            }

            virtual EnumerationDirection GetEnumerationDirection() const final
            {
                return EnumerationDirection::FIFO;
            }

            virtual ~QueueEnumerator() override
            {
                _queue->_enumeratorsCount--;

                if (_queue->_enumeratorsCount == 0)

                    _queue->_version = 0;

                _queue = nullptr;

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

            virtual int MoveNextOverride(const bool* result) final
            {
                if (_queue->_version!=_version)
                {
                    *result = false;

                    return OBJECT_HAS_CHANGED_DURING_ENUMERATION_EXCEPTION;
                }

                if (_currentNode == nullptr)

                    _currentNode = _queue->_queue->GetFirst();

                else

                    _currentNode = _currentNode->GetNextNode();

                *result = _currentNode != nullptr;

                return EXIT_SUCCESS;
            }

            virtual int ResetOverride() final
            {
                if (_queue->_version != _version)

                    return OBJECT_HAS_CHANGED_DURING_ENUMERATION_EXCEPTION;

                _currentNode = _queue->_queue->GetFirst();

                return EXIT_SUCCESS;
            }
        };
    }
}

#endif // QUEUEENUMERATOR_H

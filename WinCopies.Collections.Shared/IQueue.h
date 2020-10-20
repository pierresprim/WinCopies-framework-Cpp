#pragma once
#ifndef IQUEUE_H
#define IQUEUE_H

#include "defines.h"
#include "ISimpleLinkedListNode.h"
#include "ISimpleLinkedList.h"
#include "../WinCopies.Util.Base.Shared/OutPointer.h"

namespace WinCopies
{
    namespace Collections
    {
        TEMPLATE
            class DLLEXPORT IQueue ABSTRACT : public virtual ISimpleLinkedList<T>
        {
        public:
            virtual ~IQueue() override = default;

            virtual LinkedListDirection GetDirection() const final
            {
                return LinkedListDirection::FIFO;
            }

            virtual void Enqueue(const T value) = 0;
            virtual bool TryEnqueue(const T value) = 0;
            virtual T Dequeue() = 0;
            virtual bool TryDequeue(OUTPOINTER result) = 0;
        };
    }
}

#endif

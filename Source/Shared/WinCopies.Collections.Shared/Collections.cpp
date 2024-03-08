#include "pch.h"
#include "../../Include/Collections/Countable.h"
#include "../../Include/Collections/ICollection.h"
#include "../../Include/Collections/LinkedList/SimpleLinkedList.h"
#include "../../Include/Collections/LinkedList/ISimpleLinkedList.h"
#include "../../Include/Collections/LinkedList/ISimpleLinkedListNode.h"

using namespace WinCopies::Collections;

bool SimpleLinkedListBase::GetHasItems() const
{
	return HAS_ITEMS;
}

ErrorCode SimpleLinkedListBase::Clear()
{
	if (IsReadOnly())

		return ErrorCode::ReadOnly;

	ClearItems();

	return ErrorCode::Success;
}

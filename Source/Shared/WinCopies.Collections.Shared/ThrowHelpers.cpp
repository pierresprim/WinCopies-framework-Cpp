#include "pch.h"
#include "../../Include/Collections/ThrowHelpers.h"
#include "../../Include/Util/Misc.h"

using namespace WinCopies::Collections;

INLINE_OBJECT_RETURN(ArgumentException, ThrowHelpers::GetNotContainedLinkedListNodeException, const wchar_t* const argumentName, L"The given node is not contained in the current list." COMMA argumentName)

ArgumentException* ThrowHelpers::GetNodesAreEqualException(const wchar_t* const argumentName)
{
	return new ArgumentException(L"The given nodes are equal.", argumentName);
}

InvalidOperationException* ThrowHelpers::GetEmptyListOrCollectionException()
{
	return new InvalidOperationException(L"The current list or collection is empty.");
}
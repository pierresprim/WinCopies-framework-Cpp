#include "pch.h"
#include "../../../../Include/Collections/Array/Array.Partial/Array.h"
#include "../../../../Include/Util/Delegates.h"

using namespace WinCopies::Collections;
using namespace WinCopies::Delegates;
using namespace WinCopies::Math;

_Array::_Array(const size_t length)
{
	_length = length;
}

size_t _Array::GetCount() const
{
	return _length;
}

bool _Array::ValidateIndex(const size_t index) const
{
	return index < _length;
}

size_t _Array::GetSortIndex(const size_t index, size_t length, PredicateFunction<const size_t>& const predicate)
{
	if (length % 2 != 0)

		if (predicate(index + length - 1))

			--length;

		else

			return length;

	size_t current = length >> 1 + index;

	typedef PredicateFunction<const Converter<size_t&>> EvennessPredicate;

	EvennessPredicate evenness = IsEven(index) ? EvennessPredicate([&](const Converter<size_t&> converter) -> bool
		{
			return !(IsEven(current) || predicate(converter(current)));
		}) : [&](const Converter<size_t&> converter) -> bool
			{
				return IsEven(current) && !predicate(converter(current));
			};

		do
		{
			length >>= 2;

			if (predicate(current))
			{
				if (evenness(&DecrementByRef))

					return current;

				current -= length;
			}

			else
			{
				if (evenness(&IncrementByRef))

					return current;

				current += length;
			}
		} while (length > 1);

		return predicate(current) ? current : current + 1;
}
ErrorCode _Array::GetSortIndex(const size_t index, size_t length, size_t* const result, PredicateFunction<const size_t>& const predicate)
{
	if (length > _length - index)
	{
		*result = -1;

		return ErrorCode::ArgumentOutOfRange;
	}

	*result = GetSortIndex(index, length, predicate);

	return ErrorCode::Success;
}

void _Array::_Move(const size_t startIndex, const size_t length, const size_t destinationIndex)
{
	memmove(GetVoidPtr(destinationIndex), GetVoidPtr(startIndex), length * GetItemSize());
}
bool _Array::ValidateMove(const size_t startIndex, const size_t length, const size_t destinationIndex)
{
	if (destinationIndex > startIndex)
	{
		size_t tmp = _length - startIndex;

		return length < tmp && destinationIndex - startIndex <= tmp - length;
	}

	return length <= _length - startIndex;
}
Bool _Array::PrevalidateMove(const size_t startIndex, const size_t length, const size_t destinationIndex)
{
	if (ValidateIndex(startIndex) && ValidateIndex(destinationIndex))
	{
		if (length == 0)

			return Bool::None;

		if (ValidateMove(startIndex, length, destinationIndex))

			return Bool::True;
	}

	return Bool::False;
}
ErrorCode _Array::Move(const size_t startIndex, const size_t length, const size_t destinationIndex)
{
	switch (PrevalidateMove(startIndex, length, destinationIndex))
	{
	case Bool::True:

		_Move(startIndex, length, destinationIndex);

		break;

	case Bool::False:

		return ErrorCode::ArgumentOutOfRange;
	}

	return ErrorCode::Success;
}
void _Array::Move(void* const ptr, const size_t bufferSize, const size_t length, size_t sortIndex, size_t index)
{
	memmove(ptr, GetVoidPtr(index), bufferSize);

	Move(sortIndex, index - sortIndex, sortIndex + length);

	memmove(GetVoidPtr(sortIndex), ptr, bufferSize);
}

ActionFunction3<size_t&, size_t, PredicateFunction<size_t&>> _Array::GetSortAction(void* const ptr, const size_t bufferSize, const size_t)
{
	return [&](size_t& i, size_t _i, PredicateFunction<size_t&> func) -> void
		{
			size_t sortIndex = 0;

			for (; i < _i; ++i)
			{
				if (func(sortIndex))

					return;

				Move(ptr, bufferSize, 1, sortIndex, i);
			}
		};
}
size_t _Array::GetSortDelegate(const size_t bufferSize, Selector3<void* const, const size_t, const size_t, ActionFunction3<size_t&, size_t, PredicateFunction<size_t&>>>* func)
{
	if (bufferSize)
	{
		size_t count = (bufferSize / GetItemSize());

		*func = count == 1 ? &GetSortAction : [](void* const ptr, const size_t bufferSize, const size_t count) -> ActionFunction3<size_t&, size_t, PredicateFunction<size_t&>>
			{
				return [&](size_t& i, size_t _i, PredicateFunction<size_t&> func) -> void
					{
						size_t sortIndex = 0;
						size_t _sortIndex = 0;

						for (; i < _i; ++i)
						{
							if (func(sortIndex))

								return;

							for (++i; i < _i && i < count; ++i)

								if (func(_sortIndex))
								{

								}

							Move(ptr, bufferSize, 1, sortIndex, i);
						}
					};
			};

		return count;
	}

	*func = &GetSortAction;

	return 1;
}

bool _Array::_Merge(const size_t startIndex, const size_t length1, const size_t length2, PredicateFunction2<const size_t, const size_t>& const predicate, ActionFunction3<size_t&, size_t, PredicateFunction<size_t&>>& const action)
{
	size_t i = startIndex + length1;

	if (WinCopies::Math::IsAdditionResultInRange(i, length2, _length))
	{
		size_t _i = i + length2;
		PredicateFunction<const size_t> _predicate = [&](const size_t index) -> bool
			{
				return predicate(i, index);
			};
		PredicateFunction<size_t&> func = [&](size_t& sortIndex) -> bool
			{
				return (sortIndex = GetSortIndex(startIndex, length1, _predicate)) == i;
			};

		action(i, _i, func);

		return true;
	}

	return false;
}
ErrorCode _Array::Merge(const size_t startIndex, const size_t length1, const size_t length2, PredicateFunction2<const size_t, const size_t>& const predicate, ActionFunction3<size_t&, size_t, PredicateFunction<size_t&>>& const action)
{
	return ValidateIndex(startIndex) && IsAdditionResultInRange(startIndex, length1, _length) && (length2 == 0 || _Merge(startIndex, length1, length2, predicate, action)) ? ErrorCode::Success : ErrorCode::ArgumentOutOfRange;
}
ErrorCode _Array::Merge(const size_t startIndex, const size_t length, PredicateFunction2<const size_t, const size_t>& const predicate, ActionFunction3<size_t&, size_t, PredicateFunction<size_t&>>& const action)
{
	return Merge(startIndex, length, length, predicate, action);
}
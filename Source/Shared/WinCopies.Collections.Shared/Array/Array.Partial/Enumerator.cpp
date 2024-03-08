#include "pch.h"
#include "../../../../Include/Collections/Array/Array.Partial/Enumerator.h"
#include "../../../../Include/Collections/Array/Array.Partial/Array.h"
#include "../../../../Include/Util/Util.h"
#include "../../../../Include/Util/System.h"

using namespace WinCopies;
using namespace WinCopies::Collections;

Array::Enumerator::Enumerator(shared_ptr<Array> const array, const EnumerationDirection enumerationDirection)
{
	_array = array;
	_enumerationDirection = enumerationDirection;
}

bool Array::Enumerator::IsResetSupported() const { return true; }

EnumerationDirection Array::Enumerator::GetEnumerationDirection() const { return _enumerationDirection; }

void Array::Enumerator::Update()
{
	*_moveNext = [&]() -> ErrorCode
	{
		return CloseEnumeration();
	};
}
void Array::Enumerator::_MoveNext(FunctionFunction<bool>& const func, ActionFunctionVoid& const action)
{
	action();

	if (func())

		return;

	Update();
}
void Array::Enumerator::MoveNext(FunctionFunction<bool>& const func, ActionFunctionVoid& const action)
{
	if (func())

		*_moveNext = [&]() -> ErrorCode
		{
			_MoveNext(func, action);

			return ErrorCode::Success;
		};

	else

		Update();
}
void Array::Enumerator::Update(FunctionFunction<bool>& const func, ActionFunctionVoid& const action)
{
	*_moveNext = [&]() -> ErrorCode
	{
		MoveNext(func, action);

		return ErrorCode::Success;
	};
}

ErrorCode Array::Enumerator::OnStarting()
{
	WinCopies::Collections::Enumerator::OnStarting();

	if (!(_moveNext = MALLOC(FunctionFunction<ErrorCode>)))

		return System::ErrorHandling::SetSystemError(SystemErrorCode::OutOfMemory);

	FunctionFunction<bool> func;
	ActionFunctionVoid action;

	if (_enumerationDirection == EnumerationDirection::FIFO)
	{
		Init(_array->GetVoidPtr());

		void* last = _array->GetLastVoidPtr();

		func = [&]() -> bool
		{
			return GetCurrentPtr() < last;
		};
		action = GetAddAction();
	}

	else
	{
		void* first = _array->GetVoidPtr();

		Init(_array->GetLastVoidPtr());

		func = [&]() -> bool
		{
			return GetCurrentPtr() > first;
		};
		action = GetSubAction();
	}

	Update(func, action);
}

ErrorCode Array::Enumerator::MoveNextOverride()
{
	return (*_moveNext)();
}

void Array::Enumerator::OnCompleted(const ErrorCode& errorCode)
{
	free(_moveNext);

	WinCopies::Collections::Enumerator::OnCompleted(errorCode);
}

ErrorCode Array::Enumerator::ResetOverride() const { return ErrorCode::Success; }
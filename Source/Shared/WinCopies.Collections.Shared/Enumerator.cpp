#include "pch.h"
#include "../../Include/Collections/Enumeration/EnumeratorBase.h"
#include "../../Include/Util/System.h"
#include "../../Include/Util/Util.h"

using namespace WinCopies::Collections;

Enumerator::Enumerator()
{
	ResetMoveNext();
}

ErrorCode Enumerator::OnStarting()
{
	return ErrorCode::Success;
}
void Enumerator::OnCompleted(const ErrorCode& errorCode) { /* Left empty. */ }

EnumerationState Enumerator::GetState() const
{
	return _state;
}

bool Enumerator::IsReady() const
{
	return _state == EnumerationState::None;
}
bool Enumerator::IsStarted() const
{
	return _state == EnumerationState::Started;
}
bool Enumerator::IsCompleted() const
{
	return _state == EnumerationState::Completed;
}

bool Enumerator::CheckErrorCode(const ErrorCode& errorCode)
{
	if (errorCode < 0 || System::ErrorHandling::CheckNotification2(errorCode, SystemErrorCode::NoMoreItems))
	{
		_state = EnumerationState::Completed;

		_moveNext = CloseEnumeration;

		OnCompleted(errorCode);

		return true;
	}

	return false;
}

void Enumerator::ResetMoveNext()
{
	_moveNext = [&]() -> ErrorCode
	{
		_state = EnumerationState::Started;

		ErrorCode errorCode = OnStarting();

		if (CheckErrorCode(errorCode))

			return errorCode;

		return (_moveNext = [&]() -> ErrorCode
			{
				errorCode = MoveNextOverride();

				CheckErrorCode(errorCode);

				return errorCode;
			})();
	};
}

ErrorCode Enumerator::MoveNext()
{
	return _moveNext();
}
ErrorCode Enumerator::Reset()
{
	if (IsStarted())

		return ErrorCode::InvalidOperation;

	if (IsReady())

		return ErrorCode::Success;

	ErrorCode errorCode = ResetOverride();

	if (errorCode >= 0)
	{
		_state = EnumerationState::None;

		ResetMoveNext();
	}

	return errorCode;
}

ErrorCode Enumerator::CloseEnumeration()
{
	return System::ErrorHandling::SetSystemNotification(SystemErrorCode::NoMoreItems);
}

Enumerator::~Enumerator()
{
	if (IsStarted())

		OnCompleted(ErrorCode::Success);
}
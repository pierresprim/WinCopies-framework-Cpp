#include "../../Include/Collections/Enumeration/IEnumerable.h"
#include "../../Include/Collections/Enumeration/Enumerable.h"
#include "../../Include/Util/System.h"

using namespace WinCopies;
using namespace WinCopies::Collections;

ErrorCode Enumerable::ForEach(IEnumerator* enumerator, SelectorFunction<FunctionFunction<bool>, PredicateFunction<ErrorCode>> selector)
{
	ErrorCode errorCode;

	auto predicate = selector([errorCode]() -> bool
		{
			return System::ErrorHandling::CheckNotification2(errorCode, SystemErrorCode::NoMoreItems);
		});

	while ((errorCode = enumerator->MoveNext()) >= 0 && predicate(errorCode))
	{
		// Left empty.
	}

	delete enumerator;
	enumerator = nullptr;

	return errorCode;
}

SystemErrorCode Enumerable::Enumerate(const FunctionFunction<HANDLE>& start, const SelectorFunction<HANDLE, EnumerationReturnReason>& next, const PredicateFunction<HANDLE>& close, const ActionFunction<EnumerationReturnReason*>& callback)
{
	WinCopies::Collections::Generic::EnumerationDelegates<HANDLE> delegates;

	delegates.Start = [start](bool* result) -> HANDLE
	{
		HANDLE enumerationHandle = start();

		*result = enumerationHandle != INVALID_HANDLE_VALUE;

		return enumerationHandle;
	};
	delegates.Next = next;
	delegates.Close = close;
	delegates.Callback = callback;

	return WinCopies::Collections::Enumerable::Enumerate<HANDLE>(delegates);
}

SystemErrorCode Collections::Enumerable::Enumerate(const SelectorFunction2<LPWSTR, DWORD, HANDLE>& start, const SelectorFunction3<HANDLE, LPWSTR, DWORD, bool>& next, const PredicateFunction<HANDLE>& close, const ActionFunction2<EnumerationReturnReason*, STDSTRING*>& callback, PredicateFunction<STDSTRING*>& predicate)
{
#define INVALID_STRING (STDSTRING*)INVALID_HANDLE_VALUE
	WCHAR name[MAX_PATH] = L"";
	WCHAR* namePtr = name;
	STDSTRING *_name = INVALID_STRING;

#define GET_NAME namePtr, ARRAYSIZE(name)

	return WinCopies::Collections::Enumerable::Enumerate([namePtr, start]()
		{
			return start(GET_NAME);
		}, [namePtr, next](HANDLE handle)
		{
			if (next(handle, GET_NAME))

				return EnumerationReturnReason::Success;

			SystemErrorCode error = System::ErrorHandling::GetLastError();

			return error == SystemErrorCode::NoMoreFiles ? EnumerationReturnReason::Completed : EnumerationReturnReason::Error;
		}, [](HANDLE handle)
		{
			return true;
		}, [name, &_name, callback, predicate](WinCopies::Collections::EnumerationReturnReason* enumerationReturnReason)
		{
			// Is this a success (enumeration processing or completed) call?

			if ((BYTE)*enumerationReturnReason > 0)
			{
#define CALLBACK(str) callback(enumerationReturnReason, str);

				// Is the value retrieved valid?

				if (predicate(_name = new STDSTRING(name)))

					// If so, just call back.

					CALLBACK(_name);

				// Otherwise, notify for the error before calling back.

				System::ErrorHandling::SetLastError(SystemErrorCode::BadPathName);

				*enumerationReturnReason = EnumerationReturnReason::Error;

				CALLBACK(INVALID_STRING);
			}
		});

#undef CALLBACK
#undef GET_NAME
}
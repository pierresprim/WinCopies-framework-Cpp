#pragma once

#ifndef WINCOPIES_ENUMERABLE_BASE_H
#define WINCOPIES_ENUMERABLE_BASE_H

namespace WinCopies
{
	namespace Collections
	{
		ENUM EnumerationReturnReason : SBYTE
		{
			Error = -1,
			Completed = 0,
			Success = 1
		};

		namespace Generic
		{
			TEMPLATE STRUCT EnumerationDelegates
			{
				SelectorFunction<bool*, T> Start;
				SelectorFunction<T, EnumerationReturnReason> Next;
				PredicateFunction<T> Close;
				ActionFunction<EnumerationReturnReason*> Callback;
			};
		}

#define CALLBACK(value) delegates.Callback(&(enumerationReturnReason = EnumerationReturnReason::value));
#define CALLBACK_SUCCESS CALLBACK(Success)

		namespace
		{
			class EnumerationInternal
			{
			private:
				EnumerationInternal() = delete;

				template<typename T>
				static T InitiateEnumeration(const bool* result, const SelectorFunction<bool*, T>& start, SystemErrorCode* errorCode)
				{
					T handle = start(result);

					if (*result)

						errorCode = SystemErrorCode::Success;

					else
					{
						CALLBACK(Error);

						errorCode = System::ErrorHandling::GetLastError();
					}

					return handle;
				}
			};
		}

		INTERFACE_CLASS(IEnumerable)
		{
		public:
			virtual ~IEnumerable() = default;

			virtual bool SupportsReversedEnumeration() const = 0;
		};

		INTERFACE_CLASS(Enumerable) :
			BASE_INTERFACE IEnumerable
		{
		private:
			Enumerable() = delete;

			template<typename T>
			static const bool loop(const T& handle, const EnumerationReturnReason* enumerationReturnReason, const WinCopies::Collections::Generic::EnumerationDelegates<T>& delegates)
			{
				if ((*enumerationReturnReason = delegates.Next(handle)) == WinCopies::Collections::EnumerationReturnReason::Success)
				{
					CALLBACK_SUCCESS

					return true;
				}

				delegates.Callback(*enumerationReturnReason);

				return false;
			}

		protected:
			ErrorCode ForEach(IEnumerator* enumerator, SelectorFunction<FunctionFunction<bool>, PredicateFunction<ErrorCode>> selector);

		public:
			virtual ~Enumerable() override = default;

			template<typename T>
			static SystemErrorCode Enumerate(const WinCopies::Collections::Generic::EnumerationDelegates<T>& delegates)
			{
				EnumerationReturnReason enumerationReturnReason = EnumerationReturnReason::Error;
				SystemErrorCode errorCode = SystemErrorCode::Error;

				T handle = EnumerationInternal::InitiateEnumeration((bool*)&enumerationReturnReason, delegates.Start, errorCode);

				if (errorCode != SystemErrorCode::Success)

					return errorCode;

				CALLBACK_SUCCESS

				while (enumerationReturnReason == EnumerationReturnReason::Success && loop(handle, enumerationReturnReason, delegates.Next))
				{
					// Left empty.
				}

				if (enumerationReturnReason == EnumerationReturnReason::Completed)

					return delegates.Close(handle) ? SystemErrorCode::Success : System::ErrorHandling::GetLastError();

				enumerationReturnReason = (EnumerationReturnReason)GetLastError();

				delegates.Close(handle);

				return (SystemErrorCode)enumerationReturnReason;
			}

			static SystemErrorCode Enumerate(const FunctionFunction<HANDLE>& start, const SelectorFunction<HANDLE, EnumerationReturnReason>& next, const PredicateFunction<HANDLE>& close, const ActionFunction<EnumerationReturnReason*>& callback);

			static SystemErrorCode Enumerate(const SelectorFunction2<LPWSTR, DWORD, HANDLE>& start, const SelectorFunction3<HANDLE, LPWSTR, DWORD, bool>& next, const PredicateFunction<HANDLE>& close, const ActionFunction2<EnumerationReturnReason*, STDSTRING*>& callback, PredicateFunction<STDSTRING*>& predicate);

			template<typename T>
			static SystemErrorCode Enumerate(const SelectorFunction2<LPWSTR, DWORD, HANDLE>& start, const SelectorFunction3<HANDLE, LPWSTR, DWORD, bool>& next, const PredicateFunction<HANDLE>& close, const SelectorFunction2<EnumerationReturnReason*, STDSTRING* , T>& converter, const ActionFunction2<EnumerationReturnReason*, T>& callback, PredicateFunction<STDSTRING*>& predicate)
			{
				T value = 0;

				return Enumerate(start, next, close, [value, converter, callback](EnumerationReturnReason* enumerationReturnReason, STDSTRING* str)
					{
						if (*enumerationReturnReason > 0)
						{
							value = converter(enumerationReturnReason, str);

							delete str;

							callback(enumerationReturnReason, value);
						}

						callback(EnumerationReturnReason::Error, 0);
					}, predicate);
			}
		};

#undef CALLBACK_SUCCESS
#undef CALLBACK
	}
}

#endif
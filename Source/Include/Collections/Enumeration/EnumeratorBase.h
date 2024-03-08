#pragma once

#ifndef WINCOPIES_ENUMERATORBASE_H
#define WINCOPIES_ENUMERATORBASE_H

#include "IEnumerator.h"
#include "Enumerable.h"

namespace WinCopies
{
	namespace Collections
	{
		INTERFACE_CLASS(Enumerator) :
			BASE_INTERFACE IEnumerator
		{
		private:
			EnumerationState _state = EnumerationState::None;
			FunctionFunction<ErrorCode> _moveNext;

			void ResetMoveNext();

			bool CheckErrorCode(const ErrorCode& errorCode);

		protected:
			virtual inline ErrorCode OnStarting();
			virtual inline void OnCompleted(const ErrorCode& errorCode);

			virtual ErrorCode MoveNextOverride() = 0;
			virtual ErrorCode ResetOverride() = 0;

		public:
			explicit Enumerator();
			virtual ~Enumerator() override;

			virtual inline EnumerationState GetState() const final;

			virtual inline bool IsReady() const final;
			virtual inline bool IsStarted() const final;
			virtual inline bool IsCompleted() const final;

			virtual ErrorCode MoveNext() final;
			virtual ErrorCode Reset() final;

			static ErrorCode CloseEnumeration();
		};

		namespace Generic
		{
			TEMPLATE
				INTERFACE_CLASS(EnumeratorBase) :
				BASE_INTERFACE IEnumerator<T>,
				BASE_INTERFACE WinCopies::Collections::Enumerator
			{
			protected:
				virtual T GetCurrentOverride() const = 0;

			public:
				virtual ~EnumeratorBase() override = default;

				virtual ErrorCode GetCurrent(T* result) const final
				{
					if (_isStarted && !_isCompleted)
					{
						*result = GetCurrentOverride();

						return ErrorCode::Success;
					}

					*result = NULL;
					
					return ErrorCode::InvalidOperation;
				}
			};

			TEMPLATE
				INTERFACE_CLASS(Enumerator) :
				public virtual EnumeratorBase<T>
			{
			private:
				T _current;

			protected:
				inline void SetCurrent(const T value)
				{
					_current = value;
				}

				virtual inline T GetCurrentOverride() const
				{
					return _current;
				}

			public:
				virtual ~Enumerator() override = default;
			};

			TEMPLATE2
				CLASS CommonEnumerator :
			public virtual Enumerator<T1>
			{
			private:
				T2 _handle;
				EnumerationDelegates<T2> _delegates;
				PredicateFunction<T2> _moveNext;

				bool Close()
				{
					return _delegates.Close(_handle);
				}

				void ResetMoveNext()
				{
					
				}

			public:
				virtual ~CommonEnumerator() override
				{
					~Enumerator<T1>();

					if (!Close())

						throw WinCopies::SystemException(System::ErrorHandling::GetLastError());
				}
				
				virtual inline EnumerationDirection GetEnumerationDirection() const
				{
					return EnumerationDirection::FIFO;
				}

				virtual inline ErrorCode MoveNextOverride() override
				{
					return _moveNext(_handle);
				}
				virtual ErrorCode ResetOverride() override
				{
					if (Close())
					{
						ResetMoveNext();

						return ErrorCode::Success;
					}

					return ErrorCode::SystemException;
				}
			};
		}
	}
}

#endif

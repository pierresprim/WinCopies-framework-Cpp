#pragma once

#ifndef WINCOPIES_IENUMERABLE_H
#define WINCOPIES_IENUMERABLE_H

#include <stdlib.h>
#include <memory>

#include "IEnumerator.h"
#include "../../Util/PP/Enum/Comparison.hpp"
#include "../Countable.h"
#include "EnumerableBase.h"

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE using EnumerablePredicate = PredicateFunction2<T, ErrorCode>;

			TEMPLATE INTERFACE_CLASS(IEnumerableBase)
			{
			public:
				virtual ~IEnumerableBase() = default;

				virtual ErrorCode ForEach(const EnumerablePredicate<T>&func)const = 0;
			};

			TEMPLATE INTERFACE_CLASS(IEnumerable) :
				BASE_INTERFACE WinCopies::Collections::Enumerable,
				BASE_TEMPLATE(IEnumerableBase)
			{
			public:
				typedef EnumerablePredicate<T> Predicate;

			private:
				template<typename U>
				using EnumerationSelector = ErrorCode(IEnumerable::*)(Predicate& predicate, U& action);

				typedef EnumerationSelector<PredicateFunction<T>> EnumerationSelectorPredicate;
				typedef EnumerationSelector<ActionFunction<T>> EnumerationSelectorAction;

				template<typename U>
				class DelegateEnumerable final :
					BASE_TEMPLATE(IEnumerableBase)
				{
				private:
					IEnumerable<T>* _enumerable;
					EnumerationSelector<U> _selector;
					std::shared_ptr<Predicate> _predicate;

					DelegateEnumerable(IEnumerable<T>* const enumerable, const EnumerationSelector<U> selector, const std::shared_ptr<Predicate> predicate)
					{
						_enumerable = enumerable;
						_selector = selector;
						_predicate = predicate;
					}

				public:
					static DelegateEnumerable<U> Create(IEnumerable<T>* const enumerable, const EnumerationSelector<U> selector, const std::shared_ptr<Predicate> predicate)
					{
						return new DelegateEnumerable<U>(enumerable, selector, predicate);
					}

					virtual ErrorCode ForEach(const Predicate& func) const final
					{
						ErrorCode errorCode = ErrorCode::UnknownException;

						return _enumerable->(*_selector)([&](T item, ErrorCode _errorCode) -> bool
							{
								return _predicate(item, errorCode = _errorCode);
							}, [&](T item) -> bool
							{
								return func(item, errorCode);
							});
					}

					bool ComparePredicates(Predicate* const predicate) const
					{
						return predicate == NULL || predicate == _predicate.get();
					}
				};

				template<typename U>
				using GetDelegateEnumerable = DelegateEnumerable<U>(*)(IEnumerable<T>* const enumerable, const EnumerationSelector<U> selector, const std::shared_ptr<Predicate> predicate);

				typedef DelegateEnumerable< PredicateFunction<T>> DelegateEnumerablePredicate;
				typedef std::unique_ptr<DelegateEnumerablePredicate> DelegateEnumerablePredicatePtr;

				typedef	DelegateEnumerable< ActionFunction<T>> DelegateEnumerableAction;
				typedef	std::unique_ptr<DelegateEnumerableAction> DelegateEnumerableActionPtr;

				struct DelegateEnumerables
				{
					DelegateEnumerablePredicatePtr Include;
					DelegateEnumerablePredicatePtr Exclude;
					DelegateEnumerableActionPtr While;
					DelegateEnumerableActionPtr Until;
					DelegateEnumerableActionPtr EnumerateWhile;
					DelegateEnumerableActionPtr EnumerateUntil;
				};

				FreeableUniquePtr<DelegateEnumerables> _delegateEnumerables;

				SystemErrorCode SetDelegateEnumerables()
				{
					return WinCopies::MAlloc(&_delegateEnumerables);
				}

				ErrorCode _ForEach(IEnumerator<T>* const enumerator, const SelectorFunction<FunctionFunction<bool>, Predicate> selector)const
				{
					return ForEach(enumerator, [selector](FunctionFunction<bool> func) -> PredicateFunction<ErrorCode>
						{
							Predicate predicate = selector(func);

							return [enumerator](ErrorCode errorCode) -> bool
							{
								return predicate(enumerator->GetCurrent(), errorCode);
							};
						});
				}

				ErrorCode ForEach(IEnumerator<T>* const enumerator, const Predicate& predicate)const
				{
					return _ForEach(enumerator, [predicate](Function<bool>& func) -> Predicate
						{
							return [&](T item, ErrorCode errorCode) -> bool
							{
								return !func() && predicate(item, errorCode);
							};
						});
				}

				ErrorCode ForEachUntil(IEnumerator<T>* const enumerator, const Predicate& predicate)const
				{
					return _ForEach(enumerator, [predicate](Function<bool>& func) -> Predicate
						{
							return [&](T item, ErrorCode errorCode) -> bool
							{
								return !(func() || predicate(item, errorCode));
							};
						});
				}

				template<class U>
				SystemErrorCode GetSubEnumerable(const std::shared_ptr<Predicate> predicate, DelegateEnumerable<U>** const enumerable, const EnumerationSelector<U> selector)const
				{
					return predicate.get() == NULL ? SystemErrorCode::BadArguments : (*enumerable = DelegateEnumerable<U>::Create(this, selector, predicate)) ? SystemErrorCode::Success : SystemErrorCode::OutOfMemory;
				}
				template<class U>
				void CreateSubEnumerable(const std::shared_ptr<Predicate> predicate, std::unique_ptr<DelegateEnumerable<U>>* const enumerable, const EnumerationSelector<U> selector, SystemErrorCode* const errorCode)const
				{
					DelegateEnumerable<U>* _enumerable = NULL;

					if ((*errorCode = GetSubEnumerable<U>(predicate, &_enumerable, selector)) == SystemErrorCode::Success)

						*enumerable = std::make_unique(_enumerable);
				}

				template<class U>
				SystemErrorCode GetSubEnumerable(const std::shared_ptr<Predicate> predicate, const IEnumerableBase<T>** enumerable, const EnumerationSelector<U> selector)const
				{
					DelegateEnumerable<U>* ptr = NULL;

					SystemErrorCode errorCode = GetSubEnumerable<U>(predicate, &ptr, selector);

					if (errorCode == SystemErrorCode::Success)
					{
						*enumerable = ptr;

						return SystemErrorCode::Success;
					}

					*enumerable = NULL;

					return errorCode;
				}
				template<class U>
				SystemErrorCode AsSubEnumerable(const std::shared_ptr<Predicate> predicate, const IEnumerableBase<T>** enumerable, const FunctionFunction<std::unique_ptr<U>*> func, const EnumerationSelector<U> selector)const
				{
					SystemErrorCode errorCode = SystemErrorCode::Error;
					*enumerable = NULL;

					if ((errorCode = SetDelegateEnumerables()) != SystemErrorCode::Success)

						return errorCode;

					std::unique_ptr<U>* _enumerable = func();

					if (*_enumerable == NULL)
					{
						if (CreateSubEnumerable(predicate, _enumerable, selector, &errorCode) != SystemErrorCode::Success)

							return errorCode;
					}

					else if (!(_enumerable->ComparePredicates(predicate) || CreateSubEnumerable(predicate, _enumerable, selector, &errorCode) == SystemErrorCode::Success))

						return errorCode;

					*enumerable = _enumerable.get();

					return SystemErrorCode::Success;
				}

			protected:
				IEnumerable()
				{
					_delegateEnumerables = NULL;
				}

			public:
				virtual ~IEnumerable() override = default;

				virtual std::shared_ptr<IEnumerator<T>> GetEnumerator() const = 0;
				virtual std::shared_ptr<IEnumerator<T>> GetReversedEnumerator() const = 0;

				virtual ErrorCode ForEach(const Predicate& func)const final
				{
					return ForEach(GetEnumerator(), func);
				}
				ErrorCode ReversedForEach(const Predicate& func)const
				{
					return SupportsReversedEnumeration() ? ForEach(GetReversedEnumerator(), func) : ErrorCode::InvalidOperationException;
				}

				ErrorCode ForEachUntil(const Predicate& func)const
				{
					return ForEachUntil(GetEnumerator(), func);
				}
				ErrorCode ReversedForEachUntil(const Predicate& func)const
				{
					return SupportsReversedEnumeration() ? ForEachUntil(GetReversedEnumerator(), func) : ErrorCode::InvalidOperationException;
				}

				ErrorCode Include(const Predicate& predicate, const PredicateFunction<T>& action)const
				{
					return ForEach([predicate, action](T item, ErrorCode errorCode) -> bool
						{
							return predicate(item, errorCode) ? action(item) : true;
						});
				}
				ErrorCode Exclude(const Predicate& predicate, const PredicateFunction<T>& action)const
				{
					return ForEach([predicate, action](T item, ErrorCode errorCode) -> bool
						{
							return predicate(item, errorCode) ? true : action(item);
						});
				}

				ErrorCode While(const Predicate& predicate, const ActionFunction<T>& action)const
				{
					return ForEach([predicate, action](T item, ErrorCode errorCode) -> bool
						{
							if (predicate(item, errorCode))
							{
								action(item);

								return true;
							}

							return false;
						});
				}
				ErrorCode Until(const Predicate& predicate, const ActionFunction<T>& action)const
				{
					return ForEach([predicate, action](T item, ErrorCode errorCode) -> bool
						{
							if (predicate(item, errorCode))

								return false;

							action(item);

							return true;
						});
				}

				ErrorCode EnumerateWhile(const Predicate& predicate, const ActionFunction<T>& action)const
				{
					return ForEach([predicate, action](T item, ErrorCode errorCode) -> bool
						{
							action(item);

							return predicate(item, errorCode);
						});
				}
				ErrorCode EnumerateUntil(const Predicate& predicate, const ActionFunction<T>& action)const
				{
					return ForEachUntil([predicate, action](T item, ErrorCode errorCode) -> bool
						{
							action(item);

							return predicate(item, errorCode);
						});
				}

				SystemErrorCode GetIncludeEnumerable(const std::shared_ptr<Predicate> predicate, const IEnumerableBase<T>** enumerable)const
				{
					return GetSubEnumerable<PredicateFunction<T>>(predicate, enumerable, &Include);
				}
				SystemErrorCode AsIncludeEnumerable(const std::shared_ptr<Predicate> predicate, const IEnumerableBase<T>** enumerable)const
				{
					return AsSubEnumerable(predicate, enumerable, [&]() -> std::unique_ptr<U>*
						{
							return &_delegateEnumerables->Include;
						}, &Include);
				}
				SystemErrorCode GetExcludeEnumerable(const std::shared_ptr<Predicate> predicate, const IEnumerableBase<T>** enumerable)const
				{
					return GetSubEnumerable<PredicateFunction<T>>(predicate, enumerable, &Exclude);
				}
				SystemErrorCode AsExcludeEnumerable(const std::shared_ptr<Predicate> predicate, const IEnumerableBase<T>** enumerable)const
				{
					return AsSubEnumerable(predicate, enumerable, [&]() -> std::unique_ptr<U>*
						{
							return &_delegateEnumerables->Exclude;
						}, &Exclude));
				}

				SystemErrorCode GetWhileEnumerable(const std::shared_ptr<Predicate> predicate, IEnumerableBase<T>** enumerable)const
				{
					return GetSubEnumerable<PredicateFunction<T>>(predicate, enumerable, &While);
				}
				SystemErrorCode AsWhileEnumerable(const std::shared_ptr<Predicate> predicate, IEnumerableBase<T>** enumerable)const
				{
					return AsSubEnumerable(predicate, enumerable, [&]() -> std::unique_ptr<U>*
						{
							return &_delegateEnumerables->While;
						}, &While));
				}
				SystemErrorCode GetUntilEnumerable(const std::shared_ptr<Predicate> predicate, IEnumerableBase<T>** enumerable)const
				{
					return GetSubEnumerable<PredicateFunction<T>>(predicate, enumerable, &Until);
				}
				SystemErrorCode AsUntilEnumerable(const std::shared_ptr<Predicate> predicate, IEnumerableBase<T>** enumerable)const
				{
					return AsSubEnumerable(predicate, enumerable, [&]() -> std::unique_ptr<U>*
						{
							return &_delegateEnumerables->Until;
						}, &Until));
				}

				SystemErrorCode GetEnumerateWhileEnumerable(const std::shared_ptr<Predicate> predicate, const IEnumerableBase<T>** enumerable)const
				{
					return GetSubEnumerable<PredicateFunction<T>>(predicate, enumerable, &EnumerateWhile);
				}
				SystemErrorCode AsEnumerateWhileEnumerable(const std::shared_ptr<Predicate> predicate, const IEnumerableBase<T>** enumerable)const
				{
					return AsSubEnumerable(predicate, enumerable, [&]() -> std::unique_ptr<U>*
						{
							return &_delegateEnumerables->EnumerateWhile;
						}, &EnumerateWhile));
				}
				SystemErrorCode GetEnumerateUntilEnumerable(const std::shared_ptr<Predicate> predicate, const IEnumerableBase<T>** enumerable)const
				{
					return GetSubEnumerable<PredicateFunction<T>>(predicate, enumerable, &EnumerateUntil);
				}
				SystemErrorCode AsEnumerateUntilEnumerable(const std::shared_ptr<Predicate> predicate, const IEnumerableBase<T>** enumerable)const
				{
					return AsSubEnumerable(predicate, enumerable, [&]() -> std::unique_ptr<U>*
						{
							return &_delegateEnumerables->EnumerateUntil;
						}, &EnumerateUntil));
				}

				ErrorCode First(const Predicate& predicate, T* const result)const
				{
					bool notFound = true;

					ErrorCode retVal = Include(predicate, [&](T item) -> bool
						{
							*result = item;

							return notFound = false;
						});

					if (retVal > 0)

						return retVal;

					*result = 0;

					return notFound ? ErrorCode::NotFound : retVal;
				}

				METHOD_TEMPLATE
				ErrorCode Select(const Predicate& func, const SelectorFunction2<T, ErrorCode, F>& selector, const PredicateFunction<F>& predicate)const
				{
					return ForEach([func, selector, predicate](T item, ErrorCode errorCode) -> bool
						{
							return func(item, errorCode) && predicate(selector(item, errorCode));
						});
				}
			};
		}
	}
}
#endif
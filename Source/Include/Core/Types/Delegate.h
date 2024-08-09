#pragma once

#ifndef WINCOPIES_TYPES_DELEGATE_H
#define WINCOPIES_TYPES_DELEGATE_H

#include "../../Kernel/Macros/Template.hxx"
#include "../../Kernel/Types/Delegates/Delegates.hxx"

namespace WinCopies
{
	namespace Delegate
	{
		TEMPLATE using Function = T(*)();
		TEMPLATE using FunctionFunction = std::function<T()>;

		TEMPLATE_EC(TObj) using InstanceActionVoid = INSTANCE_DELEGATE(TObj, void);
		TEMPLATE_EC(TObj, T) using InstanceFunction = INSTANCE_DELEGATE(TObj, T);
		
		CREATE_DELEGATE_ACTION(0, _DELEGATE_ACTION)
		CREATE_DELEGATE_ACTION(1, _INSTANCE_ACTION)
		CREATE_DELEGATE_ACTION(0, _STD_ACTION)

		CREATE_DELEGATE_ACTIONS(DELEGATE)
		CREATE_DELEGATE_ACTIONS(INSTANCE)
		CREATE_DELEGATE_ACTIONS(ACTION)

		CREATE_SELECTOR_DELEGATES(Converter, T)
		CREATE_SELECTOR_DELEGATES(Predicate, bool)

		CREATE_SELECTORS(_PREDICATE)
		CREATE_SELECTORS(_COMPARISON)
		CREATE_SELECTORS(_EQUALITY_COMPARISON)

		CREATE_COMPARISON_DELEGATES()
		CREATE_COMPARISON_DELEGATES(Equality)

#define CREATE_DUAL_PREDICATE(prefix) TEMPLATE using prefix##DualPredicate = PredicateFunction2<T, prefix##ErrorCode>;
		CREATE_DUAL_PREDICATE()
		CREATE_DUAL_PREDICATE(System)
#undef CREATE_DUAL_PREDICATE
	}
}
#endif WINCOPIES_TYPES_DELEGATE_H
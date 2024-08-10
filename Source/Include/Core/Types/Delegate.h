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

#define __CREATE_EXTENDED_PREDICATE(prefix, name, decorators) TEMPLATE using SURROUND(prefix, name, Predicate) = SURROUND(FIRST_ARG decorators, Function, SECOND_ARG decorators)<T, PREFIX(prefix, ErrorCode)>;
#define _CREATE_EXTENDED_PREDICATE(isSystem, name, decorators) __CREATE_EXTENDED_PREDICATE(IF(isSystem, System), name, decorators)
#define CREATE_EXTENDED_PREDICATE(name, decorators) _CREATE_EXTENDED_PREDICATE(0, name, decorators) _CREATE_EXTENDED_PREDICATE(1, name, decorators)

		CREATE_EXTENDED_PREDICATE(Dual, (Predicate, 2))
		CREATE_EXTENDED_PREDICATE(ErrorCode, (Selector, ))

#undef CREATE_EXTENDED_PREDICATE
#undef _CREATE_EXTENDED_PREDICATE
#undef __CREATE_EXTENDED_PREDICATE
	}
}
#endif WINCOPIES_TYPES_DELEGATE_H
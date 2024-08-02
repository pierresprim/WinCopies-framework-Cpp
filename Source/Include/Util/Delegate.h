#pragma once

#ifndef WINCOPIES_DELEGATE_H
#define WINCOPIES_DELEGATE_H

#include "UtilBase.h"

namespace WinCopies
{
	namespace Delegate
	{
		typedef void(*ActionVoid)();
		typedef std::function<void()> ActionFunctionVoid;

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
	}
}
#endif WINCOPIES_DELEGATE_H
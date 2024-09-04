#pragma once

#ifndef WINCOPIES_TYPING_SHARED_H
#define WINCOPIES_TYPING_SHARED_H

#include "../../Environment.h"
#include "../../Kernel/Macros/Type/Interface.hxx"

#include "EnableIf.h"

using namespace std;

namespace WinCopies
{
	namespace Typing
	{
		TEMPLATE class SharedBase ABSTRACT :
			public SharedType<T>
		{
		protected:
			SharedBase() = default;

			template <class TDerived, ENABLE_IF_BASE_OF(T, TDerived)> INLINE_FUNCTION_RETURN(Shared<TDerived>, AsShared, std::static_pointer_cast<TDerived>(this->shared_from_this()))
		};

		INTERFACE_CLASS(SharedInterface,
			BASE_INTERFACE SharedBase<SharedInterface>)
		};
	}
}
#endif WINCOPIES_TYPING_SHARED_H
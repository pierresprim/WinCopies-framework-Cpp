#pragma once

#ifndef WINCOPIES_DELEGATE_H
#define WINCOPIES_DELEGATE_H

#include "../Core/Types/Delegate.h"

namespace WinCopies
{
	namespace Delegate
	{
		typedef void(*ActionVoid)();
		typedef std::function<void()> ActionFunctionVoid;

#define __CREATE_BOOL_FUNC(type, typeNamePrefix, typeNameSuffix, prefix, nameSuffix, ...) (prefix##Function##typeNameSuffix<__VA_ARGS__ VA_OPT(COMMA, __VA_ARGS__) type>), (typeNamePrefix##Func##nameSuffix)

#define _CREATE_BOOL_FUNC(keyword, ...) keyword __VA_ARGS__;
#define CREATE_BOOL_FUNC(type, typeNamePrefix, typeNameSuffix, prefix, nameSuffix, ...) _CREATE_BOOL_FUNC(typedef, PRINT_EXPANDED_ARGS(__CREATE_BOOL_FUNC(type, typeNamePrefix, typeNameSuffix, prefix, nameSuffix, __VA_ARGS__)))

#define _CREATE_BOOL_FUNC_TEMPLATE(...) _CREATE_BOOL_FUNC(using, SINGLE_ARG SECOND_ARG(__VA_ARGS__) = SINGLE_ARG FIRST_ARG(__VA_ARGS__))
#define CREATE_BOOL_FUNC_TEMPLATE(type, typeNamePrefix, typeNameSuffix, prefix, nameSuffix, ...) template<class TObj> _CREATE_BOOL_FUNC_TEMPLATE(__CREATE_BOOL_FUNC(type, typeNamePrefix, typeNameSuffix, prefix, nameSuffix, __VA_ARGS__))

#define __CREATE_BOOL_FUNCS(type, typeNamePrefix) CREATE_BOOL_FUNC(type, typeNamePrefix, , , ) CREATE_BOOL_FUNC_TEMPLATE(type, typeNamePrefix##Instance, , Instance, , TObj) CREATE_BOOL_FUNC(type, typeNamePrefix, Function, , tion)
#define _CREATE_BOOL_FUNCS(type) __CREATE_BOOL_FUNCS(type, type)
#define CREATE_BOOL_FUNCS(prefix) _CREATE_BOOL_FUNCS(prefix##ErrorCode)

		__CREATE_BOOL_FUNCS(bool, Bool)

		CREATE_BOOL_FUNCS()
		CREATE_BOOL_FUNCS(System)

#undef CREATE_BOOL_FUNCS
#undef _CREATE_BOOL_FUNCS
#undef __CREATE_BOOL_FUNCS
#undef CREATE_BOOL_FUNC_TEMPLATE
#undef _CREATE_BOOL_FUNC_TEMPLATE
#undef CREATE_BOOL_FUNC
#undef _CREATE_BOOL_FUNC
#undef __CREATE_BOOL_FUNC

		TEMPLATE_EC(TObj, TValue) STRUCT SharedDelegate
		{
		private:
			Shared<TObj> _ptr;
			InstanceFunction<TObj, TValue> _delegate;

		public:
			explicit SharedDelegate(TObj ptr, InstanceFunction<TObj, TValue> delegate)
			{
				_ptr = ptr;
				_delegate = delegate;
			}

			TValue operator()() const noexcept { return (_ptr->*_delegate)(); };
		};
	}
}
#endif WINCOPIES_DELEGATE_H
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

#define CREATE_BOOL_FUNC(type, typeNamePrefix, typeNameSuffix, nameSuffix) typedef Function##typeNameSuffix<type> typeNamePrefix##Func##nameSuffix;
#define __CREATE_BOOL_FUNCS(type, typeNamePrefix) CREATE_BOOL_FUNC(type, typeNamePrefix, , ) CREATE_BOOL_FUNC(type, typeNamePrefix, Function, tion)
#define _CREATE_BOOL_FUNCS(type) __CREATE_BOOL_FUNCS(type, type)
#define CREATE_BOOL_FUNCS(prefix) _CREATE_BOOL_FUNCS(prefix##ErrorCode)

		__CREATE_BOOL_FUNCS(bool, Bool)

		CREATE_BOOL_FUNCS()
		CREATE_BOOL_FUNCS(System)

#undef CREATE_BOOL_FUNCS
	}
}
#endif WINCOPIES_DELEGATE_H
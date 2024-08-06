#pragma once

#ifndef WINCOPIES_DELEGATE_H
#define WINCOPIES_DELEGATE_H

#include "../Core/Types/Delegate.h"

#include "UtilBase.h"

namespace WinCopies
{
	namespace Delegate
	{
		typedef void(*ActionVoid)();
		typedef std::function<void()> ActionFunctionVoid;
	}
}
#endif WINCOPIES_DELEGATE_H
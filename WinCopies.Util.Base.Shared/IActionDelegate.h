#pragma once
#ifndef IACTIONDELEGATE_H
#define IACTIONDELEGATE_H

#include "wincopies_defines.h"

namespace WinCopies
{
	class DLLEXPORT IActionDelegate ABSTRACT
	{
	public:
		virtual void Action() = 0;

		virtual ~IActionDelegate();
	};
}

#endif

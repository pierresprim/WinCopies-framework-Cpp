#pragma once
#ifndef SAFEPOINTER_H
#define SAFEPOINTER_H

#include "wincopies_defines.h"

namespace WinCopies
{
	template <typename T>
		struct DLLEXPORT SafePointer
	{
	private:
		T* _ptr;

		SafePointer()
		{

		}
	public:
		~SafePointer()
		{
			if (_ptr != nullptr)
			{
				delete _ptr;

				_ptr = nullptr;
			}
		}

		 static SafePointer<T> GetSafePointer(T*  pointer)
		{
			 return SafePointer<T>
			 {
				 _ptr = pointer
			 };
		}

		T* GetPointer() const
		{
			return _ptr;
		}

		T GetValue() const
		{
			return *_ptr;
		}
	};
}

#endif // SAFEPOINTER_H

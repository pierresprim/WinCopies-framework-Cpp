//#pragma once
//#ifndef OUTPOINTER_H
//#define OUTPOINTER_H
//
//#include "wincopies_defines.h"
//#include "Exception.h"
//#include "SafePointer.h"
//
//namespace WinCopies
//{
//	TEMPLATE
//		struct OutPointer
//	{
//	private:
//		const T _value;
//		bool _hasValue;
//
//	public:
//		OutPointer()
//		{
//			_value = 0;
//
//			_hasValue = false;
//		}
//
//		OutPointer(const T value)
//		{
//			_value = value;
//
//			_hasValue = true;
//		}
//
//		bool GetHasValue()
//		{
//			return _hasValue;
//		}
//
//		T GetValue()
//		{
//			if (_hasValue)
//
//				return _value;
//
//			throw new EmptyObjectException();
//		}
//	};
//}
//
//#endif

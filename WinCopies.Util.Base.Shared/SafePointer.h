//#pragma once
//#ifndef SAFEPOINTER_H
//#define SAFEPOINTER_H
//
//#include "wincopies_defines.h"
//
//namespace WinCopies
//{
//TEMPLATE
//struct DLLEXPORT SafePointer
//{
//private:
//T* _ptr;
//public:
//~SafePointer()
//{
// if (_ptr != nullptr)
// {
//     delete _ptr;
//
//     _ptr = nullptr;
// }
//}
//
//    explicit SafePointer(const T* pointer)
//{
//        _ptr = pointer;
//}
//
//void Update(const T* value)
//{
//    delete _ptr;
//
//    _ptr = value;
//}
//};
//}
//
//#endif // SAFEPOINTER_H

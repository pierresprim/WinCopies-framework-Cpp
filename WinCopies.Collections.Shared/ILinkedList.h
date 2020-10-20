///* Copyright © Pierre Sprimont, 2020
// *
// * This file is part of the WinCopies Framework.
// *
// * The WinCopies Framework is free software: you can redistribute it and/or modify
// * it under the terms of the GNU General Public License as published by
// * the Free Software Foundation, either version 3 of the License, or
// * (at your option) any later version.
// *
// * The WinCopies Framework is distributed in the hope that it will be useful,
// * but WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// * GNU General Public License for more details.
// *
// * You should have received a copy of the GNU General Public License
// * along with the WinCopies Framework.  If not, see <https://www.gnu.org/licenses/>. */
//
//#pragma once
//#ifndef ILINKEDLIST_H
//#define ILINKEDLIST_H
//
//#include "defines.h"
//#include "IEnumerable.h"
//#include "EnumeratorBase.h"
//#include "IReadOnlyLinkedList.h"
//#include "../WinCopies.Util.Base.Shared/Exception.h"
//#include "../WinCopies.Util.Base.Shared/ThrowHelper.h"
//
//namespace WinCopies
//{
//	namespace Collections
//	{
//		TEMPLATE
//			class DLLEXPORT ILinkedList ABSTRACT :
//		public virtual IReadOnlyLinkedList<T>
//		{
//	public:
//		virtual ~ILinkedList() override = default;
//
//		virtual ILinkedListNode<T>* AddAfter(const ILinkedListNode<T>* node, T value) = 0;
//
//		virtual ILinkedListNode<T>* AddBefore(const ILinkedListNode<T>* node, T value) = 0;
//
//		virtual ILinkedListNode<T>* AddFirst(const T value) = 0;
//
//		virtual ILinkedListNode<T>* AddLast(const T value) = 0;
//
//		virtual ILinkedListNode<T>* Find(const T value) = 0;
//
//		virtual ILinkedListNode<T>* FindLast(const T value) = 0;
//
//		virtual IEnumerator<ILinkedListNode<T>*>* GetNodeEnumerator(const EnumerationDirection enumerationDirection) = 0;
//
//		virtual void Remove(const ILinkedListNode<T>* node) = 0;
//
//		virtual void RemoveFirst() = 0;
//
//		virtual void RemoveLast() = 0;
//		};
//	}
//}
//
//#endif // ILINKEDLIST_H

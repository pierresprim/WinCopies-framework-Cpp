/* Copyright © Pierre Sprimont, 2020
 *
 * This file is part of the WinCopies Framework.
 *
 * The WinCopies Framework is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The WinCopies Framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the WinCopies Framework.  If not, see <https://www.gnu.org/licenses/>. */

#pragma once
#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H

#include "defines.h"
#include "IEnumerable.h"
#include "EnumeratorBase.h"
#include "../WinCopies.Util.Base.Shared/Exception.h"
#include "../WinCopies.Util.Base.Shared/ThrowHelper.h"

namespace WinCopies
{
	namespace Collections
	{
		enum class DLLEXPORT LinkedListEnumerationDirection
		{
			FIFO = 1,

			LIFO = 2
		};

		TEMPLATE
			class ILinkedList ABSTRACT;

		TEMPLATE
			class DLLEXPORT ILinkedListNode ABSTRACT
		{
		public:
			virtual ~ILinkedListNode()
			{
				// Left empty.
			}

			virtual bool GetIsReadOnly() const = 0;

			virtual ILinkedList<T>* GetList() const = 0;

			virtual ILinkedListNode<T>* GetPrevious() const = 0;

			virtual ILinkedListNode<T>* GetNext() const = 0;

			virtual T GetValue() const = 0;
		};

		TEMPLATE
			class DLLEXPORT IReadOnlyLinkedList ABSTRACT :
		public virtual IUIntCountableEnumerable<T>
		{
public:
			virtual ~IReadOnlyLinkedList() override = default;

			virtual ILinkedListNode<T>* GetLast() const = 0;

			virtual ILinkedListNode<T>* GetFirst() const = 0;

			virtual ILinkedListNode<T>* Find(const T value) const = 0;

			virtual ILinkedListNode<T> FindLast(const T value) const = 0;
		};

		TEMPLATE
			class DLLEXPORT ILinkedList ABSTRACT :
		public virtual IReadOnlyLinkedList<T>
		{
	public:
		virtual ~ILinkedList() override = default;

		virtual ILinkedListNode<T>* AddAfter(const ILinkedListNode<T>* node, T value) = 0;

		virtual ILinkedListNode<T>* AddBefore(const ILinkedListNode<T>* node, T value) = 0;

		virtual ILinkedListNode<T>* AddFirst(const T value) = 0;

		virtual ILinkedListNode<T>* AddLast(const T value) = 0;

		virtual ILinkedListNode<T>* Find(const T value) = 0;

		virtual ILinkedListNode<T>* FindLast(const T value) = 0;

		virtual IEnumerator<T>* GetEnumerator(const LinkedListEnumerationDirection enumerationDirection) = 0;

		virtual IEnumerator<ILinkedListNode<T>*>* GetNodeEnumerator(const LinkedListEnumerationDirection enumerationDirection) = 0;

		virtual void Remove(const ILinkedListNode<T>* node) = 0;

		virtual void RemoveFirst() = 0;

		virtual void RemoveLast() = 0;
		};

		TEMPLATE
			class ReadOnlyLinkedList :
			public virtual IReadOnlyLinkedList<T>,
			public virtual ILinkedList2<T>
		{
		public:
			bool GetIsReadOnly()
			{
				return true;
			}

			// protected ILinkedList<T> InnerList{ get; } // Already was ILinkedList<T> in WinCopies 2.

			ILinkedListNode<T> Last = > InnerList.Last;

			ILinkedListNode<T> First = > InnerList.First;

			unsigned int GetCount()
			{
				return InnerList.Count;
			}

			// object ICollection.SyncRoot = > InnerList.SyncRoot;

			// bool ICollection.IsSynchronized = > InnerList.IsSynchronized;

			bool Contains(const T value) const
			{
				return InnerList->Contains(value);
			}

			void CopyTo(const T[] array, const int index)
			{
				InnerList->CopyTo(array, index);
			}

			ILinkedListNode<T> Find(T value) = > InnerList.Find(value);

#if WinCopies2
			System.Collections.Generic.LinkedListNode
#else
			ILinkedListNode
#endif
				<T> FindLast(T value) = > InnerList.FindLast(value);

			System.Collections.Generic.IEnumerator<T>
#if WinCopies2
				IEnumerable<T>.
#endif
				GetEnumerator() = > InnerList.GetEnumerator();

			System.Collections.IEnumerator IEnumerable.GetEnumerator() = >
#if WinCopies2
				InnerList
#else
				((IEnumerable)InnerList)
#endif
				.GetEnumerator();

			System.Collections.Generic.IEnumerator<T> GetEnumerator(LinkedListEnumerationDirection enumerationDirection) = > InnerList.GetEnumerator(enumerationDirection);

			System.Collections.Generic.IEnumerator<ILinkedListNode<T>> GetNodeEnumerator(LinkedListEnumerationDirection enumerationDirection) = > InnerList.GetNodeEnumerator(enumerationDirection);

#if WinCopies2
			System.Collections.Generic.LinkedListNode
#else
			ILinkedListNode
#endif
				<T> AddAfter(
#if WinCopies2
					System.Collections.Generic.LinkedListNode
#else
					ILinkedListNode
#endif
					<T> node, T value) = > throw GetReadOnlyListOrCollectionException();

#if WinCopies2
			System.Collections.Generic.LinkedListNode
#else
			ILinkedListNode
#endif
				<T> AddBefore(
#if WinCopies2
					System.Collections.Generic.LinkedListNode
#else
					ILinkedListNode
#endif
					<T> node, T value) = > throw GetReadOnlyListOrCollectionException();

			ILinkedListNode<T> AddFirst(T value) = > throw GetReadOnlyListOrCollectionException();

#if WinCopies2
			System.Collections.Generic.LinkedListNode
#else
			ILinkedListNode
#endif
				<T> AddLast(T value) = > throw GetReadOnlyListOrCollectionException();

			public void Remove(
#if WinCopies2
				System.Collections.Generic.LinkedListNode
#else
				ILinkedListNode
#endif
				<T> node) = > throw GetReadOnlyListOrCollectionException();

			void RemoveFirst() = > throw GetReadOnlyListOrCollectionException();

			void RemoveLast() = > throw GetReadOnlyListOrCollectionException();
			};
			}
		}

#endif // ILINKEDLIST_H

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
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "defines.h"
#include "IEnumerable.h"
#include "EnumeratorBase.h"
#include "ILinkedList.h"
#include "../WinCopies.Util.Base.Shared/Exception.h"
#include "../WinCopies.Util.Base.Shared/ThrowHelper.h"

using namespace WinCopies;

namespace WinCopies
{
	namespace Collections
	{
		TEMPLATE
			class DLLEXPORT LinkedList :
			public virtual ILinkedList<T>
		{
		public:
			class LinkedListNode;
		private:
			unsigned int _enumeratorsCount = 0;
			// object _syncRoot;
			unsigned int _enumerableVersion;
			LinkedListNode* _first = nullptr;

			void IncrementEnumeratorsCount()
			{
				_enumeratorsCount++;
			}

			void DecrementEnumeratorsCount()
			{
				_enumeratorsCount--;

				if (_enumeratorsCount == 0)

					_enumerableVersion = 0;
			}

			void OnWeld()
			{
				if (_enumeratorsCount > 0)

					EnumerableVersion++;
			}

			void OnNewItemAdded(const LinkedListNode* node)
			{
				node.List = this;

				Count++;

				OnWeld();
			}

			void OnItemRemoved(const LinkedListNode* node)
			{
				node.OnRemove();

				Count--;

				OnWeld();
			}

			void Weld(const LinkedListNode* previous, const LinkedListNode* newNode, const LinkedListNode* next)
			{
				previous.Next = newNode;

				newNode.Previous = previous;

				newNode.Next = next;

				newNode.Previous = newNode;

				OnNewItemAdded(newNode);
			}

			void Weld(const LinkedListNode* previous, const LinkedListNode* next)
			{
				previous.Next = next;

				next.Previous = previous;
			}

			void _AddAfter(LinkedListNode addAfter, LinkedListNode node) = > Weld(addAfter, node, node.Next);

			void _AddBefore(LinkedListNode addBefore, LinkedListNode node) = > Weld(addBefore.Previous, node, addBefore);

			void _AddFirst(LinkedListNode node)
			{
				if (First != null)

					Weld(node, First);

#if CS7
				if (Last == null)

					Last = node;
#else
				Last ? ? = node;
#endif

				First = node;

				OnNewItemAdded(node);
			}

			void _AddLast(LinkedListNode node)
			{
				if (Last != null)
				{
					node.Previous = Last;

					Last.Next = node;
				}

#if CS7
				if (First == null)

					First = node;
#else
				First ? ? = node;
#endif

				Last = node;

				OnNewItemAdded(node);
			}

		protected:
			void ThrowIfNodeAlreadyHasList(const LinkedListNode* node)
			{
				if (node->GetList() != nullptr)

					throw new ArgumentException("The given node is already contained in another list.");
			}

			void ThrowIfNotContainedNode(const ILinkedListNode<T>* node)
			{
				if (node->GetList() != this)

					throw new ArgumentException("The given node is not contained in the current list.");
			}

			private ILinkedListNode<T>* Find(const T value, const LinkedListEnumerationDirection enumerationDirection)
			{
				new Enumerable<LinkedListNode*>(() = > GetNodeEnumerator(enumerationDirection)).FirstOrDefault(node = > (node.Value == null && value == null) || node.Value.Equals(value));
			}

		public:
			virtual ~LinkedList() override = default;

			virtual bool GetIsReadOnly() const final
			{
				return false;
			}

			LinkedList(IEnumerable<T>* collection)
			{
				collection->ForEach(AddLast);
			}

			class DLLEXPORT LinkedListNode :
				public virtual ILinkedListNode<T>
			{
			private:
				LinkedList<T>* _list = nullptr;
				LinkedListNode* _previous = nullptr;
				LinkedListNode* _next = nullptr;
				T _value;
			public:
				~LinkedListNode()
				{
					_list = nullptr;
					_previous = nullptr;
					_next = nullptr;
				}

				explicit LinkedListNode(T value)
				{
					_value = value;
				}

				virtual bool GetIsReadOnly() const final
				{
					return false;
				}

				LinkedList<T> GetLinkedList() const
				{
					return _list;
				}

				virtual ILinkedList<T> GetList() const final
				{
					return GetLinkedList();
				}

				LinkedListNode* GetPreviousNode()
				{
					return _previous;
				}

				virtual ILinkedListNode<T>* GetPrevious() const final
				{
					return GetPreviousNode();
				}

				LinkedListNode* GetNextNode()
				{
					return _next;
				}

				virtual ILinkedListNode<T>* GetNext() const final
				{
					return GetNextNode();
				}

				virtual T GetValue() const final
				{
					return _value;
				}

				/*void OnRemove()
				{
					List = null;
					Previous = null;
					Next = null;
				}
				*/
			};

			class DLLEXPORT Enumerator :
				public virtual EnumeratorBase<LinkedListNode*>
			{
			private:
				LinkedList<T>* _list;
				LinkedListNode* _currentNode;
				bool _first = true;
				const uint _version;
				const LinkedListEnumerationDirection _enumerationDirection;

			public:
				~Enumerator()
				{
					//
				}

				Enumerator(LinkedList<T>* list, LinkedListEnumerationDirection enumerationDirection)
				{
					// list._enumeratorsCount++;

					// _list = list ?? throw GetArgumentNullException(nameof(list));

					// _version = list.EnumerableVersion;

					_enumerationDirection = enumerationDirection;

					switch (enumerationDirection)
					{
					case LinkedListEnumerationDirection::FIFO:

						// _action = () => _currentNode = _currentNode.Next;

						// _reset = () => _currentNode = list.First;

						break;

					case LinkedListEnumerationDirection::LIFO:

						// _action = () => _currentNode = _currentNode.Previous;

						// _reset = () => _currentNode = list.Last;

						break;
					}
				}

				LinkedListEnumerationDirection GetEnumerationDirection()
				{
					return _enumerationDirection;
				}

			protected:
				virtual bool GetIsResetSupported() const final
				{
					return true;
				}

				virtual LinkedListNode* GetCurrentOverride() const final
				{
					return _currentNode;
				}

				virtual int ResetOverride() final
				{
					ThrowIfVersionHasChanged(_list.EnumerableVersion, _version);

					_first = true;

					_reset();
				}

				virtual bool MoveNextOverride() final
				{
					ThrowIfVersionHasChanged(_list.EnumerableVersion, _version);

					if (_first)
					{
						_first = false;

						return _currentNode != null;
					}

					_action();

					if (_currentNode == null)
					{
						ResetCurrent();

						return false;
					}

					// The new node has already been updated in the _action delegate.

					return true;
				}

				// virtual void ResetCurrent() => _currentNode = null;

				/*protected override void DisposeManaged()
				{
					base.DisposeManaged();

					_list = null;

					_action = null;

					ResetCurrent();

					_reset = null;
				}

				protected override void Dispose(bool disposing)
				{
					base.Dispose(disposing);

					_list.DecrementEnumeratorsCount();
				}*/
			};

			LinkedListNode* GetFirstNode() const
			{
				return _first;
			}

			virtual ILinkedListNode<T>* GetFirst() const final
			{
				return GetFirstNode();
			}

			LinkedListNode* GetLastNode()
			{
				return _last;
			}

			virtual ILinkedListNode<T>* GetLast() const final
			{
				return GetLastNode();
			}

			virtual unsigned int GetCount() const final
			{
				return _count;
			}

			/*bool ICollection.IsSynchronized => false;

			object ICollection.SyncRoot
			{
				get
				{
					if (_syncRoot == null)

						_ = System.Threading.Interlocked.CompareExchange(ref _syncRoot, new object(), null);

					return _syncRoot;
				}
			}*/

			LinkedListNode* AddAfter(const LinkedListNode* node, const T value)
			{
				ThrowHelper::ThrowIfNullPtrValue(node, L"node");

				ThrowIfNotContainedNode(node);

				LinkedListNode* newNode = new LinkedListNode(value);

				_AddAfter(node, newNode);

				return newNode;
			}

			virtual ILinkedListNode<T>* AddAfter(const ILinkedListNode<T>* node, const T value) final
			{
				LinkedListNode* _node = dynamic_cast<LinkedListNode*>(node);

				if (_node)

					AddAfter(_node, value);

				else

					throw new ArgumentException(L"node must be an instance of LinkedListNode.", L"node");
			}

			void AddAfter(const LinkedListNode* addAfter, const LinkedListNode* node)
			{
				ThrowHelper::ThrowIfNullPtrValue(addAfter, L"addAfter");
				ThrowHelper::ThrowIfNullPtrValue(node, L"node");

				ThrowIfNotContainedNode(addAfter);
				ThrowIfNodeAlreadyHasList(node);

				_AddAfter(addAfter, node);
			}

			LinkedListNode* AddBefore(const LinkedListNode* node, const T value)
			{
				ThrowHelper::ThrowIfNullPtrValue(node, L"node");

				LinkedListNode* newNode = new LinkedListNode(value);

				AddBefore(node is LinkedListNode _node ? _node : throw new ArgumentException($"{nameof(node)} must be an instance of {nameof(LinkedListNode)}."), value);
			}

			LinkedListNode* AddBefore(const LinkedListNode* node, const T value)
			{
				var newNode = new LinkedListNode(value);

				_AddBefore(node, newNode);

				return newNode;
			}

			void AddBefore(const LinkedListNode* addBefore, const LinkedListNode* node)
			{
				ThrowHelper::ThrowIfNullPtrValue(addBefore, L"addBefore");
				ThrowHelper::ThrowIfNullPtrValue(node, L"node");

				ThrowIfNotContainedNode(addBefore);
				ThrowIfNodeAlreadyHasList(node);

				_AddBefore(addBefore, node);
			}

			ILinkedListNode<T>* AddFirst(const T value)
			{
				var node = new LinkedListNode(value);

				_AddFirst(node);

				return node;
			}

			void AddFirst(const LinkedListNode* node)
			{
				ThrowHelper::ThrowIfNullPtrValue(node, L"node");

				ThrowIfNodeAlreadyHasList(node);

				_AddFirst(node);
			}

			ILinkedListNode<T>* AddLast(const T value)
			{
				LinkedListNode* node = new LinkedListNode(value);

				_AddLast(node);

				return node;
			}

			void AddLast(LinkedListNode* node)
			{
				ThrowIfNodeAlreadyHasList(node);

				_AddLast(node);
			}



			ILinkedListNode<T>* Find(const T value)
			{
				return Find(value, LinkedListEnumerationDirection::FIFO);
			}

			ILinkedListNode<T>* FindLast(const T value)
			{
				return Find(value, LinkedListEnumerationDirection.LIFO);
			}



			IEnumerator<T>* GetEnumerator()
			{
				return GetEnumerator(LinkedListEnumerationDirection::FIFO);
			}

			IEnumerator<T>* GetEnumerator(const LinkedListEnumerationDirection enumerationDirection)
			{
				return GetNodeEnumerator(enumerationDirection)=>Select(node = > node.Value);
			}

			IEnumerator<LinkedListNode>* GetNodeEnumerator(const LinkedListEnumerationDirection enumerationDirection)
			{
				return new Enumerator(this, enumerationDirection);
			}

			IEnumerator<ILinkedListNode<T>*>* ILinkedList<T>.GetNodeEnumerator(LinkedListEnumerationDirection enumerationDirection)
			{
				return GetNodeEnumerator(enumerationDirection);
			}

			void Remove(const LinkedListNode* node)
			{
				ThrowIfNotContainedNode(node);

				Weld(node.Previous, node.Next);

				OnItemRemoved(node);
			}

			void ILinkedList<T>.Remove(ILinkedListNode<T> node) = > Remove(node as LinkedListNode ? ? throw new ArgumentException($"{nameof(node)} must be an instance of {nameof(LinkedListNode)}."));

			bool Remove(const T item)
			{
				ILinkedListNode<T>* node = Find(item);

				if (node is LinkedListNode _node)
				{
					Remove(_node);

					return true;
				}

				return false;
			}

			void RemoveFirst()
			{
				ThrowIfEmptyListOrCollection(this);

				LinkedListNode* node = GetFirst();

				First = node.GetNext();

				OnItemRemoved(node);
			}

			void RemoveLast()
			{
				ThrowIfEmptyListOrCollection(this);

				LinkedListNode node = Last;

				Last = node.Previous;

				OnItemRemoved(node);
			}

			void Clear()
			{
				Count = 0;

				if (_enumeratorsCount > 0)

					EnumerableVersion++;
			}

			bool Contains(T item)
			{
				LinkedListNode node = First;

				while (node != null)
				{
					if ((node.Value == null && item == null) || node.Value.Equals(item))

						return true;

					node = node.Next;
				}

				return false;
			}

			void CopyTo(T[] array, int arrayIndex)
			{
				ThrowOnInvalidCopyToArrayOperation(array, arrayIndex, Count, nameof(array), nameof(arrayIndex));

				foreach(T item in this)

					array[arrayIndex++] = item;
			}

			void CopyTo(Array array, int index) = > Extensions.CopyTo(this, array, index, Count);

			System.Collections.IEnumerator IEnumerable.GetEnumerator() = > GetEnumerator();
		};
	}
}

#endif

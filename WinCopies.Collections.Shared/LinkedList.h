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
//#ifndef LINKEDLIST_H
//#define LINKEDLIST_H
//
//#include "defines.h"
//#include "IEnumerable.h"
//#include "EnumeratorBase.h"
//#include "ILinkedList.h"
//#include "../WinCopies.Util.Shared/Exception.h"
//#include "../WinCopies.Util.Shared/ThrowHelper.h"
//
//namespace WinCopies
//{
//	namespace Collections
//	{
//		TEMPLATE
//			class DLLEXPORT LinkedList :
//			public virtual ILinkedList<T>
//		{
//		public:
//			class DLLEXPORT LinkedListNode :
//				public virtual ILinkedList<T>::ILinkedListNode
//			{
//			private:
//				LinkedList<T>* _list = nullptr;
//				LinkedListNode* _previous = nullptr;
//				LinkedListNode* _next = nullptr;
//				T _value;
//			public:
//				~LinkedListNode()
//				{
//					_list = nullptr;
//					_previous = nullptr;
//					_next = nullptr;
//				}
//
//				explicit LinkedListNode(T value)
//				{
//					_value = value;
//				}
//
//				virtual bool GetIsReadOnly() const final
//				{
//					return false;
//				}
//
//				LinkedList<T> GetLinkedList() const
//				{
//					return _list;
//				}
//
//				virtual ILinkedList<T> GetList() const final
//				{
//					return GetLinkedList();
//				}
//
//				LinkedListNode* GetPreviousNode()
//				{
//					return _previous;
//				}
//
//				virtual ILinkedList<T>::ILinkedListNode* GetPrevious() const final
//				{
//					return GetPreviousNode();
//				}
//
//				LinkedListNode* GetNextNode()
//				{
//					return _next;
//				}
//
//				virtual ILinkedList<T>::ILinkedListNode* GetNext() const final
//				{
//					return GetNextNode();
//				}
//
//				virtual T GetValue() const final
//				{
//					return _value;
//				}
//
//				/*void OnRemove()
//				{
//					List = null;
//					Previous = null;
//					Next = null;
//				}
//				*/
//			};
//
//			class DLLEXPORT Enumerator :
//				public virtual EnumeratorBase<LinkedListNode*>
//			{
//			private:
//				LinkedList<T>* _list;
//				LinkedListNode* _currentNode;
//				bool _first = true;
//				const UINT _version;
//				const EnumerationDirection _enumerationDirection;
//
//			public:
//				~Enumerator()
//				{
//					_list = nullptr;
//					_currentNode = nullptr;
//				}
//
//				Enumerator(LinkedList<T>* list, LinkedListEnumerationDirection enumerationDirection)
//				{
//					// list._enumeratorsCount++;
//
//					// _list = list ?? throw GetArgumentNullException(nameof(list));
//
//					// _version = list.EnumerableVersion;
//
//					_enumerationDirection = enumerationDirection;
//
//					switch (enumerationDirection)
//					{
//					case EnumerationDirection::FIFO:
//
//						// _action = () => _currentNode = _currentNode.Next;
//
//						// _reset = () => _currentNode = list.First;
//
//						break;
//
//					case EnumerationDirection::LIFO:
//
//						// _action = () => _currentNode = _currentNode.Previous;
//
//						// _reset = () => _currentNode = list.Last;
//
//						break;
//					}
//				}
//
//				EnumerationDirection GetEnumerationDirection()
//				{
//					return _enumerationDirection;
//				}
//
//			protected:
//				virtual bool GetIsResetSupported() const final
//				{
//					return true;
//				}
//
//				virtual LinkedListNode* GetCurrentOverride() const final
//				{
//					return _currentNode;
//				}
//
//				virtual int ResetOverride() final
//				{
//					ThrowIfVersionHasChanged(_list.EnumerableVersion, _version);
//
//					_first = true;
//
//					_reset();
//				}
//
//				virtual bool MoveNextOverride() final
//				{
//					ThrowIfVersionHasChanged(_list.EnumerableVersion, _version);
//
//					if (_first)
//					{
//						_first = false;
//
//						return _currentNode != null;
//					}
//
//					_action();
//
//					if (_currentNode == null)
//					{
//						ResetCurrent();
//
//						return false;
//					}
//
//					// The new node has already been updated in the _action delegate.
//
//					return true;
//				}
//
//				// virtual void ResetCurrent() => _currentNode = null;
//
//				/*protected override void DisposeManaged()
//				{
//					base.DisposeManaged();
//
//					_list = null;
//
//					_action = null;
//
//					ResetCurrent();
//
//					_reset = null;
//				}
//
//				protected override void Dispose(bool disposing)
//				{
//					base.Dispose(disposing);
//
//					_list.DecrementEnumeratorsCount();
//				}*/
//			};
//
//		private:
//			unsigned int _enumeratorsCount = 0;
//			// object _syncRoot;
//			unsigned int _enumerableVersion;
//			LinkedListNode* _first = nullptr;
//
//			void IncrementEnumeratorsCount()
//			{
//				_enumeratorsCount++;
//			}
//
//			void DecrementEnumeratorsCount()
//			{
//				_enumeratorsCount--;
//
//				if (_enumeratorsCount == 0)
//
//					_enumerableVersion = 0;
//			}
//
//			void OnWeld()
//			{
//				if (_enumeratorsCount > 0)
//
//					_enumerableVersion++;
//			}
//
//			void OnNewItemAdded(const LinkedListNode* node)
//			{
//				node->_list = this;
//
//				_count++;
//
//				OnWeld();
//			}
//
//			void OnItemRemoved(const LinkedListNode* node)
//			{
//				node.OnRemove();
//
//				Count--;
//
//				OnWeld();
//			}
//
//			void Weld(const LinkedListNode* previous, const LinkedListNode* newNode, const LinkedListNode* next)
//			{
//				if (previous != nullptr)
//				{
//					previous.Next = newNode;
//
//					newNode.Previous = previous;
//				}
//
//				if (next != null)
//				{
//					newNode.Next = next;
//
//					next.Previous = newNode;
//				}
//
//				OnNewItemAdded(newNode);
//			}
//
//			void Weld(const LinkedListNode* previous, const LinkedListNode* next)
//			{
//				previous.Next = next;
//
//				next.Previous = previous;
//			}
//
//			void _AddAfter(LinkedListNode addAfter, LinkedListNode node) = > Weld(addAfter, node, node.Next);
//
//			void _AddBefore(LinkedListNode addBefore, LinkedListNode node) = > Weld(addBefore.Previous, node, addBefore);
//
//			void _AddFirst(LinkedListNode node)
//			{
//				if (First != null)
//
//					Weld(node, First);
//
//#if CS7
//				if (Last == null)
//
//					Last = node;
//#else
//				Last ? ? = node;
//#endif
//
//				First = node;
//
//				OnNewItemAdded(node);
//			}
//
//			void _AddLast(LinkedListNode node)
//			{
//				if (Last != null)
//				{
//					node.Previous = Last;
//
//					Last.Next = node;
//				}
//
//#if CS7
//				if (First == null)
//
//					First = node;
//#else
//				First ? ? = node;
//#endif
//
//				Last = node;
//
//				OnNewItemAdded(node);
//			}
//
//		protected:
//			void ThrowIfNodeAlreadyHasList(const LinkedListNode* node, const wchar_t* const argumentName)
//			{
//				ThrowHelper::ThrowIfNullPtrValue(node, argumentName);
//
//				if (node->GetList() != nullptr)
//
//					throw new ArgumentException("The given node is already contained in another list.");
//			}
//
//			void ThrowIfNotContainedNode(const LinkedListNode* node, const wchar_t* const argumentName)
//			{
//				ThrowHelper::ThrowIfNullPtrValue(node, argumentName);
//
//				_ThrowIfNotContainedNode(node);
//			}
//
//			void _ThrowIfNotContainedNode(const LinkedListNode* node)
//			{
//				if (node->GetList() != this)
//
//					throw new ArgumentException("The given node is not contained in the current list.");
//			}
//
//			private ILinkedListNode* Find(const T value, const LinkedListEnumerationDirection enumerationDirection)
//			{
//				new Enumerable<LinkedListNode*>(() = > GetNodeEnumerator(enumerationDirection)).FirstOrDefault(node = > (node.Value == null && value == null) || node.Value.Equals(value));
//			}
//
//		public:
//			virtual ~LinkedList() override = default;
//
//			virtual bool GetIsReadOnly() const final
//			{
//				return false;
//			}
//
//			LinkedList(IEnumerable<T>* collection)
//			{
//				collection->ForEach(AddLast);
//			}
//
//			LinkedListNode* GetFirstNode() const
//			{
//				return _first;
//			}
//
//			virtual ILinkedListNode* GetFirst() const final
//			{
//				return GetFirstNode();
//			}
//
//			LinkedListNode* GetLastNode()
//			{
//				return _last;
//			}
//
//			virtual ILinkedListNode* GetLast() const final
//			{
//				return GetLastNode();
//			}
//
//			virtual unsigned int GetCount() const final
//			{
//				return _count;
//			}
//
//			/*bool ICollection.IsSynchronized => false;
//
//			object ICollection.SyncRoot
//			{
//				get
//				{
//					if (_syncRoot == null)
//
//						_ = System.Threading.Interlocked.CompareExchange(ref _syncRoot, new object(), null);
//
//					return _syncRoot;
//				}
//			}*/
//
//			virtual ILinkedListNode* AddAfter(const ILinkedListNode* node, const T value) final
//			{
//				LinkedListNode* _node = dynamic_cast<LinkedListNode*>(node);
//
//				if (_node == 0)
//
//					throw new ArgumentException(L"node must be a LinkedListNode item.", L"node");
//
//				_ThrowIfNotContainedNode(node, L"node");
//
//				LinkedListNode* newNode = new LinkedListNode(value);
//
//				_AddAfter(node, newNode);
//
//				return newNode;
//			}
//
//			LinkedListNode* AddAfter(const LinkedListNode* node, const T value)
//			{
//				ThrowIfNotContainedNode(node, L"node");
//
//				LinkedListNode* newNode = new LinkedListNode(value);
//
//				_AddAfter(node, newNode);
//
//				return newNode;
//			}
//
//			void AddAfter(const LinkedListNode* addAfter, const LinkedListNode* node)
//			{
//				ThrowIfNotContainedNode(addAfter, L"addAfter");
//				ThrowIfNodeAlreadyHasList(node, L"node");
//
//				_AddAfter(addAfter, node);
//			}
//
//			LinkedListNode* AddBefore(const LinkedListNode* node, const T value)
//			{
//				ThrowHelper::ThrowIfNullPtrValue(node, L"node");
//
//				LinkedListNode* newNode = new LinkedListNode(value);
//
//				AddBefore(node is LinkedListNode _node ? _node : throw new ArgumentException($"{nameof(node)} must be an instance of {nameof(LinkedListNode)}."), value);
//			}
//
//			LinkedListNode* AddBefore(const LinkedListNode* node, const T value)
//			{
//				LinkedListNode* newNode = new LinkedListNode(value);
//
//				_AddBefore(node, newNode);
//
//				return newNode;
//			}
//
//			void AddBefore(const LinkedListNode* addBefore, const LinkedListNode* node)
//			{
//				ThrowHelper::ThrowIfNullPtrValue(addBefore, L"addBefore");
//				ThrowHelper::ThrowIfNullPtrValue(node, L"node");
//
//				ThrowIfNotContainedNode(addBefore);
//				ThrowIfNodeAlreadyHasList(node);
//
//				_AddBefore(addBefore, node);
//			}
//
//			ILinkedListNode* AddFirst(const T value)
//			{
//				var node = new LinkedListNode(value);
//
//				_AddFirst(node);
//
//				return node;
//			}
//
//			void AddFirst(const LinkedListNode* node)
//			{
//				ThrowHelper::ThrowIfNullPtrValue(node, L"node");
//
//				ThrowIfNodeAlreadyHasList(node);
//
//				_AddFirst(node);
//			}
//
//			ILinkedListNode* AddLast(const T value)
//			{
//				LinkedListNode* node = new LinkedListNode(value);
//
//				_AddLast(node);
//
//				return node;
//			}
//
//			void AddLast(LinkedListNode* node)
//			{
//				ThrowIfNodeAlreadyHasList(node);
//
//				_AddLast(node);
//			}
//
//
//
//			ILinkedListNode* Find(const T value)
//			{
//				return Find(value, LinkedListEnumerationDirection::FIFO);
//			}
//
//			ILinkedListNode* FindLast(const T value)
//			{
//				return Find(value, LinkedListEnumerationDirection.LIFO);
//			}
//
//
//
//			virtual IEnumerator<T>* GetEnumerator() final
//			{
//				return GetEnumerator(LinkedListEnumerationDirection::FIFO);
//			}
//
//			IEnumerator<T>* GetEnumerator(const LinkedListEnumerationDirection enumerationDirection)
//			{
//				return GetNodeEnumerator(enumerationDirection) = > Select(node = > node.Value);
//			}
//
//			IEnumerator<LinkedListNode>* GetNodeEnumerator(const LinkedListEnumerationDirection enumerationDirection)
//			{
//				return new Enumerator(this, enumerationDirection);
//			}
//
//			IEnumerator<ILinkedListNode*>* ILinkedList<T>.GetNodeEnumerator(LinkedListEnumerationDirection enumerationDirection)
//			{
//				return GetNodeEnumerator(enumerationDirection);
//			}
//
//			void Remove(const LinkedListNode* node)
//			{
//				ThrowIfNotContainedNode(node);
//
//				Weld(node.Previous, node.Next);
//
//				OnItemRemoved(node);
//			}
//
//			void ILinkedList<T>.Remove(ILinkedListNode node) = > Remove(node as LinkedListNode ? ? throw new ArgumentException($"{nameof(node)} must be an instance of {nameof(LinkedListNode)}."));
//
//			bool Remove(const T item)
//			{
//				ILinkedListNode* node = Find(item);
//
//				if (node is LinkedListNode _node)
//				{
//					Remove(_node);
//
//					return true;
//				}
//
//				return false;
//			}
//
//			void RemoveFirst()
//			{
//				ThrowIfEmptyListOrCollection(this);
//
//				LinkedListNode* node = GetFirst();
//
//				First = node.GetNext();
//
//				OnItemRemoved(node);
//			}
//
//			void RemoveLast()
//			{
//				ThrowIfEmptyListOrCollection(this);
//
//				LinkedListNode node = Last;
//
//				Last = node.Previous;
//
//				OnItemRemoved(node);
//			}
//
//			void Clear()
//			{
//				Count = 0;
//
//				if (_enumeratorsCount > 0)
//
//					EnumerableVersion++;
//			}
//
//			bool Contains(T item)
//			{
//				LinkedListNode node = First;
//
//				while (node != null)
//				{
//					if ((node.Value == null && item == null) || node.Value.Equals(item))
//
//						return true;
//
//					node = node.Next;
//				}
//
//				return false;
//			}
//
//			void CopyTo(T[] array, int arrayIndex)
//			{
//				ThrowOnInvalidCopyToArrayOperation(array, arrayIndex, Count, nameof(array), nameof(arrayIndex));
//
//				foreach(T item in this)
//
//					array[arrayIndex++] = item;
//			}
//
//			void CopyTo(Array array, int index) = > Extensions.CopyTo(this, array, index, Count);
//
//			System.Collections.IEnumerator IEnumerable.GetEnumerator() = > GetEnumerator();
//		};
//
//		TEMPLATE
//			class ReadOnlyLinkedList :
//			public virtual IReadOnlyLinkedList<T>,
//			public virtual ILinkedList2<T>
//		{
//		public:
//			bool GetIsReadOnly()
//			{
//				return true;
//			}
//
//			// protected ILinkedList<T> InnerList{ get; } // Already was ILinkedList<T> in WinCopies 2.
//
//			ILinkedListNode GetLast = > InnerList.Last;
//
//			ILinkedListNode First = > InnerList.First;
//
//			unsigned int GetCount()
//			{
//				return InnerList.Count;
//			}
//
//			// object ICollection.SyncRoot = > InnerList.SyncRoot;
//
//			// bool ICollection.IsSynchronized = > InnerList.IsSynchronized;
//
//			bool Contains(const T value) const
//			{
//				return InnerList->Contains(value);
//			}
//
//			void CopyTo(const T[] array, const int index)
//			{
//				InnerList->CopyTo(array, index);
//			}
//
//			ILinkedListNode Find(T value) = > InnerList.Find(value);
//
//#if WinCopies2
//			System.Collections.Generic.LinkedListNode
//#else
//			ILinkedListNode
//#endif
//				<T> FindLast(T value) = > InnerList.FindLast(value);
//
//			System.Collections.Generic.IEnumerator<T>
//#if WinCopies2
//				IEnumerable<T>.
//#endif
//				GetEnumerator() = > InnerList.GetEnumerator();
//
//			System.Collections.IEnumerator IEnumerable.GetEnumerator() = >
//#if WinCopies2
//				InnerList
//#else
//				((IEnumerable)InnerList)
//#endif
//				.GetEnumerator();
//
//			System.Collections.Generic.IEnumerator<T> GetEnumerator(LinkedListEnumerationDirection enumerationDirection) = > InnerList.GetEnumerator(enumerationDirection);
//
//			System.Collections.Generic.IEnumerator<ILinkedListNode> GetNodeEnumerator(LinkedListEnumerationDirection enumerationDirection) = > InnerList.GetNodeEnumerator(enumerationDirection);
//
//#if WinCopies2
//			System.Collections.Generic.LinkedListNode
//#else
//			ILinkedListNode
//#endif
//				<T> AddAfter(
//#if WinCopies2
//					System.Collections.Generic.LinkedListNode
//#else
//					ILinkedListNode
//#endif
//					<T> node, T value) = > throw GetReadOnlyListOrCollectionException();
//
//#if WinCopies2
//			System.Collections.Generic.LinkedListNode
//#else
//			ILinkedListNode
//#endif
//				<T> AddBefore(
//#if WinCopies2
//					System.Collections.Generic.LinkedListNode
//#else
//					ILinkedListNode
//#endif
//					<T> node, T value) = > throw GetReadOnlyListOrCollectionException();
//
//			ILinkedListNode AddFirst(T value) = > throw GetReadOnlyListOrCollectionException();
//
//#if WinCopies2
//			System.Collections.Generic.LinkedListNode
//#else
//			ILinkedListNode
//#endif
//				<T> AddLast(T value) = > throw GetReadOnlyListOrCollectionException();
//
//			public void Remove(
//#if WinCopies2
//				System.Collections.Generic.LinkedListNode
//#else
//				ILinkedListNode
//#endif
//				<T> node) = > throw GetReadOnlyListOrCollectionException();
//
//			void RemoveFirst() = > throw GetReadOnlyListOrCollectionException();
//
//			void RemoveLast() = > throw GetReadOnlyListOrCollectionException();
//		};
//	}
//}
//
//#endif

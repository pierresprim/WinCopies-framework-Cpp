//#pragma once
//#ifndef READONLYLINKEDLIST_H
//#define READONLYLINKEDLIST_H
//
//#include "../WinCopies.Util.Base.Shared/wincopies_defines.h"
//#include "../WinCopies.Util.Base.Shared/Exception.h"
//#include "ILinkedList.h"
//#include "IReadOnlyLinkedList.h"
//
//namespace WinCopies
//{
//	namespace Collections
//	{
//		TEMPLATE
//			class ReadOnlyLinkedList :
//			public virtual IReadOnlyLinkedList<T>,
//			public virtual ILinkedList<T>
//		{
//		private:
//			ILinkedList<T>* _innerList;
//		protected:
//			ILinkedList<T>* GetInnerList()
//			{
//				return _innerList;
//			}
//		public:
//			virtual bool GetIsReadOnly() const final
//			{
//				return true;
//			}
//
//			virtual ILinkedListNode<T>* GetLast() const final
//			{
//				return _innerList->Last;
//			}
//
//			virtual ILinkedListNode<T>* GetFirst() const final
//			{
//				return _innerList->First;
//			}
//
//			virtual unsigned int GetCount() const final
//			{
//				return _innerList->Count;
//			}
//
//			// object ICollection.SyncRoot = > InnerList.SyncRoot;
//
//			// bool ICollection.IsSynchronized = > InnerList.IsSynchronized;
//
//			bool Contains(const T value) const
//			{
//				return _innerList->Contains(value);
//			}
//
//			void CopyTo(const T[] _array, const int index)
//			{
//				_innerList->CopyTo(_array, index);
//			}
//
//			virtual ILinkedListNode<T>* Find(T value) const final
//			{
//				return _innerList->Find(value);
//			}
//
//			virtual ILinkedListNode<T>* FindLast(T value) const final
//			{
//				return InnerList->FindLast(value);
//			}
//
//			virtual IEnumerator<T>* GetEnumerator() final
//			{
//				return InnerList->GetEnumerator();
//			}
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
//			System.Collections.Generic.IEnumerator<ILinkedListNode<T>> GetNodeEnumerator(LinkedListEnumerationDirection enumerationDirection) = > InnerList.GetNodeEnumerator(enumerationDirection);
//
//			virtual ILinkedListNode<T>* AddAfter(ILinkedListNode<T>* node, T value) final
//			{
//				throw new ReadOnlyException();
//			}
//
//			virtual ILinkedListNode<T>* AddBefore(ILinkedListNode<T>* node, T value) final
//			{
//				throw new ReadOnlyException();
//			}
//
//			virtual ILinkedListNode<T>* AddFirst(T value) final
//			{
//				throw new ReadOnlyException();
//			}
//
//			virtual ILinkedListNode<T>* AddLast(T value) final
//			{
//				throw new ReadOnlyException();
//			}
//
//			virtual void Remove(ILinkedListNode<T>* node) final
//			{
//				throw new ReadOnlyException();
//			}
//
//			virtual void RemoveFirst() final
//			{
//				throw new ReadOnlyException();
//			}
//
//			virtual void RemoveLast() final
//			{
//				throw new ReadOnlyException();
//			}
//		};
//	}
//}
//
//#endif

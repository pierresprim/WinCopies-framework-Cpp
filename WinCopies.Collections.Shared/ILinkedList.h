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
            class DLLEXPORT LinkedList :
                public virtual ILinkedList<T>
            {
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
                        _list=nullptr;
                        _previous=nullptr;
                        _next=nullptr;
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

                virtual ILinkedListNode<T>* First() const final
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

                virtual uint GetCount() const final
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

                LinkedListNode* AddNodeAfter(LinkedListNode* node, T value)
                {
                    LinkedListNode* newNode = new LinkedListNode(value);

                    _AddAfter(node, newNode);

                    return newNode;
                }

                virtual ILinkedListNode<T>* AddAfter(ILinkedListNode<T>* node, T value) final
                {
                    LinkedListNode* _node = dynamic_cast<LinkedListNode*>(node);

                    if (_node)

                    AddAfter( _node , value);

                    else

                        throw new ArgumentException($"{nameof(node)} must be an instance of {nameof(LinkedListNode)}.");
                }

                void AddAfter(LinkedListNode addAfter, LinkedListNode node)
                {
                    ThrowIfNotContainedNode(addAfter);
                    ThrowIfNodeAlreadyHasList(node);

                    _AddAfter(addAfter, node);
                }

                ILinkedListNode<T> ILinkedList<T>.AddBefore(ILinkedListNode<T> node, T value) => AddBefore(node is LinkedListNode _node ? _node : throw new ArgumentException($"{nameof(node)} must be an instance of {nameof(LinkedListNode)}."), value);

                public LinkedListNode AddBefore(LinkedListNode node, T value)
                {
                    var newNode = new LinkedListNode(value);

                    _AddBefore(node, newNode);

                    return newNode;
                }

                public void AddBefore(LinkedListNode addBefore, LinkedListNode node)
                {
                    ThrowIfNotContainedNode(addBefore);
                    ThrowIfNodeAlreadyHasList(node);

                    _AddBefore(addBefore, node);
                }

                public ILinkedListNode<T> AddFirst(T value)
                {
                    var node = new LinkedListNode(value);

                    _AddFirst(node);

                    return node;
                }

                public void AddFirst(LinkedListNode node)
                {
                    ThrowIfNodeAlreadyHasList(node);

                    _AddFirst(node);
                }

                public ILinkedListNode<T> AddLast(T value)
                {
                    var node = new LinkedListNode(value);

                    _AddLast(node);

                    return node;
                }

                public void AddLast(LinkedListNode node)
                {
                    ThrowIfNodeAlreadyHasList(node);

                    _AddLast(node);
                }

                void ICollection<T>.Add(T item) => AddLast(item);



                public ILinkedListNode<T> Find(T value) => Find(value, LinkedListEnumerationDirection.FIFO);

                public ILinkedListNode<T> FindLast(T value) => Find(value, LinkedListEnumerationDirection.LIFO);

                private ILinkedListNode<T> Find(T value, LinkedListEnumerationDirection enumerationDirection) => new Enumerable<LinkedListNode>(() => GetNodeEnumerator(enumerationDirection)).FirstOrDefault(node => (node.Value == null && value == null) || node.Value.Equals(value));



                public System.Collections.Generic.IEnumerator<T> GetEnumerator() => GetEnumerator(LinkedListEnumerationDirection.FIFO);

                public System.Collections.Generic.IEnumerator<T> GetEnumerator(LinkedListEnumerationDirection enumerationDirection) => GetNodeEnumerator(enumerationDirection).Select(node => node.Value);

                public System.Collections.Generic.IEnumerator<LinkedListNode> GetNodeEnumerator(in LinkedListEnumerationDirection enumerationDirection) => new Enumerator(this, enumerationDirection);

                System.Collections.Generic.IEnumerator<ILinkedListNode<T>> ILinkedList<T>.GetNodeEnumerator(LinkedListEnumerationDirection enumerationDirection) => GetNodeEnumerator(enumerationDirection);

                public void Remove(LinkedListNode node)
                {
                    ThrowIfNotContainedNode(node);

                    Weld(node.Previous, node.Next);

                    OnItemRemoved(node);
                }

                void ILinkedList<T>.Remove(ILinkedListNode<T> node) => Remove(node as LinkedListNode ?? throw new ArgumentException($"{nameof(node)} must be an instance of {nameof(LinkedListNode)}."));

                public bool Remove(T item)
                {
                    ILinkedListNode<T> node = Find(item);

                    if (node is LinkedListNode _node)
                    {
                        Remove(_node);

                        return true;
                    }

                    return false;
                }

                public void RemoveFirst()
                {
    #if WinCopies2
                ThrowIfEmpty
    #else
                    ThrowIfEmptyListOrCollection
    #endif
    (this);

                    LinkedListNode node = First;

                    First = node.Next;

                    OnItemRemoved(node);
                }

                public void RemoveLast()
                {
    #if WinCopies2
                ThrowIfEmpty
    #else
                    ThrowIfEmptyListOrCollection
    #endif
    (this);

                    LinkedListNode node = Last;

                    Last = node.Previous;

                    OnItemRemoved(node);
                }

                public void Clear()
                {
                    Count = 0;

                    if (_enumeratorsCount > 0)

                        EnumerableVersion++;
                }

                public bool Contains(T item)
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

                public void CopyTo(T[] array, int arrayIndex)
                {
                    ThrowOnInvalidCopyToArrayOperation(array, arrayIndex, Count, nameof(array), nameof(arrayIndex));

                    foreach (T item in this)

                        array[arrayIndex++] = item;
                }

                public void CopyTo(Array array, int index) => Extensions.CopyTo(this, array, index, Count);

                System.Collections.IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
    #endif
            };

            [DebuggerDisplay("Count = {Count}")]
            public class ReadOnlyLinkedList<T> : IReadOnlyLinkedList<T>, ILinkedList2<T>
            {
                public bool IsReadOnly => true;

                protected ILinkedList<T> InnerList { get; } // Already was ILinkedList<T> in WinCopies 2.

                public
    #if WinCopies2
    System.Collections.Generic.LinkedListNode
    #else
                    ILinkedListNode
    #endif
                    <T> Last => InnerList.Last;

                public
    #if WinCopies2
    System.Collections.Generic.LinkedListNode
    #else
                    ILinkedListNode
    #endif
                    <T> First => InnerList.First;

                public
    #if WinCopies2
                    int
    #else
                    uint
    #endif
                    Count => InnerList.Count;

    #if !WinCopies2
                int ICollection.Count => (int)Count;

                int ICollection<T>.Count => (int)Count;

                int IReadOnlyCollection<T>.Count => (int)Count;
    #endif

                bool ICollection<T>.IsReadOnly => true;

                object ICollection.SyncRoot => InnerList.SyncRoot;

                bool ICollection.IsSynchronized => InnerList.IsSynchronized;

                public bool Contains(T value) => InnerList.Contains(value);

                public void CopyTo(T[] array, int index) => InnerList.CopyTo(array, index);

                public
    #if WinCopies2
    System.Collections.Generic.LinkedListNode
    #else
                    ILinkedListNode
    #endif
                    <T> Find(T value) => InnerList.Find(value);

                public
    #if WinCopies2
    System.Collections.Generic.LinkedListNode
    #else
                    ILinkedListNode
    #endif
                    <T> FindLast(T value) => InnerList.FindLast(value);

    #if WinCopies2
                public System.Collections.Generic.LinkedList<T>.Enumerator GetEnumerator() => InnerList.GetEnumerator();
    #else
                public
    #endif

                System.Collections.Generic.IEnumerator<T>
    #if WinCopies2
    IEnumerable<T>.
    #endif
                    GetEnumerator() => InnerList.GetEnumerator();

                System.Collections.IEnumerator IEnumerable.GetEnumerator() =>
    #if WinCopies2
    InnerList
    #else
                    ((IEnumerable)InnerList)
    #endif
                    .GetEnumerator();

    #if WinCopies2
                public virtual void GetObjectData(SerializationInfo info, StreamingContext context) => InnerList.GetObjectData(info, context);

                public virtual void OnDeserialization(object sender) => InnerList.OnDeserialization(sender);
    #else
                public System.Collections.Generic.IEnumerator<T> GetEnumerator(LinkedListEnumerationDirection enumerationDirection) => InnerList.GetEnumerator(enumerationDirection);

                public System.Collections.Generic.IEnumerator<ILinkedListNode<T>> GetNodeEnumerator(LinkedListEnumerationDirection enumerationDirection) => InnerList.GetNodeEnumerator(enumerationDirection);
    #endif

                void ICollection<T>.Add(T item) => throw GetReadOnlyListOrCollectionException();

                void ICollection<T>.Clear() => throw GetReadOnlyListOrCollectionException();

                bool ICollection<T>.Contains(T item) => InnerList.Contains(item);

                void ICollection<T>.CopyTo(T[] array, int arrayIndex) => InnerList.CopyTo(array, arrayIndex);

                bool ICollection<T>.Remove(T item) => throw GetReadOnlyListOrCollectionException
                    ();

                void ICollection.CopyTo(Array array, int index) => ((ICollection)InnerList).CopyTo(array, index);

                public
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
                    <T> node, T value) => throw GetReadOnlyListOrCollectionException();

    #if WinCopies2
                public void AddAfter(System.Collections.Generic.LinkedListNode<T> node, System.Collections.Generic.LinkedListNode<T> newNode) => throw new InvalidOperationException(ExceptionMessages.ReadOnlyCollection);

                public void AddBefore(System.Collections.Generic.LinkedListNode<T> node, System.Collections.Generic.LinkedListNode<T> newNode) => throw new InvalidOperationException(ExceptionMessages.ReadOnlyCollection);

                public void AddFirst(System.Collections.Generic.LinkedListNode<T> node) => throw new InvalidOperationException(ExceptionMessages.ReadOnlyCollection);

                public void AddLast(System.Collections.Generic.LinkedListNode<T> node) => throw new InvalidOperationException(ExceptionMessages.ReadOnlyCollection);
    #endif

                public
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
                    <T> node, T value) => throw GetReadOnlyListOrCollectionException();

                public
    #if WinCopies2
    System.Collections.Generic.LinkedListNode
    #else
                    ILinkedListNode
    #endif
                    <T> AddFirst(T value) => throw GetReadOnlyListOrCollectionException();

                public
    #if WinCopies2
    System.Collections.Generic.LinkedListNode
    #else
                    ILinkedListNode
    #endif
                    <T> AddLast(T value) => throw GetReadOnlyListOrCollectionException();

                public void Remove(
    #if WinCopies2
    System.Collections.Generic.LinkedListNode
    #else
                    ILinkedListNode
    #endif
                    <T> node) => throw GetReadOnlyListOrCollectionException();

                public void RemoveFirst() => throw GetReadOnlyListOrCollectionException();

                public void RemoveLast() => throw GetReadOnlyListOrCollectionException();
            private:
                uint _enumeratorsCount = 0;
                // object _syncRoot;
                uint _enumerableVersion;
                LinkedListNode* _first=nullptr;

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

                void ThrowIfNodeAlreadyHasList(const LinkedListNode* node)
                {
                    if (node.List != null)

                        throw new ArgumentException("The given node is already contained in another list.");
                }

                void ThrowIfNotContainedNode(in ILinkedListNode<T> node)
                {
                    if (node.List != this)

                        throw new ArgumentException("The given node is not contained in the current list.");
                }

                private void OnWeld()
                {
                    if (_enumeratorsCount > 0)

                        EnumerableVersion++;
                }

                private void OnNewItemAdded(in LinkedListNode node)
                {
                    node.List = this;

                    Count++;

                    OnWeld();
                }

                private void OnItemRemoved(in LinkedListNode node)
                {
                    node.OnRemove();

                    Count--;

                    OnWeld();
                }

                private void Weld(in LinkedListNode previous, in LinkedListNode newNode, in LinkedListNode next)
                {
                    previous.Next = newNode;

                    newNode.Previous = previous;

                    newNode.Next = next;

                    newNode.Previous = newNode;

                    OnNewItemAdded(newNode);
                }

                private void Weld(in LinkedListNode previous, in LinkedListNode next)
                {
                    previous.Next = next;

                    next.Previous = previous;
                }

                private void _AddAfter(LinkedListNode addAfter, LinkedListNode node) => Weld(addAfter, node, node.Next);

                private void _AddBefore(LinkedListNode addBefore, LinkedListNode node) => Weld(addBefore.Previous, node, addBefore);

                private void _AddFirst(LinkedListNode node)
                {
                    if (First != null)

                        Weld(node, First);

    #if CS7
                    if (Last == null)

                        Last = node;
    #else
                    Last ??= node;
    #endif

                    First = node;

                    OnNewItemAdded(node);
                }

                private void _AddLast(LinkedListNode node)
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
                    First ??= node;
    #endif

                    Last = node;

                    OnNewItemAdded(node);
                }
            };
        }
    }

#endif // ILINKEDLIST_H

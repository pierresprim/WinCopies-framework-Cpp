#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ILinkedList.h"
#include "EnumerableExtensions.h"
#include "../Util/Exception.h"
#include "ISortable.h"
#include "ThrowHelper.h"

using namespace WinCopies::Collections;
using namespace WinCopies::Collections::Generic;

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			TEMPLATE
				INTERFACE(LinkedList) :
				BASE_INTERFACE ILinkedList2<T>,
				BASE_INTERFACE ISortable
			{
				class LinkedListNode;

			private:
				ILinkedListNode<T>* _first;
				ILinkedListNode<T>* _last;
				UINT _count;

				LinkedListNode* Find(const T value, const EnumerationDirection enumerationDirection)
				{
					PREDICATE_PARAMETER(LinkedListNode*) = [](LinkedListNode* _node)
					{
						return value == _node->GetValue();
					};

					LinkedListNode* node;
					bool succeeded;

					EnumerableExtensions<T>::FirstOrDefault(this, &node, &succeeded, predicate);

					return node;
				}

				T GetNodeValue(const LinkedListNode* node)
				{
					if (node != nullptr)

						return node->GetValue();

					throw new InvalidOperationException(L"The list is empty.");
				}

				static void ThrowIfNodeAlreadyHasList(const LinkedListNode* node, const wchar_t* argumentName)
				{
					if (GETORTHROWIFNULLPTR(node, argumentName)->GetList() != nullptr)

						throw new ArgumentException(L"The given node is already contained in another list.");
				}

				static void _ThrowIfNotContainedNode(const LinkedListNode* node, const wchar_t* const argumentName)
				{
					ThrowHelper<T>::ThrowIfNotContainedNode(node, argumentName, this);
				}

				static void ThrowIfNotContainedNode(const LinkedListNode* node, const wchar_t* const argumentName)
				{
					_ThrowIfNotContainedNode(GETORTHROWIFNULLPTR(node, argumentName));
				}

				void _Weld(const LinkedListNode* previous, const LinkedListNode* newNode, const LinkedListNode* next)
				{
					if (previous == nullptr) // If previous is nullptr, next is _first. So, we replace _first by newNode.

						_first = newNode;

					else
					{
						previous->_next = newNode;

						newNode->_previous = previous;
					}

					if (next == nullptr) // If next is nullptr, previous is _last. So, we replace _last by newNode.

						_last = newNode;

					else
					{
						newNode->_next = next;

						next->_previous = newNode;
					}
				}

				void OnNodeAdded(const LinkedListNode* node)
				{
					node->_list = this;

					_count++;
				}

				void IncrementEnumerableVersion()
				{
					if (_enumeratorsCount > 0)

						_enumerableVersion++;
				}

				void OnNewItemAdded(const LinkedListNode* node)
				{
					OnNodeAdded(node);

					IncrementEnumerableVersion();
				}

				void Weld(const LinkedListNode* previous, const LinkedListNode* newNode, const LinkedListNode* next)
				{
					_Weld(previous, newNode, next);

					OnNewItemAdded(newNode);
				}

				void Weld(const LinkedListNode* previous, const LinkedListNode* next)
				{
					previous.Next = next;

					next.Previous = previous;
				}

				void _AddAfter(const LinkedListNode* addAfter, const LinkedListNode* node)
				{
					ThrowIfNodeAlreadyHasList(node, L"node");
					ThrowHelper<T>::ThrowIfNodesAreEqual(node, addAfter);

					Weld(addAfter, node, addAfter->GetNext());
				}

				void _AddBefore(const LinkedListNode* addBefore, const LinkedListNode* node)
				{
					ThrowIfNodeAlreadyHasList(node, L"node");
					ThrowHelper<T>::ThrowIfNodesAreEqual(node, addBefore);

					Weld(addBefore->GetPrevious(), node, addBefore);
				}

				void _AddFirst(LinkedListNode* node)
				{
					if (_first != nullptr)

						Weld(node, _first);

					if (_last == nullptr)

						_last = node;

					_first = node;

					OnNewItemAdded(node);
				}

				private void _AddLast(LinkedListNode node)
				{
					if (_last != nullptr)
					{
						node->GetPrevious() = _last;

						_last._next = node;
					}

					if (_first == nullptr)

						_first = node;

					_last = node;

					OnNewItemAdded(node);
				}

				void ReInitNodes()
				{
					_first = nullptr;

					_last = nullptr;
				}

				void OnItemRemoved(const LinkedListNode* node)
				{
					node->OnRemove();

					_count--;

					IncrementEnumerableVersion();

					if (_count == 0)

						ReInitNodes();
				}

				void _Remove(LinkedListNode* node)
				{
					if (node == _first)

						RemoveFirst();

					else if (node == _last)

						RemoveLast();

					else
					{
						Weld(node->GetPrevious(), node->GetNext());

						OnItemRemoved(node);
					}
				}

				void Sort(const COMPARISON(LinkedListNode*), const LinkedListNode** max)
				{
					_previous = _previous._previous;

					if (comparison(_previous, *max) > 0)

						*max = _previous;
				}

			public:
				class LinkedListNode :
					BASE_INTERFACE ILinkedListNode<T>
				{
				private:
					LinkedList<T>* _list;
					LinkedListNode* _previous;
					LinkedListNode* _next;
					T _value;

					void OnRemove()
					{
						_list = nullptr;
						_previous = nullptr;
						_next = nullptr;
					}

				public:
					virtual bool GetIsReadOnly() final
					{
						return false;
					}

					virtual LinkedList<T>* GetList() final
					{
						return _list;
					}

					virtual LinkedListNode* GetPrevious() final
					{
						return _previous;
					}

					virtual LinkedListNode* GetNext() final
					{
						return _next;
					}

					virtual T GetValue() final
					{
						return _value;
					}

					LinkedListNode(const T value)
					{
						_value = value;
					}
				};

				virtual ~LinkedList() override = default;

				virtual IReadOnlyLinkedListNode<T>* GetFirst() final
				{
					return _first;
				}

				virtual IReadOnlyLinkedListNode<T>* GetLast() final
				{
					return _last;
				}

				virtual bool GetIsReadOnly() final
				{
					return false;
				}

				virtual bool GetSupportsReversedEnumeration() final
				{
					return true;
				}

				virtual UINT GetCount() final
				{
					return _count;
				}

				virtual IReadOnlyLinkedListNode<T>* Find(const T value) final
				{
					return Find(value, EnumerationDirection::FIFO);
				}

				virtual IReadOnlyLinkedListNode<T>* FindLast(const T value) final
				{
					return Find(value, EnumerationDirection::LIFO);
				}

				virtual T GetFirstValue() final
				{
					return GetNodeValue(_first);
				}

				virtual T GetLastValue() final
				{
					return GetNodeValue(_last);
				}

				virtual IEnumerator<T>* GetEnumerator() = 0;

				virtual IEnumerator<T>* GetReversedEnumerator() = 0;

				virtual IEnumerator<ILinkedListNode<T>*> GetNodeEnumerator() = 0;

				virtual IEnumerator<ILinkedListNode<T>*> GetReversedNodeEnumerator() = 0;



				virtual ILinkedListNode<T>* AddAfter(ILinkedListNode<T>* const node, const T value) final
				{
					ThrowIfNotContainedNode(node, L"node");

					LinkedListNode* newNode = new LinkedListNode(value);

					_AddAfter(node, newNode);

					return newNode;
				}

				virtual ILinkedListNode<T>* AddBefore(ILinkedListNode<T>* const node, const T value) final
				{
					ThrowIfNotContainedNode(node, L"node"));

					LinkedListNode* newNode = new LinkedListNode(value);

					_AddBefore(node, newNode);

					return newNode;
				}

				virtual ILinkedListNode<T>* AddFirst(const T value) final
				{
					LinkedListNode* node = new LinkedListNode(value);

					_AddFirst(node);

					return node;
				}

				void AddFirst(LinkedListNode* node)
				{
					ThrowIfNodeAlreadyHasList(node, L"node"));

					_AddFirst(node);
				}

				virtual ILinkedListNode<T>* AddLast(const T value) final
				{
					LinkedListNode* node = new LinkedListNode(value);

					_AddLast(node);

					return node;
				}

				public void AddLast(LinkedListNode node)
				{
					ThrowIfNodeAlreadyHasList(node, L"node");

					_AddLast(node);
				}



				virtual void Remove(ILinkedListNode<T>* node)
				{
					ThrowIfNotContainedNode(node, L"node");

					_Remove(node);
				}

				virtual ILinkedListNode<T>* Remove(T item)
				{
					LinkedListNode* node = Find(item);

					if (node == nullptr)

						return nullptr;

					Remove(node);

					return node;
				}

				virtual void RemoveFirst() final
				{
					ThrowHelper<T>::ThrowIfEmptyListOrCollection(this);

					LinkedListNode* node = _first;

					_first = node->_next;

					OnItemRemoved(node);
				}

				virtual void RemoveLast()
				{
					ThrowHelper<T>::ThrowIfEmptyListOrCollection(this);

					LinkedListNode* node = _last;

					_last = node._previous;

					OnItemRemoved(node);
				}

				virtual void Clear() final
				{
					if (_enumeratorsCount > 0)

						_enumerableVersion++;

					while (_count != 0)

						RemoveFirst();

					ReInitNodes();
				}

				virtual bool Contains(const T item) final
				{
					PREDICATE_PARAMETER(T);

					if (item == nullptr)

						predicate = [](T _item)
					{
						return _item == nullptr;
					};

					else

						predicate = [](T _item)
					{
						return item == _item;
					};

					LinkedListNode node = First;

					while (node != nullptr)
					{
						if (predicate(node.Value))

							return true;

						node = node.Next;
					}

					return false;
				}

				virtual void CopyTo(const T* _array, const int arrayIndex, const int arrayLength) final
				{
					ThrowOnInvalidCopyToArrayOperation(array, arrayIndex, Count, nameof(array), nameof(arrayIndex));

					foreach(T item in this)

						array[arrayIndex++] = item;
				}

				void Sort(const COMPARISON(LinkedListNode*))
				{
					LinkedListNode* max;
					LinkedListNode* current = _last;
					LinkedListNode* previous;

					for (UINT i = _count - 1u; i > 0u; i--)
					{
						max = current;
						previous = current;

						for (UINT j = i - 1u; j > 0u; j--)

							Sort(comparison, &max);

						Sort(comparison, &max); // In order to avoid uint j >= 0; j--, because uint j = 0; j-- won't result to -1.

						if (current == max)

							current = current->_previous;

						else
						{
							Swap(current, max);

							current = max->_previous;
						}
					}
				}

				virtual void Sort(const COMPARISON(T)) final
				{
					return Sort([](LinkedListNode x, LinkedListNode y)
						{
							return comparison(x.Value, y.Value)
						});
				}
			};
		}
	}
}

#endif // LINKEDLIST_H

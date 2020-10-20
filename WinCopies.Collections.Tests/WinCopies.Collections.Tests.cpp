#include "pch.h"
#include "CppUnitTest.h"
#include "../WinCopies.Collections.Shared/Stack.h"
#include "../WinCopies.Collections.Shared/ReadOnlyStack.h"
#include "../WinCopies.Collections.Shared/Queue.h"
#include "../WinCopies.Collections.Shared/ReadOnlyQueue.h"
#include "../WinCopies.Collections.Shared/SafeArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace WinCopies::Collections;
using namespace std;

class Something
{
private:
	int _id = 0;
public:
	explicit Something(const int id)
	{
		_id = id;
	}

	const int GetId()
	{
		return _id;
	}
};

namespace WinCopies
{
	namespace Collections
	{
		namespace Tests
		{
			TEST_CLASS(StackTests)
			{
			public:
				TEST_METHOD(PeekAndPop)
				{
					Stack<int>* stack = new Stack<int>();

					stack->Push(10);

					Assert::AreEqual(stack->Peek(), 10);

					stack->Push(1000);

					Assert::AreEqual(stack->Peek(), 1000);

					Assert::AreEqual(stack->Pop(), 1000);

					Assert::AreEqual(stack->Peek(), 10);

					Assert::AreEqual(stack->Pop(), 10);



					stack->Push(1000);

					Assert::AreEqual(stack->Peek(), 1000);

					stack->Push(10);

					Assert::AreEqual(stack->Peek(), 10);

					Assert::AreEqual(stack->Pop(), 10);

					Assert::AreEqual(stack->Peek(), 1000);

					Assert::AreEqual(stack->Pop(), 1000);

					delete stack;

					stack = nullptr;
				}

				TEST_METHOD(TryPop)
				{
					Stack<int>* stack = new Stack<int>();

					stack->Push(10);

					stack->Push(1000);

					int i;

					Assert::IsTrue(stack->TryPop(&i));

					Assert::AreEqual(i, 1000);

					Assert::IsTrue(stack->TryPop(&i));

					Assert::AreEqual(i, 10);

					Assert::IsFalse(stack->TryPop(&i));

					delete stack;

					stack = nullptr;
				}

				TEST_METHOD(Clear)
				{
					Stack<int>* stack = new Stack<int>();

					stack->Push(10);

					stack->Push(1000);

					Assert::AreEqual(stack->GetCount(), 2u);

					stack->Clear();

					Assert::AreEqual(stack->GetCount(), 0u);

					delete stack;

					stack = nullptr;
				}

				TEST_METHOD(PeekAndPopObject)
				{
					Stack<Something*>* stack = new Stack<Something*>();

					stack->Push(new Something(10));

					Assert::AreEqual(stack->Peek()->GetId(), 10);

					stack->Push(new Something(1000));

					Assert::AreEqual(stack->Peek()->GetId(), 1000);

					Something* result;

					Assert::AreEqual((result = stack->Pop())->GetId(), 1000);

					delete result;

					Assert::AreEqual(stack->Peek()->GetId(), 10);

					Assert::AreEqual((result = stack->Pop())->GetId(), 10);

					delete result;



					stack->Push(new Something(1000));

					Assert::AreEqual((result = stack->Peek())->GetId(), 1000);

					stack->Push(new Something(10));

					Assert::AreEqual(stack->Peek()->GetId(), 10);

					Assert::AreEqual((result = stack->Pop())->GetId(), 10);

					delete result;

					Assert::AreEqual(stack->Peek()->GetId(), 1000);

					Assert::AreEqual((result = stack->Pop())->GetId(), 1000);

					delete result;

					result = nullptr;

					delete stack;

					stack = nullptr;
				}
			};

			TEST_CLASS(EnumerableStackTests)
			{
			public:
				TEST_METHOD(StackChangingDuringEnumeration)
				{
					IEnumerableStack<int>* enumerableStack = new EnumerableStack<int>();

					enumerableStack->Push(10);

					enumerableStack->Push(10);

					IEnumerator<int>* enumerator = enumerableStack->GetEnumerator();

					bool moveNextSucceeded = false;

					Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), 0);

					Assert::IsTrue(moveNextSucceeded);

					Assert::AreEqual(enumerator->GetCurrent(), 10);

					enumerableStack->Push(1000);

					Assert::AreEqual(OBJECT_HAS_CHANGED_DURING_ENUMERATION_EXCEPTION, enumerator->MoveNext(&moveNextSucceeded));

					Assert::IsFalse(moveNextSucceeded); // Should be false because the stack has changed during enumeration.

					delete enumerator;
				}

				static void EnumerateInt(const int i)
				{
					Assert::IsTrue(i == 10 || i == 1000);
				}

				static void EnumerateFloat(const float f)
				{
					Assert::IsTrue(f == 10 || f == 1000);
				}

				TEST_METHOD(CommonEnumeration)
				{
					IEnumerableStack<int>* enumerableStack = new EnumerableStack<int>();

					enumerableStack->Push(10);

					enumerableStack->Push(1000);

					enumerableStack = new ReadOnlyStack<int>(enumerableStack, true);

					IEnumerator<int>* enumerator = enumerableStack->GetEnumerator();

					bool moveNextSucceeded;

					Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), 0);

					Assert::IsTrue(moveNextSucceeded);

					int values[2] = { 1000, 10 };

					bool moveNextValues[2] = { true, false };

					for (int i = 0; i < 2; i++)
					{
						Assert::AreEqual(enumerator->GetCurrent(), values[i]);

						Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), 0);

						Assert::AreEqual(moveNextSucceeded, moveNextValues[i]);
					}

					delete enumerator;

					enumerator = nullptr;

					enumerableStack->ForEach(EnumerateInt);

					enumerableStack->ForEach(EnumerateFloat);

					delete enumerableStack;

					enumerableStack = nullptr;
				}
			};

			TEST_CLASS(QueueTests)
			{
			public:
				TEST_METHOD(PeekAndPop)
				{
					Queue<int>* queue = new Queue<int>();

					queue->Enqueue(10);

					Assert::AreEqual(queue->Peek(), 10);

					queue->Enqueue(1000);

					Assert::AreEqual(queue->Peek(), 10);

					Assert::AreEqual(queue->Dequeue(), 10);

					Assert::AreEqual(queue->Peek(), 1000);

					Assert::AreEqual(queue->Dequeue(), 1000);



					queue->Enqueue(1000);

					Assert::AreEqual(queue->Peek(), 1000);

					queue->Enqueue(10);

					Assert::AreEqual(queue->Peek(), 1000);

					Assert::AreEqual(queue->Dequeue(), 1000);

					Assert::AreEqual(queue->Peek(), 10);

					Assert::AreEqual(queue->Dequeue(), 10);

					delete queue;

					queue = nullptr;
				}

				TEST_METHOD(TryPop)
				{
					Queue<int>* queue = new Queue<int>();

					queue->Enqueue(10);

					queue->Enqueue(1000);

					int i;

					Assert::IsTrue(queue->TryDequeue(&i));

					Assert::AreEqual(i, 10);

					Assert::IsTrue(queue->TryDequeue(&i));

					Assert::AreEqual(i, 1000);

					Assert::IsFalse(queue->TryDequeue(&i));

					delete queue;

					queue = nullptr;
				}

				TEST_METHOD(Clear)
				{
					Queue<int>* queue = new Queue<int>();

					queue->Enqueue(10);

					queue->Enqueue(1000);

					Assert::AreEqual(queue->GetCount(), 2u);

					queue->Clear();

					Assert::AreEqual(queue->GetCount(), 0u);

					delete queue;

					queue = nullptr;
				}

				TEST_METHOD(PeekAndPopObject)
				{
					Queue<Something*>* queue = new Queue<Something*>();

					queue->Enqueue(new Something(10));

					Assert::AreEqual(queue->Peek()->GetId(), 10);

					queue->Enqueue(new Something(1000));

					Assert::AreEqual(queue->Peek()->GetId(), 10);

					Something* result;

					Assert::AreEqual((result = queue->Dequeue())->GetId(), 10);

					delete result;

					Assert::AreEqual(queue->Peek()->GetId(), 1000);

					Assert::AreEqual((result = queue->Dequeue())->GetId(), 1000);

					delete result;



					queue->Enqueue(new Something(1000));

					Assert::AreEqual(queue->Peek()->GetId(), 1000);

					queue->Enqueue(new Something(10));

					Assert::AreEqual(queue->Peek()->GetId(), 1000);

					Assert::AreEqual((result = queue->Dequeue())->GetId(), 1000);

					delete result;

					Assert::AreEqual(queue->Peek()->GetId(), 10);

					Assert::AreEqual((result = queue->Dequeue())->GetId(), 10);

					delete result;

					delete queue;

					queue = nullptr;
				}
			};

			TEST_CLASS(EnumerableQueueTests)
			{
			public:
				TEST_METHOD(QueueChangingDuringEnumeration)
				{
					IEnumerableQueue<int>* enumerableQueue = new EnumerableQueue<int>();

					enumerableQueue->Enqueue(10);

					IEnumerator<int>* enumerator = enumerableQueue->GetEnumerator();

					bool moveNextSucceeded = false;

					Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), 0);

					Assert::IsTrue(moveNextSucceeded);

					Assert::AreEqual(enumerator->GetCurrent(), 10);

					Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), 0);

					Assert::IsFalse(moveNextSucceeded);

					enumerableQueue->Enqueue(1000);

					Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), -1);

					Assert::IsFalse(moveNextSucceeded); // Should be false because the queue has changed during enumeration.

					delete enumerator;
				}

				static void EnumerateInt(int i)
				{
					Assert::IsTrue(i == 10 || i == 1000);
				}

				static void EnumerateFloat(float f)
				{
					Assert::IsTrue(f == 10 || f == 1000);
				}

				TEST_METHOD(CommonEnumeration)
				{
					IEnumerableQueue<int>* enumerableQueue = new EnumerableQueue<int>();

					enumerableQueue->Enqueue(10);

					enumerableQueue->Enqueue(1000);

					enumerableQueue = new ReadOnlyQueue<int>(enumerableQueue, true);

					IEnumerator<int>* enumerator = enumerableQueue->GetEnumerator();

					bool moveNextSucceeded = false;

					Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), 0);

					Assert::IsTrue(moveNextSucceeded);

					int values[2] = { 10, 1000 };

					bool moveNextValues[2] = { true, false };

					for (int i = 0; i < 2; i++)
					{
						Assert::AreEqual(enumerator->GetCurrent(), values[i]);

						Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), 0);

						Assert::AreEqual(moveNextSucceeded, moveNextValues[i]);
					}

					delete enumerator;

					enumerator = nullptr;

					enumerableQueue->ForEach(EnumerateInt);

					enumerableQueue->ForEach(EnumerateFloat);

					delete enumerableQueue;

					enumerableQueue = nullptr;
				}
			};

			TEST_CLASS(SafeArrayTests)
			{
			private:
				int _value = -1;

			public:
				void EnumerateArray(const int value)
				{
					Assert::IsTrue(value < 10);

					Assert::AreEqual(++_value, value);
				}

				void ReverseEnumerateArray(const int value)
				{
					Assert::IsTrue(value >= 0);

					Assert::AreEqual(--_value, value);
				}

				TEST_METHOD(Tests)
				{
					int _array[10];

					for (int i = 0; i < 10; i++)

						_array[i] = i;

					SafeArray<int>* safeArray = new SafeArray<int>(_array, 10);

					Assert::AreEqual(10u, safeArray->GetCount());

					for (int i = 0; i < 10; i++)

						Assert::AreEqual(i, safeArray->GetAt(i));

					int _result;

					int _retVal = safeArray->First(&_result);

					Assert::AreEqual(0, _retVal); // The size of an array must be greater than zero, so we do not need to test the return value for this method when called on an empty array.

					Assert::AreEqual(0, _result);

					typedef void(SafeArrayTests::* _enumerateArray)(int);

					_enumerateArray enumerateArray = EnumerateArray;

					safeArray->ForEach(&enumerateArray);

					Assert::IsTrue(safeArray->GetSupportsReversedEnumeration());

					_value = 10;

					enumerateArray = ReverseEnumerateArray;

					safeArray->ReversedForEach(&enumerateArray);

					delete safeArray;

					safeArray = nullptr;
				}
			};
		}
	}
}

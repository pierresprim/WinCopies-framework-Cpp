#include "pch.h"
#include "CppUnitTest.h"
#include "../WinCopies.Collections.Shared/Stack.h"
#include "../WinCopies.Collections.Shared/ReadOnlyStack.h"
#include "../WinCopies.Collections.Shared/Queue.h"
#include "../WinCopies.Collections.Shared/ReadOnlyQueue.h"
#include "../WinCopies.Collections.Shared/SafeArray.h"
#include "../WinCopies.Util.Base.Shared/SafePointer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace WinCopies::Collections;

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

#define SAFESOMETHING SafePointer<Something>
#define NEWSAFESOMETHING SAFESOMETHING(new Something(

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
					SafePointer<Stack<int>> stack = SafePointer<Stack<int>>(new Stack<int>());

					stack.GetPointer()->Push(10);

					Assert::AreEqual(stack.GetPointer()->Peek(), 10);

					stack.GetPointer()->Push(1000);

					Assert::AreEqual(stack.GetPointer()->Peek(), 1000);

					Assert::AreEqual(stack.GetPointer()->Pop(), 1000);

					Assert::AreEqual(stack.GetPointer()->Peek(), 10);

					Assert::AreEqual(stack.GetPointer()->Pop(), 10);



					stack.GetPointer()->Push(1000);

					Assert::AreEqual(stack.GetPointer()->Peek(), 1000);

					stack.GetPointer()->Push(10);

					Assert::AreEqual(stack.GetPointer()->Peek(), 10);

					Assert::AreEqual(stack.GetPointer()->Pop(), 10);

					Assert::AreEqual(stack.GetPointer()->Peek(), 1000);

					Assert::AreEqual(stack.GetPointer()->Pop(), 1000);
				}

				TEST_METHOD(TryPop)
				{
					SafePointer<Stack<int>> stack = SafePointer<Stack<int>>(new Stack<int>());

					stack.GetPointer()->Push(10);

					stack.GetPointer()->Push(1000);

					OutPointer<int> i;

					Assert::IsTrue(stack.GetPointer()->TryPop(&i));

					Assert::AreEqual(i.GetValue(), 1000);

					Assert::IsTrue(stack.GetPointer()->TryPop(&i));

					Assert::AreEqual(i.GetValue(), 10);

					Assert::IsFalse(stack.GetPointer()->TryPop(&i));
				}

				TEST_METHOD(Clear)
				{
					SafePointer<Stack<int>> stack = SafePointer<Stack<int>>(new Stack<int>());

					stack.GetPointer()->Push(10);

					stack.GetPointer()->Push(1000);

					Assert::AreEqual(stack.GetPointer()->GetCount(), 2u);

					stack.GetPointer()->Clear();

					Assert::AreEqual(stack.GetPointer()->GetCount(), 0u);
				}

				TEST_METHOD(PeekAndPopObject)
				{
					SafePointer<Stack<SAFESOMETHING>> stack = SafePointer<Stack<SAFESOMETHING>>(new Stack<SAFESOMETHING>());

					stack.GetPointer()->Push(SAFESOMETHING(NEWSAFESOMETHING 10))));

Assert::AreEqual(stack.GetPointer()->Peek().GetPointer()->GetId(), 10);

stack.GetPointer()->Push(NEWSAFESOMETHING 1000)));

Assert::AreEqual(stack.GetPointer()->Peek().GetPointer()->GetId(), 1000);

Something* result;

Assert::AreEqual((result = stack.GetPointer()->Pop().GetPointer())->GetId(), 1000);

bool exception = false;

try
{
	delete result;
}
catch (const std::exception&)
{
	exception = true;
}

Assert::IsTrue(exception);

Assert::AreEqual(stack.GetPointer()->Peek().GetPointer()->GetId(), 10);

Assert::AreEqual((result = stack.GetPointer()->Pop().GetPointer())->GetId(), 10);



stack.GetPointer()->Push(NEWSAFESOMETHING 1000)));

Assert::AreEqual((result = stack.GetPointer()->Peek().GetPointer())->GetId(), 1000);

stack.GetPointer()->Push(NEWSAFESOMETHING 10)));

Assert::AreEqual(stack.GetPointer()->Peek().GetPointer()->GetId(), 10);

Assert::AreEqual((result = stack.GetPointer()->Pop().GetPointer())->GetId(), 10);

delete result;

Assert::AreEqual(stack.GetPointer()->Peek().GetPointer()->GetId(), 1000);

Assert::AreEqual((result = stack.GetPointer()->Pop().GetPointer())->GetId(), 1000);

delete result;

result = nullptr;
				}
			};

			TEST_CLASS(EnumerableStackTests)
			{
			public:
				TEST_METHOD(StackChangingDuringEnumeration)
				{
					SafePointer<IEnumerableStack<int>> enumerableStack = SafePointer<IEnumerableStack<int>>(new EnumerableStack<int>());

					enumerableStack.GetPointer()->Push(10);

					enumerableStack.GetPointer()->Push(10);

					SafePointer<IEnumerator<int>> enumerator = SafePointer<IEnumerator<int>>(enumerableStack.GetPointer()->GetEnumerator());

					bool moveNextSucceeded = false;

					Assert::AreEqual(enumerator.GetPointer()->MoveNext(&moveNextSucceeded), 0);

					Assert::IsTrue(moveNextSucceeded);

					Assert::AreEqual(enumerator.GetPointer()->GetCurrent(), 10);

					enumerableStack.GetPointer()->Push(1000);

					Assert::AreEqual(OBJECT_HAS_CHANGED_DURING_ENUMERATION_EXCEPTION, enumerator.GetPointer()->MoveNext(&moveNextSucceeded));

					Assert::IsFalse(moveNextSucceeded); // Should be false because the stack has changed during enumeration.
				}

				static bool EnumerateInt(const int i)
				{
					Assert::IsTrue(i == 10 || i == 1000);

					return false;
				}

				static void EnumerateFloat(const float f)
				{
					Assert::IsTrue(f == 10 || f == 1000);
				}

				TEST_METHOD(CommonEnumeration)
				{
					SafePointer<IEnumerableStack<int>> enumerableStack = SafePointer<IEnumerableStack<int>>(new EnumerableStack<int>());

					enumerableStack.GetPointer()->Push(10);

					enumerableStack.GetPointer()->Push(1000);

					enumerableStack = SafePointer<IEnumerableStack<int>>(new ReadOnlyStack<int>(enumerableStack.GetPointer(), true));

					SafePointer<IEnumerator<int>> enumerator = SafePointer<IEnumerator<int>>(enumerableStack.GetPointer()->GetEnumerator());

					bool moveNextSucceeded;

					Assert::AreEqual(enumerator.GetPointer()->MoveNext(&moveNextSucceeded), 0);

					Assert::IsTrue(moveNextSucceeded);

					int values[2] = { 1000, 10 };

					bool moveNextValues[2] = { true, false };

					for (int i = 0; i < 2; i++)
					{
						Assert::AreEqual(enumerator.GetPointer()->GetCurrent(), values[i]);

						Assert::AreEqual(enumerator.GetPointer()->MoveNext(&moveNextSucceeded), 0);

						Assert::AreEqual(moveNextSucceeded, moveNextValues[i]);
					}

					enumerableStack.GetPointer()->ForEach(EnumerateInt);

					enumerableStack.GetPointer()->ForEach(EnumerateFloat);
				}
			};

			TEST_CLASS(QueueTests)
			{
			public:
				TEST_METHOD(PeekAndPop)
				{
					SafePointer<Queue<int>> queue = SafePointer<Queue<int>>(new Queue<int>());

					queue.GetPointer()->Enqueue(10);

					Assert::AreEqual(queue.GetPointer()->Peek(), 10);

					queue.GetPointer()->Enqueue(1000);

					Assert::AreEqual(queue.GetPointer()->Peek(), 10);

					Assert::AreEqual(queue.GetPointer()->Dequeue(), 10);

					Assert::AreEqual(queue.GetPointer()->Peek(), 1000);

					Assert::AreEqual(queue.GetPointer()->Dequeue(), 1000);



					queue.GetPointer()->Enqueue(1000);

					Assert::AreEqual(queue.GetPointer()->Peek(), 1000);

					queue.GetPointer()->Enqueue(10);

					Assert::AreEqual(queue.GetPointer()->Peek(), 1000);

					Assert::AreEqual(queue.GetPointer()->Dequeue(), 1000);

					Assert::AreEqual(queue.GetPointer()->Peek(), 10);

					Assert::AreEqual(queue.GetPointer()->Dequeue(), 10);
				}

				TEST_METHOD(TryPop)
				{
					SafePointer<Queue<int>> queue = SafePointer<Queue<int>>(new Queue<int>());

					queue.GetPointer()->Enqueue(10);

					queue.GetPointer()->Enqueue(1000);

					OutPointer<int> i;

					Assert::IsTrue(queue.GetPointer()->TryDequeue(&i));

					Assert::AreEqual(i.GetValue(), 10);

					Assert::IsTrue(queue.GetPointer()->TryDequeue(&i));

					Assert::AreEqual(i.GetValue(), 1000);

					Assert::IsFalse(queue.GetPointer()->TryDequeue(&i));
				}

				TEST_METHOD(Clear)
				{
					SafePointer<Queue<int>> queue = SafePointer<Queue<int>>(new Queue<int>());

					queue.GetPointer()->Enqueue(10);

					queue.GetPointer()->Enqueue(1000);

					Assert::AreEqual(queue.GetPointer()->GetCount(), 2u);

					queue.GetPointer()->Clear();

					Assert::AreEqual(queue.GetPointer()->GetCount(), 0u);
				}

				TEST_METHOD(PeekAndPopObject)
				{
					SafePointer<Queue<SAFESOMETHING>> queue = SafePointer<Queue<SAFESOMETHING>>(new Queue<SAFESOMETHING>());

					queue.GetPointer()->Enqueue(NEWSAFESOMETHING 10)));

					Assert::AreEqual(queue.GetPointer()->Peek().GetPointer()->GetId(), 10);

					queue.GetPointer()->Enqueue(NEWSAFESOMETHING 1000)));

					Assert::AreEqual(queue.GetPointer()->Peek().GetPointer()->GetId(), 10);

					Assert::AreEqual(queue.GetPointer()->Dequeue().GetPointer()->GetId(), 10);

					Assert::AreEqual(queue.GetPointer()->Peek().GetPointer()->GetId(), 1000);

					Assert::AreEqual(queue.GetPointer()->Dequeue().GetPointer()->GetId(), 1000);



					queue.GetPointer()->Enqueue(NEWSAFESOMETHING 1000)));

					Assert::AreEqual(queue.GetPointer()->Peek().GetPointer()->GetId(), 1000);

					queue.GetPointer()->Enqueue(NEWSAFESOMETHING 10)));

					Assert::AreEqual(queue.GetPointer()->Peek().GetPointer()->GetId(), 1000);

					Assert::AreEqual(queue.GetPointer()->Dequeue().GetPointer()->GetId(), 1000);

					Assert::AreEqual(queue.GetPointer()->Peek().GetPointer()->GetId(), 10);

					Assert::AreEqual(queue.GetPointer()->Dequeue().GetPointer()->GetId(), 10);
				}
			};

			TEST_CLASS(EnumerableQueueTests)
			{
			public:
				TEST_METHOD(QueueChangingDuringEnumeration)
				{
					SafePointer<IEnumerableQueue<int>> enumerableQueue = SafePointer<IEnumerableQueue<int>>(new EnumerableQueue<int>());

					enumerableQueue.GetPointer()->Enqueue(10);

					SafePointer<IEnumerator<int>> enumerator = SafePointer<IEnumerator<int>>(enumerableQueue.GetPointer()->GetEnumerator());

					bool moveNextSucceeded = false;

					Assert::AreEqual(enumerator.GetPointer()->MoveNext(&moveNextSucceeded), 0);

					Assert::IsTrue(moveNextSucceeded);

					Assert::AreEqual(enumerator.GetPointer()->GetCurrent(), 10);

					Assert::AreEqual(enumerator.GetPointer()->MoveNext(&moveNextSucceeded), 0);

					Assert::IsFalse(moveNextSucceeded);

					enumerableQueue.GetPointer()->Enqueue(1000);

					Assert::AreEqual(enumerator.GetPointer()->MoveNext(&moveNextSucceeded), -1);

					Assert::IsFalse(moveNextSucceeded); // Should be false because the queue has changed during enumeration.
				}

				static bool EnumerateInt(int i)
				{
					Assert::IsTrue(i == 10 || i == 1000);

					return false;
				}

				static void EnumerateFloat(float f)
				{
					Assert::IsTrue(f == 10 || f == 1000);
				}

				TEST_METHOD(CommonEnumeration)
				{
					SafePointer<IEnumerableQueue<int>> enumerableQueue = SafePointer<IEnumerableQueue<int>>(new EnumerableQueue<int>());

					enumerableQueue.GetPointer()->Enqueue(10);

					enumerableQueue.GetPointer()->Enqueue(1000);

					enumerableQueue = SafePointer<IEnumerableQueue<int>>(new ReadOnlyQueue<int>(enumerableQueue.GetPointer(), true));

					SafePointer<IEnumerator<int>> enumerator = SafePointer<IEnumerator<int>>(enumerableQueue.GetPointer()->GetEnumerator());

					bool moveNextSucceeded = false;

					Assert::AreEqual(enumerator.GetPointer()->MoveNext(&moveNextSucceeded), 0);

					Assert::IsTrue(moveNextSucceeded);

					int values[2] = { 10, 1000 };

					bool moveNextValues[2] = { true, false };

					for (int i = 0; i < 2; i++)
					{
						Assert::AreEqual(enumerator.GetPointer()->GetCurrent(), values[i]);

						Assert::AreEqual(enumerator.GetPointer()->MoveNext(&moveNextSucceeded), 0);

						Assert::AreEqual(moveNextSucceeded, moveNextValues[i]);
					}

					enumerableQueue.GetPointer()->ForEach(EnumerateInt);

					enumerableQueue.GetPointer()->ForEach(EnumerateFloat);
				}
			};

			TEST_CLASS(SafeArrayTests)
			{
			private:
				int _value = -1;

			public:
				bool EnumerateArray(const int value)
				{
					Assert::IsTrue(value < 10);

					Assert::AreEqual(++_value, value);
				}

				bool ReverseEnumerateArray(const int value)
				{
					Assert::IsTrue(value >= 0);

					Assert::AreEqual(--_value, value);
				}

				TEST_METHOD(Tests)
				{
					int _array[10];

					for (int i = 0; i < 10; i++)

						_array[i] = i;

					SafePointer<SafeArray<int>> safeArray = SafePointer<SafeArray<int>>(new SafeArray<int>(_array, 10));

					Assert::AreEqual(10u, safeArray.GetPointer()->GetCount());

					for (int i = 0; i < 10; i++)

						Assert::AreEqual(i, safeArray.GetPointer()->GetAt(i));

					int _result;

					int* _resultPtr = &_result;

					int _retVal = safeArray.GetPointer()->First(&_resultPtr);

					Assert::AreEqual(0, _retVal); // The size of an array must be greater than zero, so we do not need to test the return value for this method when called on an empty array.

					Assert::AreEqual(0, _result);

					typedef bool(SafeArrayTests::* _enumerateArray)(int);

					_enumerateArray enumerateArray = &SafeArrayTests::EnumerateArray;

					safeArray.GetPointer()->ForEach(&enumerateArray);

					Assert::IsTrue(safeArray.GetPointer()->GetSupportsReversedEnumeration());

					_value = 10;

					enumerateArray = &SafeArrayTests::ReverseEnumerateArray;

					safeArray.GetPointer()->ReversedForEach(&enumerateArray);
				}
			};
		}
	}
}

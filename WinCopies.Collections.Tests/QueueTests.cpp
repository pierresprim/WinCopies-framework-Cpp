#include "pch.h"
#include "CppUnitTest.h"
#include "../WinCopies.Collections.Shared/Queue.h"
//#include "../WinCopies.Collections.Shared/ReadOnlyQueue.h"
#include "Something.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			namespace Tests
			{
				TEST_CLASS(QueueTests)
				{
				public:
					TEST_METHOD(PeekAndPop)
					{
						Queue<int>* queue = new Queue<int>();

						queue->Enqueue(10);

						int result = 0;

						Assert::AreEqual(queue->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 10);

						result = 0;

						void* resultPtr = &result;

						Assert::AreEqual(queue->Peek(&resultPtr), EXIT_SUCCESS);

						Assert::AreEqual(result, 10);

						queue->Enqueue(1000);

						Assert::AreEqual(queue->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 10);

						result = 0;

						Assert::AreEqual(queue->Dequeue(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 10);

						result = 0;

						Assert::AreEqual(queue->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 1000);

						result = 0;

						Assert::AreEqual(queue->Dequeue(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 1000);

						result = 0;



						queue->Enqueue(1000);

						Assert::AreEqual(queue->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 1000);

						result = 0;

						queue->Enqueue(10);

						Assert::AreEqual(queue->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 1000);

						result = 0;

						Assert::AreEqual(queue->Dequeue(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 1000);

						result = 0;

						Assert::AreEqual(queue->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 10);

						result = 0;

						Assert::AreEqual(queue->Dequeue(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 10);

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

						SimpleLinkedListNode<int>* item = new SimpleLinkedListNode<int>(10);

						queue->Enqueue(new Something(10));

						Something* result;

						Assert::AreEqual(queue->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 10);

						result = nullptr;

						queue->Enqueue(new Something(1000));

						Assert::AreEqual(queue->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 10);

						result = nullptr;

						Assert::AreEqual(queue->Dequeue(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 10);

						delete result;

						result = nullptr;

						Assert::AreEqual(queue->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 1000);

						result = nullptr;

						Assert::AreEqual(queue->Dequeue(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 1000);

						delete result;

						result = nullptr;



						queue->Enqueue(new Something(1000));

						Assert::AreEqual(queue->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 1000);

						result = nullptr;

						queue->Enqueue(new Something(10));

						Assert::AreEqual(queue->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 1000);

						result = nullptr;

						Assert::AreEqual(queue->Dequeue(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 1000);

						delete result;

						result = nullptr;

						Assert::AreEqual(queue->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 10);

						result = nullptr;

						Assert::AreEqual(queue->Dequeue(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 10);

						delete result;

						delete queue;

						queue = nullptr;
					}
				};
			}
		}
	}
}

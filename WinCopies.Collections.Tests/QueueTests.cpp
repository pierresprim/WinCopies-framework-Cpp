#include "pch.h"
#include "CppUnitTest.h"
#include "../WinCopies.Collections.Shared/Queue.h"
#include "../WinCopies.Collections.Shared/ReadOnlyQueue.h"
#include "Something.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WinCopies
{
	namespace Collections
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
		}
	}
}

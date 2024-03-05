#include "pch.h"
//#include "CppUnitTest.h"
//#include "../WinCopies.Collections.Shared/Queue.h"
//#include "../WinCopies.Collections.Shared/ReadOnlyQueue.h"
//
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace WinCopies
//{
//	namespace Collections
//	{
//		namespace Tests
//		{
//			TEST_CLASS(EnumerableQueueTests)
//			{
//			public:
//				TEST_METHOD(QueueChangingDuringEnumeration)
//				{
//					IEnumerableQueue<int>* enumerableQueue = new EnumerableQueue<int>();
//
//					enumerableQueue->Enqueue(10);
//
//					IEnumerator<int>* enumerator = enumerableQueue->GetEnumerator();
//
//					bool moveNextSucceeded = false;
//
//					Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), 0);
//
//					Assert::IsTrue(moveNextSucceeded);
//
//					Assert::AreEqual(enumerator->GetCurrent(), 10);
//
//					Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), 0);
//
//					Assert::IsFalse(moveNextSucceeded);
//
//					delete enumerator;
//
//					enumerator = enumerableQueue->GetEnumerator();
//
//					enumerableQueue->Enqueue(1000);
//
//					Assert::AreEqual(OBJECT_HAS_CHANGED_DURING_ENUMERATION_EXCEPTION, enumerator->MoveNext(&moveNextSucceeded));
//
//					Assert::IsFalse(moveNextSucceeded); // Should be false because the queue has changed during enumeration.
//
//					delete enumerator;
//
//					enumerator = nullptr;
//
//					delete enumerableQueue;
//
//					enumerableQueue = nullptr;
//				}
//
//				static bool EnumerateInt(int i)
//				{
//					Assert::IsTrue(i == 10 || i == 1000);
//
//					return false;
//				}
//
//				/*static bool EnumerateFloat(float f)
//				{
//					Assert::IsTrue(f == 10 || f == 1000);
//
//					return false;
//				}*/
//				TEST_METHOD(CommonEnumeration)
//				{
//					IEnumerableQueue<int>* enumerableQueue = new EnumerableQueue<int>();
//
//					enumerableQueue->Enqueue(10);
//
//					enumerableQueue->Enqueue(1000);
//
//					enumerableQueue = new ReadOnlyQueue<int>(enumerableQueue, true);
//
//					IEnumerator<int>* enumerator = enumerableQueue->GetEnumerator();
//
//					bool moveNextSucceeded = false;
//
//					Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), 0);
//
//					Assert::IsTrue(moveNextSucceeded);
//
//					int values[2] = { 10, 1000 };
//
//					bool moveNextValues[2] = { true, false };
//
//					for (int i = 0; i < 2; i++)
//					{
//						Assert::AreEqual(enumerator->GetCurrent(), values[i]);
//
//						Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), 0);
//
//						Assert::AreEqual(moveNextSucceeded, moveNextValues[i]);
//					}
//
//					delete enumerator;
//
//					enumerator = nullptr;
//
//					enumerableQueue->ForEach(EnumerateInt);
//
//					// enumerableQueue->ForEach(EnumerateFloat);
//
//					delete enumerableQueue;
//
//					enumerableQueue = nullptr;
//				}
//			};
//		}
//	}
//}

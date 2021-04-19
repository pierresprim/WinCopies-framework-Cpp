#include "pch.h"
//#include "CppUnitTest.h"
//#include "../WinCopies.Collections.Shared/Stack.h"
//#include "../WinCopies.Collections.Shared/ReadOnlyStack.h"
//
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace WinCopies
//{
//	namespace Collections
//	{
//		namespace Tests
//		{
//			TEST_CLASS(EnumerableStackTests)
//			{
//			public:
//				TEST_METHOD(StackChangingDuringEnumeration)
//				{
//					IEnumerableStack<int>* enumerableStack = new EnumerableStack<int>();
//
//					enumerableStack->Push(10);
//
//					enumerableStack->Push(10);
//
//					IEnumerator<int>* enumerator = enumerableStack->GetEnumerator();
//
//					bool moveNextSucceeded = false;
//
//					Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), 0);
//
//					Assert::IsTrue(moveNextSucceeded);
//
//					Assert::AreEqual(enumerator->GetCurrent(), 10);
//
//					enumerableStack->Push(1000);
//
//					Assert::AreEqual(OBJECT_HAS_CHANGED_DURING_ENUMERATION_EXCEPTION, enumerator->MoveNext(&moveNextSucceeded));
//
//					Assert::IsFalse(moveNextSucceeded); // Should be false because the stack has changed during enumeration.
//
//					delete enumerator;
//				}
//
//				static bool EnumerateInt(int i)
//				{
//					Assert::IsTrue(i == 10 || i == 1000);
//
//					return false;
//				}
//
//				/*static bool EnumerateFloat( float f)
//				{
//					Assert::IsTrue(f == 10 || f == 1000);
//
//					return false;
//				}*/
//
//				TEST_METHOD(CommonEnumeration)
//				{
//					IEnumerableStack<int>* enumerableStack = new EnumerableStack<int>();
//
//					enumerableStack->Push(10);
//
//					enumerableStack->Push(1000);
//
//					enumerableStack = new ReadOnlyStack<int>(enumerableStack, true);
//
//					IEnumerator<int>* enumerator = enumerableStack->GetEnumerator();
//
//					bool moveNextSucceeded;
//
//					Assert::AreEqual(enumerator->MoveNext(&moveNextSucceeded), 0);
//
//					Assert::IsTrue(moveNextSucceeded);
//
//					int values[2] = { 1000, 10 };
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
//					enumerableStack->ForEach(EnumerateInt);
//
//					// enumerableStack->ForEach(EnumerateFloat);
//
//					delete enumerableStack;
//
//					enumerableStack = nullptr;
//				}
//			};
//		}
//	}
//}

#include "pch.h"
#include "CppUnitTest.h"
#include "../WinCopies.Collections.Shared/Stack.h"
//#include "../WinCopies.Collections.Shared/ReadOnlyStack.h"
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
				TEST_CLASS(StackTests)
				{
				public:
					TEST_METHOD(PeekAndPop)
					{
						Stack<int>* stack = new Stack<int>();

						stack->Push(10);

						int result = 0;

						Assert::AreEqual(stack->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 10);

						result = 0;

						void* resultPtr = &result;

						Assert::AreEqual(stack->Peek(&resultPtr), EXIT_SUCCESS);

						Assert::AreEqual(result, 10);

						stack->Push(1000);

						Assert::AreEqual(stack->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 1000);

						result = 0;

						Assert::AreEqual(stack->Pop(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 1000);

						result = 0;

						Assert::AreEqual(stack->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 10);

						result = 0;

						Assert::AreEqual(stack->Pop(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 10);

						result = 0;



						stack->Push(1000);

						Assert::AreEqual(stack->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 1000);

						result = 0;

						stack->Push(10);

						Assert::AreEqual(stack->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 10);

						result = 0;

						Assert::AreEqual(stack->Pop(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 10);

						result = 0;

						Assert::AreEqual(stack->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 1000);

						result = 0;

						Assert::AreEqual(stack->Pop(&result), EXIT_SUCCESS);

						Assert::AreEqual(result, 1000);

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

						SimpleLinkedListNode<int>* item = new SimpleLinkedListNode<int>(10);

						stack->Push(new Something(10));

						Something* result;

						Assert::AreEqual(stack->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 10);

						result = nullptr;

						stack->Push(new Something(1000));

						Assert::AreEqual(stack->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 1000);

						result = nullptr;

						Assert::AreEqual(stack->Pop(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 1000);

						delete result;

						result = nullptr;

						Assert::AreEqual(stack->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 10);

						result = nullptr;

						Assert::AreEqual(stack->Pop(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 10);

						delete result;

						result = nullptr;



						stack->Push(new Something(1000));

						Assert::AreEqual(stack->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 1000);

						result = nullptr;

						stack->Push(new Something(10));

						Assert::AreEqual(stack->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 10);

						result = nullptr;

						Assert::AreEqual(stack->Pop(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 10);

						delete result;

						result = nullptr;

						Assert::AreEqual(stack->GenericPeek(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 1000);

						result = nullptr;

						Assert::AreEqual(stack->Pop(&result), EXIT_SUCCESS);

						Assert::AreEqual(result->GetId(), 1000);

						delete result;

						delete stack;

						stack = nullptr;
					}
				};
			}
		}
	}
}

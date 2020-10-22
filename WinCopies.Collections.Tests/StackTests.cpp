#include "pch.h"
#include "CppUnitTest.h"
#include "../WinCopies.Collections.Shared/Stack.h"
#include "../WinCopies.Collections.Shared/ReadOnlyStack.h"
#include "Something.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
		}
	}
}
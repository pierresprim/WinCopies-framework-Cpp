#include "pch.h"
#include "CppUnitTest.h"
#include "../WinCopies.Collections.Shared/Stack.h"
#include <iostream>

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

namespace WinCopiesCollectionsTests
{
	TEST_CLASS(WinCopiesCollectionsTests)
	{
	public:

		TEST_METHOD(TestMethod1)
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



			Stack<Something*>* _stack = new Stack<Something*>();

			_stack->Push(new Something(10));

			Assert::AreEqual(_stack->Peek()->GetId(), 10);

			_stack->Push(new Something(1000));

			Assert::AreEqual(_stack->Peek()->GetId(), 1000);

			Assert::AreEqual(_stack->Pop()->GetId(), 1000);

			Assert::AreEqual(_stack->Peek()->GetId(), 10);

			Assert::AreEqual(_stack->Pop()->GetId(), 10);



			_stack->Push(new Something(1000));

			Assert::AreEqual(_stack->Peek()->GetId(), 1000);

			_stack->Push(new Something(10));

			Assert::AreEqual(_stack->Peek()->GetId(), 10);

			Assert::AreEqual(_stack->Pop()->GetId(), 10);

			Assert::AreEqual( _stack->Peek()->GetId(), 1000);

			Assert::AreEqual(_stack->Pop()->GetId(), 1000);
		}
	};
}

#include "pch.h"

#include "Includes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace WinCopies::Collections;

namespace WinCopies
{
	namespace Util
	{
		namespace Tests
		{
			TEST_CLASS(ActionDelegateTests)
			{
			public:
				void AssertParameterized(IParameterizedActionDelegate<int>* delegate, bool* emptyArrayFoundPtr, Queue<int>** queuePtr)
				{
					delegate->Action();

					Assert::IsTrue(*emptyArrayFoundPtr, L"SomeParameterizedDelegate::Action() did not found empty array. Maybe did not be reached?");

					int* array = new int[10];

					for (int i = 0, j = 10; i < 10; i++, j--)

						*(array + i) = j;

					SafeArray<int>* _array = new SafeArray<int>(array, 10);

					int count = 0;

					for (int i = 0, j = 10; i < 10; i++, j--)
					{
						count++;

						Assert::AreEqual(j, _array->GetAt(i));
					}

					Assert::AreEqual(10, count);

					count = 0;

					*queuePtr = new Queue<int>();

					delegate->Action(_array);

					Assert::AreEqual(10u, (*queuePtr)->GetCount());

					while ((*queuePtr)->GetCount() > 0)

						Assert::AreEqual(++count, (*queuePtr)->Dequeue());

					Assert::AreEqual(0u, (*queuePtr)->GetCount());

					emptyArrayFoundPtr = nullptr;

					delete* queuePtr;

					*queuePtr = nullptr;

					queuePtr = nullptr;

					delete _array;

					_array = nullptr;

					delete delegate;

					delegate = nullptr;
				}

				void AssertFixedParameter(IFixedParameterActionDelegate<SomeFixedParameterDelegateParameter*>* delegate, SomeFixedParameterDelegateParameter* param)
				{
					for (int i = 0; i < 10; i++)

						delegate->Action();

					Assert::AreEqual(10u, param->GetCount());

					delete param;

					param = nullptr;
				}

				TEST_METHOD(ActionDelegate)
				{
					IActionDelegate* delegate = new SomeDelegate();

					delegate->Action();

					Assert::IsTrue(SomeDelegate::result, L"SomeDelegate::Action did not update the result variable.");

					delete delegate;

					delegate = nullptr;
				}

				TEST_METHOD(ParameterizedActionDelegate)
				{
					AssertParameterized(new SomeParameterizedDelegate(), &SomeParameterizedDelegate::emptyArrayFound, &SomeParameterizedDelegate::queue);
				}

				TEST_METHOD(FixedParameterActionDelegate)
				{
					SomeFixedParameterDelegateParameter* param = new SomeFixedParameterDelegateParameter();

					AssertFixedParameter(new SomeFixedParameterDelegate(param), param);

					param = nullptr;
				}

				TEST_METHOD(FixedParameterizedActionDelegate)
				{
					SomeFixedParameterDelegateParameter* param = new SomeFixedParameterDelegateParameter();

					IFixedParameterizedActionDelegate<SomeFixedParameterDelegateParameter*, int>* delegate = new SomeFixedParameterizedDelegate(param);

					AssertFixedParameter(delegate, param);

					param = nullptr;

					AssertParameterized(delegate, &SomeFixedParameterizedDelegate::emptyArrayFound, &SomeFixedParameterizedDelegate::queue);

					delegate = nullptr;
				}
			};
		}
	}
}

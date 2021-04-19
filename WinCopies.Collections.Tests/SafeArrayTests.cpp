#include "pch.h"
#include "CppUnitTest.h"
#include "../WinCopies.Collections.Shared/SafeArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WinCopies
{
	namespace Collections
	{
		namespace Generic
		{
			namespace Tests
			{
				TEST_CLASS(SafeArrayTests)
				{
				private:
					int _value = -1;

				public:
					bool EnumerateArray(int value)
					{
						Assert::IsTrue(value < 10);

						Assert::AreEqual(++_value, value);

						return false;
					}

					bool ReverseEnumerateArray(int value)
					{
						Assert::IsTrue(value >= 0);

						Assert::AreEqual(--_value, value);

						return false;
					}

					TEST_METHOD(Tests)
					{
						int* _array = new int[10];

						for (int i = 0; i < 10; i++)

							_array[i] = i;

						SafeArray<int>* safeArray = new SafeArray<int>(_array, 10);

						Assert::AreEqual(10u, safeArray->GetCount());

						for (int i = 0; i < 10; i++)

							Assert::AreEqual(i, safeArray->GetAt(i));

						IEnumerator<int>* enumerator = safeArray->GetEnumerator();

						int count = 0;

						bool moveNextSucceeded = false;

						Assert::IsTrue(enumerator->MoveNext(&moveNextSucceeded) >= 0);

						Assert::IsTrue(moveNextSucceeded);

						count++;

						int l = 10;

						int c = 0;

						bool b = true;

						for (int i = 0; i < l; ++i)
						{
							if (b)
							{
								b = false;

								Assert::AreEqual(0, i);
							}

							c++;
						}

						Assert::AreEqual(10, c);

						while (enumerator->MoveNext(&moveNextSucceeded) >= 0 && moveNextSucceeded)
						{
							count++;
						}

						Assert::AreEqual(10, count);

						int _result;

						int _retVal = safeArray->First(&_result);

						Assert::AreEqual(0, _retVal); // The size of an array must be greater than zero, so we do not need to test the return value for this method when called on an empty array.

						Assert::AreEqual(0, _result);

						//typedef bool(SafeArrayTests::* _enumerateArray)(int);

						/*auto enumerateArray = [](int value)->bool
						{
							EnumerateArray(value);
						};

						safeArray->ForEach(enumerateArray);

						Assert::IsTrue(safeArray->GetSupportsReversedEnumeration());

						_value = 10;

						_enumerateArray	enumerateArray = &SafeArrayTests::ReverseEnumerateArray;

						 safeArray->ReversedForEach(&enumerateArray);*/

						delete safeArray;

						safeArray = nullptr;



						safeArray = new SafeArray<int>(10u);

						for (int i = 0, j = 1; i < 10; i++, j++)

							safeArray->SetAt(i, j);

						UINT _count = 0;

						for (int i = 0, j = 1; i < 10; i++, j++)
						{
							_count++;

							Assert::AreEqual(safeArray->GetAt(i), j);
						}

						Assert::AreEqual(10u, _count);
					}
				};
			}
		}
	}
}

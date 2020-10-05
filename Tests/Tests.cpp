// Tests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include "../WinCopies.IO.Shared/ShellObjectInfo.h"
#include "../WinCopies.Util.Base.Shared/Exception.h"
#include "../WinCopies.Collections.Shared/Stack.h"

using namespace std;
using namespace WinCopies;
using namespace WinCopies::Collections;
using namespace WinCopies::IO;

int main()
{
	cout << "Hello World!" << endl;

	Exception* ex = new Exception(0, L"Ok.");

	cout << ex->GetErrorCode() << '\n' << ex->GetErrorMessage() << endl;

	wcout << ex->GetErrorCode() << '\n' << ex->GetErrorMessage() << endl;

	//BrowsableObjectInfo* so = new ShellObjectInfo(L"C:\\");

	//wcout << L"IsBrowsable: " << so->GetIsBrowsable() << endl;

	//wcout << so->GetPath() << endl;

	////LinkedListDirection lld = LinkedListDirection::FIFO;

	////std::cout << lld << std::endl;

	////ISingleLinkedList<int>* l1;// = new SingleLinkedList<int>(LinkedListDirection::FIFO);

	//SimpleLinkedList* l = new SimpleLinkedList(LinkedListDirection::FIFO);

	//cout << "LinkedListDirection: " << (int)l->GetDirection() << endl;

	////SingleLinkedListNode<int>* item = l->GetFirst();

	//int i = 1000;

	//SimpleLinkedListNode* node = new SimpleLinkedListNode(&i);

	///*cout << "CurrentPointerValue: " << node->GetValue() << endl;

	//cout << "CurrentPointerValue: " << (int)node->GetValue() << endl;

	//cout << "CurrentPointerValue: " << (int*)node->GetValue() << endl;*/

	////cout << "CurrentPointerValue: " << &(void*)(node->GetValue()) << endl;

	//const void* value=node->GetValue();

	//cout << "CurrentValue: " << *(int*)(value) << endl;

	//cout << "&_value: " << &value << endl;

	//cout << "&_value: " << *(int*)value << endl;

	//SimpleLinkedListNode* _node = new SimpleLinkedListNode(so);

	//cout << "CurrentIsBrowsablePointerValue: " << _node->GetValue() << endl;

	//cout << "CurrentIsBrowsablePointerValue: " << (int)_node->GetValue() << endl;

	//cout << "CurrentIsBrowsablePointerValue: " << (int*)_node->GetValue() << endl;

	//cout << "CurrentIsBrowsableValue: " << ((BrowsableObjectInfo*)_node->GetValue())->GetIsBrowsable() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

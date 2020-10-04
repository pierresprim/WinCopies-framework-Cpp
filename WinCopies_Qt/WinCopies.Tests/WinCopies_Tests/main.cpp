#include <QCoreApplication>
#include <iostream>

#include "../../../WinCopies.Util.Base.Shared/Exception.h"
#include "../../../WinCopies.Collections.Shared/Stack.h"
#include "../../../WinCopies.Collections.Shared/EnumerableStack.h"

using namespace std;

using namespace WinCopies;
using namespace WinCopies::Collections;

class Something
{
private:
    int _num = 0;
public:
    explicit Something(const int num)
    {
        _num = num;
    }

    const wchar_t* ToString()
    {
        cout << _num << endl;

        return L"Qwerty.";
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Hello World!" << endl;

    Exception* ex = new Exception(0, L"Ok.");

    cout << ex->GetErrorCode() << '\n' << ex->GetErrorMessage() << endl;

    wcout << ex->GetErrorCode() << '\n' << ex->GetErrorMessage() << endl;

    Stack<int>* stack = new Stack<int>();

    stack->Push(10);

    cout << stack->Peek() << endl;

    stack->Push(1000);

    cout << stack->Peek() << endl;

    cout << stack->Pop() << endl;

    cout << stack->Peek() << endl;

    cout << stack->Pop() << endl;

    cout << "TryPop" << endl;

    stack->Push(10);

    stack->Push(1000);

    int i;

    cout << stack->TryPop(&i) << endl;

    cout << i << endl;

    cout << stack->TryPop(&i) << endl;

    cout << i << endl;

    cout << stack->TryPop(&i) << endl;



    stack->Push(1000);

    cout << stack->Peek() << endl;

    stack->Push(10);

    cout << stack->Peek() << endl;

    cout << stack->Pop() << endl;

    cout << stack->Peek() << endl;

    cout << stack->Pop() << endl;

    delete stack;

    stack = nullptr;



    cout << "Something" << endl;

    Stack<Something*>* _stack = new Stack<Something*>();

    _stack->Push(new Something(10));

    wcout << _stack->Peek()->ToString() << endl;

    _stack->Push(new Something(1000));

    wcout << _stack->Peek()->ToString() << endl;

    wcout << _stack->Pop()->ToString() << endl;

    wcout << _stack->Peek()->ToString() << endl;

    wcout << _stack->Pop()->ToString() << endl;



    _stack->Push(new Something(1000));

    wcout << _stack->Peek()->ToString() << endl;

    _stack->Push(new Something(10));

    wcout << _stack->Peek()->ToString() << endl;

    wcout << _stack->Pop()->ToString() << endl;

    wcout << _stack->Peek()->ToString() << endl;

    wcout << _stack->Pop()->ToString() << endl;

    delete _stack;

    _stack = nullptr;



    cout << "EnumerableStack" << endl;

    EnumerableStack<int>* enumerableStack = new EnumerableStack<int>();

    enumerableStack->Push(10);

    IEnumerator<int>* enumerator = enumerableStack->GetEnumerator();

    bool moveNextSucceeded = false;

    cout << enumerator->MoveNext(&moveNextSucceeded) << endl;

    cout << moveNextSucceeded << endl;

    while (moveNextSucceeded)
    {
        cout << enumerator->GetCurrent() << endl;

        cout << enumerator->MoveNext(&moveNextSucceeded) << endl;

        cout << moveNextSucceeded << endl;
    }

    enumerableStack->Push(1000);

    cout << enumerator->MoveNext(&moveNextSucceeded) << endl;

    cout << moveNextSucceeded << endl;

    // enumerator->~IEnumerator();

    delete enumerator;

    enumerator = enumerableStack->GetEnumerator();

    cout << enumerator->MoveNext(&moveNextSucceeded) << endl;

    cout << moveNextSucceeded << endl;

    while (moveNextSucceeded)
    {
        cout << enumerator->GetCurrent() << endl;

        cout << enumerator->MoveNext(&moveNextSucceeded) << endl;

        cout << moveNextSucceeded << endl;
    }

    delete enumerator;

    enumerator = nullptr;

    return a.exec();
}

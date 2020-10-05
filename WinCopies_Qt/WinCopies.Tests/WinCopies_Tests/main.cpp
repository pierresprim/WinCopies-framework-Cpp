#include <QCoreApplication>
#include <iostream>

#include "../../../WinCopies.Util.Base.Shared/Exception.h"
#include "../../../WinCopies.Collections.Shared/Stack.h"
#include "../../../WinCopies.Collections.Shared/EnumerableStack.h"
#include "../../../WinCopies.Collections.Shared/ReadOnlyStack.h"
#include "../../../WinCopies.Collections.Shared/Queue.h"
#include "../../../WinCopies.Collections.Shared/EnumerableQueue.h"
#include "../../../WinCopies.Collections.Shared/ReadOnlyQueue.h"

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



    cout << "Clear" << endl;

    stack->Push(10);

    stack->Push(1000);

    cout << stack->GetCount() << endl;

    stack->Clear();

    cout << stack->GetCount() << endl;

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

    IEnumerableStack<int>* enumerableStack = new EnumerableStack<int>();

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

    enumerableStack = new ReadOnlyStack<int>(enumerableStack, true);

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



    cout << "Queue" << endl;

    Queue<int>* queue = new Queue<int>();

    queue->Enqueue(10);

    cout << queue->Peek() << endl;

    queue->Enqueue(1000);

    cout << queue->Peek() << endl;

    cout << queue->Dequeue() << endl;

    cout << queue->Peek() << endl;

    cout << queue->Dequeue() << endl;

    cout << "TryDequeue" << endl;

    queue->Enqueue(10);

    queue->Enqueue(1000);

    cout << queue->TryDequeue(&i) << endl;

    cout << i << endl;

    cout << queue->TryDequeue(&i) << endl;

    cout << i << endl;

    cout << queue->TryDequeue(&i) << endl;



    queue->Enqueue(1000);

    cout << queue->Peek() << endl;

    queue->Enqueue(10);

    cout << queue->Peek() << endl;

    cout << queue->Dequeue() << endl;

    cout << queue->Peek() << endl;

    cout << queue->Dequeue() << endl;



    cout << "Clear" << endl;

    queue->Enqueue(10);

    queue->Enqueue(1000);

    cout << queue->GetCount() << endl;

    queue->Clear();

    cout << queue->GetCount() << endl;

    delete queue;

    queue = nullptr;



    cout << "Something" << endl;

    Queue<Something*>* _queue = new Queue<Something*>();

    _queue->Enqueue(new Something(10));

    wcout << _queue->Peek()->ToString() << endl;

    _queue->Enqueue(new Something(1000));

    wcout << _queue->Peek()->ToString() << endl;

    wcout << _queue->Dequeue()->ToString() << endl;

    wcout << _queue->Peek()->ToString() << endl;

    wcout << _queue->Dequeue()->ToString() << endl;



    _queue->Enqueue(new Something(1000));

    wcout << _queue->Peek()->ToString() << endl;

    _queue->Enqueue(new Something(10));

    wcout << _queue->Peek()->ToString() << endl;

    wcout << _queue->Dequeue()->ToString() << endl;

    wcout << _queue->Peek()->ToString() << endl;

    wcout << _queue->Dequeue()->ToString() << endl;

    delete _queue;

    _queue = nullptr;



    cout << "EnumerableQueue" << endl;

    IEnumerableQueue<int>* enumerableQueue = new EnumerableQueue<int>();

    enumerableQueue->Enqueue(10);

    enumerator = enumerableQueue->GetEnumerator();

    moveNextSucceeded = false;

    cout << enumerator->MoveNext(&moveNextSucceeded) << endl;

    cout << moveNextSucceeded << endl;

    while (moveNextSucceeded)
    {
        cout << enumerator->GetCurrent() << endl;

        cout << enumerator->MoveNext(&moveNextSucceeded) << endl;

        cout << moveNextSucceeded << endl;
    }

    enumerableQueue->Enqueue(1000);

    cout << enumerator->MoveNext(&moveNextSucceeded) << endl;

    cout << moveNextSucceeded << endl;

    // enumerator->~IEnumerator();

    delete enumerator;

    enumerableQueue = new ReadOnlyQueue<int>(enumerableQueue, true);

    enumerator = enumerableQueue->GetEnumerator();

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

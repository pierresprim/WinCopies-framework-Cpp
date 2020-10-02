#include <QCoreApplication>
#include <iostream>
#include "../WinCopies_Qt/test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test* test = new Test(10);

    std::cout << test->GetValue() << std::endl;

    delete test;

    test = new Test(1000);

    std::cout << test->GetValue() << std::endl;

    delete test;

    return a.exec();
}

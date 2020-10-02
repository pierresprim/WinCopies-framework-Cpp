#ifndef TEST_H
#define TEST_H

#include "wincopies_qt_global.h"
class WINCOPIES_QTSHARED_EXPORT Test
{

private:
    int _value = 0;
public:
    explicit Test(const int value);

    int GetValue() const;
};

#endif // TEST_H

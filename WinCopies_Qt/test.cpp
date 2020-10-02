#include "test.h"

Test::Test(const int value)
{
    _value = value;
}

int Test::GetValue() const
{
    return _value;
}

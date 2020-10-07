#pragma once
#ifndef NULLABLE_H
#define NULLABLE_H

#include "wincopies_defines.h"

TEMPLATE
struct DLLEXPORT Nullable
{
private:
    T _value;
    bool _hasValue;
public:
    Nullable()
    {
        _hasValue = false;
    }

    Nullable(T value)
    {
        Update(value);
    }

    bool HasValue()
    {
        return _hasValue;
    }

    void Update(T value)
    {
        _value = value;

        _hasValue = true;
    }

    void Clear()
    {
        _value = 0;

        _hasValue = false;
    }

    int GetValue(T* result)
    {
if (_hasValue)
{
    *result = _value;

    return EXIT_SUCCESS;
}

*result = 0;

return OBJECT_HAS_NO_VALUE;
    }
};

#endif // NULLABLE_H

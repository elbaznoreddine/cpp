#pragma once
#include <iostream>

template <typename T>
void iter(T* array, const int length, void (*func)(const T&))
{
    if (!array)
        return;
    for (int i = 0; i < length; i++)
    {
        func(array[i]);
    }
}
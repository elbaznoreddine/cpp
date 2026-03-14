#include <iostream>

template <typename T>
void iter(T ad, T size)
{
    if (!ad)
        return ;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << f(ad[i]) << std::endl;
    }
}
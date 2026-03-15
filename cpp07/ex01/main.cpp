#include "iter.hpp"

template<typename T> void	print(const T &data)
{
	std::cout << data << std::endl;
}

int main()
{
    std::string ar[] = {"hello", "this", "is", "CPP", "07", "Module"};
    char a[] = "ksjdf";
    std::cout << sizeof(a) << std::endl;

    int iter = sizeof(ar) / sizeof(ar[0]);

    ::iter(ar, iter, print);
    ::iter(a, sizeof(a) - 1, print);
}
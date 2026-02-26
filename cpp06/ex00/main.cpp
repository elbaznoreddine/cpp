#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "./converter [value]" << std::endl;
        return (1);
    }
    std::string str = av[1];
    ScalarConverter::convert(str);
}
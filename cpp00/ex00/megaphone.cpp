#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return (1);
    }
    for (int i = 1; i < ac; i++)
    {
        std::string str = av[i];
        int j = 0;
        while (str[j])
        {
            char c = std::toupper(str[j]);
            std::cout << c;
            j++;
        }
    }
    std::cout<< '\n';
    return (0);
}
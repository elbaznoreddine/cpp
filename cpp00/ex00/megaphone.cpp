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
        int j = 0;
        while (av[i][j])
        {
            char c = std::toupper(av[i][j]);
            std::cout << c;
            j++;
        }
    }
    std::cout<< '\n';
    return (0);
}
#include  "Harl.hpp"

int main(int ac,char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: you must enter the level" 
                    << std::endl;
        return (1);
    }
    std::string s = av[1];
    Harl Harl;
    Harl.complain(s);
    return (0);
}
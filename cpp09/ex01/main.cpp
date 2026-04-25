#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: to many or low argument \n";
        return (1);
    }
    std::string arg = av[1];
    try
    {
        RPN rpn;
        int res = rpn.pase_input(arg);
        std::cout << res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
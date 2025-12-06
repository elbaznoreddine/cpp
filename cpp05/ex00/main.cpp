#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b = Bureaucrat("noreddine", 100);
        std::cout << b << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::end;
        return (1);
    }
    return (0);
}
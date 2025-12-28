#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b = Bureaucrat();
        for (size_t i = 0; i < 151; i++)
        {
            std::cout << b << std::endl;
            b.incGrade();
        }
    }
    catch(std::exception &e)
    {

        std::cout << e.what() << std::endl;
    }
    return (0);
}
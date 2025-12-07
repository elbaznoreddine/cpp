#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b = Bureaucrat("noreddine", 101);

		Form f = Form("avatar", 10, 1);
		std::cout << f << std::endl;
        std::cout << b << std::endl;

		b.signForm(f);

    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
#include "Harl.hpp"

Harl::Harl(void){}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
                << std::endl;
}
void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
                << std::endl;
}
void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
                << std::endl;
}
void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now."
                << std::endl;
}
void Harl::invalid(void)
{
    std::cout << "invalid level" << std::endl;
}
void Harl::complain(std::string level)
{
    void (Harl::*ptr[])(void) = {&Harl::invalid, &Harl::debug, &Harl::info ,&Harl::warning, &Harl::error};
    int i = (("DEBUG" == level) * 1 +  ("INFO"== level) * 2 + ("WARNING"== level) * 3 + ("ERROR"== level) * 4);
    (this->*ptr[i])();
}

Harl::~Harl(void){}
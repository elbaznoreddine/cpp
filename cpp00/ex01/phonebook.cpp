#include <iostream>

// class PhoneBook
// {
//     public:

// }
// class Contact
// {
//     public:

// }
int main(int ac, char **av)
{

    if (ac > 2)
    {
        std::cout << "INVALID ARGS\n";
        return (1);
    }
    (void)av;
    std::string s;
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
    while (1)
    {
        std::cout << "enter :\n";
        std::cin >> s;
        if (s == "ADD")
        {
            std::cout << "enter first name\n";
            std::cin >> first_name;
            std::cout << "enter last name\n";
            std::cin >> last_name;
            std::cout << "enter nickname\n";
            std::cin >> nickname;
            std::cout << "enter phone number\n";
            std::cin >> phone_number;
            std::cout << "enter darkest secret\n";
            std::cin >> darkest_secret;
            break;
        }
        break ;
    }
    
}
#include "phonebook.hpp"

int are_print(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isprint(str[i]))
            return 0;
    return 1;
}

int are_digits(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
            return 0;
    return 1;
}

std::string get_printable_input(std::string prompt)
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        {
            std::cout << "\nEOF detected\n";
            return ("");
        }
        if (input.empty() || !are_print(input))
            std::cout << "Invalid input: cannot be empty or non-printable.\n";
        else
            break;
    }
    return input;
}

std::string get_numeric_input(std::string prompt)
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        {
            std::cout << "\nEOF detected\n";
            return ("");
        }
        if (input.empty() || !are_digits(input))
            std::cout << "Invalid input: must be numeric.\n";
        else
            break;
    }
    return input;
}

int main()
{
    PhoneBook p;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nEOF detected\n";
            break;
        }
        if (!are_print(command))
        {
            std::cout << "Error: command cannot be non-printable\n";
            continue;
        }

        if (command == "ADD")
        {
			std::string first_name  = get_printable_input("Enter first name:\n");
			if (first_name.empty())
				break;

			std::string last_name   = get_printable_input("Enter last name:\n");
			if (last_name.empty())
				break;

			std::string nickname    = get_printable_input("Enter nickname:\n");
			if (nickname.empty())
				break;

			std::string phone_number= get_numeric_input("Enter phone number:\n");
			if (phone_number.empty())
				break;

			std::string darkest_secret = get_printable_input("Enter darkest secret:\n");
			if (darkest_secret.empty())
				break;

			p.add_contact(first_name, last_name, nickname, phone_number, darkest_secret);
			std::cout << "Contact added successfully!\n";
		}
        else if (command == "SEARCH")
        {
			p.display_summary();
			std::string index_str = get_numeric_input("Enter the index of the contact to view:\n");
			
			if (index_str.empty())
				break;
			if (index_str.length() != 1)
			{
				std::cout << "Invalid index.\n";
				break ;
			}

			int index = index_str[0] - '0';
			p.display_details(index);
		}
        else if (command == "EXIT")
        {
            std::cout << "Goodbye!\n";
            break;
        }
        else
            std::cout << "Unknown command.\n";
    }
    return 0;
}

// int are_print(std::string str)
// {
// 	int lenght = str.length();
// 	for (int i = 0; i < lenght; i++)
// 	{
// 		if (!std::isprint(str[i]))
// 			return (0);
// 	}
// 	return (1);
// }
// int are_digits(std::string str)
// {
// 	int lenght = str.length();
// 	for (int i = 0; i < lenght; i++)
// 	{
// 		if (!std::isdigit(str[i]))
// 			return (0);
// 	}
// 	return (1);
// }
// int main(int ac, char **av)
// {
//     if (ac > 1)
// 	{
//         std::cout << "INVALID ARGS\n";
//         return 1;
//     }
//     (void)av;
//     std::string s;
//     std::string first_name, last_name, nickname, phone_number, darkest_secret;
//     PhoneBook p;

//     while (1)
// 	{
//         std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
//         if (!(std::getline(std::cin, s)))
// 		{
//             std::cout << "\nEOF detected\n";
//             break;
//         }
// 		if (!are_print(s))
// 		{
// 			std::cout << "Error: Field cannot be non-printable\n";
// 			continue ;
// 		}
//     	if (s == "ADD")
// 		{
// 			std::string first_name, last_name, nickname, phone_number, darkest_secret;

// 			while (true)
// 			{
// 				std::cout << "Enter first name:\n";
// 				if (!std::getline(std::cin, first_name))
// 				{
// 					std::cout << "\nEOF detected\n";
// 					return 0; 
// 				}
// 				if (first_name.empty() || !are_print(first_name))
// 				{
// 					std::cout << "Invalid input Field cannot be empty or non-printable.\n";
// 					continue;
// 				}
// 				break;
// 			}
// 			while (true)
// 			{
// 				std::cout << "Enter last name:\n";
// 				if (!std::getline(std::cin, last_name))
// 				{
// 					std::cout << "\nEOF detected\n";
// 					return 0;
// 				}
// 				if (last_name.empty() || !are_print(last_name))
// 				{
// 					std::cout << "Invalid input Field cannot be empty or non-printable.\n";
// 					continue;
// 				}
// 				break;
// 			}
// 			while (true)
// 			{
// 				std::cout << "Enter nickname:\n";
// 				if (!std::getline(std::cin, nickname))
// 				{
// 					std::cout << "\nEOF detected\n";
// 					return 0;
// 				}
// 				if (nickname.empty() || !are_print(nickname))
// 				{
// 					std::cout << "Invalid input Field cannot be empty or non-printable.\n";
// 					continue;
// 				}
// 				break;
// 			}
// 			while (true)
// 			{
// 				std::cout << "Enter phone number:\n";
// 				if (!std::getline(std::cin, phone_number))
// 				{
// 					std::cout << "\nEOF detected\n";
// 					return 0;
// 				}
// 				if (phone_number.empty() || !are_print(phone_number) ||
// 					!are_digits(phone_number))
// 				{
// 					std::cout << "Invalid input Phone must be numeric.\n";
// 					continue;
// 				}
// 				break;
// 			}
// 			while (true)
// 			{
// 				std::cout << "Enter darkest secret:\n";
// 				if (!std::getline(std::cin, darkest_secret))
// 				{
// 					std::cout << "\nEOF detected\n";
// 					return 0;
// 				}
// 				if (darkest_secret.empty() || !are_print(darkest_secret))
// 				{
// 					std::cout << "Invalid input Field cannot be empty or non-printable.\n";
// 					continue;
// 				}
// 				break;
// 			}

// 			p.add_contact(first_name, last_name, nickname, phone_number, darkest_secret);
// 			std::cout << "Contact added successfully!\n";
// 		}

//         else if (s == "SEARCH")
// 		{
//             p.display_summary();
//             std::cout << "Enter the index of the contact to view:\n";
//             std::string index_str;
//             if (!(std::getline(std::cin, index_str))) {
//                 std::cout << "\nEOF detected\n";
//                 break;
//             }
//             if (index_str.length() != 1 || !std::isdigit(index_str[0]))
// 			{
//                 std::cout << "Invalid index.\n";
//                 continue;
//             }
//             int index = index_str[0] - '0';
//             p.display_details(index);
//         }
//         else if (s == "EXIT")
// 		{
//             std::cout << "Goodbye!\n";
//             break;
//         }
//         else
// 		{
//             std::cout << "Unknown command.\n";
//         }
//     }
//     return 0;
// }

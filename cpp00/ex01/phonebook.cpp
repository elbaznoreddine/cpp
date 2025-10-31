#include "phonebook.hpp"

std::string PhoneBook::truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

PhoneBook::PhoneBook(void)
{
	i = 0;
	total_contacts = 0;
}

void PhoneBook::add_contact(std::string fname, std::string lname, std::string nname, std::string phone, std::string darkest)
{

    contacts[i].set_fname(fname);
    contacts[i].set_lname(lname);
    contacts[i].set_nname(nname);
    contacts[i].set_phone(phone);
    contacts[i].set_darkest(darkest);
    i = (i + 1) % 8;
    if (total_contacts < 8)
        total_contacts++;
}

void PhoneBook::display_summary(void)
{
    if (total_contacts == 0)
	{
        std::cout << "No contacts saved yet.\n";
        return;
    }
    std::cout << std::setw(10) << "index" << "|"
              << std::setw(10) << "first name" << "|"
              << std::setw(10) << "last name" << "|"
              << std::setw(10) << "nickname" << "|\n";

    for (int j = 0; j < total_contacts; j++) {
        std::cout << std::setw(10) << j << "|"
                  << std::setw(10) << truncate(contacts[j].get_fname()) << "|"
                  << std::setw(10) << truncate(contacts[j].get_lname()) << "|"
                  << std::setw(10) << truncate(contacts[j].get_nname()) << "|\n";
    }
}

void PhoneBook::display_details(int index)
{
    if (index < 0 || index >= total_contacts) {
        std::cout << "Error: Invalid index.\n";
        return;
    }
    std::cout << "\n--- Contact Details ---\n";
    std::cout << "First Name:     " << contacts[index].get_fname() << "\n";
    std::cout << "Last Name:      " << contacts[index].get_lname() << "\n";
    std::cout << "Nickname:       " << contacts[index].get_nname() << "\n";
    std::cout << "Phone Number:   " << contacts[index].get_phone() << "\n";
    std::cout << "Darkest Secret: " << contacts[index].get_darkest() << "\n\n";
}
PhoneBook::~PhoneBook(void){};
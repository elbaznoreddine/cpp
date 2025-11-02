#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include "Contact.hpp"


class PhoneBook {
private:
    Contact contacts[8];
    int i;
    int total_contacts;
    std::string truncate(std::string str);

public:
    PhoneBook(void);
    void add_contact(std::string fname, std::string lname, std::string nname, std::string phone, std::string darkest);
    void display_summary(void);
    void display_details(int index);
	~PhoneBook(void);
};


#endif
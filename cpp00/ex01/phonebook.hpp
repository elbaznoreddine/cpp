#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string first_name, last_name, nickname, phone_number, darkest_secret;
	public:
		Contact(void);
		Contact(std::string f, std::string l, std::string n, std::string p, std::string d);
		std::string	get_fname(void);
		std::string	get_lname(void);
		std::string	get_nname(void);
		std::string	get_phone(void);
		std::string	get_darkest(void);
        
        void set_fname(std::string new_fname);
		void set_lname(std::string new_lname);
		void set_nname(std::string new_nname);
		void set_phone(std::string new_phone);
		void set_darkest(std::string new_darkest);
		~Contact(void);
};

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
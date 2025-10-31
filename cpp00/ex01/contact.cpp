#include "Contact.hpp"


Contact::Contact(void){};

Contact::Contact(std::string f, std::string l, std::string n, std::string p, std::string d)
{
	first_name = f;
	last_name = l;
	nickname = n;
	phone_number = p;
	darkest_secret = d;
}
std::string	Contact::get_fname(void)
	{return first_name;}
std::string	Contact::get_lname(void)
	{return last_name;}
std::string	Contact::get_nname(void)
	{return nickname;}
std::string	Contact::get_phone(void)
	{return phone_number;}
std::string	Contact::get_darkest(void)
	{return darkest_secret;}

void Contact::set_fname(std::string new_fname)
	{first_name = new_fname;}
void Contact::set_lname(std::string new_lname)
	{last_name = new_lname;}
void Contact::set_nname(std::string new_nname)
	{nickname = new_nname;}
void Contact::set_phone(std::string new_phone)
	{phone_number = new_phone;}
void Contact::set_darkest(std::string new_darkest)
	{darkest_secret = new_darkest;}
Contact::~Contact(void){};
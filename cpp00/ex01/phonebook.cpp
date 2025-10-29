#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string first_name, last_name, nickname, phone_number, darkest_secret;
	public:
		Contact(){}
		Contact(std::string f, std::string l, std::string n, std::string p, std::string d)
		{
			first_name = f;
			last_name = l;
			nickname = n;
			phone_number = p;
			darkest_secret = d;
		}
		std::string	get_fname()
			{return first_name;}
		std::string	get_lname()
			{return last_name;}
		std::string	get_nname()
			{return nickname;}
		std::string	get_phone()
			{return phone_number;}
		std::string	get_darkest()
			{return darkest_secret;}
        
        void set_fname(std::string new_fname)
			{first_name = new_fname;}
		void set_lname(std::string new_lname)
			{last_name = new_lname;}
		void set_nname(std::string new_nname)
			{nickname = new_nname;}
		void set_phone(std::string new_phone)
			{phone_number = new_phone;}
		void set_darkest(std::string new_darkest)
			{darkest_secret = new_darkest;}
};
class PhoneBook {
private:
    Contact contacts[8];
    int i;
    int total_contacts;

    std::string truncate(std::string str)
	{
        return str;
        if (str.length() > 10)
            return str.substr(0, 9) + ".";
        return str;
    }

public:
    PhoneBook() : i(0), total_contacts(0) {}

    void add_contact(std::string fname, std::string lname, std::string nname, std::string phone, std::string darkest)
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

    void display_summary() {
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

    void display_details(int index) {
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
};

int main(int ac, char **av)
{
    if (ac > 1)
	{
        std::cout << "INVALID ARGS\n";
        return 1;
    }
    (void)av;
    std::string s;
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
    PhoneBook p;

    while (1)
	{
        std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;

        if (!(std::cin >> s))
		{
            std::cout << "\nEOF detected\n";
            break;
        }
        if (s == "ADD")
		{
            std::cout << "Enter first name:\n";
            if (!(std::cin >> first_name))
				break;
            std::cout << "Enter last name:\n";
            if (!(std::cin >> last_name))
				break;
            std::cout << "Enter nickname:\n";
            if (!(std::cin >> nickname))
				break;
            std::cout << "Enter phone number:\n";
            if (!(std::cin >> phone_number))
				break;
            std::cout << "Enter darkest secret:\n";
            if (!(std::cin >> darkest_secret))
				break;

            if (first_name.empty() || last_name.empty() || nickname.empty() ||
                phone_number.empty() || darkest_secret.empty())
			{
                std::cout << "Error: Fields cannot be empty.\n";
                continue;
            }
            p.add_contact(first_name, last_name, nickname, phone_number, darkest_secret);
        }
        else if (s == "SEARCH")
		{
            p.display_summary();
            std::cout << "Enter the index of the contact to view:\n";
            std::string index_str;
            if (!(std::cin >> index_str)) {
                std::cout << "\nEOF detected\n";
                break;
            }
            if (index_str.length() != 1 || !std::isdigit(index_str[0]))
			{
                std::cout << "Invalid index.\n";
                continue;
            }
            int index = index_str[0] - '0';
            p.display_details(index);
        }
        else if (s == "EXIT")
		{
            std::cout << "Goodbye!\n";
            break;
        }
        else
		{
            std::cout << "Unknown command.\n";
        }
    }

    return 0;
}

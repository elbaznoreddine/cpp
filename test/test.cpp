#include <iostream>

class PhoneBook
{
    private:
        Contact contact[8];
    public:
        void 
};

class Contact
{
    private:
        std::string first_name, last_name;
    public:
        PhoneBook(std::string x, std::string y)
        {
            first_name = x;
            last_name = y;
        }
        void print_class()
        {
            std::cout << first_name+" "+ last_name << std::endl;
        }
};
int main()
{
    PhoneBook p = PhoneBook("EL BAZ", "Noreddine");
    p.print_class();
}
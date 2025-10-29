#include <iostream>

// class PhoneBook
// {
//     private:
//         Contact contact[8];
//     public:
//         void 
// };

class PhoneBook
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
    std::string line;
    std::getline(std::cin, line);
    std::string line2;
    std::getline(std::cin, line2);
    PhoneBook p = PhoneBook(line, line2);
    p.print_class();
    
}
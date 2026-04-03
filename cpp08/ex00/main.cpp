#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::list<int> lst;
    lst.push_back(9);
    lst.push_back(8);
    lst.push_back(7);
    lst.push_back(6);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 1);
        std::cout << *it << std::endl;
        std::list<int>::iterator it1 = easyfind(lst, 8);
        std::cout << *it1 << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
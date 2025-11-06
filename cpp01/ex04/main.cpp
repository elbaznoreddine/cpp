#include <iostream>
#include <fstream>
int main (int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Error : more or less than 3 arguments" << std::endl;
        return (1);
    }
    std::ifstream ifile(av[1]);
    std::string str;
    std::string all;
    while (getline(ifile, str))
    {
        all.append(str);
        all.append("\n");
    }
    ifile.close();
    std::string s1 = av[2];
    std::string s2 = av[3];
    int pos = 0;
    std::string new_str;
    size_t index = all.find(s1);
    while (index != std::string::npos)
    {
        new_str.append(all.substr(pos, index - pos));
        new_str.append(s2);
        pos = index + s1.length();
        index = all.find(s1, pos);
    }
    
    new_str.append(all.substr(pos, all.length()));
    std::ofstream ofile("replaced.txt");
    ofile << new_str;
    ofile.close();

}
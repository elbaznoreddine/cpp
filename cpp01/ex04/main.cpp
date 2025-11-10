#include <iostream>
#include <fstream>
int main (int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Error : more or less than 3 arguments" << std::endl;
        return (1);
    }
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::ifstream ifile(av[1]);
    std::string str;
    std::string all;
    if (!ifile.is_open())
    {
        std::cout << "file not found" << std::endl;
        return (1);
    }
    while (getline(ifile, str))
    {
        all.append(str);
        if (!ifile.eof())
            all.append("\n");
    }
    ifile.close();
    std::string s = std::string(av[1]) + ".replace";
    std::ofstream ofile(s.c_str());
    if (!ofile.is_open())
    {
        std::cout << "can't create the file" << std::endl;
        return (1);
    }
    if (s1.empty())
    {
        ofile << all;
        ofile.close();
        return (0);
    }
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
    ofile << new_str;
    ofile.close();
    return (0);
}
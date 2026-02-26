#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& s)
{
    *this=s;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& s)
{
    (void)s;
    return (*this);
}
ScalarConverter::~ScalarConverter(){}

bool str_speciale(std::string str)
{
    if ((str.compare("nan") == 0) || (str.compare("nanf") == 0) 
        || (str.compare("-inf") == 0) || (str.compare("+inf") == 0)
        || (str.compare("-inff") == 0) || (str.compare("+inff") == 0))
    {
        std::cout << "char : impossible" << std::endl
                    << "int : impossible" << std::endl
                    << std::fixed
                    << std::setprecision(1)
                    << "float : nanf" << std::endl
                    << "double : nan" << std::endl;
        return true;
    }
    return false;
}
bool str_char(std::string str)
{
    if ((str.size() != 1) || !isalpha(str[0]))
        return false;
    return true;
}
// bool str_int(std::string str)
// {

// }
// bool str_double(std::string str)
// {

// }
// bool str_float(std::string str)
// {

// }
void str_impossible(std::string str)
{
    std::cout << "invalide format : " << str << std::endl;
    return;
}
void ScalarConverter::convert(std::string str)
{
    if (str_speciale(str))
        return;
    if (str_char(str))
        return;
    // if (str_int(str))
    //     return;
    // if (str_float(str))
    //     return;
    // if (str_double(str))
    //     return;
    str_impossible(str);
    return;
}
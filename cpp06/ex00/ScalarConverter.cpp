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

void display(double d) 
{
    std::cout << "char: ";
    if (d < 0 || d > 127 || d != d) 
    {
        std::cout << "impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<int>(d)))
    {
        std::cout << "Non displayable" << std::endl;
    }
    else
    {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }
    std::cout << "int: ";
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || d != d)
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << static_cast<int>(d) << std::endl;
    }
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}


bool str_speciale(std::string str) 
{
    if (str == "nan" || str == "nanf") 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return true;
    }
    if (str == "+inf" || str == "+inff") 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return true;
    }
    if (str == "-inf" || str == "-inff") 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return true;
    }
    return false;
}

bool str_char(std::string str) 
{
    if (str.length() != 1 || std::isdigit(str[0])) 
        return false;
    display(static_cast<double>(str[0]));
    return true;
}

bool str_int(std::string str) 
{
    for (size_t i = 0; i < str.length(); ++i) 
    {
        if (i == 0 && (str[i] == '-' || str[i] == '+')) 
            continue;
        if (!std::isdigit(str[i])) 
            return false;
    }
    display(std::strtod(str.c_str(), NULL));
    return true;
}

bool str_float(std::string str) 
{
    char* end;
    double d = std::strtod(str.c_str(), &end);
    
    if (*end != 'f' || *(end + 1) != '\0') 
        return false;
    display(d);
    return true;
}

bool str_double(std::string str) 
{
    char* end;
    double d = std::strtod(str.c_str(), &end);
    
    if (*end != '\0') 
        return false;
    display(d);
    return true;
}


void ScalarConverter::convert(std::string str)
{
    if (str_speciale(str))
        return;
    if (str_char(str))
        return;
    if (str_int(str))
        return;
    if (str_float(str))
        return;
    if (str_double(str))
        return;
    std::cout << "invalide format : " << str << std::endl;
    return;
}
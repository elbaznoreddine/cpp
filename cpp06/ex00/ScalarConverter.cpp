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

    if (str == "nan" || str == "nanf")
    {
        std::cout << "char : impossible\n"
                  << "int : impossible\n"
                  << "float : nanf\n"
                  << "double : nan\n";
        return true;
    }
    else if (str == "+inf" || str == "+inff")
    {
        std::cout << "char : impossible\n"
                  << "int : impossible\n"
                  << "float : +inff\n"
                  << "double : +inf\n";
        return true;
    }
    else if (str == "-inf" || str == "-inff")
    {
        std::cout << "char : impossible\n"
                  << "int : impossible\n"
                  << "float : -inff\n"
                  << "double : -inf\n";
        return true;
    }
    return false;
}
void valid_char(char c)
{
    if (!std::isprint(static_cast<unsigned char>(c)))
    {
        std::cout << "char : Non displayable\n";
        return;
    }
    std::cout << "char : '" << c << "'\n";
}
bool str_char(std::string str)
{
    if (str.length() != 1 || !isprint(str[0]) || isdigit(str[0]))
        return false;

    char c = str[0];
    valid_char(c);

    std::cout << "int : " << static_cast<int>(c) << "\n"
              << std::fixed
              << std::setprecision(1)
              << "float : " << static_cast<float>(c) << "f\n"
              << "double : " << static_cast<double>(c) << "\n";

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

    long i = atol(str.c_str());

    valid_char(i);

    std::cout << "int : " << i << std::endl
                << std::fixed
                << std::setprecision(1)
                << "float : " << static_cast<float>(i) << "f" << std::endl
                << "double : " << static_cast<double>(i)
                << std::endl;

    return true;
}
bool str_float(std::string str)
{
    char* end;
    float f = std::strtod(str.c_str(), &end);

    if ((*end != 'f' && *end != 'F') || *(end + 1) != '\0')
        return false;
    if (f < 0 || f > 127 || (f != f))
        std::cout << "char : impossible\n";
    else
        valid_char(static_cast<char>(f));

    std::cout << "int : " << static_cast<int>(f) << std::endl
                << std::fixed
                << std::setprecision(1)
                << "float : " << f << "f" << std::endl
                << "double : " << static_cast<double>(f)
                << std::endl;
    return true;
}
bool str_double(std::string str)
{
    char* end;
    double d = std::strtod(str.c_str(), &end);

    if (*end != '\0')
        return false;
    if (d < 0 || d > 127 || (d != d))
        std::cout << "char : impossible\n";
    else
        valid_char(static_cast<char>(d));

    std::cout << "int : " << static_cast<int>(d) << std::endl
                << std::fixed
                << std::setprecision(1)
                << "float : " << static_cast<float> (d)<< "f" << std::endl
                << "double : " << d
                << std::endl;
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
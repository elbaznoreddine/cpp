#pragma once

#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& s);
        ScalarConverter& operator=(const ScalarConverter& s);
        ~ScalarConverter();
    public:
        static void convert(std::string str);
};

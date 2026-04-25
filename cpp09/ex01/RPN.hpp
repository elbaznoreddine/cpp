#pragma once

#include<iostream>
#include<stack>
#include<sstream>
#include<stdlib.h>


class RPN
{
    private:
        std::stack<unsigned int> s;
    public:
        RPN();
        RPN(const RPN& r);
        RPN& operator=(const RPN& r);
        ~RPN();
        int pase_input(std::string arg);
};
#pragma once

#include<iostream>
#include<stack>
#include<sstream>
#include<stdlib.h>
#include<limits>
#include<list>


class RPN
{
    private:
        std::stack<int, std::list<int> > s;
    public:
        RPN();
        RPN(const RPN& r);
        RPN& operator=(const RPN& r);
        ~RPN();
        int pase_input(std::string arg);
        int check_res(long res);
};
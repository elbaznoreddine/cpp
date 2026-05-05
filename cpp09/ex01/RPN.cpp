#include "RPN.hpp"

RPN::RPN(){};

RPN::RPN(const RPN& r): s(r.s){}

RPN& RPN::operator=(const RPN& r)
{
    if (this != &r)
        this->s = r.s;
    return (*this);
}

RPN::~RPN(){}

int RPN::check_res(long res)
{
    if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
        throw std::runtime_error("Error: the result overflow");
    return (static_cast<int>(res));
}
int  RPN::pase_input(std::string arg)
{
    std::stringstream ss(arg);
    std::string token;
    while (ss >> token)
    {
        if (token == "-" || token == "+" || token == "*" || token == "/")
        {
            if (s.size() < 2)
                throw std::runtime_error("Error: calculation can't be done");
            long first = s.top();
            s.pop();
            long last = s.top();
            s.pop();
            if (token == "-")
            {
                long res = last - first;
                s.push(check_res(res));
            }
            else if (token == "+")
            {
                long res = last + first;
                s.push(check_res(res));

            }
            else if (token == "*")
            {
                long res = last * first;
                s.push(check_res(res));

            }
            else if (token == "/")
            {
                if (first == 0)
                    throw std::runtime_error("Error: the denominator can't be 0");
                long res = last / first;
                s.push(check_res(res));
            }
        }
        else if (token.size() > 1)
        {
            throw std::runtime_error("the number must be in range of 0-9");
        }
        else if(token.size() == 1 && isdigit(token[0]))
        {
            int ss  = std::atoi(token.c_str());
            s.push(ss);
        }
        else 
        {
            throw std::runtime_error("Error: invalid token");
        }
        
    }
    if (s.size() != 1)
        throw std::runtime_error("Error: no operator found to do the calculation");
    return (s.top());
}
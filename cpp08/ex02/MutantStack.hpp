#pragma once
#include <iostream>
#include <stack>
#include <list>


template <typename T>
class MutantStack : public std::stack<T>
{
    public :
        MutantStack(){}
		MutantStack(const MutantStack &m): std::stack<T>(m){}
		MutantStack &operator=(const MutantStack &m)
        {
            if (this != &m)
                std::stack<T>::operator=(m);
            return (*this);
        }
        ~MutantStack(){}
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};
#pragma once 

#include <iostream>
#include <vector>
#include <algorithm>
class Span
{
    private:
        unsigned int max;
        std::vector<int> span;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& s);
        Span& operator=(const Span& s);
        ~Span();
        void addNumber(int nbr);
        template <typename T> void addNumbers(T beginit, T endit)
        {
            int size = std::distance(beginit, endit);
            if (size < 0 || static_cast<unsigned int > (size) + span.size() > max)
                throw std::runtime_error("invalid range");
            span.insert(span.end(), beginit, endit);
            
        }
        int shortestSpan();
        int longestSpan();
};
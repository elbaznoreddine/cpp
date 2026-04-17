#include "Span.hpp"

Span::Span()
{}
Span::Span(unsigned int N): max(N)
{}
Span::Span(const Span& s)
{
    max = s.max;
    span = s.span;
}
Span &Span::operator=(const Span& s)
{
    if (this != &s)
    {
        max = s.max;
        span = s.span;
    }
    return (*this);
}

Span::~Span()
{
    span.clear();
}

void Span::addNumber(int nbr)
{
    if (span.size() > (size_t)max)
        throw std::runtime_error("max reached");
    span.push_back(nbr);
}

int Span::shortestSpan()
{
    if (span.size() <= 1)
        throw std::runtime_error("no span can be found");

    std::vector<int> tmp = span;
    std::sort(tmp.begin(), tmp.end());

    unsigned int short_span = tmp[1] - tmp[0];

    for (size_t i = 1; i < tmp.size(); ++i)
    {
        unsigned int diff = tmp[i] - tmp[i - 1];
        if (diff < short_span)
            short_span = diff;
    }

    return short_span;
}

int Span::longestSpan()
{
    if (span.size() <= 1)
        throw std::runtime_error("no span can found");
    unsigned int max = *std::max_element(span.begin(), span.end());
    unsigned int min = *std::min_element(span.begin(), span.end());
    return max - min;
}
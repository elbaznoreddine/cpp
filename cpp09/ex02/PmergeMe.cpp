#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& p) : sequence(p.sequence), secondSequence(p.secondSequence) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& p) {
    if (this != &p) {
        sequence = p.sequence;
        secondSequence = p.secondSequence;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parse(std::string arg) {
    for (size_t i = 0; i < arg.size(); i++) {
        if (!isdigit(arg[i]))
           throw std::runtime_error("Error: non-digit character detected.");
    }
    
    long nbr = std::atol(arg.c_str());
    if (nbr < 0)
        throw std::runtime_error("Error: number is not positive.");
    sequence.push_back(static_cast<int>(nbr));
    secondSequence.push_back(static_cast<int>(nbr));
}

void PmergeMe::showBefore() {
    std::cout << "Before: ";
    for(size_t i = 0; i < sequence.size(); i++) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::showAfter() {
    std::cout << "After:  ";
    for(size_t i = 0; i < sequence.size(); i++) {
        std::cout << sequence[i] << " ";
    }
    std::cout << sequence.size()<< std::endl;
}

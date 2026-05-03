#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <sys/time.h>
#include <utility>
#include <algorithm>

class PmergeMe
{
private:
        std::vector<int> sequence;
        std::deque<int>  secondSequence;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& p);
        PmergeMe& operator=(const PmergeMe& p);
        ~PmergeMe();

        void parse(std::string arg);
        void sort();
        void showBefore();
        void showAfter();
};
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& p) : sequence(p.sequence), deque_seq(p.deque_seq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& p) {
    if (this != &p) {
        sequence = p.sequence;
        deque_seq = p.deque_seq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parse(std::string arg) {
    for (size_t i = 0; i < arg.size(); i++) 
    {
        if (!isdigit(arg[i]))
           throw std::runtime_error("Error: non-digit character detected.");
    }
    
    long nbr = std::atol(arg.c_str());
    if (nbr < 0)
        throw std::runtime_error("Error: number is not positive.");
    sequence.push_back(static_cast<int>(nbr));
    deque_seq.push_back(static_cast<int>(nbr));
}

void PmergeMe::showBefore()
{
    std::cout << "Before: ";
    for(size_t i = 0; i < sequence.size(); i++) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::showAfter(long usecVec)
{
    std::cout << "After:  ";
    for(size_t i = 0; i < sequence.size(); i++)
    {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;

     std::cout << "Time to process a range of " << sequence.size()
                << " elements with std::vector : "
                << usecVec << " us" << std::endl;
}
std::vector<int> PmergeMe::buildT(int maxNeeded)
{
    std::vector<int> t;
    t.push_back(0); 
    t.push_back(1); 

    int k = 2;
    while (true)
    {
        int sign = -1;
        if (k % 2 == 0)
        {
            sign = 1;
        }

        int val = ((1 << (k + 1)) + sign) / 3;
        t.push_back(val);
        if (val >= maxNeeded)
        {
            break;
        }
        k++;
    }
    return t;
}

std::deque<int> PmergeMe::buildTD(int maxNeeded)
{
    std::deque<int> t;
    t.push_back(0); 
    t.push_back(1); 

    int k = 2;
    while (true)
    {
        int sign = -1;
        if (k % 2 == 0)
        {
            sign = 1;
        }

        int val = ((1 << (k + 1)) + sign) / 3;
        t.push_back(val);
        if (val >= maxNeeded)
        {
            break;
        }
        k++;
    }
    return t;
}

std::vector<int> PmergeMe::mergeInsertVec(std::vector<int> data)
{

    if (data.size() <= 1)
        return data;

    std::vector<std::pair<int, int> > pairs;
    int leftover = -1;
    bool hasLeftover = false;

    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {
        if (data[i] > data[i + 1])
        {
            pairs.push_back(std::make_pair(data[i], data[i + 1]));
        } else
        {
            pairs.push_back(std::make_pair(data[i + 1], data[i]));
        }
    }
    
    if (data.size() % 2 != 0)
    {
        leftover = data.back();
        hasLeftover = true;
    }
    std::vector<int> larger;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        larger.push_back(pairs[i].first);
    }

    larger = mergeInsertVec(larger);

    std::vector<bool> used(pairs.size(), false);
    std::vector<std::pair<int, int> > renamed;

    for (size_t i = 0; i < larger.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!used[j] && pairs[j].first == larger[i])
            {
                renamed.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    std::vector<int> chain;
    if (!renamed.empty())
    {
        chain.push_back(renamed[0].second);
    }
    for (size_t i = 0; i < renamed.size(); i++)
    {
        chain.push_back(renamed[i].first);
    }
    std::vector<int> bElems;
    for (size_t i = 0; i < renamed.size(); i++)
    {
        bElems.push_back(renamed[i].second);
    }
    if (hasLeftover)
    {
        bElems.push_back(leftover);
    }
    int totalB = static_cast<int>(bElems.size());
    if (totalB > 1)
    { 
        std::vector<int> t = buildT(totalB);

        for (size_t k = 2; k < t.size(); k++)
        {
            
            int batchEnd = t[k];
            if (t[k] >= totalB)
            {
                batchEnd = totalB;
            }

            int batchStart = t[k - 1] + 1;

            for (int idx = batchEnd; idx >= batchStart; idx--)
            {
                int value = bElems[idx - 1];
                std::vector<int>::iterator bound = chain.end();
                if (idx - 1 < static_cast<int>(renamed.size()))
                {
                    int aPartner = renamed[idx - 1].first;
                    for (std::vector<int>::iterator it = chain.begin(); it != chain.end(); ++it)
                    {
                        if (*it == aPartner)
                        {
                            bound = it;
                            break;
                        }
                    }
                }
                
                std::vector<int>::iterator insertPos = std::lower_bound(chain.begin(), bound, value);
                chain.insert(insertPos, value);
            }
        }
    }
    return chain;
}


std::deque<int> PmergeMe::mergeInsertDeq(std::deque<int> data)
{

    if (data.size() <= 1)
        return data;

    std::deque<std::pair<int, int> > pairs;
    int leftover = -1;
    bool hasLeftover = false;

    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {
        if (data[i] > data[i + 1])
        {
            pairs.push_back(std::make_pair(data[i], data[i + 1]));
        } else
        {
            pairs.push_back(std::make_pair(data[i + 1], data[i]));
        }
    }
    
    if (data.size() % 2 != 0)
    {
        leftover = data.back();
        hasLeftover = true;
    }
    std::deque<int> larger;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        larger.push_back(pairs[i].first);
    }

    larger = mergeInsertDeq(larger);

    std::deque<bool> used(pairs.size(), false);
    std::deque<std::pair<int, int> > renamed;

    for (size_t i = 0; i < larger.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!used[j] && pairs[j].first == larger[i])
            {
                renamed.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    std::deque<int> chain;
    if (!renamed.empty())
    {
        chain.push_back(renamed[0].second);
    }
    for (size_t i = 0; i < renamed.size(); i++)
    {
        chain.push_back(renamed[i].first);
    }
    std::deque<int> bElems;
    for (size_t i = 0; i < renamed.size(); i++)
    {
        bElems.push_back(renamed[i].second);
    }
    if (hasLeftover)
    {
        bElems.push_back(leftover);
    }
    int totalB = static_cast<int>(bElems.size());
    if (totalB > 1)
    { 
        std::deque<int> t = buildTD(totalB);

        for (size_t k = 2; k < t.size(); k++)
        {
            
            int batchEnd = t[k];
            if (t[k] >= totalB)
            {
                batchEnd = totalB;
            }

            int batchStart = t[k - 1] + 1;

            for (int idx = batchEnd; idx >= batchStart; idx--)
            {
                int value = bElems[idx - 1];
                std::deque<int>::iterator bound = chain.end();
                if (idx - 1 < static_cast<int>(renamed.size()))
                {
                    int aPartner = renamed[idx - 1].first;
                    for (std::deque<int>::iterator it = chain.begin(); it != chain.end(); ++it)
                    {
                        if (*it == aPartner)
                        {
                            bound = it;
                            break;
                        }
                    }
                }
                
                std::deque<int>::iterator insertPos = std::lower_bound(chain.begin(), bound, value);
                chain.insert(insertPos, value);
            }
        }
    }
    return chain;
}
void PmergeMe::sort()
{
    sequence = mergeInsertVec(sequence);
    deque_seq = mergeInsertDeq(deque_seq); 
}
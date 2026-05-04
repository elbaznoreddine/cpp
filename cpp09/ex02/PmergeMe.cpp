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
    for (size_t i = 0; i < arg.size(); i++) 
    {
        if (!isdigit(arg[i]))
           throw std::runtime_error("Error: non-digit character detected.");
    }
    
    long nbr = std::atol(arg.c_str());
    if (nbr < 0)
        throw std::runtime_error("Error: number is not positive.");
    sequence.push_back(static_cast<int>(nbr));
    secondSequence.push_back(static_cast<int>(nbr));
}

void PmergeMe::showBefore()
{
    std::cout << "Before: ";
    for(size_t i = 0; i < sequence.size(); i++) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::showAfter()
{
    std::cout << "After:  ";
    for(size_t i = 0; i < sequence.size(); i++)
    {
        std::cout << sequence[i] << " ";
    }
    std::cout << sequence.size()<< std::endl;
}

int PmergeMe::floorLog2(int x)
{
    int k = 0;
    while ((1 << (k + 1)) <= x)
        k++;
    return k;
}

std::vector<int> PmergeMe::buildT(int maxNeeded)
{
    std::vector<int> t;
    t.push_back(0); 
    t.push_back(1); 

    int k = 2;
    while (true) {
        int sign;
        if (k % 2 == 0)
            sign = 1;
        else
            sign = -1;

        int val = ((1 << (k + 1)) + sign) / 3;
        t.push_back(val);
        if (val >= maxNeeded)
            break;
        k++;
    }
    return t;
}

// --- VECTOR PATH ---

void PmergeMe::binaryInsertVec(std::vector<int>& chain, int value, int rightBound)
{
    int lo = 0;
    int hi = rightBound;

    while (lo < hi)
    {
        int size = hi - lo;
        int k = floorLog2(size);
        
        int a = size - (1 << k);
        int b = (1 << (k - 1)) - 1;
        
        int offset;
        if (a > b)
            offset = a;
        else
            offset = b;

        int pivot = lo + offset;

        if (value < chain[pivot])
            hi = pivot;
        else
            lo = pivot + 1;
    }
    chain.insert(chain.begin() + lo, value);
}

std::vector<int> PmergeMe::mergeInsertVec(std::vector<int> data)
{
    if (data.size() <= 1) return data;

    // Phase 1: Pairwise comparison
    std::vector<std::pair<int, int> > pairs;
    int leftover = -1;
    bool hasLeftover = false;

    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {
        if (data[i] > data[i + 1])
            pairs.push_back(std::make_pair(data[i], data[i + 1]));
        else
            pairs.push_back(std::make_pair(data[i + 1], data[i]));
    }
    if (data.size() % 2 != 0)
    {
        leftover = data.back();
        hasLeftover = true;
    }

    // Phase 2: Sort larger elements
    std::vector<int> larger;
    for (size_t i = 0; i < pairs.size(); i++)
        larger.push_back(pairs[i].first);

    larger = mergeInsertVec(larger);

    // Renaming (mapping b-elements to sorted a-elements)
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

    // Build initial chain
    std::vector<int> chain;
    chain.push_back(renamed[0].second); // b1
    for (size_t i = 0; i < renamed.size(); i++)
        chain.push_back(renamed[i].first); // a1, a2...

    // Collect all elements to be inserted
    std::vector<int> bElems;
    for (size_t i = 0; i < renamed.size(); i++)
        bElems.push_back(renamed[i].second);
    if (hasLeftover)
        bElems.push_back(leftover);

    int totalB = static_cast<int>(bElems.size());
    std::vector<int> t = buildT(totalB);

    //Jacobsthal Batch Insertion
    for (size_t k = 2; k < t.size(); k++)
    {
        int batchEnd;
        if (t[k] < totalB)
            batchEnd = t[k];
        else
            batchEnd = totalB - 1;

        int batchStart = t[k - 1] + 1;

        for (int idx = batchEnd; idx >= batchStart; idx--)
        {
            int value = bElems[idx - 1];
            int rightBound = static_cast<int>(chain.size());
            if (idx - 1 < static_cast<int>(renamed.size()))
            {
                int aPartner = renamed[idx - 1].first;
                for (int c = 0; c < static_cast<int>(chain.size()); c++)
                {
                    if (chain[c] == aPartner)
                    {
                        rightBound = c;
                        break;
                    }
                }
            }
            binaryInsertVec(chain, value, rightBound);
        }
    }
    return chain;
}
void PmergeMe::sort()
{
    struct timeval startVec, endVec;
    gettimeofday(&startVec, NULL);
 
    sequence = mergeInsertVec(sequence);
 
    gettimeofday(&endVec, NULL);
 
    long usecVec = (endVec.tv_sec  - startVec.tv_sec)  * 1000000L
                 + (endVec.tv_usec - startVec.tv_usec);
    showAfter();
 
    std::cout << "Time to process a range of " << sequence.size()
              << " elements with std::vector : "
              << usecVec << " us" << std::endl;
}
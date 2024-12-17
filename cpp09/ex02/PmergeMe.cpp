#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) : vec(copy.vec), deq(copy.deq) {} 

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{ 
    if (this != &copy)
    { 
        vec = copy.vec;
        deq = copy.deq; 
    } 
    return *this;
} 

PmergeMe::~PmergeMe(){}

void PmergeMe::printContainerVector(const std::vector<int>& container)
{
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& container, int start, int end)
{
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeInsertSortVector(container, start, mid);
    mergeInsertSortVector(container, mid + 1, end);
    merge(container, start, mid, end);
}

void PmergeMe::merge(std::vector<int>& container, int start, int mid, int end)
{
    std::vector<int> left;
    for (int i = start; i <= mid; ++i){
        left.push_back(container[i]);
    }
    std::vector<int> right;
    for (int i = mid + 1; i <= end; ++i) {
        right.push_back(container[i]);
    }
    size_t i = 0, j = 0, k = start;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j]) {
            container[k++] = left[i++]; 
        } else {
            container[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        container[k++] = left[i++];
    }

    while (j < right.size()) {
        container[k++] = right[j++];
    }
}

int PmergeMe::checkAtoi(char* av)
{
    long long tmp;
    std::string str(av);
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (av[i] < '0' || av[i] > '9')
            throw(std::runtime_error("Invalid Character."));
    }
    tmp = atol(av);
    if (tmp > INT_MAX)
        throw(std::runtime_error("Invalid Number."));
    return (static_cast<int>(tmp));
}

void PmergeMe::run(int argc, char* argv[])
{
    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i)
    {
        int num = checkAtoi(argv[i]);
        vec.push_back(num);
        deq.push_back(num);
    }
   
    std::cout << "Before: ";
    printContainerVector(vec);
    std::cout << std::endl;
    clock_t start = clock();
    int start_c = 0;
    int end_c = vec.size() - 1;
    mergeInsertSortVector(vec,start_c,end_c);
    clock_t end = clock();
    double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    printContainerVector(vec);
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector: " << vecTime << " us\n";
    
}
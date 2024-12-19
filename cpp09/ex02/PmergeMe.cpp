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

void PmergeMe::printContainerVector(std::vector<int>& container)
{
    for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it)
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
    mergeSortVector(container, start, mid, end);
}

void PmergeMe::mergeSortVector(std::vector<int>& container, int start, int mid, int end)
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
            container[k] = left[i]; 
            k++;
            i++;
        } else {
            container[k] = right[j];
            k++;
            j++;
        }
    }

    while (i < left.size()) {
        container[k] = left[i];
        k++;
        i++;
    } 

    while (j < right.size()) {
        container[k] = right[j];
        k++;
        j++;
    }
}

//----------- deque :

void PmergeMe::printContainerDeque(std::deque<int>& container)
{
    for (std::deque<int>::iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& container, int start, int end)
{
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;
    mergeInsertSortDeque(container, start, mid);
    mergeInsertSortDeque(container, mid + 1, end);
    mergeSortDeque(container, start, mid, end);
}

void PmergeMe::mergeSortDeque(std::deque<int>& container, int start, int mid, int end)
{
    std::deque<int> left;
    for (int i = start; i <= mid; ++i){
        left.push_back(container[i]);
    }

    std::deque<int> right;
    for (int i = mid + 1; i <= end; ++i) {
        right.push_back(container[i]);
    }
    
    size_t i = 0, j = 0, k = start;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j]) {
            container[k] = left[i]; 
            k++;
            i++;
        } else {
            container[k] = right[j];
            k++;
            j++;
        }
    }

    while (i < left.size()) {
        container[k] = left[i];
        k++;
        i++;
    } 

    while (j < right.size()) {
        container[k] = right[j];
        k++;
        j++;
    }
}

int PmergeMe::checkAtoi(char* av)
{
    long long tmp;
    std::string str(av);
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (av[i] < '0' || av[i] > '9')
            throw(std::runtime_error("Error"));
    }
    tmp = atol(av);
    if (tmp > INT_MAX)
        throw(std::runtime_error("Error"));
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

    clock_t start_vec = std::clock();
    int start_c = 0;
    int end_c = vec.size() - 1;
    mergeInsertSortVector(vec,start_c,end_c);
    clock_t end_vec = std::clock();
    double vecTime = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;;

    clock_t start_deq = std::clock();
    start_c = 0;
    end_c = deq.size() - 1;
    mergeInsertSortDeque(deq,start_c,end_c);
    clock_t end_deq = std::clock();
    double deqTime = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;;

    std::cout << "After: ";
    printContainerVector(vec);
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector: " << vecTime << " us\n";

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque: " << deqTime << " us\n";
    
}
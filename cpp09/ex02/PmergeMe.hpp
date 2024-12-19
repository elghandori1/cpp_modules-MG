#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cstdlib> 
#include <iomanip>
#include <climits>

class PmergeMe
{
private:
    std::vector<int> vec;
    std::deque<int> deq;
    int checkAtoi(char* av);
public:
    PmergeMe();
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &copy);
    ~PmergeMe();
    void run(int argc, char* argv[]);
    void printContainerVector(std::vector<int>& container);
    void mergeInsertSortVector(std::vector<int>& container, int start, int end);
    void mergeSortVector(std::vector<int>& container, int start, int mid, int end);
    
    void printContainerDeque(std::deque<int>& container);
    void mergeInsertSortDeque(std::deque<int>& container, int start, int end);
    void mergeSortDeque(std::deque<int>& container, int start, int mid, int end);

};

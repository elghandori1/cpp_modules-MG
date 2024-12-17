#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    try
    {
    if (argc < 2)
    {
        throw(std::runtime_error("Error."));
    }
        PmergeMe pm;
        pm.run(argc, argv);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
   
    return 0;
}

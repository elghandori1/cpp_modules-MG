#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Error file" << std::endl;
        return 1;
    }
    try {
        RPN rpn(argv[1]);
        RPN r2(rpn);
        r2.getResult();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

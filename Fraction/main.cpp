#include"head.hpp"

int main()
{
    Fraction A(4, 5, 2);
    Fraction B(5, 2, 5);
    B = A + B;
    std::cout << B << std::endl;
    B--;
    bool temp = A < B;
    std::cout << temp << std::endl;
    return 0;
}
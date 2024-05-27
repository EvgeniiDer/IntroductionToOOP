#include"head.h"

int main()
{
    Matrix m1(1);
    Matrix m2;
    bool b = m2 != m1;
    std::cout << b << std::endl;
    return 0;
}
#include"head.hpp"

int main()
{
    Point p1(3.4, 5.2);
    Point p2(1.1 , 4.4);
    std::cout << distance(p2) << std::endl; //Distance from Zero to Point p2
    std::cout << distance(p1, p2) << std::endl;//Distance from p1 to p2
    return 0;
}
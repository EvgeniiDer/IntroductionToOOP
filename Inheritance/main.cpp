#include"head.hpp"

int main()
{
    Line line;
    Point p(0, 0);
    Point p2(2, 10);
    line.draw(Matrix(10, 10), p, p2);
    
    return 0;
}
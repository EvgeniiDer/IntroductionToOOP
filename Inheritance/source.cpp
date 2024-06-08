#include"head.hpp"

void Line::draw(const Matrix& mat, Point& x, Point& y)
{
    int line = y.get_y() / (y.get_x());
    int line_y = line;
    for(int i = 0; i < mat.get_row(); i ++)
        {
            for(int j = 0; j < mat.get_colms(); j++)
                {
                    if(i == x.get_x() && j == x.get_y() && x.get_y() < y.get_y() && x.get_x() < y.get_y())
                    { 
                        int newX_y = x.get_y();
                        int newX_x = x.get_x();
                        if(x.get_y() < line_y)
                            {
                                x.set_y(++newX_y);
                                std::cout << '*';
                            }
                        else{
                            x.set_x(++newX_x);
                            line_y += line; 
                        }
                    }
                    else{
                        std::cout << ' ';
                    }
                }
            std::cout << std::endl;
        }
}
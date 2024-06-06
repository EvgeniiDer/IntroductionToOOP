#ifndef HEAD_HPP_
#define HEAD_HPP_
#include<iostream>

class Matrix{
    private:
        int m_row;
        int m_colms;
        int** matrix;
    public:
        int get_row()
        {
            return m_row;
        }
        int get_colms()
        {
            return m_colms;
        }
        void set_row(const int& r)
        {
            m_row = r;
        }
        void set_colms(const int& c)
        {
            m_colms = c;
        }
        explicit Matrix() : m_row(100),
                   m_colms(100),
                   matrix(new int*[m_row])
                 {
                    for(int i = 0; i < m_row; i++)
                        matrix[i] = new int[m_colms];
                 }
        explicit Matrix(const int& _row = 100, const int& _colms = 100): m_row(_row),
                                                                m_colms(_colms),
                                                                matrix(new int*[m_row])
        {
            for(int i = 0; i < m_row; i++)
                matrix[i] = new int[m_colms];
        }
        ~Matrix(){
            for(int i =0 ; i < m_row; i++)
                delete[] matrix[i];
            delete[]matrix;
        }
};

struct Figure{
    virtual ~Figure(){};

    virtual void draw() = 0;
};
class Point{
    private:
        int x, y;
    public:
        explicit Point() : x(0.0), y(0.0){};
        explicit Point(const int& _x, const int& _y): x(_x), y(_y){};
};
class Line: public Figure{
    private:
        Point x, y;
    public:
        explicit Line() : x(Point(0 , 0)),
                 y(Point(0 , 0)){}
        explicit Line(const Point& _x, const Point& _y) : x(_x),
                                                 y(_y){}
        virtual void draw(const Matrix& _mat, const Point& _x, const Point& _y);
};
/*class Rectangle: public Figure{
    private:
    public:
};
class Circle: public Figure{
    private:
    public:
};
class Triangle: public Figure{
    private:
    public:
};*/
#endif
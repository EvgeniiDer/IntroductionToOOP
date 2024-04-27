#ifndef HEAD_HPP_
#define HEAD_HPP_
#include<iostream>
#include<cmath>

class Point;

    double distance(const Point& _arg);
    double distance(const Point& _a, const Point& _b);

class Point{
    private:
        double x;
        double y;
    public:
        Point(): x(0.0), y(0.0){};
        Point(const Point& _arg) : x(_arg.x), y(_arg.y){};
        Point(const double& _x, const double& _y) : x(_x), y(_y){};
        Point& operator=(const Point& _arg)
        {
            this->x = _arg.x;
            this->y = _arg.y;
            return *this;
        }
        Point(Point&& _arg){
            this->x = _arg.x;
            this->y = _arg.y;
            _arg.x = 0.0;
            _arg.y = 0.0;
        }
        Point& operator=(Point&& _arg){
            this->x = _arg.x;
            this->y = _arg.y;
            _arg.x = 0.0;
            _arg.y = 0.0;
            return *this;
        }
        void set_x(const double& _n);
        void set_y(const double& _n);
        double get_x()const;
        double get_y()const;
        double distance(const Point& _arg);
        double distance(const Point& _a, const Point& _b);
        ~Point(){};
};


#endif
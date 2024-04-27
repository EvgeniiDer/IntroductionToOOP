#include"head.hpp"

    void Point::set_x(const double& _n)
    {
        this->x = _n;
    }
    void Point::set_y(const double& _n)
    {
        this->y = _n;
    }
    double Point::get_x()const
    {
        return this->x;
    }
    double Point::get_y()const
    {
        return this->y;
    }
    double Point::distance(const Point& _arg)
    {
        double AC = _arg.x - this->x;
        double BC = _arg.y - this->y;
        return std::sqrt(AC * AC + BC * BC);
    }
    double Point::distance(const Point& _a, const Point& _b)
    {
        double AC = _b.x - _a.x;
        double BC = _b.y - _a.y;
        return std::sqrt(AC * AC + BC * BC);
    }
        double distance(const Point& _arg)
    {
        double AC = _arg.get_x() - 0;
        double BC = _arg.get_y() - 0;
        return std::sqrt(AC * AC + BC * BC);
    }
    double distance(const Point& _a, const Point& _b)
    {
        double AC = _b.get_x() - _a.get_x();
        double BC = _b.get_y() - _a.get_y();
        return std::sqrt(AC * AC + BC * BC);
    }
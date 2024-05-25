#ifndef HEAD_HPP_
#define HEAD_HPP_
#include<iostream>
#include<string>

class Fraction{
    private:
        int integer;
        int numerator;
        int denominator;
    public:
        int get_integer()
        {
            return integer;
        }
        int get_numerator()
        {
            return numerator;
        }
        int get_denominator()
        {
            return denominator;
        }
        void set_integer(const int& _arg)
        {
            integer = _arg;
        }
        void set_numerator(const int& _arg)
        {
            numerator = _arg;
        }
        void set_denominator(const int& _arg)
        {
            denominator = _arg;
        }
        Fraction(): integer(0),
                    numerator(0),
                    denominator(1){}
        Fraction(const int& _integer, const int& _numerator, const int& _denominator): integer(_integer),
                                                                                        numerator(_numerator),
                                                                                      denominator(_denominator){}
        
        Fraction(const Fraction& _arg);
        Fraction(Fraction&& _arg);
        Fraction& operator=(const Fraction& _arg);
        Fraction& operator=(Fraction&& _arg);
        ~Fraction(){}
        Fraction& operator+(const Fraction& _arg);
        Fraction& operator-(const Fraction& _arg);
        Fraction& operator*(const Fraction& _arg);
        Fraction& operator/(const Fraction& _arg);
        Fraction& operator++();
        Fraction& operator--();
        Fraction& operator+=(const int& _arg);
        Fraction& operator-=(const int& _arg);
        Fraction& operator*=(const int& _arg);
        Fraction& operator/=(const int& _arg);

        friend std::ostream& operator<<(std::ostream& os, const Fraction& _arg);
        friend std::istream& operator>>(std::istream& is, Fraction& _arg);

        bool operator==(const Fraction& _arg);
        bool operator<=(const Fraction& _arg);
        bool operator>=(const Fraction& _arg);
        bool operator!=(const Fraction& _arg);
        bool operator<(const Fraction& _arg);
        bool operator>(const Fraction& _arg);

};

#endif
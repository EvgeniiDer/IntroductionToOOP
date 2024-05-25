#include"head.hpp"

Fraction::Fraction(const Fraction& _arg)
{
    this->set_integer(_arg.integer);
    this->set_denominator(_arg.denominator);
    this->set_numerator(_arg.numerator);
}
Fraction::Fraction(Fraction&& _arg)
{
    this->integer = std::move(_arg.integer);
    this->numerator = std::move(_arg.numerator);
    this->denominator = std::move(_arg.denominator);
}
Fraction& Fraction::operator=(const Fraction& _arg)
{
    this->integer = _arg.integer;
    this->numerator = _arg.numerator;
    this->denominator = _arg.denominator;
    return *this;
}
Fraction& Fraction::operator=(Fraction&& _arg)
{
    this->integer = std::move(_arg.integer);
    this->numerator = std::move(_arg.numerator);
    this->denominator = std::move(_arg.denominator);
    return *this;
}
std::ostream& operator<<(std::ostream& os, const Fraction& _arg)
{
    if (_arg.integer)
        os << _arg.integer;
	if (_arg.numerator)
		{
			if (_arg.integer)
                os << "(";
			    os << _arg.numerator << "/" << _arg.denominator;
			if (_arg.integer)
                os << ")";
		}
		else if (_arg.integer == 0)
                    os << 0;
		return os;
}
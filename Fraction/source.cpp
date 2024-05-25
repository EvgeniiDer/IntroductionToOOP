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

Fraction& Fraction::operator+(Fraction& _arg){
    _arg.to_improper();
	this->to_improper();
	return Fraction
	(
		_arg.get_numerator()*this->get_denominator() + this->get_numerator()*_arg.get_denominator(),
		_arg.get_denominator()*this->get_denominator()
	).to_proper().reduce();
}

Fraction& Fraction::operator-(Fraction& _arg){
    _arg.to_improper();
	this->to_improper();
	return Fraction
	(
		_arg.get_numerator()*this->get_denominator() - this->get_numerator()*_arg.get_denominator(),
		_arg.get_denominator()*this->get_denominator()
	).to_proper().reduce();
}
Fraction& Fraction::operator*(Fraction& _arg){
    _arg.to_improper();
	this->to_improper();
	return Fraction
	(
		_arg.get_numerator()*this->get_denominator() * this->get_numerator()*_arg.get_denominator(),
		_arg.get_denominator()*this->get_denominator()
	).to_proper().reduce();
    }
Fraction& Fraction::operator/(Fraction& _arg)
{
    _arg.to_improper();
	this->to_improper();
	return Fraction
	(
		_arg.get_numerator()*this->get_denominator() / this->get_numerator()*_arg.get_denominator(),
		_arg.get_denominator()*this->get_denominator()
	).to_proper().reduce();
}    
Fraction& Fraction::operator++(){
    this->integer++;
    return *this;
}
Fraction Fraction::operator++(int)
{
    Fraction old = *this;
    integer++;
    return old;
    
}
Fraction& Fraction::operator--()
{
    this->integer--;
    return *this;
}
Fraction Fraction::operator--(int)
{
    Fraction old = *this;
    integer--;
    return old;
}
Fraction& Fraction::operator+=(Fraction& _arg){
    return *this = *this + _arg;
}
Fraction& Fraction::operator-=(Fraction& _arg){
    return *this = *this - _arg;
}
Fraction& Fraction::operator*=(Fraction& _arg){
    return *this = *this * _arg;
}
Fraction& Fraction::operator/=(Fraction& _arg){
    return *this = *this / _arg;
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
std::istream& operator>>(std::istream& is, Fraction& _arg)
{
    const int SIZE = 256;
	char buffer[SIZE]{};
	std::cin >> buffer;
	int n = 0;
	int numbers[3];
	char delimiters[] = "(/ )";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		numbers[n++] = std::atoi(pch);
    _arg = Fraction();
	switch (n)
	{
	case 1: _arg.set_integer(numbers[0]); break;
	case 2:
		_arg.set_numerator(numbers[0]);
	    _arg.set_denominator(numbers[1]);
		break;
	case 3:
		_arg.set_integer(numbers[0]);
		_arg.set_numerator(numbers[1]);
		_arg.set_denominator(numbers[2]);
	}

	return is;
}

bool Fraction::operator==(Fraction& _arg)
{
    this->to_improper();
	_arg.to_improper();
	return
		this->get_numerator()*_arg.get_denominator() ==
		_arg.get_numerator()*this->get_denominator();
}
bool Fraction::operator<(Fraction& _arg)
{
    this->to_improper();
	_arg.to_improper();
	return
		this->get_numerator()*_arg.get_denominator() <
		_arg.get_numerator()*this->get_denominator();
}
bool Fraction::operator>(Fraction& _arg)
{
    this->to_improper();
	_arg.to_improper();
	return
		this->get_numerator()*_arg.get_denominator() >
		_arg.get_numerator()*this->get_denominator();
}
bool Fraction::operator!=(Fraction& _arg)
{
    this->to_improper();
	_arg.to_improper();
	return
		this->get_numerator()*_arg.get_denominator() !=
		_arg.get_numerator()*this->get_denominator();
}
bool Fraction::operator<=(Fraction& _arg)
    {
        return !(*this > _arg);
    }
bool Fraction::operator>=(Fraction& _arg)
    {
        return!(*this < _arg);
    }   
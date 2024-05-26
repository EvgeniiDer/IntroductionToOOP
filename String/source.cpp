#include"head.hpp"

std::ostream& operator<<(std::ostream& os, const String& str)
{
    for(int i = 0; i < str.get_size(); i++)
        os << str[i];
    return os;
}
String operator+(const String& _objL, const String& _objR)
{
    String temp(_objL.get_size() + _objR.get_size() - 1);
    for (int i = 0; i < _objL.get_size(); i++)
		temp[i] = _objL[i];
	for (int i = 0; i < _objR.get_size(); i++)
		temp[i + _objL.get_size() - 1] = _objR[i];
    return temp;
}
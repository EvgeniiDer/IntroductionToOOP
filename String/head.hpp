#ifndef HEAD_HPP_
#define HEAD_HPP_
#include<iostream>
class String;
String operator+(const String& _objL, const String& _objR);

class String{
    private:
        int size;
        char* str;
    public:
        void set_size(const int& SIZE)
            {
                size = SIZE;
            }
        int get_size()const
            {
                return size;
            }
        char* get_str()
            {
                return str;
            }
        
        String(const int& _size = 80) : size(_size), str(new char[size]){
            for(int i = 0; i < size - 1; i++)
                str[i] = ' ';
        };
        
        String(const String& _obj) : size(_obj.size), str(new char(_obj.size)) {
            for(int i = 0; _obj[i]; i++)
                this->str[i] = _obj[i];
        }
        String(const char* _str): size(strlen(_str)), str(new char[strlen(_str)])
        {
            for(int i = 0; _str[i]; i++)
                this->str[i] = _str[i];

        }
        
        
        String& operator=(const String& _obj){
            if(this == &_obj)
                return *this;
            delete[]this->str;
            this->size = _obj.size;
            this->str = new char[this->size];
            for(int i = 0; _obj[i]; i++)
                this->str[i] = _obj[i];
            return *this;
        }
        String(String&& _obj)
        {
            this->size = _obj.size;
            this->str = _obj.str;
            _obj.size = 0;
            _obj.str = nullptr;

        }
        String& operator=(String&& _obj)
        {
            if(this == &_obj)
                return *this;
            delete[]this->str;
            this->str = _obj.str;
            this->size = _obj.size;
            for(int i = 0; _obj[i]; i++)
                this->str[i] = _obj.str[i];
            return *this;
        }
        ~String(){
            delete[]str;
        }
        char& operator[](const int& _i)
            {
                return str[_i];
            }
        char operator[](const int& _i)const
            {
                return str[_i];
            }

        friend std::ostream& operator<<(std::ostream& os, const String& _obj);
        friend std::istream& operator>>(std::istream& is, String& _obj);
};

#endif
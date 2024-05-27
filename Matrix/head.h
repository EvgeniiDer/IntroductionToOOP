#ifndef HEAD_H_
#define HEAD_H_
#include<iostream>



class Matrix{
    private:
        int m_row;
        int m_cols;
        int** matrix;
        void free_memory(int** _matrix, const int& _row);
        int** allocate(const int& _row, const int& _cols);
        void copy(Matrix& _lM, const Matrix& _rM);
    public:
        int get_row()const;
        int get_colm()const;
        void set_row(const int& _row);
        void set_colm(const int& _colm);
        explicit Matrix(const int &_a = 1, const int& _row = 10, const int& _colm = 10): m_row(_row),
                                                                                         m_cols(_colm)
        {
            matrix = allocate(_row, _colm);
            for(int i = 0; i < m_row; i++)
                for(int j = 0; j < m_cols; j++)
                    matrix[i][j] = _a;
        }
        Matrix(const Matrix& _obj);
        Matrix(Matrix&& _obj);
        Matrix& operator=(const Matrix& _obj);
        Matrix& operator=(Matrix&& _obj);
        ~Matrix(){
            free_memory(matrix, m_row);
            std::cout << "Destructor Done...." << std::endl;
        }
        Matrix& operator+(const Matrix& _obj);
        Matrix& operator-(const Matrix& _obj);
        Matrix& operator*(const Matrix& _obj);
        Matrix& operator/(const Matrix& _obj);
        Matrix& operator+=(const Matrix& _obj);
        Matrix& operator-=(const Matrix& _obj);
        Matrix& operator*=(const Matrix& _obj);
        Matrix& operator/=(const Matrix& _obj);
        
        int operator()(const int& _i, const int& _j)const; //overload[][]
        int& operator()(const int& _i, const int& _j);//overload[][]
        friend std::ostream& operator<<(std::ostream& os, const Matrix& _obj);
};
bool operator==(const Matrix& objL, const Matrix& objR);
bool operator!=(const Matrix& objL, const Matrix& objR);
#endif
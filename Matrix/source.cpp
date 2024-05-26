#include"head.h"

int** Matrix::allocate(const int& _row, const int& _cols)
{
        int ** allco_matrix = new int*[_row];
        for(int i = 0; i < _row; i++)
            allco_matrix[i] = new int[_cols];
        return allco_matrix;
}
void Matrix::free_memory(int** _matrix, const int& _row)
{
        for(int i = 0; i < _row; i++)
            delete[]_matrix[i];
        delete[]_matrix;
}
void Matrix::copy(Matrix& _lM, const Matrix& _rM)
{
    for(int i = 0; i < _rM.get_row(); i++)
        for(int j = 0; j < _rM.get_colm(); j++)
            _lM(i, j) = _rM(i,j);
}
int Matrix::get_colm()const
{
    return m_cols;
}
int Matrix::get_row()const
{
    return m_row;
}
void Matrix::set_colm(const int& _colm)
{
    m_cols = _colm;
}
void Matrix::set_row(const int& _row)
{
    m_row = _row;
}
Matrix::Matrix(const Matrix& _obj)
{
    this->m_row = _obj.m_row;
    this->m_cols = _obj.m_cols;
    this->matrix = allocate(_obj.m_row, _obj.m_row);
    copy(*this, _obj);
}

int Matrix::operator()(const int& _i, const int& _j)const
    {
        return matrix[_i][_j];
    }
int& Matrix::operator()(const int& _i, const int& _j)
{
    return matrix[_i][_j];
}
std::ostream& operator<<(std::ostream& os, const Matrix& _obj)
{
    for(int i = 0; i < _obj.get_row(); i++)
        {
           for(int j = 0; j < _obj.get_colm(); j++) 
                os << _obj.matrix[i][j] << " ";
            os << std::endl;
        }
    return os;       
}
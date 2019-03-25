#include "matrix.h"

bool Matrix::operator==(const Matrix& rvalue)
{
    if(rows != rvalue.rows || columns != rvalue.columns) return false;
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < columns; ++j)
            if(matrix[i][j] != rvalue.matrix[i][j]) return false;
    return true;
}

bool Matrix::operator!=(const Matrix& rvalue)
{
    return !(*this == rvalue);
}

std::size_t Matrix::getColumns()
{
    return columns;
}

std::size_t Matrix::getRows()
{
    return rows;
}

Matrix& Matrix::operator*=(const int multi_number)
{   
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < columns; ++j)
            matrix[i][j] *= multi_number;
    return *this;
}


#pragma once

#include <cstdio>
#include <stdexcept>

class Matrix{

    std::size_t rows;
    std::size_t columns;
    int** matrix;

    class row{
        std::size_t size;
        int* array;

    public:
        
        row(size_t SIZE, int* arr) : size(SIZE), array(arr) {}
        int& operator[](size_t index) 
        {
            if(index >= size) throw std::out_of_range("error with second index");
            return array[index];
        }
        const int& operator[](size_t index) const 
        {
            if(index >= size) throw std::out_of_range("error with second index");
            return array[index];
        }
    };

public:

    explicit Matrix(size_t SIZErow, size_t SIZEcolumn) : rows(SIZErow), columns(SIZEcolumn)
    {
        matrix = new int* [rows];
        for (size_t i = 0; i < rows; ++i) matrix[i] = new int [columns];
    }
    explicit Matrix(const Matrix& otherMatrix) : rows(otherMatrix.rows), columns(otherMatrix.columns)
    {
        matrix = new int* [rows];
        for (size_t i = 0; i < rows; ++i) matrix[i] = new int [columns];
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < columns; ++j)
                matrix[i][j] = otherMatrix.matrix[i][j];
    }
    ~Matrix() 
    { 
        for (size_t i = 0; i < rows; ++i) delete[] matrix[i];
        delete[] matrix;
    }
    row operator[](std::size_t indexRow)
    {
        if(indexRow >= rows) throw std::out_of_range("error with first index");
        return row(columns, matrix[indexRow]);
    }
    const row operator[](std::size_t indexRow) const
    {
        if(indexRow >= rows) throw std::out_of_range("error with first index");
        return row(columns, matrix[indexRow]);
    }

    bool operator==(const Matrix& rvalue);
    bool operator!=(const Matrix& rvalue);
    std::size_t getColumns();
    std::size_t getRows();
    Matrix& operator*=(const int multi_number); 
};
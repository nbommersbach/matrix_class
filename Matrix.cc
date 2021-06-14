#include <iostream>
#include "Matrix.h"

Matrix::Matrix(const unsigned int n, const unsigned int m)
{
    rows = n;
    columns = m;

    data = new double*[rows];
    for(unsigned int i = 0; i < rows; i++)
    {
        data[i] = new double[columns];
    } 
}

Matrix::~Matrix()
{
    for(unsigned int i = 0; i < rows; i++)
    {
        delete data[i];
    } 
    delete data;
}

void Matrix::ones()
{
    for(unsigned i = 0; i < rows; i++)
    {
        double* var = data[i];
        for(unsigned j = 0; j < columns; j++)
        {
            var[j] = 1;
        }
    }
}

void Matrix::iota(int rise)
{
    int rising = rise;
    for(unsigned i = 0; i < rows; i++)
    {
        double* var = data[i];
        for(unsigned j = 0; j < columns; j++)
        {
            var[j] = rising;
            ++rising;
        }
    }
}

void Matrix::set_value(unsigned int i, unsigned int j, double input)
{
    double *var = data[i];
    var[j] = input;
}

bool Matrix::x_able(Matrix *mat)
{
    if(rows == mat->columns) return true;
    else return false;
}

Matrix* Matrix::mult(Matrix *mat)
{
    Matrix *result = new Matrix(rows, mat->columns); 
    if(x_able(mat))
    {
        for(unsigned int i = 0; i < rows; ++i)
        {
            double* row = data[i];
            for(unsigned int j = 0; j < mat->columns; ++j)
            {
                double meet = 0;
                for(unsigned int n = 0; n < columns; ++n)
                {
                    double* mat_row = mat->data[n];
                    meet += row[n] * mat_row[j];
                }
                result->set_value(i, j, meet);
            }
        }
        return result;
    }
    else{
        std::cout << "Matrix not x_able" << std::endl;
        return result;
    }
}

double Matrix::det()
{
    if(rows == 2)
    {
        return get_value(0, 0) * get_value(1, 1) - get_value(0, 1) * get_value(1, 0);
    }
    else
    {
        short posneg = 0;
        double result = 0;

        for(unsigned int i = 0; i < columns; i++)
        {
            posneg = pow(-1, (1+ (i+1)));
            Matrix *recur = new Matrix(rows - 1, columns -1);

            unsigned int recur_parse_rows = 0;
            unsigned int recur_parse_columns = 0;

            for(unsigned int a = 0; a < rows; a++)
            {
                for(unsigned int b = 0; b < columns; b++)
                {
                    if(a != 0 && b != i)
                    {
                        recur->set_value(recur_parse_rows, recur_parse_columns, get_value(a, b));
                        ++recur_parse_columns;
                    }

                    if(recur_parse_columns == columns - 1)
                    {
                        ++recur_parse_rows;
                        recur_parse_columns = 0;
                    }
                }
            }

            result += posneg * recur->det() * get_value(0, i);
        }
        return result;
    }
}

double Matrix::get_value(unsigned int i, unsigned int j)
{
    double *row = data[i];
    return row[j];
}

void Matrix::print()
{
    std::cout << "[";
    for(unsigned i = 0; i < rows; i++)
    {
        double* var = data[i];
        for(unsigned j = 0; j < columns; j++)
        {
            std::cout << var[j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "]";
}


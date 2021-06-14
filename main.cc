#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix *mat1 = new Matrix(3, 3);

    mat1->iota(2);
    mat1->set_value(1,1,20);
    
    std::cout << mat1->det() << std::endl;

    delete mat1;

    return 0;
}
#pragma once

class Matrix
{
    private:
        double **data;
        unsigned int rows;
        unsigned int columns;

    public:
        Matrix(const unsigned int n, const unsigned int m);
        ~Matrix();

        /**
         * @brief Fills matrix up with ones.
         * 
         */
        void ones();

        /**
         * @brief Fills matrix with rising values starting from param rise.
         * @param rise Starting value to start incrementing from.
         */
        void iota(int rise);

        /**
         * @brief Set the value the matrix at the position i, j.
         * 
         * @param i row of the value
         * @param j column of the value
         * @param input LValue to write to position i, j in Matrix
         */
        void set_value(unsigned int i, unsigned int j, double input);

        /**
         * @brief Multiply the Matrix with another Matrix
         * 
         * @param mat B matrix of AxB matrix multiplication
         * @return result matrix if x_able
         */
        Matrix* mult(Matrix *mat);

        /**
         * @brief Checks if matrices are multiplyable
         * 
         * @param mat B matrix of AxB matrix multliplication
         * @return true if multiplyable
         */
        bool x_able(Matrix *mat);

        double get_value(unsigned int i, unsigned int j);

        double det();

        /**
         * @brief prints the matrix
         * 
         */
        void print();
};
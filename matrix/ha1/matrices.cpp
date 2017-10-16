#include "matrices.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double ** allocate_memory (const size_t row, const size_t col) {
    
    double ** mat = new double*[row];
    for (size_t i = 0; i < row; i++) {
        mat[i] = new double[col];
    }
    
    return mat;
}

void create_matrix (const std::string &filename, double ** &mat, size_t &row, size_t &col) {
    
    ifstream file(filename);
    
    if (file) {
        file >> row >> col;
        mat = allocate_memory(row, col);
        
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                file >> mat[i][j];
            }
        }
    }
}

void delete_matrix (double ** &mat, const size_t row) {
    
    for (size_t i = 0; i < row; i++) {
        delete [] mat[i];
    }
    delete []mat;
}

void print_matrix (double const * const *mat, const size_t row, const size_t col) {
    
    cout << row << " " << col << endl;
    
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

double ** add_matrix(double **first_mat, double const * const *second_mat, const size_t row, const size_t col) {
    double **sum = allocate_memory(row, col);
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            sum[i][j] = first_mat[i][j] + second_mat[i][j];
        }
    }
    delete_matrix(first_mat, row);
    return sum;
}

double ** mult_matrix(double **first_mat, double const * const *second_mat, const size_t first_mat_row, size_t &first_mat_col, const size_t second_mat_col) {
    double **prod = allocate_memory(first_mat_row, second_mat_col);
    for (size_t i = 0; i < first_mat_row; i++) {
        for (size_t j = 0; j < second_mat_col; j++) {
            prod[i][j] = 0;
            for (size_t k = 0; k < first_mat_col; k++) {
                prod[i][j] += first_mat[i][k] * second_mat[k][j];
            }
        }
    }
    first_mat_col = second_mat_col;
    delete_matrix(first_mat, first_mat_row);
    return prod;
}
#ifndef MATRICES_H
#define MATRICES_H

#include <string>

void create_matrix (const std::string &filename, double ** &mat, size_t &row, size_t &col);
void delete_matrix (double ** &mat, const size_t row);
void print_matrix (double const * const *mat, const size_t row, const size_t col);

double ** add_matrix(double **first_mat, double const * const *second_mat, const size_t row, const size_t col);
double ** mult_matrix(double **first_mat, double const * const *second_mat, const size_t first_mat_row, size_t &first_mat_col, const size_t second_mat_col);

#endif
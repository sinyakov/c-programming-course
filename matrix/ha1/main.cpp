#include "matrices.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    double **first_mat = nullptr;
    size_t first_mat_row = 0;
    size_t first_mat_col = 0;
    
    double **second_mat = nullptr;
    size_t second_mat_row = 0;
    size_t second_mat_col = 0;
    
    if (argc % 2 == 1) {
        cerr << "Error: Incorrect argument format" << endl;
        return 1;
    }
    
    string filename = argv[1];
    create_matrix(filename, first_mat, first_mat_row, first_mat_col);
    
    if (first_mat_row == 0) {
        cerr << "Error: Incorrect number of rows or columns in " + filename << endl;
        delete_matrix(first_mat, first_mat_row);
        return 2;
    }
    
    for (int i = 2; i < argc; i += 2) {
        string instruction = argv[i];
        filename = argv[i+1];
        
        if (second_mat_row != 0) {
            delete_matrix(second_mat, second_mat_row);
        }
        
        create_matrix(filename, second_mat, second_mat_row, second_mat_col);
        
        if (instruction != "--add" && instruction != "--mult") {
            cerr << "Error: Incorrect argument format" << endl;
            delete_matrix(first_mat, first_mat_row);
            delete_matrix(second_mat, second_mat_row);
            return 1;
        }
        
        if (instruction == "--add") {
            if (first_mat_row == second_mat_row && first_mat_col == second_mat_col) {
                first_mat = add_matrix(first_mat, second_mat, first_mat_row, first_mat_col);
            }
            else {
                cerr << "Error: Incorrect number of rows or columns in " + filename << endl;
                delete_matrix(first_mat, first_mat_row);
                delete_matrix(second_mat, second_mat_row);
                return 2;
            }
        }
        if (instruction == "--mult") {
            if (first_mat_col == second_mat_row) {
                first_mat = mult_matrix(first_mat, second_mat, first_mat_row, first_mat_col, second_mat_col);
            }
            else {
                cerr << "Error: Incorrect number of rows or columns in " + filename << endl;
                delete_matrix(first_mat, first_mat_row);
                delete_matrix(second_mat, second_mat_row);
                return 2;
            }
        }
    }
    print_matrix(first_mat, first_mat_row, first_mat_col);
    delete_matrix(first_mat, first_mat_row);
    delete_matrix(second_mat, second_mat_row);
    return 0;
}

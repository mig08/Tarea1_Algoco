#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip> 
#include <cmath>
using namespace std::chrono;
using namespace std;

vector<vector<int>> multiply_matrix_Strassen(vector<vector<int>> matrix_A, vector<vector<int>> matrix_B) { // https://www.geeksforgeeks.org/strassens-matrix-multiplication/
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();
 
    if (col_1 != row_2) {
        cout << "\nError: The number of columns in Matrix A must be equal to the number of rows in Matrix B\n";
        return {};
    }
 
    vector<int> result_matrix_row(col_2, 0);
    vector<vector<int> > result_matrix(row_1, result_matrix_row);
 
    if (col_1 == 1)
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    else {
        int split_index = col_1 / 2;
        // Dividir matrices
        vector<int> row_vector(split_index, 0);
        vector<vector<int> > result_matrix_00(split_index, row_vector);
        vector<vector<int> > result_matrix_01(split_index, row_vector);
        vector<vector<int> > result_matrix_10(split_index, row_vector);
        vector<vector<int> > result_matrix_11(split_index, row_vector);
        //Encontrar valores para calcular
        vector<vector<int>> a00(split_index, row_vector);
        vector<vector<int>> a01(split_index, row_vector);
        vector<vector<int>> a10(split_index, row_vector);
        vector<vector<int>> a11(split_index, row_vector);
        vector<vector<int>> b00(split_index, row_vector);
        vector<vector<int>> b01(split_index, row_vector);
        vector<vector<int>> b10(split_index, row_vector);
        vector<vector<int>> b11(split_index, row_vector);
 
        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index][j + split_index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index][j + split_index];
            }
 
        add_matrix(multiply_matrix_Strassen(a00, b00), multiply_matrix_Strassen(a01, b10), result_matrix_00, split_index);
        add_matrix(multiply_matrix_Strassen(a00, b01), multiply_matrix_Strassen(a01, b11), result_matrix_01, split_index);
        add_matrix(multiply_matrix_Strassen(a10, b00), multiply_matrix_Strassen(a11, b10), result_matrix_10, split_index);
        add_matrix(multiply_matrix_Strassen(a10, b01), multiply_matrix_Strassen(a11, b11), result_matrix_11, split_index);
 
        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + split_index] = result_matrix_01[i][j];
                result_matrix[split_index + i][j] = result_matrix_10[i][j];
                result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j];
            }
 
        result_matrix_00.clear();
        result_matrix_01.clear();
        result_matrix_10.clear();
        result_matrix_11.clear();
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
    }
    return result_matrix;
}

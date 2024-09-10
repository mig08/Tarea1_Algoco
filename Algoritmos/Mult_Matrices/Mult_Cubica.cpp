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

vector<vector<int>> multiplicarMatrices_Cubica(const vector<vector<int>>& A, const vector<vector<int>>& B) { // https://chatgpt.com 
    int filasA = A.size();
    int columnasA = A[0].size();
    int filasB = B.size();
    int columnasB = B[0].size();

    // Verificación de la compatibilidad de las matrices
    if (columnasA != filasB) {
        cerr << "Error: Las matrices no se pueden multiplicar (columnas de A != filas de B)." << endl;
        return {}; // Devuelve una matriz vacía en caso de error
    }

    // Crea matriz final
    vector<vector<int>> C(filasA, vector<int>(columnasB, 0));

    // Realizar la multiplicación de matrices
    for(int i = 0; i < filasA; ++i) {
        for(int j = 0; j < columnasB; ++j) {
            for(int k = 0; k < columnasA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

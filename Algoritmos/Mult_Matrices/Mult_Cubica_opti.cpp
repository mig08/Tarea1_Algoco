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


// Función para transponer una matriz
vector<vector<int>> transponerMatriz(const vector<vector<int>>& matriz) { // https://chatgpt.com
    int filas = matriz.size();
    int columnas = matriz[0].size();
    vector<vector<int>> transpuesta(columnas, vector<int>(filas));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            transpuesta[j][i] = matriz[i][j];
        }
    }

    return transpuesta;
}

// Función para multiplicar matrices usando transposición para mejorar la localidad de los datos
vector<vector<int>> multiplicarMatrices_Cubica_Optimizada(const vector<vector<int>>& A, const vector<vector<int>>& B) { // https://chatgpt.com 
    int filasA = A.size();
    int columnasA = A[0].size();
    int filasB = B.size();
    int columnasB = B[0].size();

    // Verificación de la compatibilidad de las matrices
    if (columnasA != filasB) {
        cerr << "Error: Las matrices no se pueden multiplicar (columnas de A != filas de B)." << endl;
        return {}; // Devuelve una matriz vacía en caso de error
    }

    // Transponer la matriz B
    vector<vector<int>> B_T = transponerMatriz(B);

    // Inicializar la matriz resultante con ceros
    vector<vector<int>> C(filasA, vector<int>(columnasB, 0));

    // Realizar la multiplicación de matrices usando la matriz transpuesta
    for(int i = 0; i < filasA; ++i) {
        for(int j = 0; j < columnasB; ++j) {
            for(int k = 0; k < columnasA; ++k) {
                C[i][j] += A[i][k] * B_T[j][k];
            }
        }
    }

    return C;
}

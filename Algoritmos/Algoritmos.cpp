#include <Algoritmos.hpp>


void SelectionSort_peorCaso(vector<int> &v) { // https://cplusplus.com/forum/beginner/245026/
    for (size_t i = 0; i < v.size() - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < v.size(); j++)
            if (v[j] < v[min])
                min = j;
        int t = v[i];
        v[i] = v[min];
        v[min] = t;
    }
}


void selectionSort(vector<int> &v, int n) // https://www.geeksforgeeks.org/selection-sort-algorithm-2/
{
    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in
        // unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(v[min_idx], v[i]);
    }
}

void merge(vector<int>& vec, int left, int mid, int right) { // https://www.geeksforgeeks.org/cpp-program-for-merge-sort/ 
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    vector<int> leftVec(n1), rightVec(n2);

    // Copy data to temporary vectors
    for (i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];
    for (j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];

    // Merge the temporary vectors back into vec[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftVec[], if any
    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightVec[], if any
    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [left..right]
void mergeSort(vector<int>& vec, int left, int right) { // https://www.geeksforgeeks.org/cpp-program-for-merge-sort/
    if (left < right) {
      
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        // Merge the sorted halves
        merge(vec, left, mid, right);
    }
}

/*
int partition(vector<int> &vec, int low, int high) { // https://www.geeksforgeeks.org/cpp-program-for-quicksort/

    // Selecting last element as the pivot
    int pivot = vec[high];

    // Index of elemment just before the last element
    // It is used for swapping
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // Put pivot to its position
    swap(vec[i + 1], vec[high]);

    // Return the point of partition
    return (i + 1);
}

void quickSort(vector<int> &vec, int low, int high) { // https://www.geeksforgeeks.org/cpp-program-for-quicksort/ 

    // Base case: This part will be executed till the starting
    // index low is lesser than the ending index high
    if (low < high) {

        // pi is Partitioning Index, arr[p] is now at
        // right place
        int pi = partition(vec, low, high);

        // Separately sort elements before and after the
        // Partition Index pi
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}
*/

int medianOfThree(vector<int>& vec, int low, int high) {
    int mid = low + (high - low) / 2;
    
    // Ordena los tres valores para encontrar la mediana
    if (vec[low] > vec[mid]) swap(vec[low], vec[mid]);
    if (vec[low] > vec[high]) swap(vec[low], vec[high]);
    if (vec[mid] > vec[high]) swap(vec[mid], vec[high]);

    // Ahora vec[mid] es la mediana de los tres
    return mid;
}

int partition(vector<int> &vec, int low, int high) {
    // Selecciona el pivote usando la técnica de la mediana de tres
    int medianIndex = medianOfThree(vec, low, high);
    
    // Coloca el pivote en el final para utilizar el mismo esquema de partición
    swap(vec[medianIndex], vec[high]);
    int pivot = vec[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}

void quickSort(vector<int> &vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

void RandomDataSet(vector<int>& vector, int numElements) {

    string Dataset = "Random_dataset.txt";

    // Inicializar la semilla para generar números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    // Crear y abrir el archivo
    ofstream outfile(Dataset);

    // Verificar si el archivo se abrió correctamente
    if (!outfile) {
        cerr << "Error al abrir el archivo para escribir." << endl;
        return;
    }

    // Generar números aleatorios dentro del rango y escribirlos en el archivo
    for (int i = 0; i < numElements; ++i) {
        int randomNumber = rand();
        vector.push_back(randomNumber);
        outfile << randomNumber << endl; // Escribe el número en el archivo
    }

    // Cerrar el archivo
    outfile.close();

    cout << "Dataset generado y guardado en " << Dataset << endl;
}



void printVector(const vector<int>& dataset) {
    
    for (int number : dataset){
        cout << number << endl;
    }
}

// Función para generar una matriz con dimensiones aleatorias
vector<vector<int>> generarMatriz(int filas, int columnas) {
    vector<vector<int>> matriz(filas, vector<int>(columnas));

    for(int i = 0; i < filas; ++i) {
        for(int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 100; // Valores entre 0 y 99
        }
    }

    return matriz;
}

// Función principal para generar matrices, verificar multiplicabilidad y escribir en un archivo
void generarYVerificarMatrices(vector<vector<int>>& matriz_A, vector<vector<int>>& matriz_B, vector<vector<int>>& matriz_C, vector<vector<int>>& matriz_D, const string& filename) {
    srand(time(0)); // Inicializar la semilla para rand()

    int filasA, columnasA, filasB, columnasB, filasColumnasC;
    filasColumnasC = rand() % 10 + 1;
    matriz_C = generarMatriz(filasColumnasC, filasColumnasC);
    matriz_D = generarMatriz(filasColumnasC, filasColumnasC);

    do {
        // Generar dimensiones aleatorias para las matrices
        filasA = rand() % 10 + 1;      // Dimensiones entre 1 y 10 (puedes ajustar estos valores)
        columnasA = rand() % 10 + 1;
        filasB = columnasA;            // Asegura que filasB sea igual a columnasA para garantizar multiplicabilidad
        columnasB = rand() % 10 + 1;

        // Generar las matrices
        matriz_A = generarMatriz(filasA, columnasA);
        matriz_B = generarMatriz(filasB, columnasB);

    } while (columnasA != filasB); // Repetir hasta que se puedan multiplicar

    // Abrir el archivo para escribir las matrices
    ofstream outfile(filename);

    if (!outfile) {
        cerr << "Error al abrir el archivo para escribir." << endl;
        return;
    }

    // Escribir Matriz A en el archivo
    outfile << "Matriz A (" << filasA << "x" << columnasA << "):\n";
    for (const auto& fila : matriz_A) {
        for (int val : fila) {
            outfile << val << " ";
        }
        outfile << endl;
    }

    outfile << endl;

    // Escribir Matriz B en el archivo
    outfile << "Matriz B (" << filasB << "x" << columnasB << "):\n";
    for (const auto& fila : matriz_B) {
        for (int val : fila) {
            outfile << val << " ";
        }
        outfile << endl;
    }

    outfile << endl;

    outfile << "Matriz C (" << filasColumnasC << "x" << filasColumnasC << "):\n";
    for (const auto& fila : matriz_C) {
        for (int val : fila) {
            outfile << val << " ";
        }
        outfile << endl;
    }

    outfile << endl;

    outfile << "Matriz D (" << filasColumnasC << "x" << filasColumnasC << "):\n";
    for (const auto& fila : matriz_D) {
        for (int val : fila) {
            outfile << val << " ";
        }
        outfile << endl;
    }


    outfile << endl;

    outfile.close();
    cout << "Matrices generadas y guardadas en " << filename << endl;
}


void imprimirMatriz(const vector<vector<int>>& matriz) {
    for(const auto& fila : matriz) {
        for(const auto& elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}

void add_matrix(vector<vector<int> > matrix_A, vector<vector<int> > matrix_B, vector<vector<int> >& matrix_C, int split_index) { // https://www.geeksforgeeks.org/strassens-matrix-multiplication/
    for (auto i = 0; i < split_index; i++)
        for (auto j = 0; j < split_index; j++)
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
}

vector<vector<int>> multiplicarMatrices_Cubica(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int filasA = A.size();
    int columnasA = A[0].size();
    int filasB = B.size();
    int columnasB = B[0].size();

    // Verificación de la compatibilidad de las matrices
    if (columnasA != filasB) {
        cerr << "Error: Las matrices no se pueden multiplicar (columnas de A != filas de B)." << endl;
        return {}; // Devuelve una matriz vacía en caso de error
    }

    // Inicializar la matriz resultante con ceros
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

// Función para transponer una matriz
vector<vector<int>> transponerMatriz(const vector<vector<int>>& matriz) {
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
vector<vector<int>> multiplicarMatrices_Cubica_Optimizada(const vector<vector<int>>& A, const vector<vector<int>>& B) {
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
 
        vector<int> row_vector(split_index, 0);
        vector<vector<int> > result_matrix_00(split_index, row_vector);
        vector<vector<int> > result_matrix_01(split_index, row_vector);
        vector<vector<int> > result_matrix_10(split_index, row_vector);
        vector<vector<int> > result_matrix_11(split_index, row_vector);
 
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
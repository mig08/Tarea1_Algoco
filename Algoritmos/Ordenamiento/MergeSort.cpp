#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip> 
using namespace std::chrono;
using namespace std;

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
        int randomNumber = rand() % 10000 + 1;
        vector.push_back(randomNumber);
        outfile << randomNumber << endl; // Escribe el número en el archivo
    }

    // Cerrar el archivo
    outfile.close();

    cout << "Dataset generado y guardado en " << Dataset << endl;
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

int main(){
    int cant = 200000;
    cout << "Cantidad de datos: " << cant << endl; 
    vector<int> randomVector;

    RandomDataSet(randomVector, cant);
    cout << endl;
    cout << "random set" << endl;
    //printVector(randomVector);

    auto start = high_resolution_clock::now();
    mergeSort(randomVector, 0, cant-1);
    cout << endl;
    cout << "merge sort" << endl;
    //printVector(randomVector);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start); // Usar microsegundos para mayor precisión
    cout << "Tiempo de ejecución: " << fixed << setprecision(6) << duration.count() / 1e6 << " s" << endl;
    return 0;
}



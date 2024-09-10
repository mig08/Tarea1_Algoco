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


int main(){
    int cant = 200000;
    cout << "Cantidad de datos: " << cant << endl; 
    vector<int> randomVector;
    RandomDataSet(randomVector, cant);
    cout << endl;
    cout << "random set" << endl;
    auto start = high_resolution_clock::now();
    selectionSort(randomVector, cant);
    cout << endl;
    cout << "selection sort" << endl;
    //printVector(randomVector);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start); // Usar microsegundos para mayor precisión
    cout << "Tiempo de ejecución: " << fixed << setprecision(6) << duration.count() / 1e6 << " s" << endl;


    return 0;
}
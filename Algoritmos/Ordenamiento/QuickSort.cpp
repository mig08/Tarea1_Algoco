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


int medianOfThree(vector<int>& vec, int low, int high) { // https://chatgpt.com
    int mid = low + (high - low) / 2;
    
    // Ordena los tres valores para encontrar la mediana
    if (vec[low] > vec[mid]) swap(vec[low], vec[mid]);
    if (vec[low] > vec[high]) swap(vec[low], vec[high]);
    if (vec[mid] > vec[high]) swap(vec[mid], vec[high]);

    // Ahora vec[mid] es la mediana de los tres
    return mid;
}

int partition(vector<int> &vec, int low, int high) { // https://chatgpt.com
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

void quickSort(vector<int> &vec, int low, int high) { // https://chatgpt.com
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
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
    quickSort(randomVector, 0 , cant-1);
    cout << endl;
    cout << "quick sort" << endl;
    //printVector(randomVector);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start); // Usar microsegundos para mayor precisión
    cout << "Tiempo de ejecución: " << fixed << setprecision(6) << duration.count() / 1e6 << " s" << endl;


    return 0;
}


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std::chrono;
using namespace std;

void selectionSort(vector<int> &v, int n); // https://www.geeksforgeeks.org/selection-sort-algorithm-2/

void merge(vector<int>& vec, int left, int mid, int right);  // https://www.geeksforgeeks.org/cpp-program-for-merge-sort/
void mergeSort(vector<int>& vec, int left, int right);  // https://www.geeksforgeeks.org/cpp-program-for-merge-sort/

int medianOfThree(vector<int>& vec, int low, int high); // https://chatgpt.com
int partition(vector<int> &vec, int low, int high); // https://chatgpt.com
void quickSort(vector<int> &vec, int low, int high); // https://chatgpt.com

void add_matrix(vector<vector<int> > matrix_A, vector<vector<int> > matrix_B, vector<vector<int> >& matrix_C, int split_index); // https://chatgpt.com
vector<vector<int>> multiplicarMatrices_Cubica(const vector<vector<int>>& A, const vector<vector<int>>& B); // https://chatgpt.comb

vector<vector<int>> transponerMatriz(const vector<vector<int>>& matriz); // https://chatgpt.com 
vector<vector<int>> multiplicarMatrices_Cubica_Optimizada(const vector<vector<int>>& A, const vector<vector<int>>& B); // https://chatgpt.com

vector<vector<int>> multiply_matrix_Strassen(vector<vector<int>> matrix_A, vector<vector<int>> matrix_B);  // https://www.geeksforgeeks.org/strassens-matrix-multiplication/



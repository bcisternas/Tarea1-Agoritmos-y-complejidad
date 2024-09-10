#ifndef MATRICES_H
#define MATRICES_H

#include <vector>
#include <string>

using namespace std;

// Declaración de funciones

// Transpone una matriz
vector<vector<int>> transponerMatriz(const vector<vector<int>>& B);

// Multiplica dos matrices optimizando la localidad de los datos mediante la transposición
vector<vector<int>> multiplicarMatricesOpt(const vector<vector<int>>& A, const vector<vector<int>>& B);

// Implementa el algoritmo cúbico tradicional para la multiplicación de matrices
vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B);

// Implementa el algoritmo de Strassen para la multiplicación de matrices
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B);

// Imprime una matriz
void imprimirMatriz(const vector<vector<int>>& matriz);

// Lee una matriz desde un archivo .txt
vector<vector<int>> leerMatriz(const string& nombreArchivo);

#endif // MATRICES_H

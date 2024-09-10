#include <bits/stdc++.h>

using namespace std;

/**
 * transponerMatriz() Transpone una matriz.
 * 
 * Esta función toma una matriz (vector de vectores) de enteros y devuelve su transpuesta, es decir, intercambia las filas por las columnas.
 * 
 * @param B La matriz original que se va a transponer (de tamaño m x n).
 * @return Una nueva matriz que es la transposición de B (de tamaño n x m).
 */
vector<vector<int>> transponerMatriz(const vector<vector<int>>& B) {
    int filas = B.size();
    int columnas = B[0].size();
    vector<vector<int>> B_transpuesta(columnas, vector<int>(filas));
    
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            B_transpuesta[j][i] = B[i][j];
        }
    }
    
    return B_transpuesta;
}

/**
 * MultiplicarMatricesOpt() Multiplica dos matrices optimizando la localidad de los datos.
 * 
 * Esta función multiplica dos matrices A y B, donde la matriz B es transpuesta para mejorar el rendimiento
 * debido a la localidad de datos. La función comprueba que las matrices sean multiplicables, y en caso contrario,
 * devuelve una matriz vacía.
 * 
 * @param A La primera matriz (de tamaño m x n).
 * @param B La segunda matriz (de tamaño n x p).
 * @return Una matriz resultado de la multiplicación de A por B (de tamaño m x p). Si las matrices no son multiplicables, retorna un vector vacío.
 */
vector<vector<int>> multiplicarMatricesOpt(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int filasA = A.size();
    int columnasA = A[0].size();
    int columnasB = B[0].size();

    // Comprobamos que las matrices se puedan multiplicar
    if (columnasA != B.size()) {
        cout << "Las matrices no se pueden multiplicar" << endl;
        return {};
    }

    // Transponemos la matriz B para mejorar la localidad de los datos
    vector<vector<int>> B_transpuesta = transponerMatriz(B);

    // Creamos una matriz resultado llena de ceros
    vector<vector<int>> C(filasA, vector<int>(columnasB, 0));

    // Multiplicamos las matrices, usando la matriz B transpuesta
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            for (int k = 0; k < columnasA; ++k) {
                C[i][j] += A[i][k] * B_transpuesta[j][k];
            }
        }
    }

    return C;
}

#include <bits/stdc++.h>
using namespace std;

/**
 * multiplicarMatrices() Multiplica dos matrices.
 * 
 * Esta función toma dos matrices A y B y realiza la multiplicación de matrices tradicional. Comprueba que las matrices
 * sean compatibles para la multiplicación (número de columnas de A debe ser igual al número de filas de B) y luego
 * realiza la multiplicación acumulando los productos de filas y columnas.
 * 
 * @param A La primera matriz (de tamaño m x n).
 * @param B La segunda matriz (de tamaño n x p).
 * @return Una matriz resultado de la multiplicación de A por B (de tamaño m x p). Si las matrices no son multiplicables, retorna un vector vacío.
 */
vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int filasA = A.size();
    int columnasA = A[0].size();
    int columnasB = B[0].size();

    // Comprobamos que las matrices se puedan multiplicar
    if (columnasA != B.size()) {
        cout << "Las matrices no se pueden multiplicar" << endl;
        return {};
    }

    // Creamos una matriz resultado llena de ceros
    vector<vector<int>> C(filasA, vector<int>(columnasB, 0));

    // Multiplicamos las matrices
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            for (int k = 0; k < columnasA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}


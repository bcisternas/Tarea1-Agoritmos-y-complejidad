#include "algoritmos_mult_mat/matrices.h"
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

// Función para medir el tiempo de ejecución de cada algoritmo y devolver el tiempo en milisegundos
long long medirTiempo(vector<vector<int>> (*algoritmo)(const vector<vector<int>>&, const vector<vector<int>>&), const vector<vector<int>>& A, const vector<vector<int>>& B) {
    auto start = high_resolution_clock::now(); // Iniciar cronómetro
    vector<vector<int>> C = algoritmo(A, B);
    auto stop = high_resolution_clock::now(); // Detener cronómetro
    auto duration = duration_cast<milliseconds>(stop - start); // Calcular duración
    return duration.count(); // Devolver el tiempo en milisegundos
}

// Función para calcular la transpuesta de una matriz
vector<vector<int>> transponer(const vector<vector<int>>& matriz) {
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

int main() {
    // Archivos de matrices cuadradas
    vector<string> archivos_cuadrados = {
        "Datasets_matrices/matrices_cuadradas/10x10.txt",
        "Datasets_matrices/matrices_cuadradas/100x100.txt",
        "Datasets_matrices/matrices_cuadradas/200x200.txt",
        "Datasets_matrices/matrices_cuadradas/300x300.txt",
        "Datasets_matrices/matrices_cuadradas/400x400.txt",
        "Datasets_matrices/matrices_cuadradas/500x500.txt",
        "Datasets_matrices/matrices_cuadradas/600x600.txt",
        "Datasets_matrices/matrices_cuadradas/700x700.txt",
        "Datasets_matrices/matrices_cuadradas/800x800.txt",
        "Datasets_matrices/matrices_cuadradas/900x900.txt",
        "Datasets_matrices/matrices_cuadradas/1000x1000.txt"
    };

    // Archivos de matrices rectangulares
    vector<string> archivos_rectangulares = {
        "Datasets_matrices/matrices_rectangulares/200x10.txt",
        "Datasets_matrices/matrices_rectangulares/200x100.txt",
        "Datasets_matrices/matrices_rectangulares/200x200.txt",
        "Datasets_matrices/matrices_rectangulares/200x300.txt",
        "Datasets_matrices/matrices_rectangulares/200x400.txt",
        "Datasets_matrices/matrices_rectangulares/200x500.txt",
        "Datasets_matrices/matrices_rectangulares/200x600.txt",
        "Datasets_matrices/matrices_rectangulares/200x700.txt",
        "Datasets_matrices/matrices_rectangulares/200x800.txt",
        "Datasets_matrices/matrices_rectangulares/200x900.txt",
        "Datasets_matrices/matrices_rectangulares/200x1000.txt"
    };

    // Abrir archivos de salida para los resultados
    ofstream archivo_cuadradas("resultados_matrices_cuadradas.csv");
    ofstream archivo_rectangulares("resultados_matrices_rectangulares.csv");

    // Escribir la fila de encabezado en ambos archivos
    archivo_cuadradas << "tamaño algoritmo_original algoritmo_optimizado algoritmo_strassen\n";
    archivo_rectangulares << "tamaño algoritmo_original algoritmo_optimizado\n";

    // Para las matrices cuadradas, multiplicar solo cuadradas entre sí
    for (const string& archivo_cuadrado : archivos_cuadrados) {
        vector<vector<int>> matrizA = leerMatriz(archivo_cuadrado);
        vector<vector<int>> matrizB = leerMatriz(archivo_cuadrado); // Multiplicamos A x A

        if (!matrizA.empty() && !matrizB.empty()) {
            int tamano_matriz = matrizA.size(); // Asumimos que son matrices cuadradas de n x n

            // Medir tiempos de los tres algoritmos
            long long tiempo_original = medirTiempo(multiplicarMatrices, matrizA, matrizB);
            long long tiempo_optimizado = medirTiempo(multiplicarMatricesOpt, matrizA, matrizB);
            long long tiempo_strassen = medirTiempo(strassen, matrizA, matrizB);

            // Escribir en el archivo el formato: tamaño tiempo(algoritmo original) tiempo(algoritmo optimizado) tiempo(algoritmo strassen)
            archivo_cuadradas << tamano_matriz << " " << tiempo_original << " " << tiempo_optimizado << " " << tiempo_strassen << "\n";
        } else {
            cout << "Hubo un problema al leer " << archivo_cuadrado << endl;
        }
    }

    // Para las matrices rectangulares, multiplicar solo rectangulares por su traspuesta
    for (const string& archivo_rectangular : archivos_rectangulares) {
        vector<vector<int>> matrizA = leerMatriz(archivo_rectangular);
        vector<vector<int>> matrizB = transponer(matrizA); // Multiplicamos A x A^T

        if (!matrizA.empty() && !matrizB.empty()) {
            int tamano_matriz = matrizB.size(); // Usamos el número de filas de la matriz original

            // Medir tiempos de los dos algoritmos (sin Strassen)
            long long tiempo_original = medirTiempo(multiplicarMatrices, matrizA, matrizB);
            long long tiempo_optimizado = medirTiempo(multiplicarMatricesOpt, matrizA, matrizB);

            // Escribir en el archivo el formato: tamaño tiempo(algoritmo original) tiempo(algoritmo optimizado)
            archivo_rectangulares << tamano_matriz << " " << tiempo_original << " " << tiempo_optimizado << "\n";
        } else {
            cout << "Hubo un problema al leer " << archivo_rectangular << endl;
        }
    }

    // Cerrar los archivos de salida
    archivo_cuadradas.close();
    archivo_rectangulares.close();

    return 0;
}

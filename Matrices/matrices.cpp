#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Función para leer matrices desde un archivo
vector<vector<int>> leerMatriz(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;
    vector<vector<int>> matriz;

    if (archivo.is_open()) {
        // Leer la primera línea que contiene el tamaño de la matriz
        getline(archivo, linea);
        istringstream iss(linea);
        int filas, columnas;
        char x;
        iss >> filas >> x >> columnas;  // Leer el formato "filas x columnas"
        
        // Leer las siguientes líneas con los valores de la matriz
        for (int i = 0; i < filas; ++i) {
            getline(archivo, linea);
            istringstream issFila(linea);
            vector<int> fila;
            int valor;
            while (issFila >> valor) {
                fila.push_back(valor);
            }
            matriz.push_back(fila);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }

    return matriz;
}

// Función para imprimir la matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int valor : fila) {
            cout << valor << " ";
        }
        cout << endl;
    }
}

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>  // Para std::sort
#include <chrono>     // Para medir el tiempo
#include "algoritmos/sortAlgorithms.h"

#include "algoritmos_mult_mat/matrices.h"

using namespace std;
using namespace std::chrono;  // Para facilitar el uso de std::chrono

// Función para leer los primeros N elementos de un dataset desde un archivo
vector<int> leer_dataset(const string& nombre_archivo, int num_elementos) {
    vector<int> dataset;
    dataset.reserve(num_elementos);  // Reservar espacio para evitar múltiples reasignaciones
    ifstream archivo(nombre_archivo);
    int numero;
    int contador = 0;

    // Leer elementos del archivo separados por espacios
    while (archivo >> numero && contador < num_elementos) {
        dataset.push_back(numero);
        contador++;
    }

    return dataset;
}

// Función para escribir los tiempos en un archivo
void escribir_tiempos(ofstream& archivo, int tamaño, long long tiempo_selection, long long tiempo_merge, long long tiempo_quick, long long tiempo_std) {
    archivo << tamaño << ", "
            << tiempo_selection << ", "
            << tiempo_merge << ", "
            << tiempo_quick << ", "
            << tiempo_std << endl;
}



int main() {
    const int MAX_ELEMENTOS = 1000000;  // Máximo de elementos (10^6)
    const int INCREMENTO = 100000;      // Incremento de tamaño en cada prueba
    const int TAMANIO_INICIAL = 10000;  // Comenzamos desde 10.000 elementos

    // Archivos de los diferentes datasets
    string archivos[] = {
        "Datasets/dataset_aleatorio.txt",
        "Datasets/dataset_ordenado.txt",
        "Datasets/dataset_inversamente_ordenado.txt",
        "Datasets/dataset_repetido.txt",
        "Datasets/dataset_casi_ordenado.txt"
    };

    // Archivos donde se almacenarán los tiempos
    string archivos_salida[] = {
        "tiempos_aleatorio.csv",
        "tiempos_ordenado.csv",
        "tiempos_inversamente_ordenado.csv",
        "tiempos_repetido.csv",
        "tiempos_casi_ordenado.csv"
    };

    for (int i = 0; i < 5; i++) {
        string archivo = archivos[i];
        string archivo_salida = archivos_salida[i];

        cout << "Probando dataset: " << archivo << endl;

        // Inicializar archivo de salida con el encabezado
        ofstream archivo_out(archivo_salida);
        archivo_out << "Tamaño,Selection Sort,Merge Sort,Quick Sort,std::sort" << endl;

        // Leer el dataset completo una sola vez (hasta MAX_ELEMENTOS)
        vector<int> dataset_completo = leer_dataset(archivo, MAX_ELEMENTOS);
        cout<<"Se leyó el dataset correctamente"<<endl;

        // Realizar pruebas con tamaños que van desde 10.000 hasta 1.000.000, incrementando en 100.000
        for (int tamaño = TAMANIO_INICIAL; tamaño <= MAX_ELEMENTOS; tamaño += INCREMENTO) {
            if (tamaño == 110000) {
                tamaño = 100000;  // Ajuste específico para tamaño 60,000
            }
            cout << "\nTamaño del dataset: " << tamaño << " elementos" << endl;

            // Crear un subconjunto del dataset original
            vector<int> dataset(dataset_completo.begin(), dataset_completo.begin() + tamaño);

            // Medir tiempo de Selection Sort
            vector<int> dataset_selection = dataset;  // Crear una copia del dataset original
            cout << "Se está ejecutando Selection Sort" << endl;
            auto tiempo_inicial_selection = high_resolution_clock::now();
            selectionSort(&dataset_selection[0], dataset_selection.size());
            auto tiempo_final_selection = high_resolution_clock::now();
            auto duracion_selection = duration_cast<microseconds>(tiempo_final_selection - tiempo_inicial_selection).count();

            // Medir tiempo de Merge Sort
            vector<int> dataset_merge = dataset;  // Crear una copia del dataset original
            cout << "Se está ejecutando Merge Sort" << endl;
            auto tiempo_inicial_merge = high_resolution_clock::now();
            mergeSort(dataset_merge, 0, dataset_merge.size() - 1);
            auto tiempo_final_merge = high_resolution_clock::now();
            auto duracion_merge = duration_cast<microseconds>(tiempo_final_merge - tiempo_inicial_merge).count();

            // Medir tiempo de Quick Sort
            vector<int> dataset_quick = dataset;  // Crear una copia del dataset original
            cout << "Se está ejecutando Quick Sort" << endl;
            auto tiempo_inicial_quick = high_resolution_clock::now();
            quickSort(dataset_quick, 0, dataset_quick.size() - 1);
            auto tiempo_final_quick = high_resolution_clock::now();
            auto duracion_quick = duration_cast<microseconds>(tiempo_final_quick - tiempo_inicial_quick).count();

            // Medir tiempo de std::sort
            vector<int> dataset_std = dataset;  // Crear una copia del dataset original
            cout << "Se está ejecutando Sort de C++" << endl;
            auto tiempo_inicial_std = high_resolution_clock::now();
            sort(dataset_std.begin(), dataset_std.end());
            auto tiempo_final_std = high_resolution_clock::now();
            auto duracion_std = duration_cast<microseconds>(tiempo_final_std - tiempo_inicial_std).count();

            // Escribir los tiempos en el archivo correspondiente
            escribir_tiempos(archivo_out, tamaño, duracion_selection, duracion_merge, duracion_quick, duracion_std);
        }

        archivo_out.close();  // Cerrar el archivo después de todas las pruebas
        cout << "Resultados guardados en " << archivo_salida << endl;
        cout << endl;  // Separador entre datasets
    }
    return 0;
}


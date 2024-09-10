#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Realiza la partición del arreglo para el algoritmo de QuickSort.
 * 
 * Esta función toma un arreglo y selecciona un pivote. Luego reorganiza el arreglo de modo que
 * todos los elementos menores o iguales al pivote queden a su izquierda, y los elementos mayores
 * queden a su derecha.
 * 
 * @param arr El vector a particionar.
 * @param low Índice inicial del subarreglo.
 * @param high Índice final del subarreglo.
 * @return El índice del pivote después de la partición.
 */
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Se elige el último elemento como pivote
    int i = (low - 1); // Índice del elemento más pequeño
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // Se intercambian los elementos menores o iguales al pivote
        }
    }
    swap(arr[i + 1], arr[high]); // Coloca el pivote en su posición correcta
    return (i + 1); // Retorna la posición del pivote
}

/**
 * @brief Realiza una partición aleatoria del arreglo para el algoritmo de QuickSort.
 * 
 * Esta función selecciona un pivote aleatorio para mejorar la eficiencia en el peor caso de QuickSort.
 * Luego realiza la partición usando la función `partition`.
 * 
 * @param arr El vector a particionar.
 * @param low Índice inicial del subarreglo.
 * @param high Índice final del subarreglo.
 * @return El índice del pivote después de la partición.
 */
int partition_r(vector<int>& arr, int low, int high) {
    srand(time(NULL)); // Genera una semilla aleatoria
    int random = low + rand() % (high - low); // Elige un índice aleatorio entre low y high
    swap(arr[random], arr[high]); // Intercambia el elemento aleatorio con el último
    return partition(arr, low, high); // Realiza la partición con el pivote aleatorio
}

/**
 * @brief Algoritmo de ordenamiento QuickSort.
 * 
 * Esta función implementa el algoritmo de ordenamiento QuickSort utilizando particiones aleatorias para mejorar
 * el rendimiento promedio. Ordena el subarreglo definido por los índices low y high.
 * 
 * @param arr El vector a ordenar.
 * @param low Índice inicial del subarreglo a ordenar.
 * @param high Índice final del subarreglo a ordenar.
 */
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition_r(arr, low, high); // Encuentra la posición del pivote
        quickSort(arr, low, pi - 1); // Ordena los elementos antes del pivote
        quickSort(arr, pi + 1, high); // Ordena los elementos después del pivote
    }
}

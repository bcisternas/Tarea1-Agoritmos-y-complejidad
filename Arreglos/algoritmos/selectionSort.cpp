#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Algoritmo de ordenamiento por selección (Selection Sort).
 * 
 * Esta función ordena un arreglo utilizando el algoritmo de Selection Sort. El algoritmo
 * recorre el arreglo y en cada iteración encuentra el elemento más pequeño en la porción
 * no ordenada del arreglo y lo coloca en su posición correcta intercambiándolo con el
 * elemento en la posición actual.
 * 
 * @param arr El arreglo a ordenar.
 * @param n La cantidad de elementos en el arreglo.
 */
void selectionSort(int arr[], int n) {
    // Mueve el límite de la sublista no ordenada uno por uno
    for (int i = 0; i < n - 1; i++) {
        // Encuentra el elemento mínimo en la sublista no ordenada
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Intercambia el elemento mínimo encontrado con el primer elemento
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

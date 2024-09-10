#include <bits/stdc++.h>
using namespace std;

/**
 * merge() Combina dos subarreglos ordenados en uno solo.
 * 
 * Esta función toma dos subarreglos de un arreglo principal y los combina de manera ordenada.
 * Los subarreglos están definidos por los índices left, mid y right del arreglo principal.
 * 
 * @param arr El arreglo principal que contiene los subarreglos.
 * @param left Índice inicial del primer subarreglo.
 * @param mid Índice final del primer subarreglo.
 * @param right Índice final del segundo subarreglo.
 */
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear vectores temporales
    vector<int> L(n1), R(n2);

    // Copiar datos a los vectores temporales L[] y R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Combinar los vectores temporales nuevamente en arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si hay alguno
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay alguno
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * mergeSort() Ordena un arreglo usando el algoritmo de Merge Sort.
 * 
 * Esta función implementa el algoritmo de Merge Sort, un algoritmo de ordenamiento por 
 * divide y vencerás. Divide el arreglo en dos mitades, las ordena de forma recursiva y 
 * luego combina las mitades ordenadas.
 * 
 * @param arr El arreglo a ordenar.
 * @param left Índice inicial del subarreglo.
 * @param right Índice final del subarreglo.
 */
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    // Encuentra el punto medio del arreglo
    int mid = left + (right - left) / 2;

    // Ordenar recursivamente las dos mitades
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Combina las dos mitades ordenadas
    merge(arr, left, mid, right);
}


// sortAlgorithms.h
#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <bits/stdc++.h>

using namespace std;

// Declaraciones de funciones

// Selection Sort
void selectionSort(int arr[], int n);

// Merge Sort
void mergeSort(vector<int>& arr, int left, int right);

// Quick Sort
void quickSort(vector<int>& arr, int low, int high);

#endif // SORT_ALGORITHMS_H

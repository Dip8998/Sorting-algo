#include <iostream>
#include <algorithm>
using namespace std;

void countSort(int arr[], int n, int exponent) {
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exponent) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int idx = (arr[i] / exponent) % 10;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxVal = *max_element(arr, arr + n);
    for (int exponent = 1; maxVal / exponent > 0; exponent *= 10)
        countSort(arr, n, exponent);
}

void processRadixSort(int arr[], int n) {
    int hasNegative = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] < 0) hasNegative = 1;
    if (!hasNegative) {
        radixSort(arr, n);
        return;
    }
    int pos[n], neg[n], posCount = 0, negCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) pos[posCount++] = arr[i];
        else neg[negCount++] = -arr[i];
    }
    radixSort(pos, posCount);
    radixSort(neg, negCount);
    for (int i = 0; i < negCount; i++)
        arr[i] = -neg[negCount - i - 1];
    for (int i = 0; i < posCount; i++)
        arr[negCount + i] = pos[i];
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fillDynamicArrayWithRandomValues(int** arr, int* n) {
    cout << "Enter the size of the array: ";
    cin >> *n;
    *arr = new int[*n];
    srand(time(0));
    for (int i = 0; i < *n; i++) {
        (*arr)[i] = rand() % 2000 - 1000;
    }
}

int main() {
    int* arr;
    int n;
    fillDynamicArrayWithRandomValues(&arr, &n);
    cout << "Unsorted array: ";
    displayArray(arr, n);
    processRadixSort(arr, n);
    cout << "Sorted array: ";
    displayArray(arr, n);
    delete[] arr;
    return 0;
}

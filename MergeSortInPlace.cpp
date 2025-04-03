#include <iostream>
using namespace std;

void inPlaceMerge(int arr[], int start, int mid, int end) {
    int start2 = mid + 1;
    if (arr[mid] <= arr[start2]) return;
    while (start <= mid && start2 <= end) {
        if (arr[start] <= arr[start2]) {
            start++;
        } else {
            int value = arr[start2], index = start2;
            while (index != start) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;
            start++;
            mid++;
            start2++;
        }
    }
}

void inPlaceMergeSort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    inPlaceMergeSort(arr, left, mid);
    inPlaceMergeSort(arr, mid + 1, right);
    inPlaceMerge(arr, left, mid, right);
}

void processInPlaceMergeSort(int arr[], int n) {
    inPlaceMergeSort(arr, 0, n - 1);
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
        (*arr)[i] = rand() % 1000;
    }
}

int main() {
    int* arr;
    int n;
    fillDynamicArrayWithRandomValues(&arr, &n);
    cout << "Unsorted array: ";
    displayArray(arr, n);
    processInPlaceMergeSort(arr, n);
    cout << "Sorted array: ";
    displayArray(arr, n);
    delete[] arr;
    return 0;
}

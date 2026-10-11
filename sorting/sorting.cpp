#include <iostream>
using namespace std;

// ==================== Bubble Sort ====================

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


// ==================== Selection Sort ====================

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {

        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}


// ==================== Insertion Sort ====================

void insertionSort(int arr[], int n) {

    for (int i = 1; i < n; i++) {

        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


// ==================== Merge Sort ====================

void merge(int arr[], int left, int mid, int right) {

    int temp[100];
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {

        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = 0; x < k; x++) {
        arr[left + x] = temp[x];
    }
}


void mergeSort(int arr[], int left, int right) {

    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);

    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}


// ==================== Quick Sort ====================

int partitionArray(int arr[], int low, int high) {

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {

            i++;

            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}


void quickSort(int arr[], int low, int high) {

    if (low >= high)
        return;

    int pivotIndex = partitionArray(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);

    quickSort(arr, pivotIndex + 1, high);
}


// ==================== Print Array ====================

void printArray(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}



int main() {

    int arr[] = {99, 44, 6, 2, 1, 5, 63, 87, 4, 0};

    int n = sizeof(arr) / sizeof(arr[0]);


    cout << "Original Array: ";
    printArray(arr, n);


    
    // Bubble
    bubbleSort(arr, n);

    cout << "Bubble Sort: ";
    printArray(arr, n);


    // // Selection
    // selectionSort(arr, n);

    // cout << "Selection Sort: ";
    // printArray(arr, n);


    // // Insertion
    // insertionSort(arr, n);

    // cout << "Insertion Sort: ";
    // printArray(arr, n);


    // // Merge
    // mergeSort(arr, 0, n - 1);

    // cout << "Merge Sort: ";
    // printArray(arr, n);


    // // Quick
    // quickSort(arr, 0, n - 1);

    // cout << "Quick Sort: ";
    // printArray(arr, n);


    return 0;
}
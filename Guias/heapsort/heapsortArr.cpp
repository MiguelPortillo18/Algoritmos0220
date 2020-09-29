#include <iostream>

using namespace std;

int left(int i);
int right(int i);
void heapSort(int arr[], int n);
void printArray(int arr[], int n);
void max_heapify(int arr[], int n, int i);

int main(void) {

    int arr[] = {45,1,24,18,2,3,9,15,26,28,89,10,13};
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    heapSort(arr, n);
    
    cout << "Sorted array: \n";
    
    printArray(arr, n);

    return 0;
}

void max_heapify(int arr[], int n, int i) {
    
    int largest = i;
    
    int l = left(i);
    
    int r = right(i);
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
        
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        max_heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    
    //Simplifying build_max_heap function
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);

    //loop from the function
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    
    cout << arr[i] << " ";
    
    cout << "\n";
}

int left(int i) {
    return 2 * i;
}


int right(int i) {
    return 2 * i + 1;
}
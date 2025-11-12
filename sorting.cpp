#include <iostream>
using namespace std;

//Bubble Sort - Algorithm 1
void algoBubble1(int arr[], int n) {
    for(int pass = 0; pass < n-1; pass++) {
        for(int j = 0; j < n-1; j++) {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

//Bubble Sort - Algorithm 2
void algoBubble2(int arr[], int n) {
    for(int pass = 0; pass < n-1; pass++) {
        for(int j = 0; j < n-pass-1; j++) {
            if(arr[j] > arr[j+1]) 
                swap(arr[j], arr[j+1]);
        }
    }
}

//Bubble Sort - Algorithm 3
void algoBubble3(int arr[], int n) {
    int flag;
    for(int pass = 0; pass < n-1; pass++) {
        flag = 0;
        for(int j = 0; j < n-pass-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}

//Selection Sort
void selectionSort(int arr[], int n) {
    int min_ind;
    for(int pass = 0; pass <= n-2; pass++) {
        min_ind = pass;
        for(int j = pass + 1; j < n; j++) {
            if(arr[min_ind] > arr[j])
                min_ind = j;
        }
        swap(arr[pass], arr[min_ind]);
    }
}

//Insertion Sort
void insertionSort(int arr[], int n) {
    for(int j = 1; j < n; j++) {
        int key = arr[j];
        int i = j - 1;
        while(i >= 0 && key < arr[i]) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

//Input Array
void setArray(int arr[], int n) {
    cout << "Enter " << n << " elements: " << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << endl;
}

//Print Array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;

    cout << endl << "Enter size of array: ";
    cin >> n;
    cout << endl;

    int arr[n];

    setArray(arr, n);

    cout << "Before Sorting: " << endl;
    printArray(arr, n);
    cout << endl;

    insertionSort(arr, n);

    cout << "After Sorting: " << endl;
    printArray(arr, n);

    return 0;
}
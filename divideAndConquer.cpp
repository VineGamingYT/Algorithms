#include <iostream>
using namespace std;

int binarySearch(int arr[], int i, int j, int key) {
    if(i == j) {
        if(key == arr[i])
            return i;
        else
            return -1;
    }
    else {
        int mid = (i + j) / 2;

        if(key == arr[mid])
            return mid;
        else if(key < arr[mid])
            return binarySearch(arr, i, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, j, key);
    }
}

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

void minMax(int arr[], int i, int j, int &min, int &max) {
    if(i == j)
        min = max = arr[i];
    else if(j - i == 1) {
        if(arr[i] < arr[j]){
            min = arr[i];
            max = arr[j];
        }
        else {
            min = arr[j];
            max = arr[i];
        }
    }
    else {
        int min1, max1;
        int mid = (i + j) / 2;

        minMax(arr, i, mid, min, max);
        minMax(arr, mid + 1, j, min1, max1);

        if(min > min1) 
            min = min1;
        if(max < max1)
            max = max1;
    }
}

void setArray(int arr[], int n) {
    cout << "Enter " << n << " elements: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << endl;
}

void printArray(int arr[], int n) {
    cout << "This is your input: " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int min, max, n;

    cout << endl << "Enter size of array: ";
    cin >> n;
    cout << endl;

    int arr[n];

    setArray(arr, n);

    // printArray(arr, n);

    // minMax(arr, 0, n - 1, min, max);

    // cout << endl << endl;
    // cout << "Minimum: " << min << endl;
    // cout << "Maximum: " << max << endl << endl;

    insertionSort(arr, n);

    printArray(arr, n);

    int key;

    cout << "\n\nEnter key: ";
    cin >> key;
    cout << endl;

    int res = binarySearch(arr, 0, n - 1, key);

    if(res != -1)
        cout << "Element found at index: " << res << endl << endl;
    else
        cout << "Element not found!!!\n\n";

    return 0;
}
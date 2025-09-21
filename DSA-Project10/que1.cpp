#include <iostream>
using namespace std;

// Selection Sort 
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    cout << "Array sorted using Selection Sort."<<endl;
}

//  Merge Sort 
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *Left = new int[n1];
    int *Right = new int[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k++] = Left[i++];
        } else {
            arr[k++] = Right[j++];
        }
    }
    while (i < n1)
        arr[k++] = Left[i++];
    while (j < n2)
        arr[k++] = Right[j++];

    delete[] Left;
    delete[] Right;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

//  Linear Search 
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search 
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

//  Display Array 
void displayArray(int arr[], int n) {
    cout << "Array is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int *arr = new int[n];

    cout << "Enter " << n << " elements:"<<endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int choice, key;
    do {
        cout << "--- Menu ---"<<endl;
        cout << "1. Selection Sort"<<endl;
        cout << "2. Merge Sort"<<endl;
        cout << "3. Linear Search"<<endl;
        cout << "4. Binary Search"<<endl;
        cout << "5. Display Array"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            selectionSort(arr, n);
            displayArray(arr, n);
            break;
        case 2:
            mergeSort(arr, 0, n - 1);
            cout << "Array sorted using Merge Sort."<<endl;
            displayArray(arr, n);
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> key;
            {
                int index = linearSearch(arr, n, key);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found."<<endl;
            }
            break;
        case 4:
            cout << "Enter element to search: ";
            cin >> key;
            {
                int index = binarySearch(arr, n, key);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found."<<endl;
            }
            break;
        case 5:
            displayArray(arr, n);
            break;
        case 0:
            cout << "Exiting program..."<<endl;
            break;
        default:
            cout << "Invalid choice. Try again."<<endl;
        }
    } while (choice != 0);

    delete[] arr;
    return 0;
}

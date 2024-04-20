#include<iostream>
#include <algorithm>
using namespace std;

int* once_only(int arr1[], int size1, int arr2[], int size2, int* size3) {
    int* result = new int[100]; // assuming maximum size of 100
    int index = 0;
    for(int i = 0; i < size1; i++) {
        if(std::count(arr2, arr2 + size2, arr1[i]) == 0) {
            result[index++] = arr1[i];
        }
    }
    for(int i = 0; i < size2; i++) {
        if(std::count(arr1, arr1 + size1, arr2[i]) == 0) {
            result[index++] = arr2[i];
        }
    }
    *size3 = index;
    int* newResult = new int[*size3];
    for(int i = 0; i < *size3; i++) {
        newResult[i] = result[i];
    }
    delete[] result;
    return newResult;
}

int main() {
    int size1, size2, size3;
    cout << "Enter the size of the first series: ";
    cin >> size1;
    int arr1[20];
    cout << "Enter the series: ";

    for(int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second series: ";
    cin >> size2;
    int arr2[20];
    cout << "Enter the series: ";

    for(int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    int* result = once_only(arr1, size1, arr2, size2, &size3);
    cout << "The new array is: ";

    for(int i = 0; i < size3; i++) {
        cout << result[i] << " ";
    }
    
    cout << "\nThe size of the new array is: " << size3 << endl;
    delete[] result;
    return 0;
}
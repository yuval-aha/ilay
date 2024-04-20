#include <iostream>
#include <cstdlib>
#include <ctime>

int longest_series(int arr[], int size) {
    if (size == 0) return 0;

    int current = 1, max = 1;

    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[i - 1]) {
            current++;
        } else {
            max = std::max(max, current);
            current = 1;
        }
    }

    max = std::max(max, current);

    return max;
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size];

    std::srand(std::time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 50 + 1;
        std::cout << arr[i] << " ";
    }
    
    std::cout << std::endl;

    int length = longest_series(arr, size);
    std::cout << "The length of the longest ascending series is: " << length << std::endl;

    delete[] arr;
    return 0;
}
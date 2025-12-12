#include <iostream>

// Recursive function to sum array elements
int sumArray(const int arr[], int size) {
    // Base case: if size is 0, sum is 0
    if (size == 0) {
        return 0;
    }
    // Recursive case: current element + sum of remaining elements
    return arr[size - 1] + sumArray(arr, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Sum of array elements: " << sumArray(arr, size) << std::endl;
    return 0;
}

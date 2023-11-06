#include <iostream>
#include <vector>

void findMaxIndexRecursive(const std::vector<int>& arr, int& maxIndex, int index) {
    if (index >= arr.size()) {
        std::cout << "Index of the maximum element: " << maxIndex << std::endl;
        return;
    }

    if (arr[index] > arr[maxIndex]) {
        maxIndex = index;
    }

    findMaxIndexRecursive(arr, maxIndex, index + 1);
}

void productBetweenZerosRecursive(const std::vector<int>& arr, int& product, int index, int firstZero, int secondZero) {
    if (index >= arr.size()) {
        if (firstZero == -1 || secondZero == -1) {
            std::cout << "There are no two 0 elements" << std::endl;
        }
        else {
            product = 1;
            for (int i = firstZero + 1; i < secondZero; ++i) {
                product *= arr[i];
            }
            std::cout << "Product between the first and second zero elements: " << product << std::endl;
        }
        return;
    }

    if (arr[index] == 0) {
        if (firstZero == -1) {
            firstZero = index;
        }
        else if (secondZero == -1) {
            secondZero = index;
        }
    }

    productBetweenZerosRecursive(arr, product, index + 1, firstZero, secondZero);
}

int main() {
    int n;
    std::cout << "Enter the number of elements (n): ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int product = 0;
    int maxIndex = 0;
    findMaxIndexRecursive(arr, maxIndex, 0);
    productBetweenZerosRecursive(arr, product, 0, -1, -1);

    std::vector<int> transformedArray(n);

    int lastEvenPos = n / 2;
    int lastOddPos = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            transformedArray[lastEvenPos] = arr[i];
            lastEvenPos += 1;
        }
        else {
            transformedArray[lastOddPos] = arr[i];
            lastOddPos += 1;
        }
    }

    std::cout << "Transformed array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << transformedArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

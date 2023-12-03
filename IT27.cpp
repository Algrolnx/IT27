#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

double calculatePositiveSum(double arr[], int size) {
    double positiveSum = 0.0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            positiveSum += arr[i];
        }
    }
    return positiveSum;
}

int findMaxAbsElementIndex(double arr[], int size) {
    int maxIndex = 0;
    double maxAbsValue = abs(arr[0]);

    for (int i = 1; i < size; ++i) {
        if (abs(arr[i]) > maxAbsValue) {
            maxAbsValue = abs(arr[i]);
            maxIndex = i;
        }
    }

    return maxIndex;
}

int findMinAbsElementIndex(double arr[], int size) {
    int minIndex = 0;
    double minAbsValue = abs(arr[0]);

    for (int i = 1; i < size; ++i) {
        if (abs(arr[i]) < minAbsValue) {
            minAbsValue = abs(arr[i]);
            minIndex = i;
        }
    }

    return minIndex;
}

void sortDescending(double arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    const int size = 5;
    double arr[size] = { 3, -2, 1, -4, 6 };

    double positiveSum = calculatePositiveSum(arr, size);
    cout << "Сума додатних елементів: " << positiveSum << endl;

    int maxIndex = findMaxAbsElementIndex(arr, size);
    int minIndex = findMinAbsElementIndex(arr, size);

    double product = 1.0;
    int startIndex = min(minIndex, maxIndex) + 1;
    int endIndex = max(minIndex, maxIndex) - 1;

    for (int i = startIndex; i <= endIndex; ++i) {
        product *= arr[i];
    }

    cout << "Добуток елементів між max та min за модулем: " << abs(product) << endl;

    sortDescending(arr, size);

    cout << "Відсортований масив за спаданням: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

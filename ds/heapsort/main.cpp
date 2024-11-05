#include <iostream>
using namespace std;

// Функция для перестройки (heapify) поддерева с корнем i, который является индексом в массиве.
// n — это размер кучи
void heapify(int arr[], int n, int i) {
    int largest = i;         // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1;    // Левый дочерний элемент = 2*i + 1
    int right = 2 * i + 2;   // Правый дочерний элемент = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый дочерний элемент больше, чем наибольший элемент на данный момент
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший элемент не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Меняем местами i и largest

        // Рекурсивно перестраиваем затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция для сортировки массива заданного размера
void heapSort(int arr[], int n) {
    // Построение max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень (наибольший элемент) в конец
        swap(arr[0], arr[i]);

        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

// Утилита для вывода массива на экран
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array:\n";
    printArray(arr, n);

    return 0;
}



/*
HeapSort(array)
    BuildMax    

*/
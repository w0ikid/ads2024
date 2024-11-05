#include <iostream>
using namespace std;

// Функция для обмена двух элементов
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция для разделения массива относительно pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Опорный элемент
    int i = low - 1;        // Индекс для меньших элементов

    // Проходим по элементам с low до high - 1
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;  // Увеличиваем индекс для меньших элементов
            swap(arr[i], arr[j]);  // Меняем местами элементы arr[i] и arr[j]
        }
    }

    // Меняем местами pivot с элементом на его правильной позиции
    swap(arr[i + 1], arr[high]);
    return (i + 1);  // Возвращаем индекс pivot
}

// Основная функция сортировки Quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Разделяем массив и получаем индекс pivot
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем левую часть
        quickSort(arr, low, pi - 1);

        // Рекурсивно сортируем правую часть
        quickSort(arr, pi + 1, high);
    }
}

/*
QuickSort(array, low, high)
    if low < high
        pivotLocation = Partition(A, low, high)
        Quicksort(A, low, pivotLocation)
        QuickSort(A, pivotLocation + 1, high)

Partition(array, low, high)
    pivot = array[low]
    leftwall = low

    for i = low + 1 to high
        if array[i] < pivot
            swap(array, array[leftwall])
            leftwall++

    swap(pivot, leftwall)
    return leftwall















QuickSort(array, low, high)
    if low < high
        pivotLocation = Partition(array, low, high)
        Quicksort(array, low, pivotLocation)
        QuickSort(array, pivotLocation + 1, high)


Partition(array, low, high)
    pivot = array[low]
    leftwall = low - 1

    for i = low + 1 to high
        if array[i] < pivot
            swap(array[i], array[leftwall])
            leftwall++

    swap(pivot, array[leftwall])
    return leftwall

*/





// Функция для вывода массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Отсортированный массив: ";
    printArray(arr, n);

    return 0;
}
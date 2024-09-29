#include <iostream>

void insertionSort(int arr[], int size){
    for (size_t i = 1; i < size - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]){
            std::swap(arr[j], arr[j-1]);
            j--;
        }
    }
    
}

int main(){
    int size = 5;
    int array[size] = {4,32,8,2,40};

    insertionSort(array, size);

    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}
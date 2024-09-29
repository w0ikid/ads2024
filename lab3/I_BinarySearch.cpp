#include <iostream>

bool inThisArray(int* arr, int x, int len){
    int low = 0;
    int high = len - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == x){
            return true;
        }
        else if (arr[mid] < x){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return false;
}

int main(){
    int n;
    std::cin >> n;
    int array[n];
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }
    int find;
    std::cin >> find;
    if (inThisArray(array, find, n) == true){
        std::cout << "Yes" << "\n";
    } else {
        std::cout << "No" << "\n";
    }
    return 0;
}
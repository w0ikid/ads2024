#include <iostream>
#include <chrono> // Для измерения времени

int main() {
    int num = 123456789;
    bool is_even;

    // Измерение времени для побитовой операции
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000000; ++i) {
        is_even = (num & 1) == 0;  // Побитовая операция
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Побитовая операция: " << elapsed.count() << " секунд\n";

    // Измерение времени для деления с остатком
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000000; ++i) {
        is_even = (num % 2) == 0;  // Деление с остатком
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Деление с остатком: " << elapsed.count() << " секунд\n";

    return 0;
}

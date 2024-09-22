#include <iostream>

struct Node {
    int data;
    int count;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int newData) {
        Node* current = head;

        //если число уже существует в списке увеличиваем его счётчик
        while (current != nullptr) {
            if (current->data == newData) {
                current->count++;
                return;
            }
            current = current->next;
        }

        // если число новое то добавляем новый узел
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->count = 1;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void mode(int len) {
        if (head == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        // максимальная частота
        int maxCount = 0;
        Node* current = head;
        while (current != nullptr) {
            if (current->count > maxCount) {
                maxCount = current->count;
            }
            current = current->next;
        }

        // считаем кол элементов с максимальной част
        int countOfMaxElements = 0;
        current = head;
        while (current != nullptr) {
            if (current->count == maxCount) {
                countOfMaxElements++;
            }
            current = current->next;
        }

        // массив для хранения модных чисел
        int* array = new int[countOfMaxElements];
        int index = 0;
        current = head;
        while (current != nullptr) {
            if (current->count == maxCount) {
                array[index++] = current->data;
            }
            current = current->next;
        }

        bubbleSort(array, countOfMaxElements);

        delete[] array;  // Освобождаем динамически выделенную память
    }

    void bubbleSort(int* array, int len) {
        for (size_t i = 1; i < len; i++) {
            for (size_t j = 0; j < len - i; j++) {
                if (array[j] < array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }

        for (size_t i = 0; i < len; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    LinkedList list;

    int n, value;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        list.append(value);
    }
    list.mode(n);
    return 0;
}

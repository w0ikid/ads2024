#include <iostream>

struct Node {
    std::string data;
    Node* next;
};

class LinkedList
{
public:
    Node* head; // указатель на первый элемент списка

    LinkedList() : head(nullptr) {} // конструктор, изначально список пуст

    void append(std::string newData) {
        Node* newNode = new Node(); // новый узел
        newNode->data = newData;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode; // если список пуст, новый узел становится первым
        } else {
            Node* last = head;
            while (last->next != nullptr) {
                last = last->next; // находим последний узел
            }
            last->next = newNode;
        }
    }

    Node* shift(int n, int k) {
        if (n == 0 || k % n == 0) {
            return head;
        }
        k = k % n; // вычисляем эффективный сдвиг

        // находим (n - k)-й узел
        Node* current = head;
        int count = 1;
        while (count < n - k) {
            current = current->next;
            count++;
        }

        // новый "головной" узел
        Node* newHead = current->next;
        current->next = nullptr;

        // ищем последний элемент нового списка
        Node* last = newHead;
        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = head; // соединяем конец списка с началом

        return newHead;
    }

    void display(Node* start) { // добавляем параметр для указания начала списка
        Node* current = start;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    // Деструктор для освобождения памяти
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};


int main() {
    int n, k;
    std::cin >> n >> k;

    LinkedList list;
    for (int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        list.append(word);
    }

    Node* newHead = list.shift(n, k);
    list.display(newHead); // передаем новый head в display()

    return 0;
}

#include <iostream>

struct Node {
    std::string data;
    Node* next;
};

class LinkedList
{
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void append(std::string newData) {
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* shift(int n, int k) {
        if (n == 0 || k % n == 0) {
            return head;
        }
        k = k % n;
        Node* newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }
        Node* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        tail = newTail;
        return newHead;
    }

    void display(Node* start) {
        Node* current = start;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

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
    list.display(newHead);

    return 0;
}

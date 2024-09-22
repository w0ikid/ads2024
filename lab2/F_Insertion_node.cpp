#include <iostream>

struct Node {
    int data;
    int index;
    Node* next;
};

class LinkedList{
public:
    Node* head;
    int indexCount = 0;
    LinkedList() : head(nullptr) {}

    void append(int newData){
        Node* newNode = new Node();

        newNode->data = newData;
        newNode->index = indexCount;
        indexCount++;
        newNode->next = nullptr;

        if (head == nullptr){
            head = newNode;
        } else {
            Node* current = head;

            while(current->next != nullptr){
                current = current->next;
            }

            current->next = newNode;
        }
    }

void insert(int index, int num) {
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = nullptr;
    
    // If inserting at the beginning of the list
    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    // Traverse to the position before the target index
    while (current != nullptr && current->index != index) {
        prev = current;
        current = current->next;
    }

    // Insert new node between prev and current
    if (prev != nullptr) {
        prev->next = newNode;
        newNode->next = current;
    }
}

    void display(){
        Node* current = head;

        while(current != nullptr){
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << "\n";
    }

};

int main(){
    LinkedList list;
    int n, num, position, k;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> num;
        list.append(num);
    }
    std::cin >> k >> position;
    list.insert(position, k);
    list.display();
    return 0;
}
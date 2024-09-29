#include <iostream>

struct Node {
    std::string data;
    Node* prev;
    Node* next;

    Node(std::string newData) : data(newData), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void PushFront(std::string newData){
        Node* newNode = new Node(newData);

        if (this->head == nullptr){
            this->head = newNode;
            this->tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;   
            head = newNode;
        }
    }

    void PushBack(std::string newData){
        Node* newNode = new Node(newData);

        if (this->head == nullptr){
            this->head = newNode;
            this->tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void PopFront(){
        if(this->head == nullptr){
            return;
        }

        Node* nextNode = head->next;
        delete head;
        head = nextNode;

        if (head == nullptr){
            this->tail = nullptr;
        } else {
            head->prev = nullptr;
        }
    }

    void PopBack() {
        if (this->tail == nullptr)
        {
            return;
        }
        
        Node* prevNode = tail->prev;
        delete tail;
        tail = prevNode;

        if (tail == nullptr)
        {
            this->head = nullptr;
        } else {
            tail->next = nullptr;
        }
    }

    void Clear() {
        while (head != nullptr) {
            PopFront();
        }
    }

    std::string Front() {
        if (this->head == nullptr){
            return "error";
        }
        return this->head->data;
    }

    std::string Back() {
        if (this->tail == nullptr){
            return "error";
        }
        return this->tail->data;
    }

    void PrintList(){
        Node* current = head;
        while(current != nullptr){
            std::cout << current->data << "\n";
            current = current->next;
        }
    }
};

int main(){
    DoublyLinkedList list;
    std::string input;
    std::cin >> input;
    while(input != "exit"){
        if (input == "add_front"){
            std::string value;
            std::cin >> value;
            list.PushFront(value);
            std::cout << "ok\n";
        }
        else if (input == "add_back"){
            std::string value;
            std::cin >> value;
            list.PushBack(value);
            std::cout << "ok\n";
        }
        else if (input == "erase_front"){
            std::cout << list.Front() << "\n";
            list.PopFront();
        }
        else if (input == "erase_back"){
            std::cout << list.Back() << "\n";
            list.PopBack();
        }
        else if (input == "front"){
            std::cout << list.Front() << "\n";
        }
        else if (input == "back"){
            std::cout << list.Back() << "\n";
        }
        else if (input == "clear"){
            std::cout << "ok" << "\n";
            list.Clear();
        }
        std::cin >> input;
    }
    std::cout << "goodbye";
    return 0;
}
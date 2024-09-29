#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int newData) : data(newData), next(nullptr) {}
};

class LinkedList 
{
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int newData){
        Node* newNode = new Node(newData);

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
    // helper function
    void displayReversedOrderHelper(Node* node){
        if (node == nullptr) {
            return;
        }

        displayReversedOrderHelper(node->next);
        std::cout << node->data << " ";
    }

    void displayReversed(){
        displayReversedOrderHelper(head);
    }
};
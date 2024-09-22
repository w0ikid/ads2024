#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
public:
    Node* head;
    LinkedList() : head(nullptr) {};

    void append(int newData){
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->next = nullptr;

        if (head == nullptr){
            head = newNode;
        } else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteEverySecond(){
        if (head == nullptr || head->next == nullptr){
            return;
        }

        Node* prev = head;
        Node* current = head->next;

        while(current != nullptr){
            prev->next = current->next;
            delete current;

            if (prev->next != nullptr){
                prev = prev->next;
                current = prev->next;
            } else {
                break;
            }            
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

    ~LinkedList(){
        Node* current = head;
        while(current != nullptr){
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main(){
    LinkedList list;
    int n;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {   
        int num;
        std::cin >> num;
        list.append(num);
    }
    list.deleteEverySecond();
    list.display();
    return 0;
}
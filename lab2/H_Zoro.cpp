#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    if(p == 0) {
        node -> next = head;
        head = node;
    } else {
        Node * cur = head;

        for(int i = 0; i < p - 1; i++) {
            cur = cur -> next;
        }

        if (cur == nullptr) return head;

        node -> next = cur -> next;
        cur -> next = node;

    }        
    return head;
}
 
Node* remove(Node* head, int p) {
    Node * cur = head;
    if(p == 0) {
        head = cur -> next;
        delete cur;
    } else {
        for(int i = 0; i < p - 1; i++) {
            cur = cur -> next;
        }
        Node* temp = cur -> next -> next;
        delete cur -> next;
        cur -> next = temp;
    }    

    return head;
}
 
Node* replace(Node* head, int p1, int p2) {
    if(p1 == p2) {
        return head;
    }
    Node * cur = head;
    Node * move = nullptr;
    Node * prev = nullptr;

    if(p1 == 0) {
        move = head;
        head = head -> next;
    } else {
        for(int i = 0; i < p1; i++) {
            prev = cur;
            cur = cur -> next;
        }

        move = cur;
        prev -> next = cur -> next; 
    }

    if(p2 == 0) {
        move -> next = head;
        head = move;
    } else {
        Node * insert = head;
        for(int i = 0; i < p2 - 1; i++) {
            insert = insert -> next;
        }

        move -> next = insert -> next;
        insert -> next = move;
    }    

    return head;
}
 
Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* prev = nullptr;
    Node* cur = head;
    Node* next = nullptr;

    while (cur != nullptr) {
        next = cur -> next; 
        cur -> next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}
 
void print(Node* head){
    if(head == nullptr) cout << -1;
    else {
        Node * cur = head;
        while(cur != nullptr) {
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }

    cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    Node * cur = head;

    while (cur -> next != nullptr) {
        cur = cur -> next;
    }

    while (x--) {
        cur -> next = head;
        head = head -> next;
        cur = cur -> next;
        cur -> next = nullptr;
    }

    return head;
}
 
Node* cyclic_right(Node* head, int x){
    Node* cur = head;
    int length = 1;

    while (cur -> next != nullptr) {
        cur = cur -> next;
        length++;
    }

    cur -> next = head;
    x = length - x;

    while (x--) {
        cur = cur -> next;
    }

    head = cur -> next;
    cur -> next = nullptr;    

    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true) {
        int command; cin >> command;
        if (command == 0) {
            break;
        } else if(command == 1) {
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        } else if (command == 2) {
            int p; cin >> p;
            head = remove(head, p);
        } else if (command == 3) {
            print(head);
        } else if (command == 4) {
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (command == 5) {
            head = reverse(head);
        } else if (command == 6) {
            int x; cin >> x;
            head = cyclic_left(head, x);
        } else if (command == 7) {
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}
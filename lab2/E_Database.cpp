#include <iostream>

using namespace std;


struct Node {
    string val;
    Node * next;
    Node(string x) {
        val = x;
        next = NULL;
    }
};

struct List {
private:
    int size;
    Node * head, * tail;
public:
    List() {
        size = 0;
        head = tail = NULL;
    }

    void add(string x) {
        Node * n = new Node(x);
        if(head == NULL) {
            size++;
            head = tail = n;
        } else if(n -> val != head -> val) {
            n -> next = head;
            head = n;
            size++;
        }
    }

    void print() {
        Node * cur = head;
        cout << "All in all: " << size << endl << "Students:" << endl;
        while(cur != NULL) {
            cout << cur -> val << endl;
            cur = cur -> next;
        }
    }
};


int main() {
    int n; cin >> n;
    string k;
    List q;
    for(int i = 0; i < n; i++) {
        cin >> k;
        q.add(k);
    }
    cin >> k;
    q.print();
}
#include <iostream>
using namespace std;

// Структура узла для дерева
struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

// Класс для работы с деревом бинарного поиска
class BinarySearchTree {
public:
    Node* root;
    
    BinarySearchTree() : root(nullptr) {}
    
    // Вставка элемента в дерево
    void insert(int key) {
        root = insertRec(root, key);
    }
    
    // Поиск элемента в дереве
    bool search(int key) {
        return searchRec(root, key);
    }

    // Удаление элемента из дерева
    void remove(int key) {
        root = removeRec(root, key);
    }
    
    // Обход inorder
    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    // Обход preorder
    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    // Обход postorder
    void postorder() {
        postorderRec(root);
        cout << endl;
    }

    // Минимум в дереве
    int minimum() {
        Node* node = findMin(root);
        if (node) return node->key;
        throw runtime_error("Дерево пустое");
    }

    // Максимум в дереве
    int maximum() {
        Node* node = findMax(root);
        if (node) return node->key;
        throw runtime_error("Дерево пустое");
    }

    // Поиск "floor" (наибольший элемент, меньше или равен заданному)
    int floor(int key) {
        Node* node = floorRec(root, key);
        if (node) return node->key;
        throw runtime_error("Floor не найден");
    }

    // Поиск "ceil" (наименьший элемент, больше или равен заданному)
    int ceil(int key) {
        Node* node = ceilRec(root, key);
        if (node) return node->key;
        throw runtime_error("Ceil не найден");
    }

private:
    // Вспомогательная рекурсивная функция для вставки
    Node* insertRec(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insertRec(node->left, key);
        else
            node->right = insertRec(node->right, key);
        return node;
    }

    // Вспомогательная рекурсивная функция для поиска
    bool searchRec(Node* node, int key) {
        if (!node) return false;
        if (node->key == key) return true;
        if (key < node->key) return searchRec(node->left, key);
        return searchRec(node->right, key);
    }

    // Вспомогательная рекурсивная функция для удаления
    Node* removeRec(Node* node, int key) {
        if (!node) return nullptr;
        if (key < node->key)
            node->left = removeRec(node->left, key);
        else if (key > node->key)
            node->right = removeRec(node->right, key);
        else {
            // Узел с одним дочерним элементом или без детей
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Узел с двумя дочерними элементами
            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->right = removeRec(node->right, temp->key);
        }
        return node;
    }

    // Вспомогательные рекурсивные функции для обходов
    void inorderRec(Node* node) {
        if (node) {
            inorderRec(node->left);
            cout << node->key << " ";
            inorderRec(node->right);
        }
    }

    void preorderRec(Node* node) {
        if (node) {
            cout << node->key << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

    void postorderRec(Node* node) {
        if (node) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->key << " ";
        }
    }

    // Вспомогательная функция для поиска минимума
    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    // Вспомогательная функция для поиска максимума
    Node* findMax(Node* node) {
        while (node && node->right) {
            node = node->right;
        }
        return node;
    }

    // Вспомогательная рекурсивная функция для поиска "floor"
    Node* floorRec(Node* node, int key) {
        if (!node) return nullptr;
        if (node->key == key) return node;
        if (key < node->key) return floorRec(node->left, key);
        Node* temp = floorRec(node->right, key);
        return (temp && temp->key <= key) ? temp : node;
    }

    // Вспомогательная рекурсивная функция для поиска "ceil"
    Node* ceilRec(Node* node, int key) {
        if (!node) return nullptr;
        if (node->key == key) return node;
        if (key > node->key) return ceilRec(node->right, key);
        Node* temp = ceilRec(node->left, key);
        return (temp && temp->key >= key) ? temp : node;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);
    bst.insert(25);
    bst.insert(35);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Preorder traversal: ";
    bst.preorder();

    cout << "Postorder traversal: ";
    bst.postorder();

    cout << "Minimum value: " << bst.minimum() << endl;
    cout << "Maximum value: " << bst.maximum() << endl;

    cout << "Floor of 12: " << bst.floor(12) << endl;
    cout << "Ceil of 12: " << bst.ceil(12) << endl;

    bst.remove(10);
    cout << "After deletion of 10, inorder traversal: ";
    bst.inorder();

    return 0;
}

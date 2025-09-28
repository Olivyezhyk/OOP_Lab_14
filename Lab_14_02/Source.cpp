#include <iostream>
using namespace std;

// --- Структура вузла списку ---
struct Node {
    int data;
    Node* next;
};

// --- Підпрограма для створення списку ---
void createList(Node*& head, int n) {
    head = nullptr;
    Node* tail = nullptr;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        Node* newNode = new Node{ value, nullptr };
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

// --- Підпрограма для виведення списку ---
void printList(const Node* head) {
    const Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// --- Підпрограма для дублювання елементів зі значенням key ---
void duplicateElements(Node*& head, int key) {
    Node* current = head;
    while (current) {
        if (current->data == key) {
            Node* newNode = new Node{ key, current->next };
            current->next = newNode;
            current = newNode->next; // пропускаємо доданий вузол
        }
        else {
            current = current->next;
        }
    }
}

// --- Підпрограма для очищення списку ---
void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// --- Головна функція ---
int main() {
    Node* head = nullptr;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    createList(head, n);  // створення списку

    cout << "Original list: ";
    printList(head);      // виведення списку

    int key;
    cout << "Enter the value to duplicate: ";
    cin >> key;

    duplicateElements(head, key); // дублювання елементів

    cout << "Modified list: ";
    printList(head); // виведення результату

    deleteList(head); // очищення пам'яті
    return 0;
}

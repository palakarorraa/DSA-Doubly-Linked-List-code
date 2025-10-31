#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow!" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty!" << endl;
        return;
    }
    Node* temp = top;
    cout << "Stack elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    pop();
    pop();

    display();

    return 0;
}

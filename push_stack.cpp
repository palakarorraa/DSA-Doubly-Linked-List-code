#include <iostream>
using namespace std;

#define SIZE 5
int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    top++;
    stack[top] = value;
    cout << value << " pushed into stack." << endl;
}

void display() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    return 0;
}

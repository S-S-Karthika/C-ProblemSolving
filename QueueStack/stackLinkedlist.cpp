#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;
public:
    Node(int value) {
        data = value;
        next = nullptr;
    }
    int getData() const { return data; }
    Node* getNext() const { return next; }
    void setNext(Node* nextNode) { next = nextNode; }
};

class StackLinkedList {
private:
    Node* topNode;
    int stackSize;

public:
    StackLinkedList() {
        topNode = nullptr;
        stackSize = 0;
    }

    ~StackLinkedList() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->getNext();
            delete temp;
        }
    }

    // Push operation
    void push(int value) {
        Node* temp = new Node(value);
        temp->setNext(topNode);
        topNode = temp;
        cout << "The pushed value is " << topNode->getData() << endl;
        stackSize++;
    }

    // Pop operation
    int pop() {
        if (topNode == nullptr) {
            cout << "Stack underflow" << endl;
            return -1;
        } else {
            int val = topNode->getData();
            Node* temp = topNode;
            topNode = topNode->getNext();
            cout<<"poped value is "<<val<<endl;
            delete temp;
            stackSize--;
            return val;
        }
    }

    // Get the top value
    int getTop() {
        if (topNode == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return topNode->getData();
    }

    // Get the stack size
    int getSize() const {
        return stackSize;
    }
};

int main() {
    StackLinkedList s;
    s.push(10);
    s.push(20);
    s.pop();
    cout << "Top of the stack is " << s.getTop() << endl;
    cout << "Size of the stack is " << s.getSize() << endl;
    return 0;
}

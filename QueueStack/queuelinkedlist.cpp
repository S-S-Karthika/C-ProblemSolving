#include <iostream>
using namespace std;

// Define a node for the linked list
struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        front = rear = nullptr;
        size = 0;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "The dequeued value is " << front->data << endl;
        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        size--;
    }

    // Peek operation (returns the front of the queue)
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Get the size of the queue
    int getSize() const {
        return size;
    }
};

int main() {
    Queue q;

    q.enqueue(19);
    q.enqueue(30);
    q.enqueue(20);
     q.enqueue(19);
    q.enqueue(30);
    q.enqueue(20);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();
    // q.dequeue();

    if (q.isEmpty()) {
        cout << "Queue is now empty." << endl;
    }

    q.dequeue(); // Should display "Queue is empty"

    cout << "Front element: " << q.peek() << endl;
    cout<<"size is "<<q.getSize();

    return 0;
}

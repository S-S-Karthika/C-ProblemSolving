#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int arr[SIZE];
    int front, rear, size;

public: 
    // Constructor
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // Check if queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if queue is full
    bool isFull() {
        return size == SIZE;
    }

    // Enqueue operation
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << val << endl;
            return;
        }
        rear++;
        arr[rear] = val;
        size++;
        cout << "Enqueued: " << val << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
        size--;

        // Reset pointers if queue becomes empty
        if (size == 0) {
            front = 0;
            rear = -1;
        }
    }

    // Peek (front element)
    int isPeek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    // Get current size
    int getSize() const {
        return size;
    }
};

int main() {
    Queue q;

    q.enqueue(19);
    cout << "Front element: " << q.isPeek() << endl;
    q.enqueue(30);
    cout << "Front element: " << q.isPeek() << endl;
    q.enqueue(20);
    q.enqueue(40);
    cout << "Front element: " << q.isPeek() << endl;
    q.enqueue(50);
    q.enqueue(60);  // Will trigger overflow

    cout << "Front element: " << q.isPeek() << endl;

    q.dequeue();
    q.dequeue();
    cout << "Front element: " << q.isPeek() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();  // Will trigger underflow

    cout << "Front element after all dequeues: " << q.isPeek() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    return 0;
}

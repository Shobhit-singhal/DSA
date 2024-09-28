#include <iostream>
using namespace std;

class CircularQueue {
public:
    int *arr;
    int front, rear, n;

    CircularQueue(int size) {
        this->n = size;
        arr = new int[n];  // Allocate an array of size 'n'
        front = rear = -1;
    }

    // Enqueues 'value' into the queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int value) {
        if ((front == 0 && rear == n - 1) || (rear == front - 1))  // Check if the queue is full
            return false;
        if (front == -1)   // Initialize front if it's the first element
            front = 0;
        rear = (rear + 1) % n;  // Update rear in a circular manner
        arr[rear] = value;
        return true;
    }

    // Dequeues the top element from the queue. Returns -1 if the queue is empty, otherwise returns the dequeued element.
    int dequeue() {
        if (front == -1)   // Check if the queue is empty
            return -1;
        int el = arr[front];
        if (front == rear) {  // If only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % n;  // Update front in a circular manner
        }
        return el;
    }

    // Display the elements of the queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % n;
        }
        cout << endl;
    }

    // Destructor to free the allocated memory
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    int size = 5;  // Size of the queue
    CircularQueue q(size);

    // Enqueue some elements
    cout << "Enqueue 10: " << (q.enqueue(10) ? "Success" : "Fail") << endl;
    cout << "Enqueue 20: " << (q.enqueue(20) ? "Success" : "Fail") << endl;
    cout << "Enqueue 30: " << (q.enqueue(30) ? "Success" : "Fail") << endl;
    cout << "Enqueue 40: " << (q.enqueue(40) ? "Success" : "Fail") << endl;
    cout << "Enqueue 50: " << (q.enqueue(50) ? "Success" : "Fail") << endl;

    // Try to enqueue when the queue is full
    cout << "Enqueue 60: " << (q.enqueue(60) ? "Success" : "Fail") << endl;

    // Display elements
    q.display();

    // Dequeue some elements
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;

    // Display elements after dequeue
    q.display();

    // Enqueue more elements
    cout << "Enqueue 60: " << (q.enqueue(60) ? "Success" : "Fail") << endl;
    cout << "Enqueue 70: " << (q.enqueue(70) ? "Success" : "Fail") << endl;

    // Display elements after more enqueues
    q.display();

    return 0;
}

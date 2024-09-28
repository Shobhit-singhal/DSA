#include<iostream>
using namespace std;

class deque{
    private:
        int n,rear,front;
        int* arr;
    public:
        deque(int n){
            this->n=n;
            arr=new int[n];
            rear=front=-1;
        }
        bool isEmpty(){
            return front==-1;
        }
        bool isFull(){
            return ((front==0 && rear==n-1) || (front==rear+1));
        }
        bool pushFront(int x){
            if(isFull())     return false;
            if(isEmpty()){
                rear=front=0;
                arr[front]=x;
            }
            else{
                front=(front==0)?n-1:front-1;
                arr[front]=x;
            }
            return true;
        }
        bool pushRear(int x){
            if(isFull())    return 0;
            if(isEmpty()){
                front=rear=0;
                arr[rear]=x;
            }else{
                rear=(rear==n-1)?0:rear+1;
                arr[rear]=x;
            }
            return true;
        }
        int popFront(){
            if(isEmpty())   return -1;
            int el=arr[front];
            if(front==rear){
                front=rear=-1;
            }else{
                front=(front==n-1)?0:front+1;
            }
            return el;
        }
        int popRear(){
            if(isEmpty())   return -1;
            int el=arr[rear];
            if(front==rear)
                front=rear=-1;
            else
                rear=(rear==0)?n-1:rear-1;
            return el;
        }

};
int main() {
    deque dq(5); // Creating a deque of size 5
    
    // Test 1: Push elements to the front
    cout << "Pushing 10 at front: " << (dq.pushFront(10) ? "Success" : "Failed") << endl;
    cout << "Pushing 20 at front: " << (dq.pushFront(20) ? "Success" : "Failed") << endl;
    cout << "Pushing 30 at front: " << (dq.pushFront(30) ? "Success" : "Failed") << endl;
    
    // Test 2: Push elements to the rear
    cout << "Pushing 40 at rear: " << (dq.pushRear(40) ? "Success" : "Failed") << endl;
    cout << "Pushing 50 at rear: " << (dq.pushRear(50) ? "Success" : "Failed") << endl;

    // Test 3: Deque is full now, this should fail
    cout << "Pushing 60 at rear (should fail): " << (dq.pushRear(60) ? "Success" : "Failed") << endl;

    // Test 4: Pop elements from the front
    cout << "Popped from front: " << dq.popFront() << endl;
    cout << "Popped from front: " << dq.popFront() << endl;

    // Test 5: Pop elements from the rear
    cout << "Popped from rear: " << dq.popRear() << endl;
    
    // Test 6: Push again after popping (to test circular behavior)
    cout << "Pushing 60 at front (after pop): " << (dq.pushFront(60) ? "Success" : "Failed") << endl;
    cout << "Pushing 70 at rear (after pop): " << (dq.pushRear(70) ? "Success" : "Failed") << endl;

    // Test 7: Pop all elements to make deque empty
    while (!dq.isEmpty()) {
        cout << "Popped from front: " << dq.popFront() << endl;
    }

    // Test 8: Try popping from an empty deque
    cout << "Popping from empty deque (should return -1): " << dq.popFront() << endl;

    // Test 9: Push after deque is empty
    cout << "Pushing 80 at front (after deque is empty): " << (dq.pushFront(80) ? "Success" : "Failed") << endl;
    cout << "Popping from front (after pushing 80): " << dq.popFront() << endl;

    return 0;
}
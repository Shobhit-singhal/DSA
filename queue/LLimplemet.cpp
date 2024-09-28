#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};
class queue{
    public:
        Node* rear;
        Node* front;
        queue(){
            this->rear=NULL;
            this->front=NULL;
        }
        void push(int data){
            Node* temp=new Node(data);
            if(front==NULL){
                rear=front=temp;
            }
            else{
                rear->next=temp;
                rear=rear->next;
            }
            
        }
        int pop(){
            if(front==NULL) return -1;
            Node* temp=front;
            int el=front->data;
            front=front->next;
            if(front==NULL)
                front=rear=NULL;
            delete temp;
            return el;
        }
        int qfront(){
            return (front==NULL)?-1:front->data;
        }
};
int main(){
        queue q;
    q.push(10);
    q.push(20);
    cout << q.qfront() << endl;  // Should print 10
    q.pop();
    cout << q.qfront() << endl;  // Should print 20
    q.pop();
    cout << q.qfront() << endl;  // Should print -1 (queue is empty)
}
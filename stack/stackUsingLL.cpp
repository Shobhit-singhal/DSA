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

class Stack{
    public:
    Node* top;
    Stack(){
        this->top=NULL;
    }
    void push(int data){
        Node* newNode=new Node(data);
        newNode->next=this->top;
        this->top=newNode;
    }

    void pop(){
        Node* temp=this->top;
        if(temp!=NULL){
            this->top=this->top->next;
            cout<<"Deleting: "<<temp->data<<endl;
            delete temp;
        }else   
            cout<<"Stack underflow"<<endl;
    }
    int peek(){
        if(this->top!=NULL){
            return top->data;
        }else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        return (top==NULL);
    }
};
int main(){
    Stack s1;
    cout<<"Empty: "<<s1.isEmpty()<<endl;
    s1.pop();
    s1.push(0);
    s1.push(1);
    s1.pop();
    cout<<"Peek: "<<s1.peek()<<endl;
}
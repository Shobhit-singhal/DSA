#include<iostream>
using namespace std;
class stack{
    public:
        int* arr;
        int size;
        int top;
        stack(int size){
            arr=new int[size];
            this->size=size;
            this->top=-1;
        }

        void push(int data){
            if(top<size-1){
                this->top++;
                arr[this->top]=data;
            }
            else
                cout<<"Stack Overflow"<<endl;
        }
        void pop(){
            if(top==-1)
                cout<<"Stack Underflow"<<endl;
            else{
                cout<<"Popped: "<<arr[this->top--]<<endl;
            }
        }
        int peek(){
            if(top==-1){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            else{
                return arr[top];
            }
        }
        bool isEmpty(){
            return (top==-1);
        }
};
int main(){
    // stack* s1=new stack(5);
    // cout<<"stack empty: "<<s1->isEmpty()<<endl;
    // s1->push(0);
    // s1->push(1);
    // s1->push(2);
    // s1->push(3);
    // s1->push(4);
    // s1->push(5);
    // s1->pop();
    // s1->pop();
    // // s1->pop();
    // cout<<"stack empty: "<<s1->isEmpty()<<endl;
    // cout<<"Top: "<<s1->peek()<<endl;

    stack s1(5);
    cout<<"Empty: "<<s1.isEmpty()<<endl;
    s1.push(0);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    cout<<"Peek: "<<s1.peek()<<endl;
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    // s1.pop();
    cout<<"Peek: "<<s1.peek()<<endl;
    cout<<"Empty: "<<s1.isEmpty()<<endl;

    


}
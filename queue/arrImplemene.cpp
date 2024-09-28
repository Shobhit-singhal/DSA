#include<iostream>
using namespace std;


class queue{
private:
    int* arr;
    int size,qfront,qrear;
public:
    queue(int size){
        this->size=size;
        arr=new int[size];
        qrear=0;
        qfront=0;
    }

    void push(int el){
        if(qrear==size){
            cout<<"Overflow"<<endl;
            return;
        }
        arr[qrear++]=el;
    }
    int pop(){
        if(qrear==qfront){
            cout<<"Underflow"<<endl;
            return -1;
        }
        int el=arr[qfront++];
        if(qfront==qrear)
            qfront=qrear=0;
        return el;
    }
    bool empty(){
        return (qrear==qfront);
    }
    int front(){
        return (qfront==qrear)?-1:arr[qfront];
    }
};
int main(){
    queue q(5);
    q.push(10);
    q.push(20);
    cout << "Front element: " << q.front() << endl;  // Should print 10
    q.pop();
    cout << "Front element after pop: " << q.front() << endl;  // Should print 20
    q.pop();
    q.pop();  // Should print "Underflow"
    cout << "Queue empty: " << q.empty() << endl;  // Should print 1 (true)
}
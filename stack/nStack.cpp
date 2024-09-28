#include<bits/stdc++.h>
using namespace std;
class Stack{
    private:
        int* arr;
        int* next;
        int* top;
        int n,size,freeSpace;
    public:
        Stack(int n, int size){
            this->n=n;
            this->size=size;
            freeSpace=0;
            arr=new int[size];
            next=new int[size];
            top=new int[n];
            for(int i=0;i<n;i++)
                top[i]=-1;
            for(int i=0;i<size;i++)
                next[i]=i+1;
            next[size-1]=-1;
        }
        bool push(int el,int m){
            if(freeSpace==-1)
                return false;
            int idx=freeSpace;
            freeSpace=next[idx];
            next[idx]=top[m-1];
            top[m-1]=idx;
            arr[idx]=el;
            return true;
        }
        int pop(int m){
            if(top[m-1]==-1)
                return -1;
            int idx=top[m-1];
            top[m-1]=next[idx];
            next[idx]=freeSpace;
            freeSpace=idx;
            return arr[idx];
        }
};
int main(){
    Stack s1(3,6);
    cout<<"pushed: 10 in 1: "<<s1.push(10,1)<<endl;
    cout<<"pushed: 20 in 1: "<<s1.push(20,1)<<endl;
    cout<<"pushed: 30 in 2: "<<s1.push(30,2)<<endl;
    cout<<"pushed: 40 in 2: "<<s1.push(40,2)<<endl;
    cout<<"pushed: 50 in 3: "<<s1.push(50,2)<<endl;
    cout<<"pushed: 60 in 3: "<<s1.push(60,2)<<endl;
    cout<<"pushed: 70 in 3: "<<s1.push(70,2)<<endl;


    cout<<"popped from 1: "<<s1.pop(1)<<endl;
    cout<<"popped from 2: "<<s1.pop(2)<<endl;
    cout<<"popped from 2: "<<s1.pop(2)<<endl;



}
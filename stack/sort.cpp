#include<bits/stdc++.h>
using namespace std;


void insert(stack<int>& myStack,int el){
    if(myStack.empty()|| myStack.top()<=el){
        myStack.push(el);
        return;
    }
    int x=myStack.top();
    myStack.pop();
    insert(myStack,el);
    myStack.push(x);
}

void sort(stack<int>& myStack){
    if(myStack.empty()){
        return;
    }
    int el=myStack.top();
    myStack.pop();
    sort(myStack);
    insert(myStack,el);
}

void print(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){

    stack<int> myStack;
    myStack.push(5);
    myStack.push(2);
    myStack.push(4);
    myStack.push(9);
    sort(myStack);
    print(myStack);


}
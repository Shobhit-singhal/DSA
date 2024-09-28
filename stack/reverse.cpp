#include<bits/stdc++.h>
using namespace std;

void pushAtBottom(stack<int>& myStack,int x){
    if(myStack.empty() ){
        myStack.push(x);
        return;
    }

    int el=myStack.top();
    myStack.pop();
    pushAtBottom(myStack,x);
    myStack.push(el);
}

void rev(stack<int>& myStack){
    if(myStack.empty()){
        return;
    }
    int el=myStack.top();
    myStack.pop();
    rev(myStack);
    pushAtBottom(myStack,el);
}
void print(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    stack<int> myStack;
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    print(myStack);
    cout<<endl;
    rev(myStack);
    print(myStack);
}
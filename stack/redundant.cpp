#include<bits/stdc++.h>
using namespace std;


bool opPresent(stack<char>& stack,bool op=0){
    if(stack.top()=='('){
        stack.pop();
        return op;
    }
    char ch=stack.top();
    stack.pop();
    if(ch=='+' || ch=='-'|| ch=='*' || ch=='/'){
        op=1;
    }
    return opPresent(stack,op);
}

bool findRedundant(string s){
    stack<char> stack;
    for(char ch:s){
        if(ch=='(' || ch=='+' || ch=='-'|| ch=='*' || ch=='/'){
            stack.push(ch);
        }else if(ch==')'){
            if(!opPresent(stack)){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    // string ip="(a+b*c)";
    string ip="(a+b*c)+(d)";
    cout<<findRedundant(ip)<<endl;
}
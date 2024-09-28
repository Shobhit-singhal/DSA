#include<bits/stdc++.h>
using namespace std;


void findNum(stack<char> stack,int& a, int &b){
    while(!stack.empty()){
        (stack.top()=='{')? a++:b++;
        stack.pop();
    }
}
int findMin(string s1){
    if(s1.length()%2==1)
        return -1;
    stack<char> stack;
    for(char ch:s1){
        if(!stack.empty() && (stack.top()=='{' && ch=='}')){
            stack.pop();
        }
        else{
            stack.push(ch);
        }
    }
    int a=0,b=0;
    findNum(stack,a,b);
    return ((a+1)/2 + (b+1)/2);
}
int main(){
    string s1="}}}}{{{{";
    cout<<findMin(s1);

}
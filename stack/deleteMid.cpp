#include<bits/stdc++.h>
using namespace std;

void delMid(stack<int>& inp,int size,int cnt){
    if(cnt==size/2){
        inp.pop();
        return;
    }
    int el=inp.top();
    inp.pop();
    delMid(inp,size,cnt+1);
    inp.push(el);
}
int main(){
    stack<int> inp;
    inp.push(1);
    inp.push(2);
    inp.push(3);
    inp.push(4);
    inp.push(5);
    delMid(inp,inp.size(),0);
    int size=inp.size();
    for(int i=0;i<size;i++){
        cout<<inp.top()<<endl;
        inp.pop();
    }
}
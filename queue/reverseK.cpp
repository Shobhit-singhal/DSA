#include<bits/stdc++.h>
using namespace std;


void solve(queue<int> &q,int cnt, int k){
    if(cnt==k)  return;
    int el=q.front();
    q.pop();
    solve(q,cnt+1,k);
    q.push(el);
}
queue<int> reverseK(queue<int>q,int n,int k){
    solve(q,0,k);
    for(int i=0;i<n-k;i++){
        int el=q.front();
        q.pop();
        q.push(el);
    }
    return q;
}
void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main(){
    queue<int> q;
    for(int i=0;i<6;i++){
        q.push(i);
    }
    q=reverseK(q,q.size(),2);
    print(q);
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;
    q.push(1);
    cout<<q.front()<<endl ;
    q.push(2);
    
    q.push(3);
    
    q.push(4);
    
    q.pop();
    cout<<q.front()<<endl ;
    cout<<q.size()<<endl;
    cout<<q.empty();
}
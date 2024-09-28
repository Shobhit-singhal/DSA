#include<bits/stdc++.h>
using namespace std;
int main(){
    string str="shobhit";
    stack<char> s1;
    for(char ch:str){
        s1.push(ch);
    }
    string ans;
    while(!s1.empty()){
        ans.push_back(s1.top());
        s1.pop();
    }
    cout<<ans<<endl;

}
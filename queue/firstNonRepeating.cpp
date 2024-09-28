#include<bits/stdc++.h>
using namespace std;
string firstNonRepeating(string s){
    map<char,int> cnt;
    queue<char> q;
    string ans="";
    for(char ch: s){
        cnt[ch]++;
        q.push(ch);

        while(!q.empty()){
            char ch=q.front();
            if(cnt[ch]>1)
                q.pop();
            else{
                ans.push_back(ch);
                break;
            }
        }
        if(q.empty())   ans.push_back('#');
    }
        return ans;
}
int main(){
    string s="aabcadb";
    cout<<firstNonRepeating(s)<<endl;
}
#include<bits/stdc++.h>
using namespace std;

void solve(string str,vector<string> &ans,string output,int idx){
    if(idx>=str.length()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(str,ans,output,idx+1);
    //include
    char ch=str[idx];
    output.push_back(ch);
    solve(str,ans,output,idx+1);
}
vector<string> subString(string str){
    vector<string> ans;
    string output;
    int idx=0;
    solve(str,ans,output,idx);
    return ans;
}
int main(){
    string str="abc";
    vector<string> ans=subString(str);
    for(string st:ans)
        cout<<st<<endl;
}
#include<bits/stdc++.h>
using namespace std;
void solve(string &digits,vector<string> &ans,string output,string map[10],int idx){
    if(idx>=digits.length()){
        ans.push_back(output);
        return;
    }
    int num=digits[idx]-'0';
    string val=map[num];
    for(char ch:val){
        output.push_back(ch);
        solve(digits,ans,output,map,idx+1);
        output.pop_back();
    }
}
vector<string> getPossible(string &digits){
    int idx=0;
    vector<string> ans;
    string output;
    string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,ans,output,map,idx);
    return ans;
}
int main(){
    string digits="23";
    vector<string> ans=getPossible(digits);
    for(auto st:ans)
        cout<<st<<endl;
}
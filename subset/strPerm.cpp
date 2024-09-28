#include<bits/stdc++.h>
using namespace std;
void solve(string &str,vector<string>& ans,int idx){
    if(idx>=str.length()){
        ans.push_back(str);
        return;
    }
    for(int i=idx;i<str.length();i++){
        swap(str[i],str[idx]);
        solve(str,ans,idx+1);
        swap(str[i],str[idx]);
    }
}
vector<string> perm(string &str){
    vector<string> ans;
    int idx=0;
    solve(str,ans,idx);
    return ans;
}
int main(){
    string str="abcd";
    vector<string> ans=perm(str);
    // for(string st:ans)
    //     cout<<st<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
}
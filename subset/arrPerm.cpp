#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr,vector<vector<int>> &ans,int idx){
    if(idx>=arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=idx;i<arr.size();i++){
        swap(arr[i],arr[idx]);
        solve(arr,ans,idx+1);
        swap(arr[i],arr[idx]);
    }
}
vector<vector<int>> perm(vector<int> &arr){
    vector<vector<int>> ans;
    int idx=0;
    solve(arr,ans,idx);
    return ans;
}
int main(){
    // string str="abc";
    vector<int> arr={1,2,3};
    vector<vector<int>> ans=perm(arr);

        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    
}
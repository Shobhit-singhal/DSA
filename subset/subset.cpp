#include<bits/stdc++.h>
using namespace std;




void solve(vector<int> &arr,vector<vector<int>> &ans,vector<int> output,int idx){
    if(idx>=arr.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(arr,ans,output,idx+1);
    //include
    int el=arr[idx];
    output.push_back(el);
    solve(arr,ans,output,idx+1);
}
vector<vector<int>> powerSet(vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> output;
    int idx=0;
    solve(arr,ans,output,idx);
    return ans;
}
int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> ans=powerSet(arr);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}
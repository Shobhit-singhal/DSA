#include<bits/stdc++.h>
using namespace std;
int kthSmallest(vector<int>& arr,int n, int k){
    priority_queue<int> h1;
    for(int i=0;i<k;i++)
        h1.push(arr[i]);
    
    for(int i=k;i<n;i++){
        if(arr[i]<h1.top()){
            h1.pop();
            h1.push(arr[i]);
        }
    }
    return h1.top();
}
int kthLargest(vector<int>& arr, int n, int k){
    priority_queue<int,vector<int>,greater<int>> h1;
    for(int i=0;i<k;i++){
        h1.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]>h1.top()){
            h1.pop();
            h1.push(arr[i]);
        }
    }
    return h1.top();
}
pair<int,int> kthSmallLarge(vector<int>&arr, int n, int k){
    pair<int,int> ans;
    ans.first=kthSmallest(arr,n,k);
    ans.second=kthLargest(arr,n,k);
    return ans;
}
int main(){
    vector<int> arr={1,2,5,4};
    int k=3;
    pair<int,int> ans=kthSmallLarge(arr,arr.size(),k);
    cout<<ans.first<<"   "<<ans.second<<endl;
}
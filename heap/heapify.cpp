#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>& arr,int n,int i){
    int left=i*2;
    int right=i*2+1;
    int curr=i;
    if(left < n && arr[curr]<arr[left]) curr=left;
    if(right<n && arr[curr]<arr[right]) curr=right;
    if(curr==i){
        return;
    }else{
        swap(arr[i],arr[curr]);
        heapify(arr,n,curr);

    }
}
int main(){
    vector<int> arr={-1,54,53,55,52,50};
    int n=arr.size();
    for(int i=3;i>=1;i--)
        heapify(arr,n,i);
    
    for(int i: arr) 
        cout<<i<<" ";
    cout<<endl;
}
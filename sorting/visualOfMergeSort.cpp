#include<bits/stdc++.h>
using namespace std;



void print(vector<int>& arr,int s,int e,int cnt,char go){
    cout<<"For cnt:  "<<cnt<< " going: "<<go<<endl;
    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge(vector<int>& arr,int s,int e,int cnt){
    cout<<"Merging for cnt: "<<cnt<<endl;
    int mid=(s+e)/2;
    vector<int> ans;
    int l=s,r=mid+1;
    while(l<=mid && r<=e){
        if(arr[l]<=arr[r])
            ans.push_back(arr[l++]);
        else    ans.push_back(arr[r++]);
    }
    while(l<=mid)
        ans.push_back(arr[l++]);
    while(r<=e)
        ans.push_back(arr[r++]);

    for(int i=s;i<=e;i++)
        arr[i]=ans[i-s];
    for(int i=s;i<=e;i++){
            cout<<ans[i-s]<<" ";
    }
    cout<<endl;
}
void mergeSort(vector<int>& arr,int s,int e,int cnt=0,char go='n'){
    print(arr,s,e,cnt,go);
    if(s>=e)
        return;
    
    int mid=(s+e)/2;
    mergeSort(arr,s,mid,cnt+1,'L');
    mergeSort(arr,mid+1,e,cnt+1,'R');
    merge(arr,s,e,cnt);

}
int main(){
    vector<int> arr={5,8,1,9,2,7,4};

    mergeSort(arr,0,arr.size()-1);

}
#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int n, int i){
    int largest=i;
    int left=i*2;
    int right=i*2+1;
    if(left<=n && arr[left]>arr[largest])    largest=left;
    if(right<=n && arr[right]>arr[largest])  largest=right;
    if(i!=largest){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapsort(vector<int>& arr,int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }

}
int main(){
    vector<int> arr={-1,54,53,55,52,50};
    int n=arr.size()-1;
    for(int i=n/2;i>0;i--)
        heapify(arr,n,i);
    
    for(int i: arr) 
        cout<<i<<" ";
    cout<<endl;

    cout<<"Sorted: "<<endl;
    heapsort(arr,n);
    for(int i: arr) 
        cout<<i<<" ";
    cout<<endl;

}
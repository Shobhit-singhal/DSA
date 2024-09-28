#include<iostream>
using namespace std;
bool binarySearch(int arr[],int s,int e,int target){
    if(s>e)
        return false;
    int mid=s+(e-s)/2;
    if(arr[mid]==target)
        return true;
    if(arr[mid]<target)
        return binarySearch(arr,mid+1,e,target);
    else    
        return (arr,s,mid-1,target);
}
int main(){
    int size,arr[100],target;
    cin>>size;
    for(int i=0;i<size;i++)
        cin>>arr[i];
    cin>>target;
    cout<<"Search result: "<<binarySearch(arr,0,size-1,target);
}
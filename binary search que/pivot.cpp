#include<iostream>
using namespace std;
int pivot(int arr[],int size){
    int s=0,e=size-1,m,ans=-1;
    while(s<e){
        m=(s+e)/2;
        if(arr[m]>=arr[0]){
            s=m+1;
        }
        else 
        e=m;
    }
    // return arr[s];
    return s;

}
int binarySearch(int arr[],int size, int target,int pivot){
    int s=0,e=0;
    if(target>=arr[0]){
        s=0, e=pivot-1;
    }else{
        s=pivot,e=size-1;
    }
    int mid;
    while (s<=e)
    {
        mid=(s+e)/2;
        if(arr[mid]==target)
        return mid;
        else if(arr[mid]<target)
        s=mid+1;
        else
        e=mid-1;
    }
    return -1;
    
}
int main(){
    int arr[5]={1,2,3,4,5};
    int pivotIdx=pivot(arr,5);
    cout<<"The pivot index is: "<<pivotIdx<<endl;
    int target=1;
    int targetIdx=binarySearch(arr,5,target,pivotIdx);
    cout<<target<<" at index "<<targetIdx<<endl;

}
#include<iostream>
using namespace std;
int binarySearch(int arr[],int size,int target){
    int high=size-1,low=0,mid;
    while(high>=low){
        mid=(high+low)/2;
        // cout<<"mid ele"<<arr[mid]<<endl;
        if(arr[mid]==target)
            return mid;
        if(arr[mid]>target)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
int firstOcc(int arr[],int size,int target){
    int s=0,e=size-1,mid,ans=-1;
    while(s<=e){
        mid=(s+e)/2;
        if(arr[mid]==target){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]<target)
            s=mid+1;
        else
            e=mid-1;
    }
    return ans;
}
int lastOcc(int arr[],int size,int target){
    int s=0,e=size-1,mid,ans=-1;
    while(s<=e){
        mid=(s+e)/2;
        if(arr[mid]==target){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]<target){
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return ans;
}

int peak(int arr[],int size){
    int s=0,e=size-1,peak,mid;
    while (s<e)
    {
        mid=(s+e)/2;
        if(arr[mid]<arr[mid+1])
            s=mid+1;
        else
            e=mid;
    }
    return s;
    
}
int main(){
    // int arr1[8]={0,3,3,5,6,7,87,543};
    int arr[5]={1,2,3,2,1};
    // int arr[6]={3,4,5,6,1,0};
    // int arr2[6]={1,23,356,421,765,1000};
    // cout<<"First occurance of 3 is: "<<firstOcc(arr1,8,3)<<endl;
    // cout<<"Last occurance of 3 is: "<<lastOcc(arr1,8,3)<<endl;
    cout<<"Peak is: "<<peak(arr,5)<<endl;

}
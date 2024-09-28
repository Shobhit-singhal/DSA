#include<iostream>
using namespace std;
bool isSorted(int arr[],int size){
    if(size==0 || size==1)
        return true;
    if(arr[0]>arr[1])
        return false;
    return isSorted(arr+1,size-1);
}

int getSum(int *arr,int size,int sum=0){
    if(size==0)
        return sum;
    // cout<<sum<<endl;
    sum+=arr[0];
    return getSum(arr+1,size-1,sum);
}

bool linearSearch(int arr[],int size,int target){
    if(arr[0]==target)
        return 1;
    if(size==0)
        return false;
    linearSearch(arr+1,size-1,target);
    
}
int main(){
    int size,arr[100],target;
    cin>>size;
    for(int i=0;i<size;i++)
        cin>>arr[i];
    cin>>target;
    // cout<<isSorted(arr,size);
    // cout<<getSum(arr,size);
    cout<<"target found or nor: "<<linearSearch(arr,size,target);
}
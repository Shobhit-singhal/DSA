#include<iostream>
using namespace std;
void sort(int arr[],int size){
    if(size==0 || size==1)
        return;


    for(int i=0;i<size;i++){
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }
    return sort(arr,size-1);
}
int main(){
    int size,arr[100];
    cin>>size;
    for(int i=0;i<size;i++)
        cin>>arr[i];
    // for(int i=0;i<size;i++)
        sort(arr,size);
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;   
}
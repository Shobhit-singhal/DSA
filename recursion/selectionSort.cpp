#include<iostream>
using namespace std;

void sort(int arr[],int size){
    if(size==0 || size==1)
        return ;
    int mini=0;
    for(int i=1;i<size;i++)
        if(arr[i]< arr[mini])
            mini=i;
    swap(arr[mini],arr[0]);
    return sort(arr+1,size-1);
}
int main(){
    int size=5,arr[10]={5,30,6,9,1};
    sort(arr,size);
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    return 0;
}
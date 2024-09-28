#include<iostream>
using namespace std;

void print(int *arr,int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void sort(int arr[],int i,int size){
    
    int val=arr[i];
    if(i>=size)
        return;
    int j;
    for(j=i-1;j>=0;j--){
        if(val<arr[j])
            arr[j+1]=arr[j];
        else
            break;
    }
    arr[j+1]=val;

    return sort(arr,i+1,size);
}
int main(){
    int size=5,arr[10]={5,18,4,9,1};
    sort(arr,1,size);
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
#include<iostream>
using namespace std;
void sort(int arr[],int size){
    int minIdx;
    for(int i=0;i<size-1;i++){
        minIdx=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[minIdx])
                minIdx=j;
        }
        swap(arr[i],arr[minIdx]);
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int size,arr[100];
    cout<<"Enter the size: ";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter an element: ";
        cin>>arr[i];
    }
    sort(arr,size);
}
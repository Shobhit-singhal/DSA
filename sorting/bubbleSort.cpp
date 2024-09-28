#include<iostream>
using namespace std;
void sort(int arr[],int size){
    for(int i=1;i<size;i++){
        bool swapped=false;
        for(int j=0;j<size-i;j++){
            swapped=true;
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
        if(!swapped)
        break;
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
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}
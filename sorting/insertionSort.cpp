#include<iostream>
using namespace std;
void sort(int arr[],int size){
    int j,temp;
    for(int i=1;i<size;i++){
        temp=arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j]>temp)
                arr[j+1]=arr[j];
            else
                break;
        }
        arr[j+1]=temp;
    }
}
int main(){
    int size,arr[100];
    cout<<"Enter the size: ";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter the element: ";
        cin>>arr[i];
    }
    sort(arr,size);
    for(int i=0;i<size;i++)
    cout<<arr[i]<<endl;
}
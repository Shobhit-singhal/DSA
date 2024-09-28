#include<iostream>
using namespace std;
void printArr(int arr[],int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<"\t";
        cout<<endl;
}
void reverse(int arr[],int size){
    int start=0,end=size-1,temp;
    while(start<end){
        swap(arr[start],arr[end]);

        end--;
        start++;
    }
}
int main(){
    int n, arr[10];
    cout<<"Enter the size";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter an element: ";
        cin>>arr[i];
    }
    cout<<"Given array is: \n";
    printArr(arr,n);
    reverse(arr,n);
    cout<<"After reversing: \n";
    printArr(arr,n);

}
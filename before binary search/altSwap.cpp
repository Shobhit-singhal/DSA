#include<iostream>
using namespace std;
void printArr(int arr[],int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}
void altSwap(int arr[],int size){
    // int first=0,second=1;
    // while (second<size)
    // {
    //     swap(arr[first],arr[second]);
    //     first+=2;
    //     second+=2 ;
    // }
    for(int i=0;i<size;i+=2){
        if(i+1<size)
            swap(arr[i],arr[i+1]);
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    int brr[6]={1,2,3,4,5,6};
    altSwap(arr,5);
    altSwap(brr,6);
    printArr(arr,5);
    printArr(brr,6);
}
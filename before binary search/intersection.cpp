#include<iostream>
#include<algorithm>
#include<array>
#include<iterator>
using namespace std;
void printArr(int arr[],int size){
    for(int i=0;i<size;i++)
    cout<<arr[i]<<"\t";
    cout<<endl;
}
void sorting(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }
    // sort(arr.begin(),arr.end());
    printArr(arr,size);
}
void sort01(int arr[],int size){
    int i=0,j=size-1;
    while (i<j)
    {
        if(arr[i]==0 || arr[j]==1){

        if(arr[i]==0)
        i++;
        // while (arr[i]==0)
        // {
        //     i++;
        // }
        
        if(arr[j]==1)
        j--;
        // while (arr[j]==1)
        // {
        //     j--;
        // }
        }
        else if(arr[i]==1 && arr[j]==0){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        
    }

    //0 0 1 1 1 1
    //    i j
    printArr(arr,size);
}
int main(){
    int size,arr[100];
    cout<<"Enter the size: ";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter an element: ";
        cin>>arr[i];
    }
    sort01(arr,size);

}
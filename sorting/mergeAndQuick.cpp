#include<iostream>
using namespace std;

void printArr(int arr[],int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void merge(int arr[],int s, int mid, int e){
    int temp[100];
    int left=s,right=mid+1,k=0;
    while(left<=mid && right<=e){
        if(arr[left]<=arr[right])
            temp[k++]=arr[left++];

        else
            temp[k++]=arr[right++];
    }
    while(left<=mid)
        temp[k++]=arr[left++];
    while(right<=e)
        temp[k++]=arr[right++];

    for(int i=s;i<=e;i++){
        arr[i]=temp[i-s];
    }
}
void mergeSort(int arr[],int s,int e){
    if(s>=e)
        return ;
    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}


int partition(int arr[],int s,int e){
    int p=arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++)
        if(arr[i]<=p)
            cnt++;
    int pivotIdx=s+cnt;
    swap(arr[s],arr[pivotIdx]);
    int left=s,right=e;
    while(left<pivotIdx && right>pivotIdx){
        while(arr[left]<=p)
            left++;
        while(arr[right]>p)
            right--;
        if(left<pivotIdx && right>pivotIdx)
            swap(arr[left++],arr[right--]);

    }
    return pivotIdx;
}
void quickSort(int arr[],int s,int e){
    if(s>=e)
        return;
    int p=partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}
int main(){
    int size1=5,arr1[100]={5,1,8,2,9};
    cout<<"\n\nBy Merge Sort: "<<endl;
    mergeSort(arr1,0,size1-1);
    printArr(arr1,size1);


    int size2=5,arr2[100]={5,41,80,2,9};
    cout<<"\n\nBy Quick Sort: "<<endl;
    quickSort(arr2,0,size2-1);
    printArr(arr2,size2);
    cout<<endl<<endl;
}
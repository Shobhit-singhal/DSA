#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int start,int end){
    int p=arr[start];
    int count=0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<=p)
            count++;
    }
    // cout<<count<<endl;
    int pivotIdx=start+count;
    swap(arr[start],arr[pivotIdx]);
    int left=start;
    int right=end;
    while(left<pivotIdx && right>pivotIdx){
        while (arr[left]<=p)
        {
            left++;
        }
        while (arr[right]>p)
        {
            right++;
        }
        if(left<pivotIdx && right>pivotIdx)
            swap(arr[left++],arr[right++]);       
        
    }
    return pivotIdx;
}

void quickSort(int arr[],int start,int end){
    if(start>=end)
        return;
    int p=partition(arr,start,end);
    quickSort(arr,start,p-1);
    quickSort(arr,p+1,end);
}
int main(){
    int n=5,arr[5]={5,3,8,9,1};
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
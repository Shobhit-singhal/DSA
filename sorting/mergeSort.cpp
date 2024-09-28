#include<bits/stdc++.h>
using namespace std;

int call=1;
void print(int arr[],int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


void merge(int arr[],int s,int mid,int e){
    vector<int> ans;
    int l=s;
    int r=mid+1;
    while(l<=mid && r<=e){
        if(arr[l]<=arr[e]){
            ans.push_back(arr[l++]);
        }else{
            ans.push_back(arr[r++]);
        }
    }
    while(l<=mid){
        ans.push_back(arr[l++]);
    }
    while(r<=e)
        ans.push_back(arr[r++]);
    for(int i=s;i<=e;i++){
        arr[i]=ans[i-s];
    }

}
// void merge(int arr[],int s,int mid;int e){
//     int len1=mid-s+1;
//     int len2=e-mid;

//     int *arr1=new int[len1];
//     int *arr2=new int[len2];

//     int k=s;
//     for(int i=0;i<len1;i++){
//         arr1[i]=arr[k++];
//     }

//     k=mid+1;
//     for(int i=0;i<len2;i++){
//         arr2[i]=arr[k++];
//     }


//     int i=0,j=0;
//     k=s;
//     while(i<len1 && j<len2){
//         if(arr1[i]<arr2[j])
//             arr[k++]=arr1[i++];
//         else    
//             arr[k++]=arr2[j++];
//     }
//     while(i<len1)
//         arr[k++]=arr1[i++];
//     while (j<len2)
//         arr[k++]=arr2[j++];


//     delete []arr1;
//     delete []arr2;


// }
void mergeSort(int arr[],int s,int e){

    if(s>=e)
        return;


    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}
int main(){
    int size=5,arr[5]={5,8,9,1,4};
    mergeSort(arr,0,size-1);

    print(arr,size);


    return 0;
}
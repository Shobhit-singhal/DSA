#include<bits/stdc++.h>
using namespace std;



void print(vector<int>& arr,int s,int e,int cnt,char go){
    cout<<"For cnt: "<<cnt<<" going: "<<go<<endl;
    for(int i=s;i<=e;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}
int partition(vector<int>& arr,int s, int e,int cnt=0,char go='n'){
    int i=s+1,j=e;
    int p=arr[s];
    while(i<=j){
        while(arr[i]<=p)
            i++;
        while(arr[j]>p)
            j--;
        if(i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[s],arr[j]);
    cout<<"Partition for cnt= "<<cnt <<" is "<<j<<" pivot is: "<<arr[j]<<endl;
    print(arr,s,e,cnt,go);
    return j;
}

void quickSort(vector<int>& arr,int s,int e,int cnt=0,char go='n'){
    print(arr,s,e,cnt,go);
    if(s>=e)
        return;
    int p=partition(arr,s,e,cnt+1,go);
    quickSort(arr,s,p-1,cnt+1,'l');
    quickSort(arr,p+1,e,cnt+1,'r');

}
int main(){
    vector<int> arr={5,8,1,9,2,7,4};

    quickSort(arr,0,arr.size()-1,0,'n');

    for(int i:arr)
        cout<<i<<" ";
    cout<<endl;
}
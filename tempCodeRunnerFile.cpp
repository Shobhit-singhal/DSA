#include<bits/stdc++.h>
using namespace std;


int partition(vector<int>& arr,int s,int e){
    int p=arr[s],l=s+1,r=e;
    while(l<=r){
        while(l<=e && arr[l]<=p) l++;
        while(arr[r]>p) r--;
        if(l<r) swap(arr[l++],arr[r--]);
    }
    swap(arr[s],arr[r]);
    return r;
}

void quickSort(vector<int>& arr,int s,int e){
    if(s>=e)
        return ;
    
    int p=partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);
    
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
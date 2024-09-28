#include<iostream>
using namespace std;
int uniqueEl(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++)
    ans=ans^arr[i];
    return ans;


}
int main(){
    int n,arr[100];
    cout<<"Enter the size: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter a element: ";
        cin>>arr[i];
    }
    int unique=uniqueEl(arr,n);
    cout<<"unique: "<<unique;
}
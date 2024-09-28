#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int **arr=new int*[n];
    int *size=new int[n];
    for(int i=0;i< n;i++){
        cin>>size[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=new int[size[i]];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<size[i];j++){
            cout<<"for "<<i<<" Row and "<<j<<" coloumn"<<endl;
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<size[i];j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }



    delete []size;
    for(int i=0;i<n;i++){
        delete []arr[i];
    }
    delete []arr;
}
#include<iostream>
using namespace std;
bool inarray(int target,int arr[],int size){
    for(int i=0;i<size;i++){
        if(target==arr[i])
        return 1;
    }
    return 0;
}
bool isUnique(int arr[],int size){
    int visited[size],j=0,counted[size],l=0,count;
    for(int i=0;i<size;i++){
        if(!inarray(arr[i],visited,size)){
            visited[j]=arr[i];
            j++;
            for(int k=i+1;k<size;k++){
                count=1;
                if(arr[i]==arr[k])
                count++;
                // cout<<count<<endl;
            }
            counted[l]=count;
            l++;
            
        }
        else{
            // cout<<arr[i]<<endl;   
        }
    }
    cout<<"The visited arr: "<<endl;
    for(int i=0;i<j;i++){
        cout<<visited[i]<<endl;
    }
    cout<<"The count arr: "<<endl;
    for(int i=0;i<l;i++){
        cout<<counted[i]<<endl;
    }
}
int main(){
    int arr[10];
    cout<<"Enter the size";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter a element: ";
        cin>>arr[i];
    }
    bool ans=isUnique(arr,n);
}
#include<iostream>
using namespace std;
bool present(int arr[][4],int row,int col,int target){
    int s=0,e=(row*col)-1,mid;
    while(s<=e){
        mid=s+(e-s)/2;
        int el=arr[mid/col][mid%col];
        if(el==target)
            return 1;
        if(el<target)
            s=mid+1;
        else
            e=mid-1;
    }
    return 0;
}
int main(){
    int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int target;
    cin>>target;
    bool ans=present(arr,3,4,target);
    cout<<target<<" present or not: "<<ans<<endl;
}
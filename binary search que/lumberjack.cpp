#include<iostream>
using namespace std;
bool isPossible(int trees[],int noTree,int target,int maxHeight){
    int sum=0;
    for(int i=0;i<noTree;i++){
        if((trees[i]-maxHeight)>=0){
            sum+=(trees[i]-maxHeight);
            if(sum>=target){
                return 1;
            }
        }
    }
    return 0;
}
int getHeight(int trees[],int noTree,int target){
    int s=0,e=-1,mid,ans=-1;
    for(int i=0;i<noTree;i++){
        e=max(e,trees[i]);
    }
    while(s<=e){
        mid=s+(e-s)/2;
        if(isPossible(trees,noTree,target,mid)){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return ans;

}
int main(){
    int noTree,target,trees[100];
    cout<<"Enter the no of trees: ";
    cin>>noTree;
    for(int i=0;i<noTree;i++){
        cout<<"Enter the height of tree: ";
        cin>>trees[i];
    }
    cout<<"Enter the target: ";
    cin>>target;
    int maxHeight=getHeight(trees,noTree,target);
    cout<<"max height: "<<maxHeight;
}
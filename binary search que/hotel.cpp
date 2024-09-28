#include<iostream>
using namespace std;
int totalDishPossible(int rank,int maxTime){
    int time=0,dish=0;
    while ((time+rank*(dish+1))<=maxTime)
    {
        dish++;
        time+=rank*dish;
    }
    cout<<"Rank: "<<rank<<" Total dish: "<<dish<<" in "<<time<<endl;
    return dish;
    
}
bool isPossible(int rank[],int noCook,int noDish,int maxTime){
    int totalDish=0;
    for(int i=0;i<noCook;i++){
        totalDish+=totalDishPossible(rank[i],maxTime);
        if(totalDish>=noDish){
            cout<<"possible for "<<maxTime<<endl; 
            return 1;
        }
    }
    cout<<"not possible for "<<maxTime<<endl;
    return 0;
}
int getTime(int rank[],int noCook,int noDish){
    int s=0,e;
    int maxi=-1,mid,ans=-1;
    for(int i=0;i<noCook;i++){
        maxi=max(maxi,rank[i]);
    }
    e=maxi*noDish*(noDish+1)/2;
    while (s<=e)
    {
        mid=s+(e-s)/2;
        if(isPossible(rank,noCook,noDish,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
    
}
int main(){
    int noDish,noCook,rank[100];
    cout<<"Enter the no of cooks: ";
    cin>>noCook;
    for(int i=0;i<noCook;i++){
        cout<<"Enter the rank: ";
        cin>>rank[i];
    }
    cout<<"Enter no of dishes: ";
    cin>>noDish;
    int minTime=getTime(rank,noCook,noDish);
    cout<<"The min time taken: "<<minTime;
}
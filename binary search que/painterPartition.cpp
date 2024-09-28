#include<iostream>
using namespace std;
bool isPossible(int boards[],int noBoards,int painters,int maxTime){
    int sum=0,leastPainter=1,i=0,temp;
    while(i<noBoards){
        cout<<"checking for: "<<maxTime<<endl;
        if(sum+boards[i]<=maxTime){
            sum+=boards[i];
            i++;  
        }else{
            leastPainter++;
            sum=0;
            if(leastPainter>painters||boards[i]>maxTime){
                return 0;
            }
        }
    }
    return 1;
}
int getMaxTime(int boards[],int noBoards,int painters){
    int s=0,e,mid,sum=0,ans=-1;
    for(int i=0;i<noBoards;i++){
        sum+=boards[i];
    }
    e=sum;
    while (s<=e)
    {
        mid=s+(e-s)/2;
        if(isPossible(boards,noBoards,painters,mid)){
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
    int noBoards,painters;
    int boards[100];
    cout<<"Enter the no of boards: ";
    cin>>noBoards;
    for(int i=0;i<noBoards;i++){
        cout<<"Enter the Board's area: ";
        cin>>boards[i];
    }
    cout<<"Enter the no of painters: ";
    cin>>painters;

    int time=getMaxTime(boards,noBoards,painters);
    cout<<"Max time for the above job given that "<<painters<<" painters are available is "<<time<<endl;
}
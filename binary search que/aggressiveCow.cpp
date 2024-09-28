#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int stalls[],int noStalls,int noCows, int dist){
    int cowCurrent=0,cowPrev=stalls[0],num=1,temp,i=0;
    while(i<noStalls){
        temp=stalls[i++];
        if(temp-cowPrev>=dist){
            cowPrev=temp;
            num++;
            if(num==noCows){
                return 1;
            }
        }
    }
    return 0;
}
int minDistance(int stalls[],int noStalls,int noCows){
    int s=0,e,minimum=stalls[0],maximum=stalls[0],mid,ans;
    // for(int i=1;i<noStalls;i++){
    //     minimum=min(minimum,stalls[i]);
    //     maximum=max(maximum,stalls[i]);
    // }
    sort(stalls , stalls + noStalls);
    e=stalls[noStalls];
    // e=maximum;
    e=stalls[noStalls];
    while(s<=e){
        mid=s+(e-s)/2;
        if(isPossible(stalls,noStalls,noCows,mid)){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return ans;
}
int main(){
    int noCows,noStalls,stalls[100];
    cout<<"Enter the no of stalls: ";
    cin>>noStalls;
    for(int i=0;i<noStalls;i++){
        cout<<"Enter the stall Position: ";
        cin>>stalls[i];
    }
    cout<<"Enter the no of cows: ";
    cin>>noCows;
    int dist=minDistance(stalls,noStalls,noCows);
    cout<<"Max min distance is: "<<dist<<endl;
}
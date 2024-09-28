#include<bits/stdc++.h>
using namespace std;

int circularTour(vector<int> petrol, vector<int> distance,int n){
    int start=0,deficit=0,balance=0;
    for(int i=0;i<n;i++){
        balance+=petrol[i]-distance[i];
        if(balance<0){
            deficit+=balance;
            balance=0;
            start=i+1;
        }
    }
    return (balance+deficit>=0)?start:-1;
}
int main(){
    int n;
    vector<int> petrol,distance;
    cin>>n;
    for(int i=0;i<n;i++){
        int el;
        cin>>el;
        petrol.push_back(el);
    }
    for(int i=0;i<n;i++){
        int el;
        cin>>el;
        distance.push_back(el);
    }
    cout<<"Start from: "<<circularTour(petrol,distance,n)<<endl;
}
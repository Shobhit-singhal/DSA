#include<bits/stdc++.h>
#include<cmath>
using namespace std;
vector<int> seige(int n){
    vector<int> prime;
    int end=sqrt(n);
    vector<bool> v(end+1,1);
    for(int i=2;i*i<=end;i++){
        if(v[i]){
            for(int j=i*i;j<=end;j+=i){
                v[j]=0;
                // cout<<"not Prime: "<<j<<endl;

            }
        }
    }
    for(int i=2;i<=end;i++)
        if(v[i])
            prime.push_back(i);

    return prime;
}
vector<bool> segmentedSeive(vector<int>prime,int l,int r){
    vector<bool> v(r-l+1,1);
    for(int i=0;i<prime.size();i++){
        for(int d=ceil(float(l)/prime[i]);prime[i]*d<=r && prime[i]*d>=l;d++){
            v[(prime[i]*d)-l]=0;
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i])
            cout<<i+l<<" ";
    }
}
int main(){
    int l=18,r=40;
    vector<int> prime=seige(r);
    segmentedSeive(prime,l,r);

}
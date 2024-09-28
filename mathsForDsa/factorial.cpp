#include<bits/stdc++.h>
using namespace std;
int calcFact(int n,int m){
    long long ans=1;
    for(long long i=1;i<=n;i++){
        ans=((ans)%m*(i)%m)%m;
    }
    return ans;
}
int main(){
    long n,m;
    cin>>n>>m;
    cout<<calcFact(n,m)<<endl;
}
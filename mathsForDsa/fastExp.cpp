#include<iostream>
using namespace std;
int calcPow(int x,int m,int mod){
    int ans=1;
    while(m>0){
        if(m&1){
            ans=((ans)%mod*(x)%mod)%mod;
        }
        x=((x)%mod*(x)%mod)%mod;
        m=m>>1;
    }
    return ans;
}
int main(){
    int n,m,mod;
    cin>>n>>m>>mod;
    int ans=calcPow(n,m,mod);
    cout<<ans<<endl;
}
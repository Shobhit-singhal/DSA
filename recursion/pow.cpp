#include<iostream>
using namespace std;
int powr(int n,int m){
    if(m==0)
        return 1;
    if(m==1)
        return n;
    int ans=powr(n,m/2);
    if(m%2==0)
        return ans*ans;
    else    
        return n*ans*ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<powr(n,m)<<endl;
}
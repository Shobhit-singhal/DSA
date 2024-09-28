#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    vector<bool> v(n+1,1);
    int count=0;
    for(i=2;i*i<=n;i++){
        if(v[i]){
            // v[i]=0;
            count++;
            for(int j=i*i;j<=n && i<=n/2;j+=i){
                v[j]=0;
            }
        }
    }
    for(int i=2;i<v.size();i++){
        if(v[i])
            cout<<i<<endl;
        
    }
    cout<<"\n total: "<<count;
}

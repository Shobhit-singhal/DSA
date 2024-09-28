#include<iostream>
using namespace std;
int countBit(int n){
    int bit=0;
    while(n!=0){
        if(n&1==1)
            bit++;
        n=n>>1;
    }
    return bit;
}
int main(){
    int n1,n2;
    cout<<"Enter two numbers: ";
    cin>>n1>>n2;
    int ans=countBit(n1)+countBit(n2);
    cout<<"Total one bits are: "<<ans<<endl;
}
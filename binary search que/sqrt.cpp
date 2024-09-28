#include<iostream>
using namespace std;
int getSqrt(int n){
    int s=0,e=n-1,mid,ans=-1;
    while (s<=e)
    {
        mid=(s+e)/2;
        if(mid*mid==n)
            return mid;
        else if(mid*mid<n){
            s=mid+1;
            ans=mid;
        }
        else
            e=mid-1;
    }
    return ans;
}
double precise(int n,int precise,int temp){
    double ans=temp;
    double factor=1;
    for(int i=0;i<precise;i++){
        factor/=10;
        // for(double j=ans;j*j<n;j+=factor){
        //     ans=j;
        // }
        double j=ans;
        while ((j*j)<n)
        {
            ans=j;
            j+=factor;
        }
    }
    return ans;


}
int main(){
    int n;
    cout<<"Enter a num: ";
    cin>>n;
    int ans=getSqrt(n);
    double exact=precise(n,3,ans);
    cout<<"The root of "<<n<<" is: "<<exact<<endl;
}
#include<iostream>
#include<cmath>
using namespace std;
int allocateBooks(int books[],int n,int m){

    int ans=-1,sum1=0,sum2=0,max1=1000,max2=1000;
    if(n>=m){
        for(int i=0;i<n;i++){
            // sum1=0;
            sum1+=books[i];
            sum2=0;
            cout<<"Sum1: "<<sum1<<endl;
            for(int j=i+1;j<n;j++){
                sum2+=books[j]; 
            }
            cout<<"Sum2: "<<sum2<<endl;
            max2=max(sum1,sum2);
            // cout<<"diff1: "<<diff1<<endl;
            cout<<"max: "<<max2<<endl;
            if(max2<max1){
                ans=max2;
                max1=max2;
            }
            
        }
    }
    return ans;
}
int main(){
    int books[4]={10,20,30,40},m=2;
    cout<<"max pages: " <<allocateBooks(books,4,m);
}
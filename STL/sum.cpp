#include<iostream>
#include<vector>
using namespace std;
int main(){
    int sum1=0,sum2=0,sum3;
    vector<int> v={1,2,5};
    vector<int> v2={6,4,5,6};
    vector<int> ans;
    for(int i=0;i<v.size();i++){
        sum1=(sum1*10)+v[i];
    }
    for(int i=0;i<v2.size();i++){
        sum2=(sum2*10)+v2[i];
    }
    sum3=sum1+sum2;
    while(sum3>0){
        ans.push_back(sum3%10);
        sum3/=10;
    }
    for(int i:ans)
    cout<<i<<" ";
}
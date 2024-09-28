#include<iostream>
#include<vector>
using namespace std;
vector<int> reverse(vector<int> v,int m){
    int i=m+1,j=v.size()-1;
    while(i<=j){
        swap(v[i],v[j]);
        i++;
        j--;
    }
    return v;
}
void print(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    vector<int> ans=reverse(v,3);
    print(ans);
}
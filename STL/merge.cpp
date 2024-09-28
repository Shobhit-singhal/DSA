#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=0,j=0,k=0;
    vector<int> merged;
    while(i<m && j<n ){
        if(nums1[i]<=nums2[j]){
            merged.push_back(nums1[i++]);
            k++;
        }
        else{
            merged.push_back(nums2[j++]);
            k++;
        }
    }
    while(i<m){
        merged.push_back(nums1[i++]);
            k++;
    }
    while(j<n){
        merged.push_back(nums2[j++]);
            k++;
    }
    for(i=0;i<n+m;i++){
        // nums1[i]=merged[i];
        cout<<merged[i]<<" ";
    }

}
int main(){
    vector<int> v1,v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v2.push_back(2);
    v2.push_back(5);
    v2.push_back(6);
    merge(v1,v1.size(),v2,v2.size());
}
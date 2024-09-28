#include<iostream>
using namespace std;
int getSum(int books[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=books[i];
    }
    return sum;
}
bool posibleSoln(int books[],int n,int m,int maxPage){
    int leastSt=1,sum=0,temp=0;
    // for(int i=0;i<n;i++){
    //     if(sum+books[i]<=maxPage){
    //         sum+=books[i];
    //     }else{
    //         sum=books[i];
    //         leastSt++;
    //         if(leastSt>m || books[i]>maxPage)
    //         return 0;
    //     }
    // }
    int i=0;
    while(i<n){
        temp=sum+books[i];
        if(temp<=maxPage){
            sum=temp;
            i++;
        }else{
            leastSt++;
            sum=0;
            if(leastSt>m||books[i]>maxPage){
                return 0;
            }
        }
    }
    return 1;
}
int binarySearch(int books[],int n,int m){
    int s=0;
    int e=getSum(books,n);
    int mid,ans=-1;
    while(s<e){
        mid=(s+e)/2;
        if(posibleSoln(books,n,m,mid)){
            // cout<<"possible ans: "<<mid<<endl;
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}
int main(){
    int m=4,n=4;
    int books[n]={5,17,100,11};
    int minPage=binarySearch(books,n,m);
    cout<<"Min pages: "<<minPage;


}